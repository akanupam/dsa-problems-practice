class Solution {
public:
    void f(int i, vector<int> &arr, vector<vector<int>> &res, int k, int n){
        if(arr.size()==k && n==0){
            res.push_back(arr);
            return;
        }
        if(n<= 0 || arr.size()> k) return; 
        for(int j=i;j<10;j++){
            if(j>n) break;
            arr.push_back(j);
            f(j+1, arr, res, k, n-j);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        vector<vector<int>> res;
        f(1, arr, res, k, n);
        return res;
    }
};