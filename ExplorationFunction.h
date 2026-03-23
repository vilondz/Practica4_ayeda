template <typename key> 
class ExplorationFunction {
  private:

  public:
    virtual unsigned operator()(const key&, unsigned) const = 0;
};