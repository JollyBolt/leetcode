class LFUCache {
private:
    //ordered map for < frequency , dll<key,freq> >
    map < int,list<pair<int,int>> > freq;
    //Unordered map for <key, < Address, value >>
    unordered_map <int, pair<list<pair<int,int>>::iterator,int>> mp;
    int n;
public:
    LFUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)!=0){
            auto node = *mp[key].first;
            int f = node.second;
            freq[f].erase(mp[key].first);
            if(freq[f].size()==0) freq.erase(f);
            freq[f+1].push_front({key,f+1});
            mp[key].first = freq[f+1].begin();
            return mp[key].second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)!=0){
            auto node = *mp[key].first;
            int f = node.second;
            freq[f].erase(mp[key].first);
            if(freq[f].size()==0) freq.erase(f);
            freq[f+1].push_front({key,f+1});
            mp[key] = {freq[f+1].begin(),value};
        }
        else {
            if(mp.size()==n){
                int f = freq.begin()->first;
                int del_key = freq[f].back().first;
                freq[f].pop_back();
                mp.erase(del_key);
                if(freq[f].size()==0) freq.erase(f);

        }
            freq[1].push_front({key,1});
            mp[key] = {freq[1].begin(),value};
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */