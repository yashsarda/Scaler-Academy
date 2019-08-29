inline long long power(long long base,int ex)
{
    long long ans = 1;
    while(ex){
        if(ex & 1){
            ans = ans * base;
        }
        base = base * base;
        ex >>= 1;
    }
    return ans;
}
long long convert(string A)
{
    stringstream ss(A);
    long long ans;
    
    ss >> ans;
    return ans;
}
string convert_back(long long A)
{
    string ans;
    stringstream ss;
    ss << A; 
    ans =  ss.str();
    return ans;
}
unsigned long long calculate(long long x,long long m,int i)
{
    unsigned long long ans = 1;
    if(i >= 18 && m >= 10)
        return 1000000000000000005;
    for(int k=1;k<=i;k++){
        if(ans >= 1000000000000000000)
            return 1000000000000000005;
        ans = ans + power(m,k);
    }
    return ans;
    
}
string Solution::solve(string A) {
    long long x = convert(A);
    for(int i=63;i>=0;i--){
        long long lb = 2;
        long long ub = x - 1;
        while(lb <= ub){
            unsigned long long mid = lb + ((ub - lb) >> 1);
            unsigned long long cal = calculate(x,mid,i);
            if(cal == x)
                return convert_back(mid);
            if(cal < x)
                lb = mid + 1;
            else
                ub = mid - 1;
        }
    }
}
