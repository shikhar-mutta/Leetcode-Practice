// Link: https://leetcode.com/problems/naming-a-company/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26*26*N + sum|ideas|), SC: O(N)
// Approach: group suffixes by first letter into sets; for each pair of letters, common = intersection size,
// contributes 2*(sizeA-common)*(sizeB-common) valid swap pairs.
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> groups[26];
        for (auto& idea : ideas) groups[idea[0]-'a'].insert(idea.substr(1));

        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i+1; j < 26; j++) {
                long long common = 0;
                auto& small = groups[i].size() < groups[j].size() ? groups[i] : groups[j];
                auto& large = groups[i].size() < groups[j].size() ? groups[j] : groups[i];
                for (auto& s : small) if (large.count(s)) common++;
                long long a = groups[i].size() - common, b = groups[j].size() - common;
                ans += 2 * a * b;
            }
        }
        return ans;
    }
};
