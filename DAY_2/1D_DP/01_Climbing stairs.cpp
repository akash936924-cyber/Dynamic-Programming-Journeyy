// #include <iostream>
// using namespace std;
// int climbStairs(int n)
// {
//     // Base Case
//     if (n == 0 || n == 1)
//     {
//         return 1;
//     }
//     // Recursion
//     return climbStairs(n - 1) + climbStairs(n - 2);
// }
// int main()
// {
//     int n;
//     cout << "Enter number of stairs: ";
//     cin >> n;
//     int ans = climbStairs(n);
//     cout << "Total ways = " << ans << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n, vector<int>& dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = climbStairs(n - 1, dp) + 
            climbStairs(n - 2, dp);

    return dp[n];
}

int main(){
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    int ans = climbStairs(n, dp);
    cout << "Total ways = " << ans << endl;
    return 0;}



















//  this is memonazation salution of dp 
/*
#include <bits/stdc++.h>
using namespace std;
int climbing(int n, vector<int>& dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = climbing(n - 1, dp) + climbing(n - 2, dp);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int ans = climbing(n, dp);
    cout << ans << endl;
    return 0;
}
*/







// this is tabilatin top down salution of dp 
#include <bits/stdc++.h>
using namespace std;
int climing(int n, vector<int>& dp)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    int ans = climing(n, dp);
    cout << ans << endl;
    return 0;
}