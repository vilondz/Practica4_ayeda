
#pragma once
template <typename key> 
class DispersionFunction{
  private:
    int tablesize_;
  public:
    DispersionFunction(int tz){
      tablesize_ = tz;
    }
    virtual unsigned operator()(const key&) const = 0;
    unsigned get_tablesize() const {return tablesize_;}
    void set_tablesize(int tz){tablesize_ = tz;}
};

