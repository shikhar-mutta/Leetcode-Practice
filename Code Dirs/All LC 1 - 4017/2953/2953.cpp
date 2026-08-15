// Link: https://leetcode.com/problems/count-complete-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        int start = 0;
        while (start < n) {
            int end = start;
            while (end + 1 < n && abs(word[end+1] - word[end]) <= 2) end++;
            int segLen = end - start + 1;
            for (int d = 1; d <= 26; d++) {
                int len = d * k;
                if (len > segLen) break;
                vector<int> freq(26, 0);
                for (int i = start; i < start + len; i++) freq[word[i]-'a']++;
                int valid = 0;
                for (int c = 0; c < 26; c++) if (freq[c] == 0 || freq[c] == k) valid++;
                if (valid == 26) ans++;
                for (int i = start + len; i <= end; i++) {
                    freq[word[i]-'a']++;
                    freq[word[i-len]-'a']--;
                    valid = 0;
                    for (int c = 0; c < 26; c++) if (freq[c] == 0 || freq[c] == k) valid++;
                    if (valid == 26) ans++;
                }
            }
            start = end + 1;
        }
        return ans;
    }
};
