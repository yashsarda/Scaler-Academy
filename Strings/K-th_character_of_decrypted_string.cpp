int convert_to_int(string s)
{
    int x = 0;
    stringstream ss(s);
    ss >> x;
    return x;
}
string Solution::solve(string A, int B) {
    int len = 0;
    int a = A.size();
    int counter = 0;
    int j = 0;
    for(int i=0;i<a;){
        if(A[i] >= 'a' && A[i] <= 'z'){
            counter++;
            i++;
        }
        else{
            string sub = A.substr(j,counter);
            string t = "";
            while(i < a && (A[i] >= '0' && A[i] <= '9')){
                t += A[i];
                i++;
            }
            j = i;
            int xd = convert_to_int(t);
            vector<int> x;
            int l = len + 1;
            for(int i=0;i<sub.size();i++){
                x.push_back(l % counter);
                l++;
            }
            len += xd * counter;
            if(len >= B){
                int mod = B % counter;
                string ans = "";
                int index = find(x.begin(),x.end(),mod) - x.begin();
                ans += sub[index];
                return ans;
            }
            counter = 0;
        }
    }
    
    
}
