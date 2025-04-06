#include<iostream>
#include<map>
#include<vector>

using std::map;
using std::vector;

class LRUcache{

    struct priority {
        int Size;
        vector<vector<int>> store;
        priority (){
            Size = 0;   
        }
        void remove(){
            store.erase(store.begin());
        }
    };

    int Capacity;
    int ind = 0;
    std::map<int,int> cache;
    priority pq;

    void swap (vector<int>& a, vector<int>& b){
        vector<int> temp = a;
        a = b;
        b = temp;
    }

    void correction(vector<vector<int>>& all, int i){
        int n = all.size();
        int left = (2*i) + 1;
        int right = (2*i) + 2;
        if (left>=n&&right>=n) return;
        else if (right>=n) {
            if (all[left][1]<all[i][1]) swap (all[left],all[i]);
            return;
        }
        else {
            if ((all[left][1]>=all[i][1])&&(all[right][1]>=all[i][1])) return;
            else if (all[left][1]>=all[i][1]) {
                swap (all[right],all[i]);
                correction (all,right);
            }
            else if (all[right][1]>=all[i][1]) {
                swap (all[left],all[i]);
                correction(all,left);
            }
            else {
                vector<int> minim = (all[left][1]<all[right][1]) ? all[left] : all[right];
                if (minim ==all[left]) {
                    swap (all[left],all[i]);
                    correction(all,left);
                }
                else {
                    swap (all[right],all[i]);
                    correction(all,right);
                }
            }
        }
    }

    void heapify(vector<vector<int>>& all){
        int n = all.size();
        if (n<=1) return;
        for (int i = n-1;i>=0;i--){
            int left = (2*i) + 1;
            int right = (2*i) + 2;
            if (left>=n&&right>=n) continue;
            else if (right>=n) {
                if (all[left][1]<all[i][1]) swap (all[left],all[i]);
                continue;
            }
            correction(all,i);
        }
    }

    int search (vector<vector<int>> check, int key){
        vector<int> answer;
        int n = check.size();
        for (int i=0;i<n;i++){
            if (check[i][0]==key) return i;
        }
        return -1;
    }   
    


    public :
    LRUcache(int capacity){
        Capacity = capacity;
    }

    int get(int key){
        if (cache.find(key)==cache.end()) return -1;
        else {
            int index = search(pq.store, key);
            pq.store[index][1] = ++ind;
            // std::cout<<"key : "<<key<<" and priority : "<<ind<<" : from get : " <<pq.store[index][1]<<std::endl;
            heapify(pq.store);
            return cache[key];
        }
    }

    void put (int key, int value){
        // std::cout<<pq.Size<<" : Size of priority queue and key to be inserted/modified : key : "<<key<<" -- value : "<<value<<std::endl;
        if (cache.find(key)!=cache.end()) {
            cache[key] = value;
            int index = search(pq.store, key);
            pq.store[index][1] = ++ind;
            // std::cout<<"key : "<<key<<" and priority : "<<ind<<" : from get : " <<pq.store[index][1]<<std::endl;
            heapify(pq.store);
            return;
        }
        if (pq.Size<Capacity){
            cache[key] = value;
            vector<int> temp;
            temp.push_back(key);
            // std::cout<<"key : "<<key<<" and priority : "<<ind<<std::endl;
            temp.push_back(++ind);
            pq.store.push_back(temp);
            heapify(pq.store);
            pq.Size++;
        }
        else {
            cache.erase(pq.store[0][0]);
            pq.remove();
            cache[key] = value;
            vector<int> temp;
            temp.push_back(key);
            // std::cout<<"key : "<<key<<" and priority : "<<ind<<" when priority size is full"<<std::endl;
            temp.push_back(++ind);
            pq.store.push_back(temp);
            heapify(pq.store);
        }
    }

};

int main(){
    LRUcache LRU(2);
    LRU.put(1,1);
    LRU.put(2,2);
    std::cout<<"from main : "<<LRU.get(1)<<std::endl;
    LRU.put(3,3);
    std::cout<<"from main : "<<LRU.get(2)<<std::endl;
    LRU.put(4,4);
    std::cout<<"from main : "<<LRU.get(1)<<std::endl;
    std::cout<<"from main : "<<LRU.get(3)<<std::endl;
    std::cout<<"from main : "<<LRU.get(4)<<std::endl;
    return 0;
}