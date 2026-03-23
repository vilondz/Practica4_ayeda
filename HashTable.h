#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"
#include "StaticSequence.h"
#include "DinamicSecuence.h"
#include <vector>
#include <memory>

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
  bool insert(const key& k) const;
  bool search(const key& k);
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
bool HashTable<key, container>::insert(const key& k)const {

}
template <typename key, class container>
bool HashTable<key, container>::search(const key& k){
  
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
   
  }

  bool insert(const key &k)
  {
    
  }
};
