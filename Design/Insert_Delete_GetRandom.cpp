/**
A hashmap could be used to insert an element in O(1) time
While inserting if we add the element to the array also.
Then deleting an element is simple from an hashmap 
But how do we delete from the array.
If we are going to delete the element from the array, then that element must be present.
We need to bring the element to the last index of the array.
If |ARRAY| = N, and the element belongs in the range[0,N - 2], then we'll take the last 
element and swap it with the current element we want to delete and update tha hashmap
*/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> number_to_index;
    vector<int> array;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(number_to_index.find(val) != number_to_index.end()) {
            return false;
        }
        array.push_back(val);
        number_to_index[val] = array.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(number_to_index.find(val) == number_to_index.end()) {
            return false;
        }
        int index = number_to_index[val];
        if(index < array.size() - 1) {
            number_to_index[array.back()] = index;
            swap(array[index], array.back());
        }
        array.pop_back();
        number_to_index.erase(val);
        return true;
    } 
    
    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % (array.size());
        return array[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */