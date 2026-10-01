// class Solution {
// public:

//     bool solve(int i, string& s, int minJump, int maxJump) {

//         if (i == s.length() - 1) {
//             return true;
//         }

//         for (int j = i + minJump; j <= i + maxJump && j < s.length(); j++) {

//             if (s[j] == '0') {

//                 if (solve(j, s, minJump, maxJump)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }

//     bool canReach(string s, int minJump, int maxJump) {

//         return solve(0, s, minJump, maxJump);
//     }
// };