// We'll use backtracking to solve the problem
// The maximum number of digits can be 16 (10^15)
// If we a number is of N digits, then N / 2 number will be set and the remaining N / 2 will just be mirror
// of these N / 2
// Expand from the center
unordered_map<int, int> mapping;
bool compare(string a, string b)
{
    long long c = stol(a);
    long long d = stol(b);
    return c <= d;
}
void AllPossible(string current, string low, string high, int& answer, int digits)
{
    // Base case
    if(digits == 0 && compare(low,current) && compare(current, high)) {
        answer++;
        return;
    }
    
    if(digits % 2) {
        AllPossible("0", low, high, answer, digits - 1);
        AllPossible("1", low, high, answer, digits - 1);
        AllPossible("8", low, high, answer, digits - 1);
    }
    else {
        for(auto& element: mapping) {
            if(digits == 2 && element.first != 0) {
                string temp = to_string(element.first) + current + to_string(element.second);
                AllPossible(temp, low, high, answer, digits - 2);
                temp = current;
            }
            else if(digits > 2) {
                string temp = to_string(element.first) + current + to_string(element.second);
                AllPossible(temp, low, high, answer, digits - 2);
                temp = current;
            }
        }
    }
}
int Solution::solve(string A, string B) {
    // Mirror images
    mapping[0] = 0;
    mapping[1] = 1;
    mapping[6] = 9;
    mapping[8] = 8;
    mapping[9] = 6;
    
    int cnt = 0;
    for(int digits=A.length();digits<=B.length();digits++) {
        string current = "";
        AllPossible(current, A, B, cnt, digits);
    }
    return cnt;
}
