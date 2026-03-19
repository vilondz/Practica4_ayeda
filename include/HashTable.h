#include "DispersionFunction.h"
#include "ExplorationFunction.h"
#include "Sequence.h"
#include "StaticSequence.h"
#include <vector>
#include <memory>

template <typename key, class container = StaticSequence<key>>
class HashTable {
  private:
    unsigned blocksize_;
    std::vector<container>table_;
    unsigned tablesize_;
    std::unique_ptr<DispersionFunction> fd_;
    std::unique_ptr<ExplorationFunction> fe_;
  public:
    HashTable(unsigned, DispersionFunction<key>&, ExplorationFunction<key>&, unsigned);
    ~HashTable(){} 
};

template <typename key, class container>
HashTable<key,container>::HashTable(unsigned tablesize, DispersionFunction<key>& fd,
                                    ExplorationFunction<key>& fe, unsigned blocksize){
tablesize_ = tablesize;
blocksize_ = blocksize;
fd_ = fd;
fe_ = fe;
for(int i = 0; i< tablesize_; i++){
  table_.push_back(StaticSequence(blocksize_));
}
}


//clase especializada 

