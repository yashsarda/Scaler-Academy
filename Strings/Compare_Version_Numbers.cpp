int cmp(string x,string y)
{
    // If size of x > y then x is going to be a bigger version
    if(x.size() > y.size())
        return 1;
    if(y.size() > x.size())
        return 2;
    // If both of them are of equal size then compare lexicographically
    if(x > y)
        return 3;
    if(y > x)
        return 4;
    // If after comparing it still it remains equal
    return 5;
}
int Solution::compareVersion(string A, string B) {
    vector<string> token1,token2;
    int a = A.size();
    int b = B.size();
    stringstream ss,ss2;
    ss << A;
    string inter;
    // Split the string into tokens separated by .
    while(getline(ss,inter,'.'))
        token1.push_back(inter);
    ss2 << B;
    while(getline(ss2,inter,'.'))
        token2.push_back(inter);
    
    a = token1.size();
    b = token2.size();
    
    // Remove leading zeros from any string present in token array
    for(int i=0;i<a;i++){
        string x = token1[i];
        if(x == "0")
            continue;
        reverse(x.begin(),x.end());
        while(x.back() == '0')
            x.pop_back();
        reverse(x.begin(),x.end());
        token1[i] = x;
    }
    for(int i=0;i<b;i++){
        string x = token2[i];
        if(x == "0")
            continue;
        reverse(x.begin(),x.end());
        while(x.back() == '0')
            x.pop_back();
        reverse(x.begin(),x.end());
        token2[i] = x;
    }
    
    // Make both of the arrays of the similar size
    if(a > b){
        int add_extra_zeros = a - b;
        for(int i=1;i<=add_extra_zeros;i++)
            token2.push_back("0");
    }
    else if(b > a){
        int add_extra_zeros = b - a;
        for(int i=1;i<=add_extra_zeros;i++)
            token1.push_back("0");
    }
    a = token1.size();
    b = token2.size();
    
    // Then check for every two strings
    for(int i=0;i<a;i++){
        string x = token1[i];
        string y = token2[i];
        int val = cmp(x,y);
        if(val == 1 || val == 3)
            return 1;
        if(val == 2 || val == 4)
            return -1;
    }
    return 0;
}
