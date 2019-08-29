#define f first
#define s second
vector<int> Solution::equal(vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    unordered_map<int,pair<int,int> > m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = A[i] + A[j];
            if(m.find(sum) == m.end()){
                m[sum] = {i,j};
            }
            else{
                pair<int,int> el = m[sum];
                    if(el.f < i && el.s != i && el.s != j){
                        if(ans.empty()){
                            ans.push_back(el.f);
                            ans.push_back(el.s);
                            ans.push_back(i);
                            ans.push_back(j);
                        }
                        else{
                            //return ans;
                            int a = ans[0];
                            int b = ans[1];
                            int c = ans[2];
                            int d = ans[3];
                            if(el.f < a || (el.f == a) && el.s < b || (el.f == a) && (el.s == b) && i < c
                                || (el.f == a) && (el.s == b) && (i == c) && j < d){
                                    ans.erase(ans.begin(),ans.end());
                                    ans.push_back(el.f);
                                    ans.push_back(el.s);
                                    ans.push_back(i);
                                    ans.push_back(j);
                                }
                        }
                    }
                }
            }
    }
    return ans;
}

