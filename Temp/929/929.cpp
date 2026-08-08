// Link: https://leetcode.com/problems/unique-email-addresses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        for (auto& e : emails) {
            int at = e.find('@');
            string local = e.substr(0, at);
            string domain = e.substr(at);
            int plus = local.find('+');
            if (plus != (int)string::npos) local = local.substr(0, plus);
            string cleaned;
            for (char c : local) if (c != '.') cleaned += c;
            unique.insert(cleaned + domain);
        }
        return unique.size();
    }
};
