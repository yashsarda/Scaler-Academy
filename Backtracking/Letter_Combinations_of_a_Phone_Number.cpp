// Leetcode problem
class Solution {
public:
    vector<string> mapping;
    void countCombination(int index, string& inter, string digits, vector<string>& answer)
    {
        if(index == digits.size()) {
            answer.push_back(inter);
            return;
        }
        for(int j=0;j<mapping[digits[index] - '0'].size();j++) {
            inter += mapping[digits[index] - '0'][j];
            countCombination(index + 1, inter, digits, answer);
            inter.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits.empty())
            return answer;
        for(char c: digits)
            if(c == '1')
                return answer;
        mapping.resize(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        string inter = "";
        countCombination(0, inter,digits, answer);
        return answer;
    }
};