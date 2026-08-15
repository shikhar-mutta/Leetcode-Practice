// Link: https://leetcode.com/problems/maximum-palindromes-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> freq(26, 0);
        for (auto& w : words) for (char c : w) freq[c - 'a']++;
        long long totalPairs = 0;
        for (int f : freq) totalPairs += f / 2;

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int cnt = 0;
        for (auto& w : words) {
            long long need = w.size() / 2;
            if (totalPairs >= need) {
                totalPairs -= need;
                cnt++;
            } else break;
        }
        return cnt;
    }
};
