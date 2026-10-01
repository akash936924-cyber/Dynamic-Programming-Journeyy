#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {

    int n = prices.size();

    // dp[index][buy][cap]
    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(2, vector<int>(3, 0))
    );

    // index = n se pehle wale states already 0 hain
    for (int index = n - 1; index >= 0; index--) {

        for (int buy = 0; buy <= 1; buy++) {

            for (int cap = 1; cap <= 2; cap++) {

                // BUY state
                if (buy) {

                    dp[index][buy][cap] = max(
                        -prices[index] + dp[index + 1][0][cap],
                        dp[index + 1][1][cap]
                    );
                }

                // SELL state
                else {

                    dp[index][buy][cap] = max(
                        prices[index] + dp[index + 1][1][cap - 1],
                        dp[index + 1][0][cap]
                    );
                }
            }
        }
    }

    return dp[0][1][2];
}

int main() {

    int n;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int ans = maxProfit(prices);

    cout << "Maximum Profit: " << ans << endl;

    return 0;
}