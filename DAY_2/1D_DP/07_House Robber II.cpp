// class Solution {
// public:

//     int solve(int index, vector<int>& nums) {
//         if (index == 0) {
//             return nums[index];
//         }

//         if (index == -1) {
//             return 0;
//         }
//         int pick = nums[index] + solve(index - 2, nums);
//         int notPick = 0 + solve(index - 1, nums);
//         return max(pick, notPick);
//     }
//     int rob(vector<int>& nums) {
//         if (nums.size() == 1) {
//             return nums[0];
//         }
//         int n = nums.size();
//         vector<int> v1(nums.begin(), nums.end() - 1);
//         vector<int> v2(nums.begin() + 1, nums.end());
//         int ans1 = solve(n - 2, v1);
//         int ans2 = solve(n - 2, v2);
//         return max(ans1, ans2);
//     }
// }:
