// Link: https://leetcode.com/problems/maximize-the-minimum-game-score/description/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
bool possible3449(ll t, const vector<int>& pts, int M) {
    ll mv = 0, ext = 0, bon = 0;
    for (int p : pts) {
        ll req = (t + p - 1LL) / p;
        if (ext >= req) {
            ext = 0;
            bon++;
        } else {
            ll d = req - ext;
            mv += 2 * d - 1 + bon;
            ext = d - 1;
            bon = 0;
        }
        if (mv > M) return false;
    }
    return true;
}

class Solution {
public:
    long long maxScore(vector<int>& points, int m) {
        if (m < (int)points.size()) return 0;
        ll lo = 1, hi = 1e18, ans = 0;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (possible3449(mid, points, m)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
