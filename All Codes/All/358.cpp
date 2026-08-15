// Link: https://leetcode.com/problems/rearrange-string-k-distance-apart/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log 26)  SC: O(n)
// Approach: greedy max-heap by frequency, place the most frequent available
// char each step, hold it in a cooldown queue for k-1 steps before reuse
class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) return s;
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        priority_queue<pair<int,char>> pq;
        for (auto& [c, cnt] : freq) pq.push({cnt, c});

        queue<pair<int,char>> cooldown; // (count remaining, char), released after k steps
        string res;
        while (!pq.empty()) {
            auto [cnt, c] = pq.top(); pq.pop();
            res += c;
            cooldown.push({cnt - 1, c});
            if ((int)cooldown.size() >= k) {
                auto [rcnt, rc] = cooldown.front(); cooldown.pop();
                if (rcnt > 0) pq.push({rcnt, rc});
            }
        }
        return (int)res.size() == (int)s.size() ? res : "";
    }
};
