const int N = 100005;
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    map<int,int> freq;
    for(int i=0;i<n;i++)
        freq[A[i]]++;
    vector<int> ans;
    vector<int> temp;
    if(n == 1){
        ans.push_back(A[0]);
        return ans;
    }
    else if(n == 2){
        int m = max(A[0],A[1]);
        int d = min(A[0],A[1]);
        ans.push_back(m);
        ans.push_back(d);
        return ans;
    }
    else{
        int cnt;
        // if we can rearrange the array it must be in a sorted order with the exception of first two elements by the equation
        sort(A.begin(),A.end());
        int first = A[0];
        int second = A[1];
        freq[first]--;
        freq[second]--;
        temp.push_back(first);
        temp.push_back(second);
        while(true){
            // Find the third element
            int g = __gcd(first,second);
            int search = g + temp.back();
            if(freq[search] >= 1){
                freq[search]--;
                temp.push_back(search);
                first = second;
                second = search;
            }
            else{
                // If there is no third element then count how mant elements are remaining
                // If the count > 1 then we cannot rearrange the array
                // If the count is 0 the array is rearranged
                // If the count is 1 then we need to look if we can place the element with count 1 as the first element
                // and the property still holds
                cnt = 0;
                for(int i=0;i<n;i++){
                    cnt += freq[A[i]];
                }
                if(cnt > 1){
                    ans.push_back(-1);
                    return ans;
                }
                else{
                    break;
                }
            }
        }
        
        if(cnt == 0){
            // Even if the count is 0 then also we can get a lexicographically larger permutation if last element after being
            // first still holds the property
            // Just check for that. If it does not satisfy just return the original answer
            int last = temp.back();
            int g = __gcd(last,temp[0]);
            if(g + temp[0] == temp[1]){
                ans.push_back(last);
                for(int i=0;i<temp.size() - 1;i++)
                    ans.push_back(temp[i]);
                return ans;
            }
            else{
                for(int i=0;i<temp.size();i++)
                    ans.push_back(temp[i]);
                return ans;
            }
        }
        else if(cnt == 1){
            int last = -1;
            for(int i=0;i<n;i++){
                if(freq[A[i]] == 1){
                    last = A[i];
                    break;
                }
            }
            int g = __gcd(last,temp[0]);
            if(g + temp[0] == temp[1]){
                ans.push_back(last);
                for(int i=0;i<temp.size();i++)
                    ans.push_back(temp[i]);
                return ans;
            }
            else{
                ans.push_back(-1);
                return ans;
            }
        }
        
    }
}
