// Link: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> bit;
    int n;
    void update(int i, int v) { for (; i <= n; i += i & (-i)) bit[i] += v; }
    int query(int i) { int s = 0; for (; i > 0; i -= i & (-i)) s += bit[i]; return s; }
public:
    string minInteger(string num, int k) {
        n = num.size();
        vector<deque<int>> pos(10);
        for (int i = 0; i < n; i++) pos[num[i] - '0'].push_back(i + 1); // 1-indexed
        bit.assign(n + 1, 0);
        vector<int> used(n + 1, 0);
        string res;
        long long remaining = k;
        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int d = 0; d <= 9 && !placed; d++) {
                if (pos[d].empty()) continue;
                int p = pos[d].front();
                // number of unused elements before p = p - 1 - already removed before p
                int already = query(p);
                int distance = p - 1 - already;
                if (distance <= remaining) {
                    remaining -= distance;
                    pos[d].pop_front();
                    update(p, 1);
                    res += char('0' + d);
                    placed = true;
                }
            }
        }
        return res;
    }
};
