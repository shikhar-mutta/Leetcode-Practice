// Link: https://leetcode.com/problems/count-pairs-of-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> deg(n + 1, 0);
        map<pair<int,int>, int> shared;
        for (auto& e : edges) {
            int a = min(e[0], e[1]), b = max(e[0], e[1]);
            deg[a]++;
            deg[b]++;
            shared[{a, b}]++;
        }

        vector<int> sortedDeg(deg.begin() + 1, deg.end());
        sort(sortedDeg.begin(), sortedDeg.end());

        vector<int> ans;
        for (int q : queries) {
            // count pairs with sortedDeg[i]+sortedDeg[j] > q, i<j
            long long count = 0;
            int lo = 0, hi = n - 1;
            while (lo < hi) {
                if (sortedDeg[lo] + sortedDeg[hi] > q) {
                    count += hi - lo;
                    hi--;
                } else {
                    lo++;
                }
            }
            for (auto& [pr, cnt] : shared) {
                int a = pr.first, b = pr.second;
                bool baseTrue = deg[a] + deg[b] > q;
                bool actualTrue = deg[a] + deg[b] - cnt > q;
                if (baseTrue && !actualTrue) count--;
            }
            ans.push_back((int)count);
        }
        return ans;
    }
};
