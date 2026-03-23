#include "ExplorationFunction.h"
#pragma once
template <typename key> 
class LinealExploration : public ExplorationFunction<key> {
  private:

  public:
    unsigned operator()(const key&, unsigned i) const override {
      return i;
    }
};