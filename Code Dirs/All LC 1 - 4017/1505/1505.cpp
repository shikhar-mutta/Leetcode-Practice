// Link: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bit;
    int n;

    void update(int i) {
        for (; i <= n; i += i & (-i)) bit[i]++;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & (-i)) s += bit[i];
        return s;
    }

    string minInteger(string num, int k) {
        n = num.size();
        bit.assign(n + 1, 0);

        vector<deque<int>> positions(10);
        for (int i = 0; i < n; i++) positions[num[i] - '0'].push_back(i);

        string res;
        for (int i = 0; i < n; i++) {
            for (int d = 0; d <= 9; d++) {
                if (positions[d].empty()) continue;
                int origIdx = positions[d].front();
                int removedBefore = query(origIdx + 1);
                int cost = origIdx - removedBefore;
                if (cost <= k) {
                    k -= cost;
                    positions[d].pop_front();
                    update(origIdx + 1);
                    res += char('0' + d);
                    break;
                }
            }
        }
        return res;
    }
};
