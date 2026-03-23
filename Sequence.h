template <typename key>
class Sequence{
	public:
		virtual bool insert(const key& k) = 0;
		virtual bool search(const key& k) = 0;
		virtual bool isFull(void) const = 0;
}; 