// lots of cases
class Solution {
public:
    int reverseIt(int x, bool isNegative, int countDigits)
    {
        int ans = 0;
        int p10 = pow(10, (countDigits - 1));
        while(x) {
            int rem = x % 10;
            ans += rem * p10;
            p10 /= 10;
            x = x / 10;
        }
        if(isNegative)
            ans = -ans;
        return ans;
    }
    int reverse(int x) {
        /* Crude way of solving the problem 
        // If it's minimum value of integer
        if(x == INT_MIN)
            return 0;
        // single digit numbers
        if(x >= 0 && x <= 9 || x >= -9 && x <= -1)
            return x;
        bool isNegative = false;
        if(x < 0)
            isNegative = true;
        int countDigits = 0;
        int temp = abs(x);
        while(temp) {
            countDigits += 1;
            temp = temp / 10;
        }
        x = abs(x);
        // If the number of digits are less than 10 then return the reverse directly
        if(countDigits <= 9)
            return reverseIt(x, isNegative, countDigits);
        vector<int> arr = {2,1,4,7,4,8,3,6,4,7};
        if(isNegative)
            arr[9] = {8};
        vector<int> reverseDig;
        while(x) {
            reverseDig.push_back(x % 10);
            x /= 10;
        }
        for(int i=0;i<10;i++) {
            if(reverseDig[i] < arr[i])
                break;
            if(reverseDig[i] > arr[i])
                return 0;
        }
        int p10 = 1;
        int answer = 0;
        for(int i=9;i>=0;i--){
            answer += reverseDig[i] * p10;
            if(i != 0)
            p10 *= 10;
        }
        if(isNegative)
            answer = -answer;
        return answer;
        */
        /* editorials way */
        int temp = 0;
        while(x) {
            int rem = x % 10;               // In C++, whatever is sign of number 
                                            // that will be sign for modulo operation
            x /= 10;
            
            if(temp > INT_MAX / 10 || (temp == INT_MAX / 10 && rem > 7))
                return 0;
            if(temp < INT_MIN / 10 || (temp == INT_MIN / 10 && rem < -8))
                return 0;
            temp = temp * 10 + rem;
        }
        return temp;
    }
};