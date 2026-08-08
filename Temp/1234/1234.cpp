// Link: https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char,int> cnt;
        for (char c : s) cnt[c]++;
        int k = n / 4;
        if (cnt['Q']==k && cnt['W']==k && cnt['E']==k && cnt['R']==k) return 0;
        int left = 0, best = n;
        for (int right = 0; right < n; right++) {
            cnt[s[right]]--;
            while (left < n && cnt['Q']<=k && cnt['W']<=k && cnt['E']<=k && cnt['R']<=k) {
                best = min(best, right - left + 1);
                cnt[s[left]]++;
                left++;
            }
        }
        return best;
    }
};
