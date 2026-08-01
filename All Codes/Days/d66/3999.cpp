// Link: https://leetcode.com/problems/minimum-number-of-string-groups-through-transformations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * log(n))  SC: O(n)
// Approach: We can use hashing to represent the strings. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes. We can use a hash function to represent the strings and use a set to store the unique hashes.
class Solution
{
private:
    int getMinRotationIndex(const string &s, int startIdx, int step, int n)
    {
        if (n <= 1)
            return 0;
        int i = 0, j = 1, k = 0;
        while (i < n && j < n && k < n)
        {
            char ci = s[startIdx + ((i + k) % n) * step];
            char cj = s[startIdx + ((j + k) % n) * step];
            if (ci == cj)
            {
                k++;
            }
            else
            {
                if (ci > cj)
                    i += k + 1;
                else
                    j += k + 1;
                if (i == j)
                    j++;
                k = 0;
            }
        }
        return min(i, j);
    }

public:
    int minimumGroups(vector<string> &words)
    {
        unsigned long long base1 = 131, base2 = 137;
        vector<unsigned long long> hashes;
        hashes.reserve(words.size());

        for (const string &w : words)
        {
            int len = w.length();
            int n_e = (len + 1) / 2;
            int n_o = len / 2;

            int rot_e = getMinRotationIndex(w, 0, 2, n_e);
            int rot_o = getMinRotationIndex(w, 1, 2, n_o);

            unsigned long long h1 = 0, h2 = 0;

            for (int i = 0; i < n_e; i++)
            {
                char c = w[((rot_e + i) % n_e) * 2];
                h1 = h1 * base1 + c;
                h2 = h2 * base2 + c;
            }

            h1 = h1 * base1 + '#';
            h2 = h2 * base2 + '#';

            for (int i = 0; i < n_o; i++)
            {
                char c = w[((rot_o + i) % n_o) * 2 + 1];
                h1 = h1 * base1 + c;
                h2 = h2 * base2 + c;
            }

            hashes.push_back((h1 << 32) | (h2 & 0xFFFFFFFFFFFFFFULL));
        }

        sort(hashes.begin(), hashes.end());
        int unique_count = unique(hashes.begin(), hashes.end()) - hashes.begin();
        return unique_count;
    }
};
