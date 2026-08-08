// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3] = {0, 0, 0};
        int left = 0, result = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            cnt[s[right] - 'a']++;
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                cnt[s[left] - 'a']--;
                left++;
            }
            result += left;
        }
        return result;
    }
};
