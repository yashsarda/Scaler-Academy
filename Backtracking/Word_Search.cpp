// Leetcode 212
//Looks like a straight forward recursive problem
/*
    
    1. Base step
    2. Hypothesis
    3. Inductive step
    
    Brute Force :
    Consider each cell as starting point for our word
    Go through the complete matrix recursively building the string as you go.
    At any point if you find the string present in words list you can put it the answer
    
    How do we prune our recursion? --> Use tries
    
*/
struct Node {
    Node* alpha[26];
    bool isLeaf;
    
    Node() {
        for(int i=0;i<26;i++)
            this -> alpha[i] = nullptr;
        this -> isLeaf = false;
    }
};
class Trie {
     public:
    
        void insert(Node* root, string s)
        {
            int len = s.length();
            for(int i=0;i<len;i++) {
                if(!root -> alpha[s[i] - 'a']) {
                    Node* n = new Node();
                    root -> alpha[s[i] - 'a'] = n;
                }
                root = root -> alpha[s[i] - 'a'];
            }
            root -> isLeaf = true;
        }
    
        bool search(Node* root, string s)
        {
            int len = s.length();
            for(int i=0;i<len;i++) {
                if(!root -> alpha[s[i] - 'a'])
                    return false;
                root = root -> alpha[s[i] - 'a'];
            }
            return true;
        }

};
class Solution {
public:
    int rows, columns;
    vector<bool> charPresent;
    map<string, bool> isPresent;
    Node* root;
    Trie t;
    bool isSafe(int x, int y)
    {
        return !(x >= rows || x < 0 || y >= columns || y < 0);
    }
    void findAll(int i,int j, string temp, vector<vector<char>>& board,vector<vector<bool>>& visited,vector<string>& answer) {
        //Base case
        bool se = t.search(root, temp);
        if(!se) 
            return;
        if(isPresent[temp]) {   
          answer.push_back(temp);
        }
        int x[] = {0,0,1,-1};
        int y[] = {1,-1,0,0};
        
        for(int k=0;k<4;k++) {
            int xd = x[k] + i;
            int yd = y[k] + j;
            if(isSafe(xd,yd) && !visited[xd][yd]) {
                visited[xd][yd] = true;
                temp += board[xd][yd];
                findAll(xd,yd,temp,board,visited,answer);
                temp.pop_back();
                visited[xd][yd] = false;
            } 
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        columns = board[0].size();
        charPresent.clear();
        charPresent.resize(26, false);
        root = new Node();
        for(string word : words) {
            t.insert(root, word);
            isPresent[word] = true;
            charPresent[word[0] - 'a'] = true;
        }
        vector<string> answer;
        vector<vector<bool> > visited(rows, vector<bool>(columns, false));
         for(int i=0;i<rows;i++) {
            for(int j=0;j<columns;j++) {
                if(charPresent[board[i][j] - 'a']) {
                    string temp = "";
                    temp += board[i][j];
                    visited[i][j] = true;
                    findAll(i,j,temp,board,visited,answer);
                    temp.pop_back();
                    visited[i][j] = false;
                }
            }
        }
        set<string> a(answer.begin(), answer.end());
        vector<string> final_answer(a.begin(), a.end());
        return final_answer;
        
    }
};