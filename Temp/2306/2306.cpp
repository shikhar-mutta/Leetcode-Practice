// Link: https://leetcode.com/problems/naming-a-company/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int> suffixMask;
        int groupSize[26] = {0};
        for (auto& idea : ideas) {
            char c = idea[0];
            string suffix = idea.substr(1);
            suffixMask[suffix] |= (1 << (c - 'a'));
            groupSize[c - 'a']++;
        }

        long long common[26][26] = {};
        for (auto& [suffix, mask] : suffixMask) {
            vector<int> bits;
            for (int b = 0; b < 26; b++) if (mask & (1 << b)) bits.push_back(b);
            for (int i = 0; i < (int)bits.size(); i++)
                for (int j = i + 1; j < (int)bits.size(); j++)
                    common[bits[i]][bits[j]]++;
        }

        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                long long c = common[i][j];
                ans += 2LL * (groupSize[i] - c) * (groupSize[j] - c);
            }
        }
        return ans;
    }
};
