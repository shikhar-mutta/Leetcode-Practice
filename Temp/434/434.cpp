// Link: https://leetcode.com/problems/number-of-segments-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: count positions where a non-space char follows a space or start
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i-1] == ' ')) count++;
        }
        return count;
    }
};
