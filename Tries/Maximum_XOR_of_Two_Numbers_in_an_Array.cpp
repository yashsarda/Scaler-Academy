/*struct Trie
{
    int data;
    bool isTerminal;
    Trie* children[2];
    
    Trie()
    {
        this->isTerminal = false;
        this -> children[0] = nullptr;
        this -> children[1] = nullptr;
        
    }   
};
void insert(Trie* head,int value)
{
        Trie* root = head;
        for(int i=31;i>=0;i--){
            int val = (value & (1 << i)) ? 1 : 0;
            if(!root -> children[val]){
                Trie* node = new Trie();
                root -> children[val] = node;
            }
            root = root -> children[val];
        }
        root -> isTerminal = true;
        root -> data = value;
}
    
int search(Trie* head,int value)
{
        int ans = 0;
        Trie* root = head;
        for(int i=31;i>=0;i--){
            int val = value & (1 << i);
            val = val ? 1 : 0;
            if(root -> children[1-val]){
                root = root -> children[1-val];
            }
            else {
                root = root -> children[val];
            }
        }
        return value ^ root -> data;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n <= 1) return 0;
    
    Trie* root = new Trie();
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        insert(root,A[i]);
        int val = search(root,A[i]);
        ans = max(ans, val);
    }
    return ans;
    
}*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n == 1)
        return 0;
    
    int ans = 0;
    // mask is useful in reprsenting those number which have bit set 
    int mask = 0;
    int temp = 0;
    for(int i=31;i>=0;i--){
        //set the 2^i bit
        mask = mask | (1 << i);
        // we see if we can form this number or not
        temp = ans | (1 << i);
        
        set<int> s;
        // This will insert all the elements which have bit 1 from position 31 to i
        for(int num:A){
            s.insert(num & mask);
        }
        
        for(auto it=s.begin();it!=s.end();it++){
            // We try to see if we can form this temp. 
            // How ? We know that a ^ b = c, then a ^ c = b;
            // a ^ b = temp then a ^ temp = b;
            // For every a present in the set we try to find b
            // if we don't find any we cannot form the result so we don't update ans
            if(s.find(*it ^ temp) != s.end()){
                ans = temp;
                break;
            }
        }
    }
    return ans;
}
