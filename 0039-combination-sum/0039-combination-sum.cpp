class Solution {
public:
    void f(int i, int target, vector<int> arr, vector<vector<int>> &res, vector<int> &nums){
        if(target==0){
            res.push_back(arr);
            return;
        }
        if(target<0 || i==nums.size()){
            return;
        }
        arr.push_back(nums[i]);
        f(i, target - nums[i], arr, res, nums);
        arr.pop_back();
        f(i+1, target, arr, res, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        f(0, target, arr, res, candidates);
        return res;
    }
};