// Link: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [](const string& s) {
            char mn = *min_element(s.begin(), s.end());
            return count(s.begin(), s.end(), mn);
        };
        vector<int> wf;
        for (auto& w : words) wf.push_back(f(w));
        sort(wf.begin(), wf.end());

        vector<int> res;
        for (auto& q : queries) {
            int fq = f(q);
            int idx = upper_bound(wf.begin(), wf.end(), fq) - wf.begin();
            res.push_back(wf.size() - idx);
        }
        return res;
    }
};
