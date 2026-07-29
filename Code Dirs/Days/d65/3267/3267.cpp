// Link: https://leetcode.com/problems/count-almost-equal-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2 * D), SC: O(N*D)
// Approach: pad both numbers (as digit strings) to equal length with leading zeros. Swaps
// preserve each number's own digit multiset, so the digit multisets must match first. Given
// that, count mismatched positions m: m=0 needs 0 swaps; m=2 is always a forced 2-cycle (1
// swap); m=3 is always a single 3-cycle (2 swaps, standard cycle-swap count); m=4 needs 2 swaps
// only if the 4 mismatches split into two independent 2-cycles (check all 3 ways to pair them
// up) — a genuine 4-cycle needs 3 swaps, which 2 operations (even split across both numbers)
// can't achieve. Any other m is unfixable within 2 operations.
class Solution {
public:
    bool almostEqual(const string& a, const string& b) {
        int L = a.size();
        int cntA[10] = {}, cntB[10] = {};
        for (char c : a) cntA[c-'0']++;
        for (char c : b) cntB[c-'0']++;
        for (int d = 0; d < 10; d++) if (cntA[d] != cntB[d]) return false;

        vector<int> pos;
        for (int i = 0; i < L; i++) if (a[i] != b[i]) pos.push_back(i);
        int m = pos.size();

        if (m == 0 || m == 2 || m == 3) return true;
        if (m == 4) {
            int p0 = pos[0], p1 = pos[1], p2 = pos[2], p3 = pos[3];
            auto is2cycle = [&](int i, int j) { return a[i] == b[j] && a[j] == b[i]; };
            if (is2cycle(p0,p1) && is2cycle(p2,p3)) return true;
            if (is2cycle(p0,p2) && is2cycle(p1,p3)) return true;
            if (is2cycle(p0,p3) && is2cycle(p1,p2)) return true;
            return false;
        }
        return false;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        vector<string> s(n);
        for (int i = 0; i < n; i++) s[i] = to_string(nums[i]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                string a = s[i], b = s[j];
                int L = max(a.size(), b.size());
                while ((int)a.size() < L) a = "0" + a;
                while ((int)b.size() < L) b = "0" + b;
                if (almostEqual(a, b)) ans++;
            }
        }
        return ans;
    }
};
