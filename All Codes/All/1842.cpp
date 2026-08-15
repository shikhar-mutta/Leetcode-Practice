// Link: https://leetcode.com/problems/next-palindrome-using-same-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nextPalindrome(string num) {
        int n = num.size();
        int half = n / 2;
        string first = num.substr(0, half);
        if (!next_permutation(first.begin(), first.end())) return "";
        string res = first;
        if (n % 2 == 1) res += num[half];
        string second = first;
        reverse(second.begin(), second.end());
        res += second;
        return res;
    }
};
