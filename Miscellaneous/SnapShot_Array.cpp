/*
What is the most complicated operation to perform in this set?
--> It's the get operation because we want to know the values of all elements at that particular snap id.

What can be a brute force method?
--> Initilize a vector with the given length
    Maintain a global count variable which will denote the number of times we     have snapped
    Maintain a map of vectors where the key will be snap_id and value will be     vector at that particular snap id
    This gives MLE
    
Between two snaps some elements will change so we'll just keep those element 
which have changed

0 - 0,1,2
1
give me value of 0 or 1 then give from 1
2 - 0,1
3 - 0
give me value of 1 then give from 2

*/
class SnapshotArray {
public:
    int count = 0;
    map<int,int> umap[50001];
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        umap[count][index] = val;
    }
    
    int snap() {
        ++count;
        return count - 1;
    }
    
    int get(int index, int snap_id) {
        for(int i=snap_id;i>=0;i--) {
            unordered_map<int,int> u = umap[i];
            if(!u.empty() && u.find(index) != u.end())
                return u[index];
        }
        return 0;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */