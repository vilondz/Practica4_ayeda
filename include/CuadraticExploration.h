#include "ExplorationFunction.h"

template <typename key> 
class CuadraticExploration : public ExplorationFunction<key> {
  private:

  public:
    unsigned operator()(const key&, unsigned i) const override{
      return i * i;
    }
};