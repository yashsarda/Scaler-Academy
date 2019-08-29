string Solution::intToRoman(int A) {
    if(A == 0)
        return "";
    // Map is for subtractive combination. 
    map<int,string> m;
    m[4] = "IV";
    m[9] = "IX";
    m[40] = "XL";
    m[90] = "XC";
    m[400] = "CD";
    m[900] = "CM";
    // Split the numbers into tokens of 1000,500,100,50....
    vector<int> tokens;
    int mul = 10;
    while(A != 0){
        tokens.push_back(A % mul);
        A = (A - A % mul);
        mul *= 10;
    }
    string ans = "";
    reverse(tokens.begin(),tokens.end());
    int n = tokens.size();
    // Go through the token list in reverse order
    for(int i=0;i<=n-1;i++){
        int number = tokens[i];
        if(m.find(number) != m.end())
            ans = ans + m[number];
        else{
            int how_many;
            if(number >= 1000){
                how_many = number / 1000;
                for(int i=1;i<=how_many;i++)
                    ans = ans + "M";
            }
            else if(number >= 500){
                how_many = number / 500;
                for(int i=1;i<=how_many;i++)
                    ans = ans + "D";
                number -= 500;
                for(int i=1;i<=number/100;i++)
                    ans = ans + "C";
            }
            else if(number >= 100){
                how_many = number / 100;
                for(int i=1;i<=how_many;i++)
                    ans = ans + "C";
            }
            else if(number >= 50){
                how_many = number / 50;
                for(int i=1;i<=how_many;i++)
                    ans = ans + "L";
                number -= 50;
                for(int i=1;i<=number/10;i++)
                    ans = ans + "X";
            }
            else if(number >= 10){
                how_many = number / 10;
                for(int i=1;i<=how_many;i++)
                    ans = ans + "X";
            }
            else if(number >= 5){
                how_many = number / 5;
                for(int i=1;i<=how_many;i++)
                    ans = ans + "V";
                number -= 5;
                for(int i=1;i<=number;i++)
                    ans = ans + "I";
            }
            else if(number >= 1){
                how_many = number / 1;
                for(int i=1;i<=how_many;i++)
                    ans = ans + "I";
            }
        }
    }
    
    return ans;
}
