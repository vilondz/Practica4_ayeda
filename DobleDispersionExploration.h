#include "ExplorationFunction.h"
#include "DispersionFunction.h"
#pragma once
template <typename key> 
class DobleDispersionExploration : public ExplorationFunction<key> {
  private:
    DispersionFunction<key>& f_;
  public:
    DobleDispersionExploration(DispersionFunction<key>& f) : f_(f){}; 
    unsigned operator()(const key& k, unsigned i) const override{
      return f_(k) * i;
    } 
};