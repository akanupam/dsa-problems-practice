class Solution {
public:
    void f(int index, int target, vector<int> arr, vector<vector<int>> &res, vector<int> &nums){
        if(target==0){
            res.push_back(arr);
            return;
        }
        if(target<0 || index==nums.size()){
            return;
        }
        for(int i=index;i < nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            if (nums[i]>target) break;
            arr.push_back(nums[i]);
            f(i+1, target -nums[i], arr, res, nums);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> arr;
        f(0, target, arr, res, candidates);
        return res;
    }
};