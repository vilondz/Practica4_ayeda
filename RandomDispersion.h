#include <cstdlib>
#include "DispersionFunction.h"
#pragma once
template <typename key>
class RandomDispersion : public DispersionFunction<key> {
 private:
  unsigned tableSize_;

 public:
  RandomDispersion(unsigned tableSize) : DispersionFunction<key>(tableSize){};

  unsigned operator()(const key& k) const override {
    srand(static_cast<long>(k));
    return rand();
  }
};