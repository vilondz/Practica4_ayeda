#include "ExplorationFunction.h"
#include <cstdlib>
template <typename key> 
class RedispersionExploration : public ExplorationFunction<key> {
  private:

  public:
    unsigned operator()(const key&, unsigned) const override{
      srand(k);
      unsigned numero= 0;
      for(int k = 0; k < i; k++){
        numero = rand();
      }
      return numero;
    }
};