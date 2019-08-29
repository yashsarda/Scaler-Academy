// Use the algorithm of radix sort
const int N = 100005;
vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
    
    int row = A.size();
    int col = 2;
    int max1,max2;
    max1 = max2 = INT_MIN;
    // This step finds the maximum of second and first pair of all the inputs
    for(int i=0;i<row;i++){
        max1 = max(max1,abs(A[i][0]));
        max2 = max(max2,abs(A[i][1]));
    }
    // Use counting sort on the second pair of input
    vector<int> freq(max2 + 1,0);
    for(int i=0;i<A.size();i++){
        int second = abs(A[i][1]);
        freq[second]++;
    }
    
    // Calculate the suffix sum for stable sorting since radix must a stable sort 
    vector<int> cum(max2 + 1,0);
    cum[max2] = freq[max2];
    for(int i=max2-1;i>=0;i--)
        cum[i] = cum[i + 1] + freq[i];
    vector<vector<int> > ans;
    ans.resize(row);
    for(int i=0;i<row;i++)
        ans[i].resize(2);
    
    // Insert the element at the proper position
    for(int i=0;i<row;i++){
        int el = abs(A[i][1]);
        int place = row - cum[el];
        ans[place][0] = A[i][0];
        ans[place][1] = A[i][1];
        cum[el]--;
    }
    
    // DO the same thing again for the first position
     vector<int> freq2(max1 + 1,0);
    for(int i=0;i<A.size();i++){
        int second = abs(A[i][0]);
        freq2[second]++;
    }
    
    vector<int> cum2(max1 + 1,0);
    cum2[max1] = freq2[max1];
    for(int i=max1-1;i>=0;i--)
        cum2[i] = cum2[i + 1] + freq2[i];
    
    for(int i=0;i<row;i++){
        int el = abs(A[i][0]);
        int place = row - cum2[el];
        ans[place][0] = A[i][0];
        ans[place][1] = A[i][1];
        cum2[el]--;
    }
    // First B element are the answer
    vector<vector<int> > final(B);
    for(int i=0;i<B;i++)
        final[i] = ans[i];
    return final;
    
    
}
