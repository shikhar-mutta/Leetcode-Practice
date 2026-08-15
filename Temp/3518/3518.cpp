// Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> count(26);

        for (int i = 0; i < (int)size(s) / 2; ++i) {
            ++count[s[i] - 'a'];
        }

        int total = 0, counting = 1, remain = 0;
        int i;

        for (i = (int)size(count) - 1; i >= 0; --i) {
            for (int c = 1; c <= count[i]; ++c) {
                ++total;
                counting = counting * total / c;
                if (counting >= k) {
                    remain = count[i] - c;
                    break;
                }
            }

            if (counting >= k) {
                break;
            }
        }

        if (counting < k) {
            return "";
        }

        string hasil(size(s), 0);
        int l = 0;

        for (int j = 0; j <= i; ++j) {
            const char x = 'a' + j;
            const int c = j != i ? count[j] : remain;

            for (int _ = 0; _ < c; ++_) {
                --count[j];
                hasil[l++] = x;
            }
        }

        while (total) {
            for (int j = i; j < (int)size(count); ++j) {
                if (!count[j]) {
                    continue;
                }

                const auto new_count =
                    static_cast<int64_t>(counting) * count[j] / total;

                if (new_count < k) {
                    k -= new_count;
                    continue;
                }

                counting = new_count;
                --count[j];
                --total;
                hasil[l++] = 'a' + j;
                break;
            }
        }

        if (size(s) % 2) {
            hasil[l++] = s[size(s) / 2];
        }

        for (int i = l - 1 - (int)size(s) % 2; i >= 0; --i) {
            hasil[l++] = hasil[i];
        }
        return hasil;
    }
};
