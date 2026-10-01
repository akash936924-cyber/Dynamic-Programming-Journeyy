// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {

//         int maxi = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {

//             int zeros = 0;

//             for (int j = i; j < n; j++) {

//                 if (nums[j] == 0) {
//                     zeros++;
//                 }

//                 if (zeros > k) {
//                     break;
//                 }

//                 maxi = max(maxi, j - i + 1);
//             }
//         }

//         return maxi;
//     }
// };


// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {

//         int maxi = 0;
//         int left = 0;
//         int right = 0;
//         int zeros = 0;
//         int n = nums.size();

//         while (right < n) {

//             if (nums[right] == 0) {
//                 zeros++;
//             }

//             if (zeros > k) {

//                 if (nums[left] == 0) {
//                     zeros--;
//                 }

//                 left++;
//             }

//             if (zeros <= k) {
//                 maxi = max(maxi, right - left + 1);
//             }

//             right++;
//         }

//         return maxi;
//     }
// };

// // this is optimal salution 
