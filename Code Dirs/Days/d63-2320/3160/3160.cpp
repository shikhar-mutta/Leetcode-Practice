// Link: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: Track each ball's current color and, per color, how many balls
// hold it. On repainting a ball that already had a color, decrement that
// color's count (removing the color entirely if it hits 0); then increment
// the new color's count (adding a new distinct color if it was previously
// 0). num_colors after each query is the answer.
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size(), num_colors = 0;
        unordered_map<int, int> color_freq, ball_color;
        color_freq.reserve(n * 2);
        ball_color.reserve(n * 2);
        vector<int> ans;
        ans.reserve(n);
        for (auto& u : queries) {
            if (ball_color.find(u[0]) != ball_color.end()) {
                if (--color_freq[ball_color[u[0]]] == 0)
                    --num_colors;
            }
            ball_color[u[0]] = u[1];
            if (++color_freq[u[1]] == 1)
                ++num_colors;
            ans.push_back(num_colors);
        }
        return ans;
    }
};
