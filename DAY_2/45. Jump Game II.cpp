#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;

    int solve(int i, vector<int>& nums, vector<int>& dp) {

        if (i == n - 1) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int ans = INT_MAX;

        for (int j = i + 1; j <= i + nums[i] && j < n; j++) {

            int temp = solve(j, nums, dp);

            if (temp != INT_MAX) {
                ans = min(ans, 1 + temp);
            }
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {

        n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    int answer = obj.jump(nums);

    cout << answer << endl;

    return 0;
}