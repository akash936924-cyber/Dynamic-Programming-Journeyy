/*
========================================================
1239. MAXIMUM LENGTH OF A CONCATENATED STRING
========================================================

PATTERN:
Bitmask DP + Pick / Not Pick + Recursion + Memoization


QUESTION DEKHTE HI KYA PEHCHANNA HAI?
--------------------------------------------------------

1. Array ka size chhota hai
   arr.length <= 16

   ↓

   Small N
   ↓
   Subset / Subsequence
   ↓
   Pick / Skip


2. Har element ko lene ya chhodne ka option hai

   TAKE
   SKIP

   ↓

   Recursion / Pick-Not Pick


3. Humein track karna hai ki kaunse characters
   already use ho chuke hain.

   Characters = a to z
   Total = 26

   ↓

   Bitmask use kar sakte hain.


4. Maximum answer chahiye

   ↓

   DP / Memoization


========================================================
FINAL PATTERN
========================================================

Small N
   ↓
Pick / Skip
   ↓
Used characters track karo
   ↓
Bitmask
   ↓
Memoization
   ↓
Bitmask DP


========================================================
STATE
========================================================

solve(i, mask)

i    = current string ka index

mask = kaunse characters already use ho chuke hain


Example:

arr = ["un", "iq", "ue"]

Agar "un" select kiya:

mask mein 'u' aur 'n' ke bits ON honge.


========================================================
TRANSITION
========================================================

1. SKIP current string

skip = solve(i + 1, mask)


2. TAKE current string

Pehle check karo:

Kya current string ke characters
already mask mein present hain?

Agar nahi:

newMask banao

take = arr[i].size()
       + solve(i + 1, newMask)


Finally:

return max(take, skip);


========================================================
IMPORTANT CLUE
========================================================

Question mein agar:

- N bahut small ho (usually <= 20)
- Har element ko TAKE / SKIP karna ho
- Selected elements ko track karna ho
- Unique / used / visited condition ho
- Maximum / Minimum answer chahiye

To:

        BITMASK DP
            +
        PICK / SKIP

ke baare mein zaroor socho.


========================================================
ONE LINE SHORTCUT
========================================================

Small N + Take/Skip + Used items track karne hain
                    ↓
              BITMASK DP


========================================================
IS QUESTION KA STATE
========================================================

dp[i][mask]

Meaning:

"Index i se aage, given ki mask mein
ye characters already used hain,
maximum kitni length bana sakte hain?"
========================================================

*/


// class Solution {
// public:

//     unordered_map<int, int> dp[17];

//     int solve(vector<string>& arr, int i, int mask) {

//         if(i == arr.size()) {
//             return 0;
//         }

//         if(dp[i].count(mask)) {
//             return dp[i][mask];
//         }

//         // Skip
//         int skip = solve(arr, i + 1, mask);

//         // Take
//         int take = 0;

//         int newMask = mask;
//         bool possible = true;

//         for(char c : arr[i]) {

//             int bit = 1 << (c - 'a');

//             if(newMask & bit) {
//                 possible = false;
//                 break;
//             }

//             newMask |= bit;
//         }

//         if(possible) {

//             take = arr[i].size()
//                  + solve(arr, i + 1, newMask);
//         }

//         return dp[i][mask] = max(take, skip);
//     }

//     int maxLength(vector<string>& arr) {

//         return solve(arr, 0, 0);
//     }
// };