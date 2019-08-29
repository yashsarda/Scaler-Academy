// In this problem we basically had to use the array index as position to determine the first postive integer value
// Now how to do that with constant space. Swapping would not be possible because some of the number would not be at proper place
// Eg: 4 1 2 3 5. If we swap the element at respective positions, some numbers would not be at their proper places. 3 would
// one of those
// We need some strategy to determine whether the number is actually present in the array witout taking extra space.
// We do that by marking the elements presence by a negative sign. This will fail if their are negative numbers.
// So the first step is separate the positive from the negative numbers.
// Once we do that we find the range between which the positive elements are present and mark them accordingly if they are within
// the size of the array

void swap_the_negative(vector<int>& A)
{
    int n = A.size();
    int j = 0;
    for(int i=0;i<n;i++){
        if(A[i] <= 0){
            swap(A[i],A[j]);
            j++;
        }
    }
}
int Solution::firstMissingPositive(vector<int> &A) {
    swap_the_negative(A);
    int start_of_positive = -1;
    int flag = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] > 0){
            start_of_positive = i;
            flag = 1;
        }
        if(flag)
            break;
    }
    if(start_of_positive == -1)
        return 1;
    int end_of_positive = A.size() - 1;
    for(int i=0;i<start_of_positive;i++){
        if(A[i] == 0)
            A[i] = -INT_MAX;
    }
    for(int i=start_of_positive;i<=end_of_positive;i++){
        int el = abs(A[i]);
        if(el <= A.size()){
            int pos = el - 1;
            A[pos] = -A[pos];
        }
    }
    for(int i=0;i<start_of_positive;i++){
        if(A[i] < 0)
            return i+1;
    }
    for(int i=start_of_positive;i<=end_of_positive;i++){
        if(A[i] > 0)
            return i + 1;
    }
    return A.size() + 1;

}
