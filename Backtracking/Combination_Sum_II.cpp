#define pb push_back
void calculate(vector<vector<int>> &v,vector<int> &A,int B,vector<int>& temp,int index,int sum)
{
    
    if(sum == B)
    {
        if(v.size() == 0)
        {
            v.pb(temp);
            return;
        }
        else
        {
            vector<int> teop;
            teop = v[v.size()-1];
            if(teop == temp)
            return;
            else 
            {
                v.pb(temp);
                return;
            }
        }
    }
    if(index == A.size())
    return;
    else
    {
        calculate(v,A,B,temp,index+1,sum);
        temp.pb(A[index]);
        calculate(v,A,B,temp,index+1,sum + A[index]);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end());
    vector<vector<int>> v;
    vector<int> temp;
    
    calculate(v,A,B,temp,0,0);
    
    return v;
}