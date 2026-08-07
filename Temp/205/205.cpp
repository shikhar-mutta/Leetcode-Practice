// Link: https://leetcode.com/problems/isomorphic-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) (fixed 256-entry maps)
// Approach: two-way char maps enforcing a bijection — each s-char must map consistently to one t-char and vice versa
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapST[256], mapTS[256];
        fill(begin(mapST), end(mapST), -1);
        fill(begin(mapTS), end(mapTS), -1);
        for (int i = 0; i < (int)s.size(); i++) {
            unsigned char a = s[i], b = t[i];
            if (mapST[a] == -1 && mapTS[b] == -1) {
                mapST[a] = b;
                mapTS[b] = a;
            } else if (mapST[a] != b || mapTS[b] != a) {
                return false;
            }
        }
        return true;
    }
};
