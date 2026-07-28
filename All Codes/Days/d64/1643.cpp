// Link: https://leetcode.com/problems/kth-smallest-instructions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0], h = destination[1];
        vector<vector<long long>> C(h + v + 1, vector<long long>(h + v + 1, 0));
        for (int i = 0; i <= h + v; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = C[i-1][j-1] + (j <= i-1 ? C[i-1][j] : 0);
        }
        string res;
        int total = h + v;
        for (int i = 0; i < total; i++) {
            if (h == 0) { res += 'V'; v--; continue; }
            if (v == 0) { res += 'H'; h--; continue; }
            long long cnt = C[h - 1 + v][h - 1]; // ways if we place H here
            if (k <= cnt) { res += 'H'; h--; }
            else { res += 'V'; v--; k -= cnt; }
        }
        return res;
    }
};
