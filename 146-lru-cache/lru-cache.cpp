class LRUCache {
private:
    //List of <key>
    list<int> cache;
    //Map of < key < Address , value > >
    unordered_map<int,pair<list<int>::iterator,int>> mp;
    int n;
public:
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void makeRecentlyUsed(int key,int value){
        cache.push_front(key);
        mp[key]={cache.begin(),value};
    }

    int get(int key) {
        if(mp.count(key)!=0){
            cache.erase(mp[key].first);
            makeRecentlyUsed(key,mp[key].second);
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)!=0){
            cache.erase(mp[key].first);
        }
        makeRecentlyUsed(key,value);
        if(cache.size()>n) {
            mp.erase(cache.back());
            cache.pop_back();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */