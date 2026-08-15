// Link: https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int cnt[26] = {0};
        int satisfiedCount = 0; // number of distinct chars with count >= k
        int left = 0;
        long long ans = 0;
        for (int right = 0; right < n; right++) {
            int c = s[right] - 'a';
            cnt[c]++;
            if (cnt[c] == k) satisfiedCount++;

            while (satisfiedCount > 0) {
                int lc = s[left] - 'a';
                cnt[lc]--;
                if (cnt[lc] == k - 1) satisfiedCount--;
                left++;
            }
            ans += left;
        }
        return (int)ans;
    }
};
