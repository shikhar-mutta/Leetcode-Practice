// Link: https://leetcode.com/problems/longest-balanced-substring-after-one-swap/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: prefix sum pre[i] = (#1s - #0s) up to i. A balanced
// substring corresponds to equal prefix sums (diff 0). A single swap can
// only close a gap of 2 (moving a surplus '1' or '0' out), so also check
// substrings whose prefix-sum difference is +-2, provided a character
// of the needed type still exists OUTSIDE that substring to swap in
// (checked via total counts, trying the earliest matching prefix
// position first, falling back to the second-earliest if that one
// doesn't leave a spare character outside).
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int cnt0 = count(s.begin(), s.end(), '0');
        int cnt1 = n - cnt0;
        unordered_map<int, vector<int>> pos;
        pos[0] = {-1};
        int ans = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            pre += (s[i] == '1') ? 1 : -1;
            pos[pre].push_back(i);

            ans = max(ans, i - pos[pre][0]);

            auto it1 = pos.find(pre - 2);
            if (it1 != pos.end()) {
                auto& p = it1->second;
                if ((i - p[0] - 2) / 2 < cnt0) ans = max(ans, i - p[0]);
                else if (p.size() > 1) ans = max(ans, i - p[1]);
            }

            auto it2 = pos.find(pre + 2);
            if (it2 != pos.end()) {
                auto& p = it2->second;
                if ((i - p[0] - 2) / 2 < cnt1) ans = max(ans, i - p[0]);
                else if (p.size() > 1) ans = max(ans, i - p[1]);
            }
        }
        return ans;
    }
};
