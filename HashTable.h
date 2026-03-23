#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"
#include "StaticSequence.h"
#include "DinamicSecuence.h"
#include <vector>
#include <memory>
#pragma once
template <typename key, class container = StaticSequence<key>>
class HashTable
{
private:
  unsigned blocksize_;
  std::vector<std::unique_ptr<container>> table_;
  unsigned tablesize_;
  DispersionFunction<key> &fd_;
  ExplorationFunction<key> &fe_;

public:
  HashTable(unsigned, DispersionFunction<key> &, ExplorationFunction<key> &, unsigned);
  ~HashTable() {}
  bool insert(const key& k) ;
  bool search(const key& k);
  void print() const ;
};

template <typename key, class container>
HashTable<key, container>::HashTable(unsigned tablesize, DispersionFunction<key> &fd,
                                     ExplorationFunction<key> &fe, unsigned blocksize)
    : fd_(fd), fe_(fe), tablesize_(tablesize), blocksize_(blocksize)
{
  for (unsigned i = 0; i < tablesize_; i++)
  {
    table_.push_back(std::make_unique<container>(blocksize_));
  }
}
template <typename key, class container>
bool HashTable<key, container>::insert(const key& k) {
  bool insertado = false;
  unsigned intentos = 1;
  unsigned pos = fd_(k) % tablesize_;
  if(table_[pos]->insert(k)){
    //std::cout << "el bloque no esta lleno " << std::endl;
    //std::cout << "llave insertada en " << fd_(k) % tablesize_ << std::endl;
    insertado = true;
  }
  //std::cout << "el bloque esta lleno usamos la funcion de exploracion" << std::endl;
  while(!insertado){
    pos = (fd_(k) + fe_(k,intentos)) % tablesize_;
    //std::cout << "intentando meter la llave en :"<<  (fd_(k) + fe_(k,intentos)) % tablesize_ << std::endl;
    if(table_[pos]->insert(k)){
      //std::cout << "llave añadida " << std::endl;
      insertado = true;
    }
    //std::cout << "el bloque esta lleno usando la funcion de exploracion de nuevo " << std::endl;
    ++intentos;
    if(intentos >= tablesize_){
      //std::cout << "demasiados intentos no se pudo meter la llave en la tabla" << std::endl;
      return false;
    }
  }
  return true;
}
template <typename key, class container>
bool HashTable<key, container>::search(const key& k){
  bool encontrado = false;
  unsigned intentos = 1;
  unsigned pos = fd_(k) % tablesize_;
  //std::cout << fd_(k) % tablesize_ << std::endl;
  if(table_[pos]->search(k)){
    encontrado = true;
  }
  while(!encontrado){
    pos = (fd_(k) + fe_(k,intentos)) % tablesize_;
    //std::cout <<  (fd_(k) + fe_(k,intentos)) % tablesize_ << std::endl;
    if(table_[pos]->search(k)){
      encontrado = true;
    }
    ++intentos;
    if(intentos >= tablesize_){
      return false;
    }
  }
  return true;
}
template <typename key, class container>
void HashTable<key, container>::print()const {
  for(auto& aux : table_){
    aux->print_block();
    std::cout << std::endl;
  }
}
// clase especializada

template <typename key>
class HashTable<key, DinamicSequence<key>>
{
private:
  unsigned tablesize_;
  std::vector<std::unique_ptr<DinamicSequence<key>>> table_;
  DispersionFunction<key> &fd_;

public:
  HashTable(unsigned size, DispersionFunction<key> &fd)
      : tablesize_(size), fd_(fd)
  {
    for (unsigned i = 0; i < tablesize_; ++i)
    {
      table_.push_back(std::make_unique<DinamicSequence<key>>());
    }
  }

  bool search(const key &k) const
  {
    unsigned pos = fd_(k) % tablesize_;
    return table_[pos]->search(k);
  }

  bool insert(const key &k)
  {
    unsigned pos = fd_(k) % tablesize_;
    return table_[pos]->insert(k);
  }
  void print(){
    for(auto& aux : table_){
      std::cout << aux->size();
      std::cout << std::endl;
    }
  }
};
