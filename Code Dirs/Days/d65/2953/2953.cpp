// Link: https://leetcode.com/problems/count-complete-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26*N), SC: O(N)
// Approach: split word into maximal runs where adjacent chars differ by <=2 (a valid substring
// can never cross a bigger jump). Within each run, for every distinct-char-count m (1..26), a
// complete substring has fixed length m*k; slide a window of that length maintaining frequency
// counts, tracking how many distinct chars are present and how many have frequency exactly k.
class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        vector<string> runs;
        int start = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n || abs(word[i] - word[i-1]) > 2) {
                runs.push_back(word.substr(start, i - start));
                start = i;
            }
        }

        long long ans = 0;
        for (auto& run : runs) {
            int len = run.size();
            for (int m = 1; m <= 26; m++) {
                int L = m * k;
                if (L > len) break;
                vector<int> freq(26, 0);
                int distinct = 0, good = 0;
                for (int i = 0; i < len; i++) {
                    int c = run[i] - 'a';
                    freq[c]++;
                    if (freq[c] == 1) distinct++;
                    if (freq[c] == k) good++;
                    else if (freq[c] == k + 1) good--;
                    if (i >= L) {
                        int rc = run[i-L] - 'a';
                        if (freq[rc] == k) good--;
                        else if (freq[rc] == k + 1) good++;
                        freq[rc]--;
                        if (freq[rc] == 0) distinct--;
                    }
                    if (i >= L - 1 && distinct == m && good == m) ans++;
                }
            }
        }
        return (int)ans;
    }
};
