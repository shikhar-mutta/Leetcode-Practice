// Link: https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> zFunction(const string& s) {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] > r) { l = i; r = i + z[i]; }
        }
        return z;
    }

    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        vector<int> maxExtend(n, 0);

        for (auto& w : words) {
            string s = w + '\x01' + target;
            vector<int> z = zFunction(s);
            int wlen = w.size();
            for (int j = 0; j < n; j++) {
                int val = z[wlen + 1 + j];
                if (val > maxExtend[j]) maxExtend[j] = val;
            }
        }

        int jumps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < n; i++) {
            if (i > curEnd) return -1;
            farthest = max(farthest, i + maxExtend[i]);
            if (i == curEnd) {
                if (farthest == curEnd) return -1;
                jumps++;
                curEnd = farthest;
                if (curEnd >= n) return jumps;
            }
        }
        return curEnd >= n ? jumps : -1;
    }
};
