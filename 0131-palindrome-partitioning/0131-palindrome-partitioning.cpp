class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void f(string s, int index, vector<string> &arr, vector<vector<string>> &res){
        if(index==s.length()){
            res.push_back(arr);
            return;
        }
        for(int i=index;i< s.length();i++){
            if(isPalindrome(s,index, i)){
                arr.push_back(s.substr(index, i-index+1));
                f(s, i+1, arr, res);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        vector<vector<string>> res;
        f(s, 0, arr, res);
        return res;
    }
};