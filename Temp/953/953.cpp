// Link: https://leetcode.com/problems/verifying-an-alien-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int rank[26];
        for (int i = 0; i < 26; i++) rank[order[i] - 'a'] = i;
        for (int i = 1; i < (int)words.size(); i++) {
            if (!inOrder(words[i-1], words[i], rank)) return false;
        }
        return true;
    }

private:
    bool inOrder(const string& a, const string& b, int rank[26]) {
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) return rank[a[i]-'a'] < rank[b[i]-'a'];
        }
        return a.size() <= b.size();
    }
};
