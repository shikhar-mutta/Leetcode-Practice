// Link: https://leetcode.com/problems/count-digit-appearances/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum of digit counts) SC: O(1)
// Approach: convert each number to a string and count occurrences of
// the target digit character.
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        char d = '0' + digit;
        int count = 0;
        for (int x : nums) {
            for (char c : to_string(x)) if (c == d) count++;
        }
        return count;
    }
};
