class Solution {
public:
    void place(int n, vector<string> &res, string str, int l, int r){
        if(str.length()==n*2){
            res.push_back(str);
            return;
        }
        if(l<n){
            place(n, res, str+'(',l+1, r);
        }
        if(r<l){
           place(n, res, str+')',l,r+1);
        }
    } 
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        place(n, res, "(", 1, 0);
        return res;
    }
};