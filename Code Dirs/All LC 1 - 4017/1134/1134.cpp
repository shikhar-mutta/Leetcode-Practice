// Link: https://leetcode.com/problems/armstrong-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        string s = to_string(n);
        int k = s.size();
        long long sum = 0;
        for (char c : s) {
            long long d = c - '0';
            long long p = 1;
            for (int i = 0; i < k; i++) p *= d;
            sum += p;
        }
        return sum == n;
    }
};
