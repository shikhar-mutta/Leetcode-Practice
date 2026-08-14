// Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);
        for (char c : s) total[c - 'a']++;
        if (total[0] < k || total[1] < k || total[2] < k) return -1;

        vector<int> cnt(3, 0);
        int left = 0, best = 0;
        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;
            while (total[0] - cnt[0] < k || total[1] - cnt[1] < k || total[2] - cnt[2] < k) {
                cnt[s[left] - 'a']--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return n - best;
    }
};
