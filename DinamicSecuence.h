#include "Sequence.h"
#include <vector>
template <typename key>
class DinamicSequence : public Sequence<key>{
	private:
		std::vector<key> block_;
	public:
		bool search(const key& k);
		bool insert(const key& k);
		bool isFull(void);
};
template <typename key>
bool DinamicSequence<key>::insert(const key& k){
	block_.insert(block_.begin(), k);
}
template <typename key>
bool DinamicSequence<key>::search(const key& k){
	for(auto aux : block_){
		if(aux == k){
			return true;
		}
	}
	return false;
}
template <typename key>
bool DinamicSequence<key>::isFull(void){
	return false;
}