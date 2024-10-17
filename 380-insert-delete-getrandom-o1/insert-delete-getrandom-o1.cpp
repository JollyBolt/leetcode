class RandomizedSet {
private:
    vector<int> v; //Vector of elements
    unordered_map<int,int>mp; // map of <element,index>
    int n;
public:
    RandomizedSet() {
        n=0;
    }
    
    bool insert(int val) {
        if(mp.count(val)==0){
            v.push_back(val);
            mp[val] = n;
            n++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)!=0){
            int ind = mp[val];
            swap(v[ind],v[n-1]);
            v.pop_back();
            mp[v[ind]] = ind;
            mp.erase(val);
            n--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int ind = rand()%n;
        return v[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */