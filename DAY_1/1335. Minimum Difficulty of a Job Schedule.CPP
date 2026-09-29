/*
========================================
PARTITION DP PATTERN
========================================

Jab question mein ARRAY / STRING ko
multiple PARTS / GROUPS / DAYS mein divide
karna ho, to sabse pehle PARTITION DP socho.

----------------------------------------
1. QUESTION DEKHTE HI KYA SOCHNA HAI?
----------------------------------------

"Array ko kitne parts mein todna hai?"

        ↓

"Main current part ko kaha tak le jaun?"

        ↓

"Baaki array ko remaining parts mein
solve karwa deta hoon."

        ↓

"Har possible partition try karunga
aur minimum/maximum answer lunga."

----------------------------------------
2. MAIN CLUE
----------------------------------------

Agar question mein:

✓ Array ko K parts mein divide karna hai
✓ D days mein jobs/tasks baantne hain
✓ Har group/segment ka cost hai
✓ Total cost minimum/maximum karna hai
✓ Elements ka order change nahi kar sakte
✓ Continuous segments ban rahe hain

        ↓

PARTITION DP

----------------------------------------
3. BASIC THINKING
----------------------------------------

Maan lo:

a = [6,5,4,3,2,1]
days = 2

Mujhe decide karna hai:

Aaj kitna part loon?

[6] | [5,4,3,2,1]

ya

[6,5] | [4,3,2,1]

ya

[6,5,4] | [3,2,1]

ya ...

Har possible cut try karo.

----------------------------------------
4. RECURSION KA QUESTION
----------------------------------------

solve(i, days)

ka matlab:

"Index i se remaining array ko
days number of parts mein divide karne
ki minimum cost kya hai?"

----------------------------------------
5. STATE
----------------------------------------

dp[i][days]

i     = kaha se start kar rahe hain
days  = kitne parts/days remaining hain

----------------------------------------
6. TRANSITION
----------------------------------------

Current part ko i se j tak rakho.

        [ i ........ j ] | [ j+1 ........ ]

Current part ka cost calculate karo.

Phir:

current cost
+
remaining part ka best answer

        ↓

solve(j+1, days-1)

----------------------------------------
7. MIND ME YE LINE RAKHO
----------------------------------------

"MAIN CURRENT PART KA END POINT CHOOSE
KARUNGA, AUR BAaki PART RECURSION KO DE DUNGA."

----------------------------------------
8. BASE CASE
----------------------------------------

Agar sirf 1 part/day bacha:

days == 1

To remaining saare elements
usi ek part mein jayenge.

----------------------------------------
9. MEMOIZATION
----------------------------------------

Agar same:

solve(i, days)

dobara aa gaya,

to dobara calculate nahi karna.

dp[i][days] mein answer store karo.

----------------------------------------
10. QUICK TRIGGER
----------------------------------------

Question dekha:

"Divide / Split / Partition"

        ↓

"Kitne groups?"

        ↓

"Current group kaha tak?"

        ↓

"Baaki groups recursion"

        ↓

"Best answer = min/max"

        ↓

PARTITION DP
========================================



*/
#include <bits/stdc++.h>
using namespace std;

int dp[301][11];

int solve(vector<int>& a, int i, int days) {
    int n = a.size();

    if (days == 1) {
        int maxi = 0;

        for (int j = i; j < n; j++) {
            maxi = max(maxi, a[j]);
        }

        return maxi;
    }

    if (dp[i][days] != -1) {
        return dp[i][days];
    }

    int ans = INT_MAX;
    int maxi = 0;

    for (int j = i; j <= n - days; j++) {

        maxi = max(maxi, a[j]);

        int next = solve(a, j + 1, days - 1);

        ans = min(ans, maxi + next);
    }

    return dp[i][days] = ans;
}

int main() {

    int n, d;

    cin >> n >> d;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n < d) {
        cout << -1 << endl;
        return 0;
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(a, 0, d) << endl;

    return 0;
}