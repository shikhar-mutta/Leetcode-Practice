// Link: https://leetcode.com/problems/count-pairs-of-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> deg(n + 1, 0);
        map<pair<int,int>, int> shared;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (a > b) swap(a, b);
            deg[a]++; deg[b]++;
            shared[{a, b}]++;
        }
        vector<int> sorted_deg(deg.begin() + 1, deg.end());
        sort(sorted_deg.begin(), sorted_deg.end());

        vector<int> res;
        for (int q : queries) {
            // count pairs with deg[i]+deg[j] > q using two pointer
            long long cnt = 0;
            int l = 0, r = n - 1;
            while (l < r) {
                if (sorted_deg[l] + sorted_deg[r] > q) {
                    cnt += r - l;
                    r--;
                } else {
                    l++;
                }
            }
            // adjust for shared edges
            for (auto& [key, s] : shared) {
                int a = key.first, b = key.second;
                int base = deg[a] + deg[b];
                bool wasCounted = base > q;
                bool actual = (base - s) > q;
                if (wasCounted && !actual) cnt--;
                else if (!wasCounted && actual) cnt++;
            }
            res.push_back((int)cnt);
        }
        return res;
    }
};
