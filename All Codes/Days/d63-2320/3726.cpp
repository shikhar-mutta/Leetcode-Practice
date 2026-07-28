// Link: https://leetcode.com/problems/remove-zeros-in-decimal-representation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(log n)
// Approach: convert to string, strip '0' characters, parse back.
class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        string result;
        for (char c : s) if (c != '0') result += c;
        return stoll(result);
    }
};
