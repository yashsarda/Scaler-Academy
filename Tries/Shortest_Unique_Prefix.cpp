class Node
{
    public:
    
    char data;
    bool isTerminal;
    unordered_map<char,Node*> children;
    int encounter;
    
    Node(char value) 
    {
        this -> data = value;
        this -> isTerminal = false;
        this -> encounter = 0;
    }
    
    void insert(string str)
    {
        Node* root = this;
        int n = str.size();
        for(int i=0;i<n;i++){
            char c = str[i];
            if(root -> children.count(c) > 0){
                root -> encounter++;
                root = root -> children[c];
            }
            else {
                Node* node = new Node(c);
                root -> encounter = 1;
                root->children[c] = node;
                root = root -> children[c];
            }
        }
        root -> isTerminal = true;
    }
    
    string search(string str)
    {
        Node* root = this;
        int n = str.size();
        string ans = "";
        for(int i=0;i<n;i++){
            char c = str[i];
            root = root -> children[c];
            if(root -> encounter == 1){
                ans += root -> data;
                return ans;
            }
            else {
                if(root -> data != '\0')
                     ans += root -> data;
            }
          //  root = root -> children[c];
        }
    }
};
vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    vector<string> ans;
    if(n == 0)
        return ans;
    
    if(n == 1){
        string x = string(1,A[0][0]);
        ans.push_back(x);
        return ans;
    }
    Node* root = new Node('\0');
    for(int i=0;i<n;i++){
        root -> insert(A[i]);
    }
    
    for(int i=0;i<n;i++){
        string r = root -> search(A[i]);
        ans.push_back(r);
    }
    
    return ans;
        
}
