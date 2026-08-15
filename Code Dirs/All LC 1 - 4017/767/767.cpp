// Link: https://leetcode.com/problems/reorganize-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log 26) SC: O(n)
// Approach: max-heap by frequency; repeatedly pick the two most frequent remaining chars, append one, then the other (or just one if only one remains), avoiding placing the same char consecutively. Fail if any char's frequency exceeds ceil(n/2).
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        int cnt[26] = {0};
        for (char c : s) cnt[c-'a']++;
        priority_queue<pair<int,char>> pq;
        for (int i = 0; i < 26; i++) if (cnt[i] > 0) pq.push({cnt[i], 'a'+i});
        if (!pq.empty() && pq.top().first > (n+1)/2) return "";
        string res;
        while (!pq.empty()) {
            auto [c1, ch1] = pq.top(); pq.pop();
            if (res.empty() || res.back() != ch1) {
                res += ch1;
                if (--c1 > 0) pq.push({c1, ch1});
            } else {
                if (pq.empty()) return "";
                auto [c2, ch2] = pq.top(); pq.pop();
                res += ch2;
                if (--c2 > 0) pq.push({c2, ch2});
                pq.push({c1, ch1});
            }
        }
        return res;
    }
};
