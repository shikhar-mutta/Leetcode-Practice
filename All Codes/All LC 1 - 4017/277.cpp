// Link: https://leetcode.com/problems/find-the-celebrity/description/

#include <bits/stdc++.h>
using namespace std;

// The knows API is provided by the judge/driver at submission time.
bool knows(int a, int b);

// TC: O(n)  SC: O(1)
// Approach: single pass to find a candidate — if candidate knows i, candidate can't be the celebrity
// (celebrity knows nobody), so switch to i; the survivor is the only possible celebrity, verify it
class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) candidate = i;
        }
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (knows(candidate, i) || !knows(i, candidate)) return -1;
        }
        return candidate;
    }
};
