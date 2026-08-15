// Link: https://leetcode.com/problems/palindrome-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k^2)  SC: O(n * k)
// Approach: hashmap word->index; for each word, for every split point check
// if left+right parts, when one is a palindrome, the other's reverse exists
// in the map (handles empty-string and unequal-length cases)
class Solution {
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> idx;
        for (int i = 0; i < (int)words.size(); i++) idx[words[i]] = i;

        vector<vector<int>> res;
        for (int i = 0; i < (int)words.size(); i++) {
            string& w = words[i];
            int n = w.size();
            for (int j = 0; j <= n; j++) {
                // left = w[0..j), right = w[j..n)
                if (isPalindrome(w, 0, j - 1)) {
                    string revRight = w.substr(j);
                    reverse(revRight.begin(), revRight.end());
                    auto it = idx.find(revRight);
                    if (it != idx.end() && it->second != i) res.push_back({it->second, i});
                }
                if (j < n && isPalindrome(w, j, n - 1)) {
                    string revLeft = w.substr(0, j);
                    reverse(revLeft.begin(), revLeft.end());
                    auto it = idx.find(revLeft);
                    if (it != idx.end() && it->second != i) res.push_back({i, it->second});
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
