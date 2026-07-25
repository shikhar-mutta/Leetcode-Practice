// Link: https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: any substring starting and ending with c is fully determined by
// picking one occurrence of c as the start and another (at or after it) as
// the end, so with k total occurrences of c the count is C(k+1, 2) = k*(k+1)/2.
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
        for (char ch : s) {
            if (ch == c) {
                count++;
            }
        }
        return count * (count + 1) / 2;
    }
};
