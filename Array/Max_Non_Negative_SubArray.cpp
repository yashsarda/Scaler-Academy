vector<int> Solution::maxset(vector<int> &A) {

    int max_sum = INT_MIN;
    int max_length = 0;
    int min_index = 0;

    int temp_sum = 0;
    int temp_length = 0;
    int temp_index = 0;
    int temp = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] < 0){
            temp = 0;
            temp_sum = 0;
            temp_length = 0;
            temp_index = 0;
            continue;
        }

        if(temp == 0){
            temp_sum = A[i];
            temp_length += 1;
            temp_index = i;
        }
        else {
            temp_sum += A[i];
            temp_length += 1;
        }

        if(temp_sum > max_sum){
            max_sum = temp_sum;
            max_length = temp_length;
            min_index = temp_index;
         }
         else if(temp_sum == max_sum){
             if(temp_length > max_length)
                max_length = temp_length;
             else if(temp_length == max_length){
                 if(temp_index < min_index){
                     min_index = temp_index;
                 }
             }
         }
    }
    vector<int> ans;
    for(int i=min_index;i<min_index + max_length;i++)
        ans.push_back(A[i]);
    return ans;

}
