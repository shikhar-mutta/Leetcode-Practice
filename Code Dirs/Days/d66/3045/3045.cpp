// Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(sum(len^2)) amortized via trie ~ O(sum(len) * 26^2) worst, but
// practically O(sum(len)) per insert with map children  SC: O(sum(len))
// Approach: trie keyed by pairs (word[i], word[len-1-i]) walked
// simultaneously from front and back. For each word, before inserting,
// walk the trie following its (front,back) char pairs; each node passed
// through (that has cnt>0, meaning it was a completed word ending there)
// contributes to the answer, since that represents a shorter word that is
// both a prefix and suffix of the current one. Then insert the current
// word's full pair-path, incrementing cnt at the final node.
class Solution {
    struct Node {
        unordered_map<int, Node*> child;
        long long cnt = 0;
    };
    Node* root = new Node();
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        for (auto& w : words) {
            int n = w.size();
            Node* cur = root;
            for (int i = 0; i < n; i++) {
                int key = (w[i] - 'a') * 26 + (w[n - 1 - i] - 'a');
                if (!cur->child.count(key)) cur->child[key] = new Node();
                cur = cur->child[key];
                ans += cur->cnt;
            }
            cur->cnt++;
        }
        return ans;
    }
};
