string Solution::solve(string A, string B) {
    int lena = A.size();
    int lenb = B.size();
    
    vector<int> countInB(26, 0);
    
    for(char c: B) {
        countInB[c - 'a']++;
    }
    string answer = "";
    // Put the characters of B first in the answer
    for(char c: A) {
        while(countInB[c - 'a']-- > 0) {
            answer += c;
        }
    }
    // then perform the normal lexicographic order
    for(int i=0;i<26;i++) {
        while(countInB[i]-- > 0) {
            answer += 'a' + i;
        }
    }
    return answer;
    
}
