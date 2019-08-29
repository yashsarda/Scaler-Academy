int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

    int i=0,j=0,k=0;
    int a1 = A.size();
    int b1 = B.size();
    int c1 = C.size();
    int ans = INT_MAX;
    while(i < a1 && j < b1 && k < c1){
        int a = A[i];
        int b = B[j];
        int c = C[k];

        if(a == b && b == c){
            return 0;
        }
        else if(a == b && a < c || a == c && a < b){
            int t = max(a,max(b,c));
            int t2 = a;
            ans = min(ans,abs(t-t2));
            i++;
        }
        else if(b == c && b < a || b == a && b < c){
           int t = max(a,max(b,c));
            int t2 = b;
            ans = min(ans,abs(t-t2));
            j++;
        }
        else if(b == c && c < b || c == a && c < a){
            int t = max(a,max(b,c));
            int t2 = c;
            ans = min(ans,abs(t-t2));
            k++;
        }
        else if(a < b && a < c){
           int t = max(b,c);
            int t2 = a;
            ans = min(ans,abs(t-t2));
            i++;
        }
        else if(b < a && b < c){
            int t = max(a,c);
            int t2 = b;
            ans = min(ans,abs(t-t2));
            j++;
        }
        else if(c < a && c < b){
            int t = max(a,b);
            int t2 = c;
            ans = min(ans,abs(t-t2));
            k++;
        }
    }
    return ans;
}
