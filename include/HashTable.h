
template <typename key, typename container>
class HashTable {
  private:
    std::vector<container> tabla_hash_;
    int tablesize_;
  public:
    HashTable(int);
    ~HashTable(){}
    
};
