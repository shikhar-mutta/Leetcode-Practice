// Link: https://leetcode.com/problems/image-overlap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> a, b;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) a.push_back({i,j});
                if (img2[i][j]) b.push_back({i,j});
            }
        unordered_map<int,int> cnt;
        int best = 0;
        for (auto& p1 : a) {
            for (auto& p2 : b) {
                int dr = p1.first - p2.first;
                int dc = p1.second - p2.second;
                int key = (dr + n) * 200 + (dc + n);
                best = max(best, ++cnt[key]);
            }
        }
        return best;
    }
};
