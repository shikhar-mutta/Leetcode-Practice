// Link: https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if (k > n) return 0;
        unordered_map<char,int> cnt;
        int count = 0;
        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
            if (i >= k) {
                cnt[s[i-k]]--;
                if (cnt[s[i-k]] == 0) cnt.erase(s[i-k]);
            }
            if (i >= k - 1 && (int)cnt.size() == k) count++;
        }
        return count;
    }
};
