vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> ans;
    int A_i = 0;
    int B_i = 0;
    int C_i = 0;
    ans.push_back(1);
    while(ans.size() <= D){
        int min_element = INT_MIN;
        int a = ans[A_i]*A;
        int b = ans[B_i]*B;
        int c = ans[C_i]*C;
        if(a == b && b == c){
            if(ans.back() != a){
                ans.push_back(a);
            }
            A_i++;
        }
        else if(a == b && a < c || a == c && a < b){
            if(ans.back() != a){
                ans.push_back(a);
            }
            A_i++;
        }
        else if(b == c && b < a || b == a && b < c){
           if(ans.back() != b){
                ans.push_back(b);
            }
            B_i++;
        }
        else if(b == c && c < b || c == a && c < a){
            if(ans.back() != c){
                ans.push_back(c);

            }
            C_i++;
        }
        else if(a < b && a < c){
           if(ans.back() != a){
                ans.push_back(a);
            }
            A_i++;
        }
        else if(b < a && b < c){
            if(ans.back() != b){
                ans.push_back(b);
            }
            B_i++;
        }
        else if(c < a && c < b){
            if(ans.back() != c){
                ans.push_back(c);
            }
            C_i++;
        }
    }
    ans.erase(ans.begin());
    return ans;
}
