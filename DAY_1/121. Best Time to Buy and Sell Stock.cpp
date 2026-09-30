/*
/*
==================================================
LEETCODE 121 - BEST TIME TO BUY AND SELL STOCK
==================================================

DP PATTERN:
State Machine DP / 2-State DP

QUESTION MEIN KYA DEKHNA HAI?
--------------------------------
Agar question mein:

- BUY / SELL
- HOLD / NOT HOLD
- STOCK / TRADING
- TRANSACTION

jaise concepts aayein,

toh State Machine DP ke baare mein socho.

MAIN STATES:
--------------------------------

1. HOLD
   → Mere paas stock hai.

2. NOT HOLD
   → Mere paas stock nahi hai.

BASIC STATE TRANSITION:
--------------------------------

        BUY
NOT HOLD ───────→ HOLD
   ↑                │
   │                │ SELL
   └────────────────┘

IMPORTANT:
--------------------------------
Is question mein sirf ONE transaction allowed hai.

BUY → SELL

Aur BUY hamesha SELL se pehle hona chahiye.

EXAMPLE:
--------------------------------

prices = [7, 1, 5, 3, 6, 4]

Buy = 1
Sell = 6

Profit = 6 - 1 = 5

ANSWER = 5

PATTERN:
--------------------------------
State Machine DP
      ↓
2 States
      ↓
HOLD / NOT HOLD

NOTE:
--------------------------------
LeetCode 121 ka optimal solution
Greedy se O(n) mein bhi solve ho sakta hai.
Lekin DP pattern samajhne ke liye
ye State Machine DP ka basic example hai.
==================================================
*/

// recution se 
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices, int i, int buy) {

    // Base case
    if(i == prices.size()) {
        return 0;
    }

    int profit = 0;

    // We can BUY
    if(buy == 1) {

        // Buy today
        int buyStock =
            -prices[i] + solve(prices, i + 1, 0);

        // Don't buy today
        int skip =
            solve(prices, i + 1, 1);

        profit = max(buyStock, skip);
    }

    // We can SELL
    else {

        // Sell today
        int sellStock =
            prices[i] + solve(prices, i + 1, 1);

        // Don't sell today
        int skip =
            solve(prices, i + 1, 0);

        profit = max(sellStock, skip);
    }

    return profit;
}

int main() {

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter prices: ";

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int answer = solve(prices, 0, 1);

    cout << "Maximum Profit = " << answer << endl;

    return 0;
}






// dp memonazation se 
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices, int i, int buy,
          vector<vector<int>>& dp) {

    // Base case
    if(i == prices.size()) {
        return 0;
    }

    // Already calculated
    if(dp[i][buy] != -1) {
        return dp[i][buy];
    }

    int profit = 0;

    // BUY state
    if(buy == 1) {

        // Buy today
        int buyStock =
            -prices[i] + solve(prices, i + 1, 0, dp);

        // Don't buy
        int skip =
            solve(prices, i + 1, 1, dp);

        profit = max(buyStock, skip);
    }

    // SELL state
    else {

        // Sell today
        int sellStock =
            prices[i] + solve(prices, i + 1, 1, dp);

        // Don't sell
        int skip =
            solve(prices, i + 1, 0, dp);

        profit = max(sellStock, skip);
    }

    // Store answer
    return dp[i][buy] = profit;
}

int main() {

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter prices: ";

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // dp[i][buy]
    // i    = current day
    // buy  = 1 -> can buy
    // buy  = 0 -> can sell

    vector<vector<int>> dp(n, vector<int>(2, -1));

    int answer = solve(prices, 0, 1, dp);

    cout << "Maximum Profit = " << answer << endl;

    return 0;
}