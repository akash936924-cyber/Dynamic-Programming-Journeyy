//nums = [2, 7, 9, 3, 1]



// class Solution {
// public:
//     int solve(int i, vector<int>& nums, vector<int>& dp) {
//         if (i >= nums.size()) return 0;
//         if (dp[i] != -1) return dp[i];
//         int take = nums[i] + solve(i + 2, nums, dp);
//         int skip = solve(i + 1, nums, dp);
//         return dp[i] = max(take, skip);
//     }
//     int rob(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return solve(0, nums, dp);
//     }
// };








// this is recurtion 
// class Solution {
// public:
//     int solve(int i, vector<int>& nums) {
//         if (i >= nums.size()) return 0;
//         int take = nums[i] + solve(i + 2, nums);
//         int skip = solve(i + 1, nums);
//         return max(take, skip);
//     }

//     int rob(vector<int>& nums) {
//         return solve(0, nums);
//     }
// };