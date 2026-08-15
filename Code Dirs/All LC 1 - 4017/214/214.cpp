// Link: https://leetcode.com/problems/shortest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: KMP failure function on (s + '#' + reverse(s)) finds the longest prefix of s that is also
// a palindrome; prepend the reverse of the remaining suffix
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;
        int n = combined.size();
        vector<int> fail(n, 0);
        for (int i = 1; i < n; i++) {
            int j = fail[i-1];
            while (j > 0 && combined[i] != combined[j]) j = fail[j-1];
            if (combined[i] == combined[j]) j++;
            fail[i] = j;
        }
        int palinLen = fail[n-1];
        return rev.substr(0, s.size() - palinLen) + s;
    }
};
