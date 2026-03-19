#include <cstdlib>
#include "DispersionFunction.h"
template <typename Key>
class RandomDispersion : public DispersionFunction<Key> {
 private:
  unsigned tableSize_;

 public:
  RandomDispersion(unsigned tableSize) : tableSize_(tableSize) {}

  unsigned operator()(const Key& k) const override {
    srand(k);
    return rand() % tableSize_;
  }
};