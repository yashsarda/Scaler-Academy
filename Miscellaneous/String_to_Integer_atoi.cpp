class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        if(len == 0)
            return 0;
        int i = 0;
        while(i < len && str[i] == ' ')
            i++;
        if(i == len)
            return 0;
        if(str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
            return 0;
        char sign;
        if(str[i] == '+' || str[i] == '-') {
            sign = str[i];
            i++;
        }
        string num = "";
        while(i < len && (str[i] >= '0' && str[i] <= '9')) {
            num += str[i];
            i++;
        }
        if(num == "")
            return 0;
        int final_ans = 0;
        for(int i=0;i<num.size();i++) {
            int digit = num[i] - '0';
            if(final_ans > INT_MAX / 10 || final_ans == INT_MAX / 10 && digit > 7) {
                return (sign == '-' ? INT_MIN : INT_MAX);
            }
            final_ans = final_ans * 10 + digit;
        }
        if(sign == '-')
            final_ans = -final_ans;
        return final_ans;
        
    }
};