// Shortest path is taken out with BFS
// How do we find the elements of the shortest path
// It's not necessary that there will be only 1 shortest. There can be many path having the same length
// but differing in the transformations.
// To find all paths Will we need recursion??

// Here's one idea
// Find shortest path using BFS. Let the length = l
// Use backtracking to find all the paths 


bool adjacent(string s1, string s2)
{
    int count = 0;
    for(int i=0;i<s1.length();i++){
        count += s1[i] != s2[i];
    }
    
    return count == 1 ? true : false; 
}
void findallsol(vector<vector<string> >& ans, vector<string>& temp, int min_len, string start, string end, 
                vector<string>& dict, unordered_map<string, bool>& visited, int len)
{
    // Base case
    if(len == min_len && start == end){
        ans.push_back(temp);
        return;
    }
    if (len >= min_len || start == end)
        return;
    
    
    // hypothesis
    for(string word: dict) {
        if(adjacent(start, word) && !visited[word]) {
            visited[word] = true;
            temp.push_back(word);
            findallsol(ans, temp, min_len, word, end, dict, visited, len + 1);
            temp.pop_back();
            visited[word] = false;
        }
    }
}                
vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unordered_map<string,bool> visited;
    queue<pair<string, int> > q;
    q.push({start, 1});
    visited[start] = true;
    int min_len = INT_MAX;
    while(!q.empty()){
        pair<string, int> parent = q.front();
        q.pop();
        string pword = parent.first;
        int len = parent.second;
        if(pword == end){
            min_len = len;
            break;
        }
        for(auto word: dict){
            if(adjacent(pword, word) && !visited.count(word)){
                visited[word] = true;
                q.push({word, len + 1});
            }
        }
    }
   for(auto word: dict)
        visited[word] = false;
    while(!q.empty()) q.pop();
    vector<vector<string> > ans;
     if(start == end){
        vector<string> t;
        t.push_back(start);
        ans.push_back(t);
        return ans;
    }
    if(min_len == INT_MAX)  return ans;
    vector<string> temp;
    visited[start] = true;
    temp.push_back(start);
    // Words should be unique else code does not work
    set<string> s(dict.begin(),dict.end());
    dict.clear();
    for(auto it=s.begin();it!=s.end();it++)
        dict.push_back(*it);
    for(auto word: dict) {
        if(adjacent(start, word) && !visited[word]){
            temp.push_back(word);
            visited[word] = true;
            findallsol(ans, temp,min_len, word, end, dict, visited,2);
            visited[word] = false;
            temp.pop_back();
        }
    }
    return ans;
}
