// #include <bits/stdc++.h>
// using namespace std;

// /*
// ===========================================================
//         LEETCODE 2770
//         Maximum Number of Jumps to Reach the Last Index
// ===========================================================


// 🔥 QUESTION DEKHTE HI DIMAG ME KYA AANA CHAHIYE?
// -----------------------------------------------------------

// 1. Ek index se aage ke kisi bhi index par ja sakte hain.

// 2. Har index par multiple choices hain:
   
//        i → i+1
//        i → i+2
//        i → i+3
//        ...

// 3. Har choice ko try karna hai.

// 4. Hume MAXIMUM number of jumps chahiye.

// 5. Same index par baar-baar calculation ho sakti hai.

//         ↓

//    OVERLAPPING SUBPROBLEMS

//         ↓

//    DP / MEMOIZATION


// 🔥 PATTERN:
// -----------------------------------------------------------

// "Current index se aage jaakar maximum answer find karo."

// Ye generally:

//         INDEX BASED DP

// Pattern ki taraf indicate karta hai.


// 🔥 STATE KYA HOGI?
// -----------------------------------------------------------

// solve(i)

// ka matlab:

//     "Index i par khade hokar
//      last index tak maximum kitne jumps
//      laga sakta hoon?"

// Isliye sirf:

//         i

// state ke liye enough hai.


// 🔥 TRANSITION:
// -----------------------------------------------------------

// i se har j ko try karo:

//         i+1, i+2, i+3, ...

// Agar jump possible hai:

//         abs(nums[i] - nums[j]) <= target

// to:

//         solve(j)

// Aur current jump ke liye:

//         1 + solve(j)

// Maximum lena hai:

//         max(result, 1 + solve(j))


// 🔥 BASE CASE:
// -----------------------------------------------------------

// Agar:

//         i == n-1

// to hum already last index par hain.

// Isliye:

//         0 jumps

// return karenge.


// 🔥 MEMOIZATION:
// -----------------------------------------------------------

// Agar solve(i) pehle calculate ho chuka hai,
// to dobara calculate mat karo.

//         t[i]

// me answer store kar do.


// ===========================================================
// */

// class Solution {

// public:

//     int n;


//     /*
//     =======================================================
//                     RECURSIVE DP
//     =======================================================

//     solve(i) ka meaning:

//     "Index i se last index tak maximum jumps
//      kitne laga sakte hain?"
//     */

//     int solve(int i, vector<int>& nums, int target,
//               vector<int>& t) {


//         /*
//         ---------------------------------------------------
//         BASE CASE

//         Agar last index par pahunch gaye:

//                     i == n-1

//         To aur jump ki zarurat nahi.

//                     answer = 0
//         ---------------------------------------------------
//         */

//         if (i == n - 1) {
//             return 0;
//         }


//         /*
//         ---------------------------------------------------
//         MEMOIZATION

//         Agar is index ka answer pehle calculate ho chuka hai,
//         to directly return kar do.

//         Isse repeated calculation bachti hai.
//         ---------------------------------------------------
//         */

//         if (t[i] != INT_MIN) {
//             return t[i];
//         }


//         /*
//         ---------------------------------------------------
//         RESULT

//         Hume MAXIMUM jumps chahiye.

//         Initially impossible maan rahe hain:

//                     INT_MIN
//         ---------------------------------------------------
//         */

//         int result = INT_MIN;


//         /*
//         ---------------------------------------------------
//         CHOICE / TRANSITION

//         Current index i se:

//             i+1
//             i+2
//             i+3
//             ...
            
//         sabko try karo.
//         ---------------------------------------------------
//         */

//         for (int j = i + 1; j < n; j++) {


//             /*
//             ------------------------------------------------
//             CHECK:

//             Kya i se j par jump kar sakte hain?

//             Condition:

//                 |nums[i] - nums[j]| <= target

//             ------------------------------------------------
//             */

//             if (abs(nums[i] - nums[j]) <= target) {


//                 /*
//                 ------------------------------------------------
//                 j par pahunch gaye.

//                 Ab j se last index tak maximum jumps
//                 calculate karo.
//                 ------------------------------------------------
//                 */

//                 int temp = solve(j, nums, target, t);


//                 /*
//                 ------------------------------------------------
//                 Agar j se last index tak jaana possible hai,
//                 tabhi current jump ko count karo.
//                 ------------------------------------------------
//                 */

//                 if (temp != INT_MIN) {

//                     /*
//                     Current jump = 1

//                     Aage ke jumps = temp

//                     Total:

//                         1 + temp
//                     */

//                     temp = 1 + temp;


//                     /*
//                     Maximum answer store karo.
//                     */

//                     result = max(result, temp);
//                 }
//             }
//         }


//         /*
//         ---------------------------------------------------
//         MEMOIZATION

//         Index i ka answer store kar do.

//         Next time solve(i) aaya to directly mil jayega.
//         ---------------------------------------------------
//         */

//         return t[i] = result;
//     }


//     /*
//     =======================================================
//                     MAIN DP FUNCTION
//     =======================================================
//     */

//     int maximumJumps(vector<int>& nums, int target) {

//         /*
//         Number of elements
//         */

//         n = nums.size();


//         /*
//         ---------------------------------------------------
//         DP ARRAY

//         t[i] = index i se last index tak
//                maximum jumps

//         INT_MIN ka matlab:

//             "Abhi calculate nahi hua"
//         ---------------------------------------------------
//         */

//         vector<int> t(n, INT_MIN);


//         /*
//         ---------------------------------------------------
//         Index 0 se journey start karo.
//         ---------------------------------------------------
//         */

//         int result = solve(0, nums, target, t);


//         /*
//         ---------------------------------------------------
//         Agar result negative hai:

//             Last index tak pahunchna possible nahi.

//         Isliye:

//             -1
//         ---------------------------------------------------
//         */

//         return result < 0 ? -1 : result;
//     }
// };


// /*
// ===========================================================
//                         MAIN
// ===========================================================

// VS Code me locally run karne ke liye.
// ===========================================================
// */

// int main() {

//     /*
//     Input:

//     n
//     */

//     int n;
//     cin >> n;


//     /*
//     nums array
//     */

//     vector<int> nums(n);

//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }


//     /*
//     target
//     */

//     int target;
//     cin >> target;


//     /*
//     Solution object
//     */

//     Solution obj;


//     /*
//     Function call
//     */

//     int answer = obj.maximumJumps(nums, target);


//     /*
//     Answer print
//     */

//     cout << answer << endl;


//     return 0;
// }


// /*
// ===========================================================
//                  EXAMPLE INPUT
// ===========================================================

// 4
// 1 3 6 4
// 2


// ===========================================================
//                  EXAMPLE OUTPUT
// ===========================================================

// 2


// ===========================================================
//             PATTERN REVISION 🔥
// ===========================================================

// Question dekha:

//     "Current index se aage kisi bhi index par ja sakte ho"

//                 ↓

//     Multiple choices

//                 ↓

//     Har choice try karo

//                 ↓

//     Maximum / Minimum answer?

//                 ↓

//     Recursion

//                 ↓

//     Same index repeatedly aa raha?

//                 ↓

//     Memoization / DP


// IMPORTANT:

//     solve(i)

//     =

//     "i se last tak maximum answer"


// Transition:

//     for every j > i

//         if condition valid:

//             1 + solve(j)


// Base:

//     i == n-1

//         return 0


// Ye ek:

//         INDEX + CHOICE + MAXIMUM
//         + MEMOIZATION

// pattern hai.

// ===========================================================
// */








#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;

    int solve(int i, vector<int>& nums, int target, vector<int>& t) {

        // Base case
        if (i == n - 1) {
            return 0;
        }

        // Already calculated
        if (t[i] != INT_MIN) {
            return t[i];
        }

        int result = INT_MIN;

        // Try every next index
        for (int j = i + 1; j < n; j++) {

            if (abs(nums[i] - nums[j]) <= target) {

                int temp = solve(j, nums, target, t);

                // Only consider valid paths
                if (temp != INT_MIN) {
                    temp = 1 + temp;
                    result = max(result, temp);
                }
            }
        }

        return t[i] = result;
    }

    int maximumJumps(vector<int>& nums, int target) {

        n = nums.size();

        vector<int> t(n, INT_MIN);

        int result = solve(0, nums, target, t);

        return result < 0 ? -1 : result;
    }
};


int main() {

    // Input
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;


    // Create object
    Solution obj;

    // Function call
    int answer = obj.maximumJumps(nums, target);

    // Output
    cout << answer << endl;

    return 0;
}