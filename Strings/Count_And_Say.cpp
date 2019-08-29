string cts(int x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}
string Solution::countAndSay(int A) {
    if(A == 1)
        return "1";
    if(A == 2)
        return "11";
    string prev = "11";
    for(int i=1;i<=A-2;i++){
        string temp = "";
        int j = 0;
        while(j < prev.size()){
            char current_char = prev[j];
            int count = 1;
            j++;
            while(j < prev.size() && prev[j] == current_char){
                j++;
                count++;
            }
            temp = temp + cts(count) + current_char;
        }
        prev = temp;
      //  cout << prev << '\n';
    }
    return prev;
}
