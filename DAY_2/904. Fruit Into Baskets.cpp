// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {

//         int maxLength = 0;
//         int n = fruits.size();

//         for (int i = 0; i < n; i++) {

//             set<int> mySet;

//             for (int j = i; j < n; j++) {

//                 mySet.insert(fruits[j]);

//                 if (mySet.size() > 2) {
//                     break;
//                 }

//                 maxLength = max(maxLength, j - i + 1);
//             }
//         }

//         return maxLength;
//     }
// };








//   this is better salution 
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {

//         int maxLength = 0;
//         int left = 0;
//         int right = 0;

//         unordered_map<int, int> myDict;

//         while (right < fruits.size()) {

//             myDict[fruits[right]]++;

//             while (myDict.size() > 2) {

//                 myDict[fruits[left]]--;

//                 if (myDict[fruits[left]] == 0) {
//                     myDict.erase(fruits[left]);
//                 }

//                 left++;
//             }

//             if (myDict.size() <= 2) {
//                 maxLength = max(maxLength, right - left + 1);
//             }

//             right++;
//         }

//         return maxLength;
//     }
// };





// this is optimal salution 
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {

//         unordered_map<int, int> mp;

//         int left = 0;
//         int right = 0;
//         int ans = 0;

//         while (right < fruits.size()) {

//             mp[fruits[right]]++;

//             while (mp.size() > 2) {

//                 mp[fruits[left]]--;

//                 if (mp[fruits[left]] == 0) {
//                     mp.erase(fruits[left]);
//                 }

//                 left++;
//             }

//             ans = max(ans, right - left + 1);

//             right++;
//         }

//         return ans;
//     }
// };