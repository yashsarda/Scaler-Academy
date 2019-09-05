// Use BFS to find the shortest path from start to end node
// For a particular word, the child for that word will be the words from the list
// which differ in only one character

bool adjacent(string s1, string s2)
{
    int count = 0;
    for(int i=0;i<s1.length();i++){
        count += s1[i] != s2[i];
    }
    
    return count == 1 ? true : false; 
}
int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<string,bool> visited;
    queue<pair<string, int> > q;
    q.push({start, 1});
    visited[start] = true;
    if(start == end)
        return 1;
    
    while(!q.empty()){
        pair<string, int> parent = q.front();
        q.pop();
        string pword = parent.first;
        int len = parent.second;
        if(pword == end)
            return len;
        for(auto word: dictV){
            if(adjacent(pword, word) && !visited.count(word)){
                visited[word] = true;
                q.push({word, len + 1});
            }
        }
    }
    return 0;
}
