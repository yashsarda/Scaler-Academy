// Backtracking problem
// Find all the poosible position for '.'
int len = 0;
string substring(int start, int end, string A)
{
    string ans = "";
    for(int i=start;i<=end;i++)
        ans += A[i];
    return ans;
}
bool check(string rem)
{
    if(rem.length() == 0)
        return false;
    // If the number is of form "0ddd.." d = {0,...,9}
    // return false since 0 is always alone
    if(rem[0] == '0' && rem.length() > 1)
        return false;
    // convert to number and check whether it lies in the range
    int number = stoi(rem);
    return (number >= 0 && number <= 255);
    
}
void findAllAddress(int index, int number_of_dots, string A, string temp, vector<string>& ans)
{
    // Base conditions
    // If all the 3 dots have been placed, then find the remaning part of the string
    // Check whether it follows the correct notations and push it if it follows
    if(number_of_dots == 0) {
        string rem = substring(index, len - 1 ,A);
        if(check(rem)) {
            temp += rem;
            ans.push_back(temp);
        }
        return;
    }
    
    // Hypothesis
    // You can make a number with atmost 3 digits
    for(int i=index;i<=min(index + 2,len - 1);i++) {
        string rem = substring(index, i, A);
        string prevTemp = temp;
        if(check(rem)) {
            temp += rem + ".";
            findAllAddress(i + 1, number_of_dots - 1, A, temp, ans);
            // Important reset the value of temp to the previous value
            temp = prevTemp;
        }
    }
}
vector<string> Solution::restoreIpAddresses(string A) {
    len = A.length();
    vector<string> ans;
    string temp = "";
    if(A == "")
        return ans;
    
    findAllAddress(0, 3, A, temp, ans);
    return ans;
}
