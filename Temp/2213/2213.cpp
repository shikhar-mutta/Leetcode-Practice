// Link: https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, pair<int,char>> runs; // start -> (length, char)
    multiset<int> lengths;

    void addRun(int start, int len, char c) {
        runs[start] = {len, c};
        lengths.insert(len);
    }
    void removeRun(int start) {
        auto it = runs.find(start);
        lengths.erase(lengths.find(it->second.first));
        runs.erase(it);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        // build initial runs
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            addRun(i, j - i, s[i]);
            i = j;
        }

        int q = queryIndices.size();
        vector<int> res(q);
        for (int qi = 0; qi < q; qi++) {
            int idx = queryIndices[qi];
            char c = queryCharacters[qi];
            if (s[idx] == c) {
                res[qi] = *lengths.rbegin();
                continue;
            }
            // find run containing idx
            auto it = runs.upper_bound(idx);
            --it;
            int start = it->first;
            int len = it->second.first;
            char oldC = it->second.second;
            removeRun(start);
            if (idx > start) addRun(start, idx - start, oldC);
            if (idx + 1 < start + len) addRun(idx + 1, start + len - idx - 1, oldC);

            int newStart = idx, newLen = 1;
            // find run ending exactly at idx-1
            {
                auto probe = runs.upper_bound(idx - 1);
                if (probe != runs.begin()) {
                    auto pr = prev(probe);
                    if (pr->first + pr->second.first == idx && pr->second.second == c) {
                        newStart = pr->first;
                        newLen += pr->second.first;
                        removeRun(pr->first);
                    }
                }
            }
            // check right neighbor: run starting exactly at newStart+newLen
            int rightStart = newStart + newLen;
            if (runs.count(rightStart) && runs[rightStart].second == c) {
                newLen += runs[rightStart].first;
                removeRun(rightStart);
            }
            addRun(newStart, newLen, c);
            s[idx] = c;
            res[qi] = *lengths.rbegin();
        }
        return res;
    }
};
