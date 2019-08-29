vector<int> Solution::solve(int A) {
    vector<int> v(A);
    if(A == 1){
        v[0] = 1;
        return v;
    }
    else if(A == 2){
        v[0] = 1;
        v[1] = 2;
        return v;
    }
    else{
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        int index = 1;
        while(index <= A){
            int number = q.front();
            q.pop();
            v[index - 1] = number;
            q.push(number * 10 + 1);
            q.push(number * 10 + 2);
            q.push(number * 10 + 3);
            index++;
        }
        return v;
    }
}
