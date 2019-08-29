string Solution::minWindow(string A, string B) {
    
    map<char,int> BT;
    int bsize = B.size();
    int distinct_char  = 0;
    for(int i=0;i<bsize;i++){
        distinct_char += BT[B[i]] == 0 ? 1 : 0;
        BT[B[i]]++;
    }
    int start = 0;
    int en = 0;
    int counter = 0;
    map<char,int> AT;
    int asize = A.size();
    int i;
    for(i=0;i<asize;i++){
        AT[A[i]]++;
        if(BT.find(A[i]) != BT.end() && BT[A[i]] == AT[A[i]])
            counter++;
        if(counter == distinct_char)
            break;
    }
    if(counter != distinct_char)
        return "";
    en = i;
    int first = start;
    int second = en;
    int ans = INT_MAX;
    ans = min(ans,en - start + 1);
     while(BT.find(A[start]) == BT.end() || AT[A[start]] > BT[A[start]]){
           AT[A[start]]--;
           start++;
       }
    int len = en - start + 1;
    if(len < ans){
        ans = len;
        first = start;
        second = en;
    }
    while(start <= en && en < asize){
        en++;
        AT[A[en]]++;
       while(BT.find(A[start]) == BT.end() || AT[A[start]] > BT[A[start]]){
           AT[A[start]]--;
           start++;
       }
        int len = en - start + 1;
        if(len < ans){
            first = start;
            second = en;
            ans = len;
        }
    }
    string x = "";
    for(int i=first;i<=second;i++)
        x += A[i];
    return x;
}
