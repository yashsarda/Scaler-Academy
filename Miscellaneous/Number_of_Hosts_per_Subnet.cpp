int Solution::solve(string A) {
    stringstream ss(A);
    string intermediate;
    vector<string> tokens;
    while(getline(ss, intermediate, '.')) {
        tokens.push_back(intermediate);
    }
    int counter = 0;
    for(int i=0;i<4;i++) {
        int number = stoi(tokens[i]);
        for(int j=7;j>=0;j--) {
            if(!(number & (1 << j)))
                counter++;
        }
    }
    return (1 << counter) - 2;
}
