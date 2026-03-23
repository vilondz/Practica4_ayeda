#include "Sequence.h"
#include <vector>
#pragma once
template <typename key>
class StaticSequence : public Sequence<key>{
	public:
		std::vector<key> block_;
		int blocksize_;
	public:
		StaticSequence(int blocksize) : blocksize_(blocksize) {};
		bool search(const key& k)const;
		bool insert(const key& k);
		bool isFull(void)const ;
		void print_block() override;
		int size() override;
};

template <typename key>
bool StaticSequence<key>::insert(const key& k){
	std::cout << "bloque " << k << std::endl;
	if(!isFull()){
		block_.insert(block_.begin(), k);
		return true;
	}
	return false;
}
template <typename key>
bool StaticSequence<key>::search(const key& k)const {
	for(auto aux : block_){
		if(aux == k){
			return true;
		}
	}
	return false;
}
template <typename key>
bool StaticSequence<key>::isFull(void)const {
	if(block_.size() == blocksize_){
		return true;
	}
	return false;
}

template<typename key>
void StaticSequence<key>::print_block(){
	for(auto& aux : block_){
		std::cout << "imprimiendo bloque" << std::endl;
		std::cout << aux << " ";
	}
}

template <typename key>
int StaticSequence<key>::size(){
	return block_.size();
}