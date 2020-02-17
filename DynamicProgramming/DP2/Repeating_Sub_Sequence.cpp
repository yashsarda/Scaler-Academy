/*
Check every subsequence of length 2.
If the subsequence of length 2 repeats itself then answer is True

How many subsequences of length 2 = (100 C 2) = 100 * 99 / 2 = 50 * 99 = 4950 in worst case
*/
bool check_if_present(int st, int en, string A, string to_compare)
{
    int n = A.size();
    for(int start=st;start<n-1;start++) {
        if(A[start] != to_compare[0])
            continue;
        string length_2 = "";
        length_2 += A[start];
        for(int end=start+1;end<n;end++) {
            if(end == en)
                continue;
            length_2 += A[end];
            if(length_2 == to_compare) {
                return true;
            }
            length_2.pop_back();
        }
    }
    return false;
}
int Solution::anytwo(string A) {
    int n = A.size();
    
    for(int start=0;start<n-1;start++) {
        string length_2 = "";
        length_2 += A[start];
        for(int end=start+1;end<n;end++) {
            length_2 += A[end];
            if(check_if_present(start+1, end, A, length_2)) {
                return true;
            }
            length_2.pop_back();
        }
    }
    return false;
}
