// Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: binary search for the first letter strictly greater than target; wrap to letters[0] if none found.
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return letters[lo % letters.size()];
    }
};
