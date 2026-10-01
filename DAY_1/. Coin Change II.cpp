/*
========================================
COIN CHANGE II — DP PATTERN
========================================

Question mein:
- Coins diye hain
- Target amount diya hai
- Coin ko unlimited times use kar sakte hain
- Number of ways count karni hain

        ↓

UNBOUNDED KNAPSACK
        ↓
PICK / SKIP
        ↓
TAKE  → same index
         (coin unlimited times)

SKIP  → index + 1
        (next coin)

        ↓

WAYS COUNT KARNA HAI
        ↓

TAKE + SKIP

DP STATE:

dp[index][amount]

========================================
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(int index, int amount, vector<int>& coins) {

    // Amount complete
    if (amount == 0)
        return 1;

    // Coins khatam
    if (index == coins.size())
        return 0;

    // Already calculated
    if (dp[index][amount] != -1)
        return dp[index][amount];

    // TAKE
    int take = 0;

    if (coins[index] <= amount) {
        // Same index -> unlimited use
        take = solve(index, amount - coins[index], coins);
    }

    // SKIP
    int skip = solve(index + 1, amount, coins);

    // Total ways
    return dp[index][amount] = take + skip;
}

int main() {

    int amount;
    cin >> amount;

    int n;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp.assign(n + 1, vector<int>(amount + 1, -1));

    cout << solve(0, amount, coins) << endl;

    return 0;
}