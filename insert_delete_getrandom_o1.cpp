// we can insert and remove from hashmap in O(1)
// however, we cannot get a random value in O(1) because this would require an iterator
// but we can keep an updated array with elements to pull randomly from in O(1)

class RandomizedSet {
    private:
        vector<int> array;
    
        // key = num, val = array location
        unordered_map<int, int> storeNums;
    
    public:
        RandomizedSet() {
            
        }
        
        bool insert(int val) {
    
            // first check if we have this number stored already
            if(storeNums.count(val))
                return false;
            
            // then push to the array
            array.push_back(val);
    
            // add this new pos to the hash map
            storeNums[val] = array.size() - 1;
    
            return true;
            
        }
        
        bool remove(int val) {
            // check if val is in the hash map
            if(!storeNums.count(val))
                return false;
            
            // collect array location, and delete that element
            int location = storeNums[val];
    
            // since we can't delete a random location in O(1) from an array we will need
            // to swap this location with the end of the array, then pop it off
            array[location] = array[array.size() - 1];
    
            // update hash map (since we moved around an element)
            storeNums[array[location]] = location;
    
            array.pop_back();
            storeNums.erase(val);
    
            return true;
        }
        
        int getRandom() {
            int randomIndex = rand() % array.size();
            return array[randomIndex];
        }
    };
    
    /**
     * Your RandomizedSet object will be instantiated and called as such:
     * RandomizedSet* obj = new RandomizedSet();
     * bool param_1 = obj->insert(val);
     * bool param_2 = obj->remove(val);
     * int param_3 = obj->getRandom();
     */