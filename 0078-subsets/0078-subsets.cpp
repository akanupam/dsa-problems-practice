class Solution {
public:
    void f(int i, vector<vector<int>> &res, vector<int> arr, vector<int> nums){
        if(i==nums.size()){
            res.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        f(i+1, res, arr, nums);
        arr.pop_back();
        f(i+1, res, arr, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        f(0,res,arr,nums);
        return res;
    }
};