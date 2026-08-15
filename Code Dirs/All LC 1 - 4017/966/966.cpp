// Link: https://leetcode.com/problems/vowel-spellchecker/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> lowerMap, vowelMap;

        auto toLower = [](const string& s) {
            string r = s;
            for (char& c : r) c = tolower(c);
            return r;
        };
        auto devowel = [&](const string& s) {
            string r = toLower(s);
            for (char& c : r) if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
            return r;
        };

        for (auto& w : wordlist) {
            string lw = toLower(w);
            if (!lowerMap.count(lw)) lowerMap[lw] = w;
            string dv = devowel(w);
            if (!vowelMap.count(dv)) vowelMap[dv] = w;
        }

        vector<string> res;
        for (auto& q : queries) {
            if (exact.count(q)) { res.push_back(q); continue; }
            string lq = toLower(q);
            if (lowerMap.count(lq)) { res.push_back(lowerMap[lq]); continue; }
            string dq = devowel(q);
            if (vowelMap.count(dq)) { res.push_back(vowelMap[dq]); continue; }
            res.push_back("");
        }
        return res;
    }
};
