// Link: https://leetcode.com/problems/extra-characters-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum(dictionary word lengths)) to build the trie + O(n^2) for the
// memoized DFS over s (n = s.length())
// SC: O(sum(dictionary word lengths)) for the trie pool + O(n) for memo
// Approach: insert all dictionary words into a flat-array trie (bitmask per
// node tracks which of the 26 children exist, node indices are pool offsets
// instead of pointers). countMissing(i) = min extra chars in s[i..] : either
// skip s[i] as extra (1 + countMissing(i+1)), or walk the trie from i forward
// and, at every position j where a dictionary word ends, try consuming
// s[i..j] as a whole match (countMissing(j+1)) — memoized per start index.
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    class alignas(64) Node {
    public:
        uint16_t nodeMap[26]{};
        bool wordEnd{false};
        uint32_t mask;
    };
    inline static vector<Node> pool;
    inline static vector<int> memo;
    int docLen;

public:
    Solution() {
        static bool init = (pool.reserve(10000), memo.reserve(50), true);
        pool.clear();
        pool.emplace_back();
    }
    void insert(string_view word) {
        uint16_t level = 0;
        for (char c : word) {
            Node& node = pool[level];
            uint32_t idx = c - 'a', mask = node.mask;
            if (!(mask & (1 << idx))) {
                node.mask |= (1 << idx);
                node.nodeMap[idx] = pool.size();
                pool.emplace_back();
            }
            level = node.nodeMap[idx];
        }
        pool[level].wordEnd = true;
    }
    int countMissing(string_view doc, int startIdx) {
        if (startIdx == docLen) {
            return 0;
        }
        if (memo[startIdx] != -1)
            return memo[startIdx];
        int res = 1 + countMissing(doc, startIdx + 1);
        int level = 0;
        for (int i = startIdx; i < docLen; ++i) {
            uint32_t idx = doc[i] - 'a', mask = pool[level].mask;
            if (!(mask & (1 << idx)))
                break;
            level = pool[level].nodeMap[idx];
            if (pool[level].wordEnd) {
                res = min(res, countMissing(doc, i + 1));
            }
        }
        return memo[startIdx] = res;
    }
    int minExtraChar(string_view s, vector<string>& dictionary) {
        for (string& word : dictionary)
            insert(word);
        docLen = s.length();
        memo.assign(s.length() + 1, -1);
        return countMissing(s, 0);
    }
};
