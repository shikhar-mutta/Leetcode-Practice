// Link: https://leetcode.com/problems/first-bad-version/description/

#include <bits/stdc++.h>
using namespace std;

// The isBadVersion API is provided by the judge/driver at submission time.
bool isBadVersion(int version);

// TC: O(log n)  SC: O(1)
// Approach: binary search for the first version where isBadVersion becomes true
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
