// Link: https://leetcode.com/problems/hash-divided-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n/k)
// Approach: Split s into chunks of size k, sum each chunk's letter values
// (0-25) mod 26, and map that back to a letter for the output character.
class Solution {
public:
    string stringHash(string s, int k) {
        string ans;

        for (int i = 0; i < s.size(); i += k) {
            int sum = 0;
            for (int j = i; j < i + k; j++)
                sum += s[j] - 'a';
            ans += char('a' + (sum % 26));
        }

        return ans;
    }
};
