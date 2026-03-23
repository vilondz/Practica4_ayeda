#include "DispersionFunction.h"
#pragma once
template <typename key>
class SumDispersion : public DispersionFunction<key> {
 private:

 public:
  SumDispersion(unsigned tableSize) : DispersionFunction<key>(tableSize){};

  unsigned operator()(const key& k) const override {
    unsigned sum = 0;
    unsigned n = k; 
    while (n > 0) {
        sum += n % 10; 
        n /= 10;       
    }
    return sum % this->get_tablesize();
  }
};