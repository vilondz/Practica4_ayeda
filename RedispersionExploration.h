#include "ExplorationFunction.h"
#include <cstdlib>
#pragma once
template <typename key> 
class RedispersionExploration : public ExplorationFunction<key> {
  private:

  public:
    unsigned operator()(const key& k, unsigned i) const override{
      srand(k);
      unsigned numero= 0;
      for(int k = 0; k < i; k++){
        numero = rand();
      }
      return numero;
    }
};