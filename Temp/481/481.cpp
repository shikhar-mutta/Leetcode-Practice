// Link: https://leetcode.com/problems/magical-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: build the string using itself as its own run-length encoding;
// s[i] tells the length of the next run, alternating between 1s and 2s
class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1;
        vector<int> s{1, 2, 2};
        int i = 2;
        while ((int)s.size() < n) {
            int next = s.back() == 1 ? 2 : 1;
            for (int k = 0; k < s[i]; k++) {
                s.push_back(next);
                if ((int)s.size() >= n + 2) break;
            }
            i++;
        }
        int count = 0;
        for (int k = 0; k < n; k++) if (s[k] == 1) count++;
        return count;
    }
};
