class Solution {
public:
    void f(int i, vector<int> &arr, vector<vector<int>> &res, vector<int> nums){
        res.push_back(arr);   
        for(int j=i; j<nums.size(); j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            arr.push_back(nums[j]);
            f(j+1, arr, res, nums);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        f(0, arr, res, nums);
        return res;
    }
};