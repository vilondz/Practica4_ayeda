template <typename Key>
class SumDispersion : public DispersionFunction<Key> {
 private:
  unsigned tableSize_;

 public:
  SumDispersion(unsigned tableSize) : tableSize_(tableSize) {}

  unsigned operator()(const Key& k) const override {
    unsigned sum = 0;
    for (auto c : k) {
      sum += static_cast<unsigned>(c);
    }
    return sum % tableSize_;
  }
};