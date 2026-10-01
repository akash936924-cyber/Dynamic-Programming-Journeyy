// class Solution {
// public:

//     int n;

//     bool dfs(vector<int>& arr, int i) {

//         if (i < 0 || i >= n || arr[i] < 0) {
//             return false;
//         }

//         if (arr[i] == 0) {
//             return true;
//         }

//         int jump = arr[i];

//         arr[i] *= -1;

//         bool left = dfs(arr, i - jump);
//         bool right = dfs(arr, i + jump);

//         return left || right;
//     }

//     bool canReach(vector<int>& arr, int start) {

//         n = arr.size();

//         return dfs(arr, start);
//     }
// };