string Solution::convertToTitle(int A) {

    string ans = "";
    map<int,char> m;
    m[0] = 'Z';
    for(int i=1;i<=25;i++)
        m[i] = 'A' + i - 1;
    int n = A;
    while(n != 0){
        int rem = n % 26;
        ans = ans + m[rem];
        n = n  / 26;
        if(rem == 0)
            n--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
