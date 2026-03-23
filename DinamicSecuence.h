#include "Sequence.h"
#include <vector>
#pragma once
template <typename key>
class DinamicSequence : public Sequence<key>{
	private:
		std::vector<key> block_;
	public:
		bool search(const key& k)const override;
		bool insert(const key& k) override;
		bool isFull(void)const override;
		void print_block() override;
		int size() override;
};
template <typename key>
bool DinamicSequence<key>::insert(const key& k){
	block_.insert(block_.begin(), k);
	return true;
}
template <typename key>
bool DinamicSequence<key>::search(const key& k)const{
	for(auto aux : block_){
		if(aux == k){
			return true;
		}
	}
	return false;
}
template <typename key>
bool DinamicSequence<key>::isFull(void)const {
	return false;
}

template <typename key>
void DinamicSequence<key>::print_block() {
	for(auto aux : block_){
		std::cout << aux << " ";
	}
}

template <typename key>
int DinamicSequence<key>::size(){
	return block_.size();
}