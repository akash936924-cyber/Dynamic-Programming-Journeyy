//  recution se 
#include <bits/stdc++.h>
using namespace std;
int frogJump(int index, vector<int>& height){
    if (index == 0){
    return 0;}
    int jump1 = frogJump(index - 1, height)
               + abs(height[index] - height[index - 1]);
    int jump2 = INT_MAX;
    if (index > 1)
    {
        jump2 = frogJump(index - 2, height)
               + abs(height[index] - height[index - 2]);
    }
    return min(jump1, jump2);
}
int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    int ans = frogJump(n - 1, height);
    cout << ans << endl;
    return 0;
}

















#include <bits/stdc++.h>
using namespace std;
int frogJump(vector<int>& height)
{
    int n = height.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int jump1 = dp[i - 1]
                  + abs(height[i] - height[i - 1]);
        int jump2 = INT_MAX;

        if (i > 1)
        {
            jump2 = dp[i - 2]
                  + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(jump1, jump2);
    }
    return dp[n - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    int ans = frogJump(height);
    cout<< ans << endl;
    return 0;
}