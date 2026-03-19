#include "ExplorationFunction.h"

template <typename key> 
class RedispersionExploration : public ExplorationFunction<key> {
  private:

  public:
    unsigned operator()(const key&, unsigned) const;
};