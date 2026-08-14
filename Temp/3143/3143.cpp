// Link: https://leetcode.com/problems/maximum-points-inside-the-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        auto dist = [&](int i) { return max(abs(points[i][0]), abs(points[i][1])); };
        sort(idx.begin(), idx.end(), [&](int a, int b) { return dist(a) < dist(b); });

        unordered_set<char> seen;
        int count = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && dist(idx[j]) == dist(idx[i])) j++;
            unordered_set<char> group;
            bool ok = true;
            for (int k = i; k < j; k++) {
                char c = s[idx[k]];
                if (group.count(c) || seen.count(c)) { ok = false; break; }
                group.insert(c);
            }
            if (!ok) break;
            for (char c : group) seen.insert(c);
            count += (j - i);
            i = j;
        }
        return count;
    }
};
