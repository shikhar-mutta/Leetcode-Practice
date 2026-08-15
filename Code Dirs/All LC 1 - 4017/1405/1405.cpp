// Link: https://leetcode.com/problems/longest-happy-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string res;
        while (!pq.empty()) {
            auto [cnt, ch] = pq.top(); pq.pop();
            int len = res.size();
            if (len >= 2 && res[len-1] == ch && res[len-2] == ch) {
                if (pq.empty()) break;
                auto [cnt2, ch2] = pq.top(); pq.pop();
                res += ch2;
                cnt2--;
                if (cnt2 > 0) pq.push({cnt2, ch2});
                pq.push({cnt, ch});
            } else {
                res += ch;
                cnt--;
                if (cnt > 0) pq.push({cnt, ch});
            }
        }
        return res;
    }
};
