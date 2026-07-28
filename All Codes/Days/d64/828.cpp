// Link: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1) (26 letters)
// Approach: contribution technique. For each character c at index i,
// it counts as "unique" in exactly those substrings where no other
// occurrence of c is present, i.e. substrings starting after the
// previous occurrence of c and ending before the next occurrence. That
// count is (i - prev) * (next - i), summed over all indices.
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> lastSeen(26, -1);
        vector<int> prevOcc(n), nextOcc(n);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            prevOcc[i] = lastSeen[c];
            lastSeen[c] = i;
        }
        fill(lastSeen.begin(), lastSeen.end(), n);
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'A';
            nextOcc[i] = lastSeen[c];
            lastSeen[c] = i;
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prevOcc[i];
            long long right = nextOcc[i] - i;
            total += left * right;
        }
        return (int)total;
    }
};
