#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size()) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        if (buy == 1) {
            int buyStock = -prices[i] + solve(i + 1, 0, prices, dp);
            int skip = solve(i + 1, 1, prices, dp);
            dp[i][buy] = max(buyStock, skip);
        }
        else {
            int sellStock = prices[i] + solve(i + 1, 1, prices, dp);
            int hold = solve(i + 1, 0, prices, dp);
            dp[i][buy] = max(sellStock, hold);
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution obj;
    int answer = obj.maxProfit(prices);
    cout << "Maximum Profit: " << answer << endl;
    return 0;
}