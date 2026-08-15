// Link: https://leetcode.com/problems/maximum-score-from-removing-stones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        if (v[0] + v[1] <= v[2]) return v[0] + v[1];
        return (a + b + c) / 2;
    }
};
