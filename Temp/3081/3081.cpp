// Link: https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq(26, 0);
        for (char c : s) if (c != '?') freq[c - 'a']++;

        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<>> pq;
        for (int c = 0; c < 26; c++) pq.push({freq[c], (char)('a'+c)});

        int qCount = count(s.begin(), s.end(), '?');
        vector<char> chosen;
        for (int i = 0; i < qCount; i++) {
            auto [f, c] = pq.top(); pq.pop();
            chosen.push_back(c);
            pq.push({f+1, c});
        }
        sort(chosen.begin(), chosen.end());

        int idx = 0;
        string res = s;
        for (char& c : res) {
            if (c == '?') c = chosen[idx++];
        }
        return res;
    }
};
