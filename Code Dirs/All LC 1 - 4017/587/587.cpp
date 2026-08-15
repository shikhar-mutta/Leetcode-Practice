// Link: https://leetcode.com/problems/erect-the-fence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: Andrew's monotone chain convex hull, including collinear boundary points (cross==0 kept, not popped).
class Solution {
    long long cross(vector<int>&O, vector<int>&A, vector<int>&B) {
        return (long long)(A[0]-O[0])*(B[1]-O[1]) - (long long)(A[1]-O[1])*(B[0]-O[0]);
    }
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4) return trees;
        sort(trees.begin(), trees.end());
        vector<vector<int>> hull;
        // lower hull
        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), trees[i]) < 0)
                hull.pop_back();
            hull.push_back(trees[i]);
        }
        // upper hull
        int lower_size = hull.size()+1;
        for (int i = n-2; i >= 0; i--) {
            while ((int)hull.size() >= lower_size && cross(hull[hull.size()-2], hull.back(), trees[i]) < 0)
                hull.pop_back();
            hull.push_back(trees[i]);
        }
        hull.pop_back();
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        return hull;
    }
};
