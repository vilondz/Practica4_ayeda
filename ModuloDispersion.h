#include "DispersionFunction.h"
#pragma once

template <typename key>
class ModuloDispersion : public DispersionFunction<key> {
 public:
  ModuloDispersion(int ts) : DispersionFunction<key>(ts) {}

  unsigned operator()(const key& k)const override {
    return k % this->get_tablesize();
  }
};