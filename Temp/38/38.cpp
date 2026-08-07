// Link: https://leetcode.com/problems/count-and-say/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * len)  SC: O(len)
// Approach: iteratively build each term by run-length-encoding the previous term
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            string next;
            int j = 0;
            while (j < (int)s.size()) {
                int k = j;
                while (k < (int)s.size() && s[k] == s[j]) k++;
                next += to_string(k - j) + s[j];
                j = k;
            }
            s = next;
        }
        return s;
    }
};
