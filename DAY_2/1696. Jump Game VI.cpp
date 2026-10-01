// class Solution {
// public:
//     int n;

//     int solve(int i, vector<int>& nums, int k, vector<int>& dp) {
//         if (i == n - 1) {
//             return nums[i];
//         }

//         if (dp[i] != INT_MIN) {
//             return dp[i];
//         }

//         int ans = INT_MIN;

//         for (int j = i + 1; j <= i + k && j < n; j++) {
//             ans = max(ans, nums[i] + solve(j, nums, k, dp));
//         }

//         return dp[i] = ans;
//     }

//     int maxResult(vector<int>& nums, int k) {
//         n = nums.size();

//         vector<int> dp(n, INT_MIN);

//         return solve(0, nums, k, dp);
//     }
// };







///  optimzation 

// class Solution {
// public:
//     int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();

//         vector<int> dp(n);
//         deque<int> dq;

//         dp[0] = nums[0];
//         dq.push_back(0);

//         for (int i = 1; i < n; i++) {

//             while (!dq.empty() && dq.front() < i - k) {
//                 dq.pop_front();
//             }

//             dp[i] = nums[i] + dp[dq.front()];

//             while (!dq.empty() && dp[dq.back()] <= dp[i]) {
//                 dq.pop_back();
//             }

//             dq.push_back(i);
//         }

//         return dp[n - 1];
//     }
// };





// patern kya hai 
//Previous K elements ka MAX/MIN"
              //↓
     //Sliding Window
              //↓
     //Monotonic Deque