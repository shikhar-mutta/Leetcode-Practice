// Link: https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int,int>, long long> cnt;
        long long ans = 0;
        for (auto& r : rectangles) {
            int g = __gcd(r[0], r[1]);
            pair<int,int> key = {r[0]/g, r[1]/g};
            ans += cnt[key]++;
        }
        return ans;
    }
};
