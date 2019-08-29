int Solution::romanToInt(string A) {
    map<string,int> m;
    m["I"] = 1;
    m["V"] = 5;
    m["X"] = 10;
    m["L"] = 50;
    m["C"] = 100;
    m["D"] = 500;
    m["M"] = 1000;
    // Add subtractive combinatons
    m["IV"] = 4;
    m["IX"] = 9;
    m["XL"] = 40;
    m["XC"] = 90;
    m["CD"] = 400;
    m["CM"] = 900;
    
    int ans = 0;
    int si = A.size();
    for(int i=0;i<si;){
        string temp;
        if((i + 1) < si){
            temp += A[i];
            temp += A[i+1];
            if(m.find(temp) != m.end()){
                ans = ans + m[temp];
                i+=2;
            }
            else{
                temp = "";
                temp += A[i];
                ans = ans + m[temp];
                i++;
            }
        }
        else{
            temp += A[i];
         //   cout << temp << '\n';
            ans = ans + m[temp];
            i++;
        }
    }
    return ans;
}
