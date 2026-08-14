// Link: https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> R(n);
        int cnt0 = 0, cnt1 = 0, right = 0;
        for (int left = 0; left < n; left++) {
            if (right < left) right = left;
            if (right == left) {
                cnt0 = 0; cnt1 = 0;
            }
            while (right < n) {
                int nc0 = cnt0 + (s[right] == '0' ? 1 : 0);
                int nc1 = cnt1 + (s[right] == '1' ? 1 : 0);
                if (nc0 <= k || nc1 <= k) {
                    cnt0 = nc0; cnt1 = nc1;
                    right++;
                } else break;
            }
            R[left] = right - 1;
            // remove left char for next iteration
            if (s[left] == '0') cnt0--; else cnt1--;
        }

        vector<long long> prefixTerm(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixTerm[i+1] = prefixTerm[i] + (long long)(R[i] - i + 1);
        }

        vector<long long> res;
        res.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int lo = l, hi = r, t = l - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (R[mid] <= r) { t = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            long long part1 = prefixTerm[t+1] - prefixTerm[l];
            long long cnt2 = r - t;
            long long part2 = cnt2 * (cnt2 + 1) / 2;
            res.push_back(part1 + part2);
        }
        return res;
    }
};
