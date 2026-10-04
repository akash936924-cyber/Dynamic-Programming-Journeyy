#include <bits/stdc++.h>
using namespace std;
int frogJump(int index, int k, vector<int>& height)
{
    if (index == 0)
    {
        return 0;
    }
    int minEnergy = INT_MAX;
    for (int jump = 1; jump <= k; jump++)
    {
        if (index - jump >= 0)
        {
            int energy = frogJump(index - jump, k, height)
                       + abs(height[index] - height[index - jump]);
            minEnergy = min(minEnergy, energy);
        }
    }
    return minEnergy;
}
int main()
{
    int n;
    int k;
    cin >> n;
    cin >> k;
    vector<int> height(n);
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    int ans = frogJump(n - 1, k, height);
    cout <<ans << endl;
    return 0;
}