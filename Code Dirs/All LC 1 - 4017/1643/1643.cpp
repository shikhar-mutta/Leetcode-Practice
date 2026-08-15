// Link: https://leetcode.com/problems/kth-smallest-instructions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> C;

    void buildPascal(int n) {
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i-1][j-1] + (j <= i-1 ? C[i-1][j] : 0);
            }
        }
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        int h = destination[1], v = destination[0];
        buildPascal(h + v);
        string res;
        int total = h + v;
        for (int i = 0; i < total; i++) {
            if (h == 0) { res += 'V'; v--; continue; }
            if (v == 0) { res += 'H'; h--; continue; }
            long long cnt = C[h + v - 1][h - 1];
            if (k <= cnt) {
                res += 'H';
                h--;
            } else {
                res += 'V';
                v--;
                k -= cnt;
            }
        }
        return res;
    }
};
