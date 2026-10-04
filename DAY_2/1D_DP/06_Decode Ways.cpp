#include <iostream>
#include <vector>
using namespace std;

int solve(int index, string &s, vector<int> &dp) {
    if (index == s.length())
        return 1;

    if (dp[index] != -1)
        return dp[index];

    if (s[index] == '0')
        return dp[index] = 0;

    int ways = solve(index + 1, s, dp);

    if (index + 1 < s.length()) {
        int num = (s[index] - '0') * 10 +
                  (s[index + 1] - '0');

        if (num >= 10 && num <= 26) {
            ways += solve(index + 2, s, dp);
        }
    }

    return dp[index] = ways;
}
int main() {
    string s;
    cin >> s;
    vector<int> dp(s.length(), -1);
    cout << solve(0, s, dp) << endl;
    return 0;
}