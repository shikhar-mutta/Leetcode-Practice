// Link: https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n)
// Approach: greedy two-pointer. For left pointer i, scan from right pointer
// j down to find a matching char; swap it adjacent-by-adjacent to position
// j (adding to move count), then shrink window. If no match found (odd
// middle char), move it toward center without cost. Repeat until pointers
// meet.
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int moves = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            int k = j;
            while (k > i && s[k] != s[i]) k--;
            if (k == i) {
                swap(s[i], s[i + 1]);
                moves++;
            } else {
                for (int t = k; t < j; t++) {
                    swap(s[t], s[t + 1]);
                    moves++;
                }
                i++;
                j--;
            }
        }
        return moves;
    }
};
