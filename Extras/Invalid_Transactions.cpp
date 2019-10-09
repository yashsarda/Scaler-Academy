class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> answer;
        int len = transactions.size();
        if(len == 0) return answer;
        
        // 1:remove those with > 1000
        // O(N^2) lookup for transactions wiht same name;
        
        vector<string> names, time, amount, place;
        
        for(int i=0;i<len;i++) {
            string s = transactions[i];
            
            stringstream ss(s);
            string inter;
            vector<string> tokens;
            while(getline(ss,inter,',')) {
               tokens.push_back(inter); 
            }
            names.push_back(tokens[0]);
            time.push_back(tokens[1]);
            amount.push_back(tokens[2]);
            place.push_back(tokens[3]);
            
        }
        set<string> t;
        int len2 = names.size();
        for(int i=0;i<len2;i++) {
            if(stoi(amount[i]) > 1000) {
                string ans = names[i] + "," + time[i] + "," + amount[i] + "," + place[i];
                t.insert(ans);
            }
            for(int j=i+1;j<len2;j++) {
                if(names[i] == names[j] && abs(stoi(time[i]) - stoi(time[j])) <= 60 && place[i] != place[j]) {
                    string ans = names[i] + "," + time[i] + "," + amount[i] + "," + place[i];
                    t.insert(ans);
                    ans = names[j] + "," + time[j] + "," + amount[j] + "," + place[j];
                    t.insert(ans);
                }
            }
        }
        for(auto it=t.begin();it!=t.end();it++)
            answer.push_back(*it);
        return answer;
    }
};