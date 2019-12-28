int Solution::candy(vector<int> &A) {
    int asize = A.size();
    if(asize == 1)
        return 1;
    
    int ans = 0;
    vector<int> greater(asize);
    if(A[0] > A[1])
        greater[0] = 1;
    else
        greater[0] = 0;
    
    if(A[asize - 1] > A[asize - 2])
        greater[asize - 1] = 1;
    else
        greater[asize - 1] = 0;
    
    for(int i=1;i<asize - 1;i++){
        if(A[i] > A[i - 1] && A[i] > A[i + 1])
            greater[i] = 2;
        else if(A[i] > A[i - 1] || A[i] > A[i + 1])
            greater[i] = 1;
        else
            greater[i] = 0;
     }
     vector<int> candies(asize);
     for(int i=0;i<asize;i++){
         if(greater[i] == 0)
            candies[i] = 1;
     }
     
     for(int i=1;i<asize;i++){
         if(greater[i] == 1){
             if(greater[i - 1] != 2 && A[i] > A[i - 1])
                candies[i] = candies[i - 1] + 1;
         }
     }
     for(int i=asize - 2;i >= 0;i--){
         if(greater[i] == 1){
             if(greater[i + 1] != 2 && A[i] > A[i + 1])
                candies[i] = candies[i + 1] + 1;
         }
     }
     
     for(int i=1;i<asize-1;i++){
         if(greater[i] == 2)
            candies[i] = max(candies[i-1],candies[i+1]) + 1;
     }
     for(int i=0;i<asize;i++)
        ans += candies[i];
     return ans;
}
