// Link: https://leetcode.com/problems/next-greater-element-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(digits)  SC: O(digits)
// Approach: classic next-permutation on the digit string; find pivot,
// swap with smallest larger digit to its right, reverse the suffix
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) i--;
        if (i < 0) return -1;

        int j = s.size() - 1;
        while (s[j] <= s[i]) j--;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());

        long long result = stoll(s);
        return result > INT_MAX ? -1 : (int)result;
    }
};
