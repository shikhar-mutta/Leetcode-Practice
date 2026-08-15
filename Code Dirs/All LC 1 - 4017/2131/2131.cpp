// Link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> cnt;
        for (auto& w : words) cnt[w]++;
        long long total = 0;
        bool hasOdd = false;
        unordered_set<string> visited;
        for (auto& [w, c] : cnt) {
            if (visited.count(w)) continue;
            string rev(w.rbegin(), w.rend());
            if (w == rev) {
                total += 4 * (c / 2);
                if (c % 2 == 1) hasOdd = true;
                visited.insert(w);
            } else if (cnt.count(rev)) {
                int m = min(c, cnt[rev]);
                total += 4 * m;
                visited.insert(w);
                visited.insert(rev);
            } else {
                visited.insert(w);
            }
        }
        if (hasOdd) total += 2;
        return (int)total;
    }
};
