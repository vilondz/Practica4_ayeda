#include "ExplorationFunction.h"

template <typename key> 
class DobleDispersionExploration : public ExplorationFunction<key> {
  private:
    std::unique_ptr<DispersionFunction<key>> f_;
  public:
    DobleDispersionExploration<std::unique_ptr<DispersionFunction<key>>(f) : f_(f){}; 
    unsigned operator()(const key&, unsigned i) const override{
      return f_(k) * i;
    } 
};