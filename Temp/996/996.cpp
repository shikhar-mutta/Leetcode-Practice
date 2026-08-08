// Link: https://leetcode.com/problems/number-of-squareful-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> used(n, false);
        int count = 0;
        vector<int> path;
        backtrack(nums, used, path, count);
        return count;
    }

private:
    bool isSquare(int a, int b) {
        double r = sqrt((double)(a + b));
        return (long long)r * r == a + b;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, int& count) {
        int n = nums.size();
        if ((int)path.size() == n) { count++; return; }
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if (!path.empty() && !isSquare(path.back(), nums[i])) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, count);
            path.pop_back();
            used[i] = false;
        }
    }
};
