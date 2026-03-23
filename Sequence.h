#pragma once
template <typename key>
class Sequence{
	public:
		virtual bool insert(const key& k) = 0;
		virtual bool search(const key& k)const  = 0;
		virtual bool isFull(void) const = 0;
		virtual void print_block() = 0;
		virtual int size() = 0;
}; 