// Link: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 0, cnt = 1;
        while (cnt * 2 <= label) { cnt *= 2; level++; }

        vector<int> path;
        int cur = label;
        while (cur >= 1) {
            path.push_back(cur);
            int lo = 1 << level, hi = (1 << (level+1)) - 1;
            int mirrored = lo + hi - cur;
            cur = mirrored / 2;
            level--;
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
