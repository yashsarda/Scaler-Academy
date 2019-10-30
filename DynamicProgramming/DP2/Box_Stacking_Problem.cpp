// Every box has 3 possible configuration.
// Take all the three possible configuration. So if initially we had N boxes, so now we'll have 3*N boxes
// Next we'll the sort the boxes by area in increasing order, since the area will give the size of surface on a 2-d plane
// Then the problem boils down to finding the Longest Increasing Subsequence in a array
// Since the constraints are small, we can use the O(N^2) version 

int Solution::solve(vector<vector<int> > &A) {
    int rows = A.size();
    int col = 3;
    
    vector<vector<long long> > v(3 * rows);
    for(int i=0;i<rows;i++) {
        int height = A[i][0];
        int width = A[i][1];
        int length = A[i][2];
        
        v[3 * i + 0] = {height, max(width,length), min(width,length)};
        v[3 * i + 1] = {width, max(height, length), min(height,length)};
        v[3 * i + 2] = {length, max(height, width), min(height,width)};
        
    }
    
    sort(v.begin(),v.end(),[](const vector<long long>& a,const vector<long long>& b) {
       return (a[1] * a[2] > b[1] * b[2]); 
    });
    vector<long long> max_height(3 * rows, 0);
    long long ans = 0;
    for(int i=0;i<3 * rows;i++) {
        int width1 = v[i][1];
        int length1 = v[i][2];
        for(int j=0;j<i;j++) {
            int width2 = v[j][1];
            int length2 = v[j][2];
            if(width2 > width1 && length2 > length1) {
                max_height[i] = max(max_height[i], max_height[j]);
            }
        }
        max_height[i] += 0ll + v[i][0];
        //cout << "i = " << i << ' ' << max_height[i] << '\n';
        ans = max(max_height[i], ans);
    }
    return ans;
}
