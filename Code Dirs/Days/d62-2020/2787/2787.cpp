// Link: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 1
#endif

using ll = long long;
using db = long double;
using VS = vector<string>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using PLL = pair<ll, ll>;
using MLL = map<ll, ll>;
using SLL = set<ll>;
using QLL = queue<ll>;
using SS = stringstream;

#define rep(x, l, u) for (ll x = l; x < u; x++)
#define rrep(x, l, u) for (ll x = l; x >= u; x--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x, v) memset(x, v, sizeof(x))
#define sz(x) (ll) x.size()

#define umap unordered_map
#define uset unordered_set
#define mset multiset

// clang-format off

ll ob(ll i, ll n) { return i < 0 || i >= n; }
ll tp(ll x) { return ( 1LL << x ); }
ll rup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
ll sign(ll x) {	return x == 0 ? 0 : x / abs(x); }
void makemod(ll& x, ll m) { x %= m; if (x < 0) { x += m; } }
ll getmod(ll x, ll m) { makemod(x, m); return x; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1; ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
ll invmod(ll a, ll m) { return powmod(a, m - 2, m); }
template <typename A, typename B> bool upmin(A& x, B v) { if (v >= x) return false; return x = v, true; }
template <typename A, typename B> bool upmax(A& x, B v) { if (v <= x) return false; return x = v, true; }
// clang-format on

const VLL di = {0, 0, 1, -1, 1, -1, 1, -1}, dj = {1, -1, 0, 0, -1, -1, 1, 1};
const ll inf = 1e18, mod = 1'000'000'007;
const string vowels = "aeiou";

// sol here

// TC: O(300 * 6 * 300) states, each O(1) work -> effectively O(1) given fixed
// constraints (memoized over the lifetime of the process via a global dp
// table + one-time init flag, so repeated calls across test cases reuse it)
// SC: O(305*6*305) for the memo table
// Approach: get(n, k, cur) = number of ways to write n as a sum of DISTINCT
// perfect k-th powers using bases >= cur. At each base, either use cur^k (if
// it fits) and recurse on n-cur^k with base cur+1, or skip it and recurse on
// n with base cur+1; base case n==0 counts as one valid (possibly empty) way.
ll mypow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll h = mypow(a, b / 2);
    ll ans = h * h;
    return b % 2 ? ans * a : ans;
}

ll init = 0;
ll dp[305][6][305];

ll get(ll n, ll k, ll cur) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    ll curPower = mypow(cur, k);
    if (curPower > n) {
        return 0;
    }
    ll& ans = dp[n][k][cur];
    if (ans != -1)
        return ans;

    ans = get(n - curPower, k, cur + 1);
    ans += get(n, k, cur + 1);
    ans %= mod;
    return ans;
}

class Solution {
public:
    int numberOfWays(int n, int x) {
        if (init == 0) {
            init = 1;
            mst(dp, -1);
        }
        return get(n, x, 1);
    }
};
