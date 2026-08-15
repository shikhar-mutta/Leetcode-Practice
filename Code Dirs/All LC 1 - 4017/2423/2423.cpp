// Link: https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = 0; j < n; j++) if (j != i) freq[word[j]-'a']++;
            int target = -1;
            bool ok = true;
            for (int f : freq) {
                if (f == 0) continue;
                if (target == -1) target = f;
                else if (f != target) { ok = false; break; }
            }
            if (ok) return true;
        }
        return false;
    }
};
