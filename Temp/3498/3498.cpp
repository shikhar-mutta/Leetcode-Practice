// Link: https://leetcode.com/problems/reverse-degree-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < (int)s.size(); ++i)
            sum += (26 - (s[i] - 'a')) * (i + 1);
        return sum;
    }
};
