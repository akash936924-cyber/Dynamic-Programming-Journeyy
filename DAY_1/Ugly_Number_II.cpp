// 264. Ugly Number II

// Pattern:
// 1D DP + Multiple Pointers

// State:
// dp[i] = (i+1)th Ugly Number

// Idea:
// next = min(dp[p2]*2,
//            dp[p3]*3,
//            dp[p5]*5)

// Pointers:
// p2 → ×2
// p3 → ×3
// p5 → ×5


#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {

    vector<int> dp(n);

    // 1 is the first Ugly Number
    dp[0] = 1;

    // Three pointers
    int p2 = 0;
    int p3 = 0;
    int p5 = 0;

    for(int i = 1; i < n; i++) {

        // Three possible next Ugly Numbers
        int a = dp[p2] * 2;
        int b = dp[p3] * 3;
        int c = dp[p5] * 5;

        // Choose the smallest
        dp[i] = min({a, b, c});

        // Move the pointer(s) that produced dp[i]
        if(dp[i] == a) {
            p2++;
        }

        if(dp[i] == b) {
            p3++;
        }

        if(dp[i] == c) {
            p5++;
        }
    }

    return dp[n - 1];
}

int main() {

    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "The " << n << "th Ugly Number is: "
         << nthUglyNumber(n) << endl;

    return 0;
}