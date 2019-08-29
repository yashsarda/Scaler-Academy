const int m = 1e9+7;
int choose_3(int a)
{
    if(a < 3)
        return 0;
    int ans = (1ll * a * (a - 1) * (a-2)) / 6;
    return ans;

 }
 int choose_2(int a)
 {
     if(a < 2)
        return 0;
     int ans = (1ll * a * (a-1)) >> 1;
     return ans;
 }
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> cnt(B,0);
    for(int i=0;i<n;i++)
        cnt[A[i] % B]++;
    int ans = 0;
    for(int i=0;i<=B-1;i++){
        for(int j=i;j<=B-1;j++){
            int k = (B - (i+j) % B) % B;
          //  cout << i <<' ' << j << ' ' << k << '\n';
            if(k < j)
                continue;

            if(i == j && j == k){
                ans += choose_3(cnt[i]);
                ans%=m;
            }

            else if(i == j){
                ans += choose_2(cnt[i]) * cnt[k];
                ans %=m;
            }

            else if(i == k){
                ans += choose_2(cnt[i]) * cnt[j];
                ans %=m;
            }

            else if(j == k){
                ans += choose_2(cnt[j]) * cnt[i];
                ans %=m;
            }

            else{
                ans += 1ll * cnt[i] * cnt[j] * cnt[k];
                ans %=m;
            }
           // cout << "Ans for " << i <<' ' << j << ' ' << k  << ' ' << ans << '\n';
         }
    }
    return ans;
}
