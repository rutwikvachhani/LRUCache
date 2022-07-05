
#include <iostream>
#include "LRUCache.h"

LRUCache::LRUCache(int s) : size(s)
{
    cout << "LRUCache created" << endl;
}

LRUCache::~LRUCache()
{
    cout << "LRUCache destroyed" << endl;
}

void LRUCache::printCache()
{
    cout << "LRUCache : ";
    for(auto i:cache)
    {
        cout << i << " ";
    }
    cout << endl;
}

void LRUCache::refer(int k)
{

    if(map.find(k)==map.end())
    {
        //cache miss
        if(cache.size()==size)
        {
            //page fault
            int last = cache.back();
            cache.pop_back();
            map.erase(last);
        }
    }
    else
    {
        //cache hit
        cache.erase(map[k]);
    }

    cache.push_front(k);
    map[k] = cache.begin();

}

LRUCache2::LRUCache2(int s) : size(s)
{
    cout << "LRUCache2 created" << endl;
}

LRUCache2::~LRUCache2()
{
    cout << "LRUCache2 destroyed" << endl;
}

void LRUCache2::refer(int k, char c)
{

    if(map.find(k)==map.end())
    {
        //cache miss
        if(cache.size()==size)
        {
            //page fault
            int last = cache.back().first;
            cache.pop_back();
            map.erase(last);
        }
    }
    else
    {
        //cache hit
        cache.erase(map[k]);
    }

    cache.push_front(make_pair(k,c));
    map[k] = cache.begin();

}

void LRUCache2::printCache()
{
    cout << "LRUCache2 : ";
    for(auto i:cache)
    {
        cout << i.first << ":" << i.second << " ";
    }
    cout << endl;
}


int main()
{

    //LRUCache c(10);
    LRUCache2 c2(10);

    //Input Sequence
    //2,B
    //3,C
    //4,D
    //2,B
    //1,A
    //3,C
    //6,F
    //8,H
    //4,D

    c2.refer(2,'B');
    c2.printCache();
    c2.refer(3,'C');
    c2.printCache();
    c2.refer(4,'D');
    c2.printCache();
    c2.refer(2,'B');
    c2.printCache();
    c2.refer(1,'A');
    c2.printCache();
    c2.refer(3,'C');
    c2.printCache();
    c2.refer(6,'F');
    c2.printCache();
    c2.refer(8,'H');
    c2.printCache();
    c2.refer(4,'D');
    c2.printCache();

    system("pause");
    return 0;

}

