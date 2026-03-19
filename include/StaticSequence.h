#include "Sequence.h"
#include <vector>
template <typename key>
class StaticSequence : public Sequence{
	public:
		std::vector<key> block_;
		int blocksize_;
	public:
		StaticSequence(blocksize) : blocksize_(blocksize) {};
		bool search(const key& k);
		bool insert(const key& k);
		bool isFull(void);
};

template <typename key>
bool StaticSequence<key>::insert(const key& k){
	if(!isFull()){
		block_.insert(block_.begin(), k);
	}
	return false;
}
template <typename key>
bool StaticSequence<key>::search(const key& k){
	for(auto aux : block_){
		if(aux == k){
			return true;
		}
	}
	return false;
}
template <typename key>
bool StaticSequence<key>::isFull(void){
	if(block_.size() == blocksize_){
		return true;
	}
	return false;
}