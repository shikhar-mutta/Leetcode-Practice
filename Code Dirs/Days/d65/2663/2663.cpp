// Link: https://leetcode.com/problems/lexicographically-smallest-beautiful-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*k), SC: O(N)
// Approach: treat s as a base-k number restricted to no length-2/3 palindromic substrings.
// Scan from the right: try to bump s[i] to the next char (within the first k letters) that
// differs from its two predecessors; on success, greedily fill everything to its right with the
// smallest valid chars. If no position can be bumped, no answer exists.
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        char limit = 'a' + k - 1;
        int i = n - 1;

        while (i >= 0) {
            char p1 = i >= 1 ? s[i-1] : 0;
            char p2 = i >= 2 ? s[i-2] : 0;
            char c = s[i] + 1;
            while (c <= limit && (c == p1 || c == p2)) c++;
            if (c <= limit) {
                s[i] = c;
                for (int j = i+1; j < n; j++) {
                    char q1 = s[j-1], q2 = j >= 2 ? s[j-2] : 0;
                    char x = 'a';
                    while (x == q1 || x == q2) x++;
                    s[j] = x;
                }
                return s;
            }
            i--;
        }
        return "";
    }
};
