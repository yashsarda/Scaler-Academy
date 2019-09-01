#include<bits/stdc++.h>

using namespace std;

// If we know the LCS subsequence of the 2 strings, then we will only repeat this character once
// We want the positions of the characters in LCS in both the strings

int main()  {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        string s,t;
        cin >> s >> t;
        int slen = s.length();
        int tlen = t.length();
        
        // Fill the LCS table
        vector<vector<int> > LCS;
        LCS.resize(slen + 1);
        for(int i=0;i<slen + 1;i++)
            LCS[i].resize(tlen + 1);
        
        LCS[0][0] = 0;
        for(int i=1;i<tlen + 1;i++)
            LCS[0][i] = 0;
        
        for(int i=1;i<slen + 1;i++)
            LCS[i][0] = 0;
        
        for(int i=1;i<slen + 1;i++){
            for(int j=1;j<tlen + 1;j++){
                if(s[i - 1] == t[j - 1])
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
        
        vector<pair<int,int> > position;
        int start = slen;
        int end = tlen;
        
        while(start > 0 && end > 0){
            if(s[start - 1] == t[end - 1]){
                position.push_back({start - 1, end - 1});
                start--;
                end--;
            }
            
            else if(LCS[start - 1][end] > LCS[start][end - 1]){
                start--;
            }
            else
                end--;
        }
        
        reverse(position.begin(),position.end());
        
        string ans = "";
        pair<int,int> pehla = position[0];
        for(int i=0;i<pehla.first;i++)
            ans += s[i];
        for(int i=0;i<pehla.second;i++)
            ans += t[i];
        
        ans += s[pehla.first];
        for(int i=1;i<position.size();i++){
            for(int j=position[i - 1].first + 1;j<position[i].first;j++)
                ans += s[j];
            for(int j=position[i - 1].second + 1;j<position[i].second;j++)
                ans += t[j];
            
            ans += s[position[i].first];
        }
        
        pair<int,int> last = position.back();
        for(int i=last.first + 1;i<slen;i++)
            ans += s[i];
        for(int i=last.second + 1;i<tlen;++i)
            ans += t[i];
        cout << ans << '\n';
    }
    
    return 0;
}