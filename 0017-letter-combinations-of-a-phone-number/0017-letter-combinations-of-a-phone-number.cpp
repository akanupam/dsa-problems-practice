class Solution {
public:
    void f(int index, string str, vector<string> &res, string seq[], string digits){
        if(index == digits.size()){
            res.push_back(str);
            return;
        }
        int digit = digits[index] - '0';
        for(int i=0;i<seq[digit].size();i++){
            f(index+1, str+seq[digit][i], res, seq,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        string seq[] = {"", "" , "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        string str = "";
        f(0, str, res, seq, digits);
        return res;
    }
};