// Given two Integer A and B. Find a number X such that A xor X is minimum possible and number of set bits in X equals to B.

int Solution::solve(int A, int B) {
    
    int X = A;
    int number_of_set = 0;
    for(int i=0;i<=31;i++) {
        if(X & (1 << i))
            number_of_set++;
    }
    if(number_of_set == B)
        return  X;
    
    if(number_of_set > B) {
        int y = number_of_set - B;
        for(int i=0;i<=31 && y > 0;i++) {
            if(X & (1 << i)) {
                X = X - (1 << i);
                y--;
            }
        }
    }
    
    if(number_of_set < B) {
        int y = B - number_of_set;
        for(int i=0;i<=31 && y > 0;i++) {
            if(!(X & (1 << i))) {
                X = X + (1 << i);
                y--;
            }
        }
    }
    return X;
}
