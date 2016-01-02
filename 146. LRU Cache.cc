//146. LRU Cache.cc
#include<list>
#include"../CC/header.h"

class LRUCache{
private:
    size_t cache_sz;
    // key: value use key to index map
    list<pair<int, int>>m_list;
    // key: iter
    map<int, list<pair<int, int>>::iterator>m_map;
public:
    LRUCache(size_t capacity) {
        cache_sz = capacity;
    }
    
    int get(int key) {
    	auto found = m_map.find(key);
    	if(found == m_map.end())return -1;
    	m_list.splice(m_list.begin(), m_list, found->second);
    	//cout << found->second->second << endl;
    	return found->second->second;
    }
    
    void set(int key, int value) {
        auto found = m_map.find(key);
        //hit
        if(found != m_map.end()){
        	m_list.splice(m_list.begin(), m_list, found->second);
        	found->second->second = value;
        	//must return
        	return;
        }
        //miss
        if(m_map.size()==cache_sz){
        	m_map.erase(m_list.back().first);
        	m_list.pop_back();
        }
        m_list.emplace_front(key,value);
        m_map[key]=m_list.begin();
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