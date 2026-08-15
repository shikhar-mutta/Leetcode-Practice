// Link: https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long n = count(s.begin(), s.end(), c);
        return n * (n + 1) / 2;
    }
};
