struct content
{
    // 'used' is used to determine whether this particular bucket is used
    bool used;
    // max_value and min_value are maximum and minimum values within a bucket
    int max_value;
    int min_value;
};
int Solution::maximumGap(const vector<int> &A) {
    int asize = A.size();
    if(asize <= 1)
        return 0;

    if(asize == 2){
        return max(A[0],A[1]) - min(A[0],A[1]);
    }

    int max_v = *max_element(A.begin(),A.end());
    int min_v = *min_element(A.begin(),A.end());
    int bucket_size = (max_v - min_v) / (asize - 1);
    // the bucket_size could be zero hence we equate it with maximum of 1 or bucket_size
    bucket_size = max(1, bucket_size);
    int number_of_buckets = ceil((max_v - min_v) / (bucket_size)) + 1 ;

    vector<content> buckets(number_of_buckets);
    for(int i=0;i<number_of_buckets;i++){
        buckets[i].max_value = INT_MIN;
        buckets[i].min_value = INT_MAX;
        buckets[i].used = false;
    }
    for(int i=0;i<asize;i++){
        int bucket_number = (A[i] - min_v) / bucket_size;
        buckets[bucket_number].used = true;
        buckets[bucket_number].max_value = max(buckets[bucket_number].max_value, A[i]);
        buckets[bucket_number].min_value = min(buckets[bucket_number].min_value, A[i]);
    }


    int ans = 0;
    content prev_bucket;
    int i;
    for(i=0;i<number_of_buckets;i++){
        if(buckets[i].used){
            prev_bucket = buckets[i];
            break;
        }
    }
    for(int j=i + 1;j<number_of_buckets;j++){
        if(!buckets[j].used)
            continue;

        ans = max(ans, buckets[j].min_value - prev_bucket.max_value);
        prev_bucket = buckets[j];
    }

    return ans;

}
