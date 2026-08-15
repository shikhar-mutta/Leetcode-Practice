// Link: https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        vector<bool> used(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            for (int j = i + 1; j < n; j++) {
                if (!used[j] && words[j] == rev) {
                    used[i] = used[j] = true;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
