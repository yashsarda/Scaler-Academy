bool checkFreq(vector<int>& freq, int number)
{
    while(number) {
        if(freq[number % 10] > 0)
            return false;
        number /= 10;
    }
    return true;
}
void update(int number, vector<int>& freq, int value)
{
    while(number) {
        freq[number % 10] += value;
        number /= 10;
    }
}
int findMaximumSum(int index, vector<int>& A, vector<int>& freq)
{
    // Base case
    if(index == A.size()) {
        return 0;
    }
    int answer = -1;
    int first = 0;
    int second = 0;
    // 2 choices
    // either take the element or do not take the element
    // We can only take the element if the digits are not already present
    if(checkFreq(freq, A[index])) {
        update(A[index], freq, 1);
        first = A[index] + findMaximumSum(index + 1, A, freq);
        update(A[index], freq, -1);
    }
    second = findMaximumSum(index + 1, A, freq);
    
    answer = max(first, second);
    
    return answer;
}
int Solution::maxSum(vector<int> &A) {
    int n = A.size();
    
    if(n == 1)
        return A[0];
    int max_sum = INT_MIN;
    vector<int> freq(10, 0);
    max_sum = findMaximumSum(0, A, freq);
    return max_sum;
}
