int gcd2(int num,int den)
{
    if(den == 0)
        return num;
    return gcd2(den,num % den);
}
int gcd(int num,int den)
{
    if(num == 0)
        return den;
    return gcd2(num,den);
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    int ans = 0;
    int n = A.size();
    for(int i=0;i<n;i++){
        int ovp = 0;
        int vp = 0;
        map<pair<int,int> ,int> smap;
        int current_max = 0;
        for(int j=i+1;j<n;j++){
            int xpoint1 = A[i];
            int ypoint1 = B[i];
            int xpoint2 = A[j];
            int ypoint2 = B[j];
            if(A[i] == A[j] && B[i] == B[j])
                ovp++;
            else if(A[i] == A[j])
                vp++;
            else{
                int xdiff = A[j] - A[i];
                int ydiff = B[j] - B[i];
                int get = gcd(abs(ydiff),abs(xdiff));
                xdiff /= get;
                ydiff /= get;
                int sign;
                if(xdiff >0 && ydiff > 0 || xdiff < 0 && ydiff < 0)
                    sign = 1;
                else
                    sign = -1;
                pair<int,int> p2 = {sign * abs(ydiff),abs(xdiff)};
                smap[p2] += 1;
                current_max = max(current_max,smap[p2]);
            }
            int max1 = max(current_max + ovp + 1,vp + 1 + ovp);
            ans = max(ans,max1);
        }
    }
    return ans;
}
