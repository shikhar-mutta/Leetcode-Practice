// Link: https://leetcode.com/problems/minimum-time-to-activate-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: a substring is "valid" iff it contains >=1 '*'. Track the
// total number of INVALID substrings (fully star-free), which is the sum
// of len*(len+1)/2 over maximal star-free runs; valid count = total
// substrings - invalid count, which only grows as stars are added. Add
// stars one at a time (in `order`), maintaining star positions in a set
// so each insertion's run-splitting update is O(log n); check after each
// insertion whether valid count >= k.
class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        long long total = (long long)n * (n + 1) / 2;
        long long noStarSum = total; // one full run initially
        set<int> stars;

        auto runVal = [](long long len) { return len * (len + 1) / 2; };

        for (int t = 0; t < n; t++) {
            int p = order[t];
            auto it = stars.upper_bound(p);
            int rightBound = (it == stars.end()) ? n - 1 : (*it - 1);
            int leftBound = (it == stars.begin()) ? 0 : (*prev(it) + 1);

            noStarSum -= runVal(rightBound - leftBound + 1);
            if (p - 1 >= leftBound) noStarSum += runVal(p - 1 - leftBound + 1);
            if (rightBound >= p + 1) noStarSum += runVal(rightBound - (p + 1) + 1);

            stars.insert(p);

            long long validCount = total - noStarSum;
            if (validCount >= k) return t;
        }
        return -1;
    }
};
