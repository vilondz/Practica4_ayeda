#include "DispersionFunction.h"
#pragma once

template <typename key>
class ModuloDispersion : public DispersionFunction<key> {
 public:
  ModuloDispersion(int ts) : DispersionFunction<key>(ts) {}

  unsigned operator()(const key& k)const override {
    return static_cast<long>(k) % this->get_tablesize();
  }
};