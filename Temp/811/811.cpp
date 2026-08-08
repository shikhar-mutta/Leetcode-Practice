// Link: https://leetcode.com/problems/subdomain-visit-count/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: for each entry, parse count and domain; add the count to every suffix (subdomain) of the domain using a map for deterministic sorted output.
// TC: O(n log n) SC: O(n)
// Approach: for each entry, split the domain into parts by '.'; add the count to every suffix (built by joining parts from position i to end) using a map for deterministic sorted output.
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string,int> counts;
        for (auto& entry : cpdomains) {
            int sp = entry.find(' ');
            int cnt = stoi(entry.substr(0, sp));
            string domain = entry.substr(sp+1);
            vector<string> parts;
            stringstream ss(domain);
            string part;
            while (getline(ss, part, '.')) parts.push_back(part);
            for (size_t i = 0; i < parts.size(); i++) {
                string suffix;
                for (size_t j = i; j < parts.size(); j++) {
                    if (j > i) suffix += ".";
                    suffix += parts[j];
                }
                counts[suffix] += cnt;
            }
        }
        vector<string> res;
        for (auto& [domain, cnt] : counts) res.push_back(to_string(cnt) + " " + domain);
        return res;
    }
};
