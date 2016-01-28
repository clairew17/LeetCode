//146. LRU Cache.cc
#include<list>
#include"../CC/header.h"

class LRUCache{
private:
    int sz;
    //key:val
    list<pair<int, int>>data_list;
    //key:iterator
    map<int, list<pair<int, int>>::iterator>m;
public:
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        auto found = m.find(key);
        if(found==m.end())
        {
            return -1;
        }else{
            //insert to head
            data_list.splice(data_list.begin(), data_list, found->second);
            return found->second->second;
        }
    }
    
    void set(int key, int value)
    {
        if(m.find(key)==m.end())//miss
        {
            if(m.size()==sz){//delete the last
                auto p = data_list.back();
                m.erase(p.first);
                data_list.pop_back();
            }
            //insert to head
            data_list.emplace_front(key,value);
            m[key] = data_list.begin();
        }else
        {
            //update value
            auto it = m[key];
            it->second = value;
            //insert to head
            data_list.splice(data_list.begin(), data_list, it);
        }
    }
};

int main(){
	int capacity = 10;
	LRUCache cache(capacity);
	cout << cache.get(2) << endl;
	cache.set(2,6);
	cout << cache.get(1) << endl;
	cache.set(1,5);
	cache.set(1,2);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	return 0;
}