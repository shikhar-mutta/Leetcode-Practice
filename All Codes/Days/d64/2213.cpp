// Link: https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n+q) log n)  SC: O(n)
// Approach: maintain segment start indices (set) and lengths (map) for
// maximal same-char runs, plus a multiset of lengths for O(log n) max
// query. On update at idx: split its old segment into before/idx/after
// pieces, then merge the idx piece with left/right neighbors if same char.
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        set<int> starts; // segment start indices
        map<int,int> segLen; // start -> length
        multiset<int> lens;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            starts.insert(i);
            segLen[i] = j - i;
            lens.insert(j - i);
            i = j;
        }
        auto removeSeg = [&](int start) {
            int len = segLen[start];
            lens.erase(lens.find(len));
            segLen.erase(start);
            starts.erase(start);
        };
        auto addSeg = [&](int start, int len) {
            starts.insert(start);
            segLen[start] = len;
            lens.insert(len);
        };
        int m = queryIndices.size();
        vector<int> ans(m);
        for (int qi = 0; qi < m; qi++) {
            int idx = queryIndices[qi];
            char c = queryCharacters[qi];
            if (s[idx] == c) { ans[qi] = *lens.rbegin(); continue; }
            // find segment containing idx
            auto it = starts.upper_bound(idx);
            --it;
            int segStart = *it;
            int segEndExcl = segStart + segLen[segStart];
            removeSeg(segStart);
            s[idx] = c;
            // rebuild pieces: [segStart, idx), [idx,idx+1), [idx+1, segEndExcl)
            if (idx > segStart) addSeg(segStart, idx - segStart);
            if (idx + 1 < segEndExcl) addSeg(idx + 1, segEndExcl - idx - 1);
            int newStart = idx, newLen = 1;
            addSeg(newStart, newLen);
            // merge with left neighbor if same char
            auto lit = starts.find(newStart);
            if (lit != starts.begin()) {
                auto prev = std::prev(lit);
                int prevStart = *prev;
                if (s[prevStart] == c) {
                    newLen += segLen[prevStart];
                    removeSeg(prevStart);
                    removeSeg(newStart);
                    newStart = prevStart;
                    addSeg(newStart, newLen);
                }
            }
            // merge with right neighbor if same char
            int rightPos = newStart + newLen;
            auto rit = starts.find(rightPos);
            if (rit != starts.end() && s[*rit] == c) {
                newLen += segLen[*rit];
                removeSeg(*rit);
                removeSeg(newStart);
                addSeg(newStart, newLen);
            }
            ans[qi] = *lens.rbegin();
        }
        return ans;
    }
};
