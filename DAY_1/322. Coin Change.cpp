// class Solution {
// public:
//     vector<vector<int>> dp;

//     int solve(int index, int amount, vector<int>& coins) {

//         if (amount == 0)
//             return 0;

//         if (index == coins.size())
//             return 1e9;

//         if (dp[index][amount] != -1)
//             return dp[index][amount];

//         int take = 1e9;
//         if (coins[index] <= amount)
//             take = 1 + solve(index, amount - coins[index], coins);

//         int skip = solve(index + 1, amount, coins);

//         return dp[index][amount] = min(take, skip);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();

//         dp.assign(n + 1, vector<int>(amount + 1, -1));

//         int ans = solve(0, amount, coins);

//         return (ans >= 1e9) ? -1 : ans;
//     }
// };

/*
322. Coin Change

Pattern:
UNBOUNDED KNAPSACK / COIN CHANGE DP

State:
solve(index, amount)

Take:
1 + solve(index, amount - coins[index])

Skip:
solve(index + 1, amount)

Answer:
min(take, skip)

*/