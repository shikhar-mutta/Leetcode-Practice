// Link: https://leetcode.com/problems/confusing-number-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> digits = {0, 1, 6, 8, 9};
    unordered_map<int,int> rot = {{0,0},{1,1},{6,9},{8,8},{9,6}};
    long long limit;
    int count = 0;

    void dfs(long long num) {
        if (num > limit) return;
        if (num != 0) {
            long long rotated = 0, x = num;
            int digitsCount = 0;
            while (x > 0) { rotated = rotated * 10 + rot[x % 10]; x /= 10; digitsCount++; }
            if (rotated != num) count++;
        }
        for (int d : digits) {
            long long next = num * 10 + d;
            if (next == 0) continue;
            if (next > limit) continue;
            dfs(next);
        }
    }

public:
    int confusingNumberPairs(int n) {
        limit = n;
        for (int d : digits) {
            if (d == 0) continue;
            dfs(d);
        }
        return count;
    }
};
