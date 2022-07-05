
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    LRUCache(){size=10;}
    LRUCache(int s);
    ~LRUCache();

    void refer(int);
    void printCache();


private:    
    list<int> cache;
    unordered_map< int,list<int>::iterator > map;
    int size;
};

class LRUCache2 : public LRUCache
{
public:
    LRUCache2(int s);
    ~LRUCache2();

    void refer(int,char);
    void printCache();

private:    
    list< pair<int,char> > cache;
    unordered_map< int,list<pair<int,char>>::iterator > map;
    int size;
};