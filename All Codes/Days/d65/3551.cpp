// Link: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) { s += x % 10; x /= 10; }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            int sa = digitSum(nums[a]), sb = digitSum(nums[b]);
            if (sa != sb) return sa < sb;
            return nums[a] < nums[b];
        });

        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[idx[i]] = i;

        vector<bool> visited(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            cycles++;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[j];
            }
        }
        return n - cycles;
    }
};
