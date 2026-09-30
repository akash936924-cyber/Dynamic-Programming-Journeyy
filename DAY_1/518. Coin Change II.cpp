//COIN CHANGE II — PATTERN

// Question mein:
// • Coins / Items
// • Target amount
// • Unlimited use
// • Number of ways

//         ↓

// UNBOUNDED KNAPSACK
//         ↓
// PICK / SKIP
//         ↓
// PICK  → index same
// SKIP  → index + 1
//         ↓
// Ways count karni hain
//         ↓
// TAKE + SKIP
//         ↓
// 2D DP: dp[index][amount]



#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(int index, int amount, vector<int>& coins) {

    // Amount successfully bana diya
    if (amount == 0)
        return 1;

    // Saare coins khatam
    if (index == coins.size())
        return 0;

    // Already calculated
    if (dp[index][amount] != -1)
        return dp[index][amount];

    // TAKE
    int take = 0;

    if (coins[index] <= amount) {
        // Same index because coin can be used unlimited times
        take = solve(index, amount - coins[index], coins);
    }

    // SKIP
    int skip = solve(index + 1, amount, coins);

    return dp[index][amount] = take + skip;
}

int main() {

    int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cin >> amount;

    dp.assign(n + 1, vector<int>(amount + 1, -1));

    cout << solve(0, amount, coins) << endl;

    return 0;
}
