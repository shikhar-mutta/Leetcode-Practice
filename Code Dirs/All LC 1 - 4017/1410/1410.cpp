// Link: https://leetcode.com/problems/html-entity-parser/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string,string> entities = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };
        string res;
        int n = text.size();
        for (int i = 0; i < n; ) {
            if (text[i] == '&') {
                int semi = text.find(';', i);
                if (semi != (int)string::npos && semi - i <= 7) {
                    string token = text.substr(i, semi - i + 1);
                    if (entities.count(token)) {
                        res += entities[token];
                        i = semi + 1;
                        continue;
                    }
                }
            }
            res += text[i];
            i++;
        }
        return res;
    }
};
