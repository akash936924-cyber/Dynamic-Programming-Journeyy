#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // dp[index][buy][transaction]
    int dp[100005][2][3];

    int solve(int index, int buy, int transaction,
              vector<int>& prices) {

        // Saare days khatam
        if (index == prices.size())
            return 0;

        // 2 transactions complete
        if (transaction == 2)
            return 0;

        if (dp[index][buy][transaction] != -1)
            return dp[index][buy][transaction];

        int ans = 0;

        if (buy == 1) {

            // BUY
            int take = -prices[index] +
                       solve(index + 1, 0, transaction, prices);

            // SKIP
            int skip =
                solve(index + 1, 1, transaction, prices);

            ans = max(take, skip);
        }

        else {

            // SELL
            int sell = prices[index] +
                       solve(index + 1, 1, transaction + 1, prices);

            // SKIP
            int skip =
                solve(index + 1, 0, transaction, prices);

            ans = max(sell, skip);
        }

        return dp[index][buy][transaction] = ans;
    }

    int maxProfit(vector<int>& prices) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 1, 0, prices);
    }
};