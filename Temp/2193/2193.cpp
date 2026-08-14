// Link: https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int moves = 0;
        int i = 0, j = n - 1;
        while (i < j) {
            int k = j;
            bool found = false;
            while (k > i) {
                if (s[k] == s[i]) {
                    for (int m = k; m < j; m++) {
                        swap(s[m], s[m + 1]);
                        moves++;
                    }
                    i++;
                    j--;
                    found = true;
                    break;
                }
                k--;
            }
            if (!found) {
                swap(s[i], s[i + 1]);
                moves++;
            }
        }
        return moves;
    }
};
