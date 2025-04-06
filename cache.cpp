#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<queue>

using std::vector;
using std::map;
using std::pair;

class LRUCache {
    int ind = 1;
    int Capacity;
    map<int,int> cache;
    map<int,int> priority;
    
    public:
    LRUCache(int capacity){
        Capacity = capacity;
    }
    int get (int key){
        if (cache.find(key)==cache.end()) return -1;
        else {
            priority[key] = ind++;
            return cache[key];
        }
    }
    void put(int key, int value) {
        if (cache.find(key)!=cache.end()) {
            cache[key] = value;
            priority[key] = ind++;
            return;
        }
        if (cache.size()<Capacity){
            cache[key] = value;
            priority[key] = ind++;
        }
        else {
            int minim = -1;
            int keys = -1;
            for (auto it = priority.begin();it!=priority.end();it++){
                if (it->second<minim||minim == -1) {
                    minim = it->second;
                    keys = it->first;
                }
            }
            priority.erase(keys);
            cache.erase(keys);
            cache[key] = value;
            priority[key] = ind++;
        }
    }

};