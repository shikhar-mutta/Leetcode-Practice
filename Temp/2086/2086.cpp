// Link: https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n = hamsters.size();
        string s = hamsters;
        int buckets = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'H') continue;
            if ((i > 0 && s[i - 1] == 'B') || (i + 1 < n && s[i + 1] == 'B')) continue;
            if (i + 1 < n && s[i + 1] == '.') {
                s[i + 1] = 'B';
                buckets++;
                i++;
            } else if (i > 0 && s[i - 1] == '.') {
                s[i - 1] = 'B';
                buckets++;
            } else {
                return -1;
            }
        }
        return buckets;
    }
};
