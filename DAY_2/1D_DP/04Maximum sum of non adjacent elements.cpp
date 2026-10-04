// int solve(int index) {

//     if(index >= n)
//         return 0;

//     int take = arr[index] + solve(index + 2);

//     int notTake = solve(index + 1);

//     return max(take, notTake);
// }
   


// input se 
//[2, 7, 9, 3, 1]
// 2+9+1=12
// 7+3=10 
// yah mujhe maximam sum return karna hai  






// dp se if(dp[index] != -1)
//     return dp[index];

// dp[index] = max(take, notTake);
// return dp[index];