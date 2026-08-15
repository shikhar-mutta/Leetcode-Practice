// Link: https://leetcode.com/problems/count-caesar-cipher-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) SC: O(n * m)
// Approach: for each word, compute its "signature" as the vector of differences between each character and the first character (mod 26). Count the frequency of each signature, then for each signature with frequency f, add f * (f - 1) / 2 to the total count of pairs.
class Solution
{
public:
    long long countPairs(vector<string> &words)
    {

        long long count = 0, sum;
        int val;
        int sizeI = words.size(), sizeJ = words[0].size(), i;
        if (sizeJ == 1)
        {
            count = sizeI;
            count *= (sizeI - 1);
            count /= 2;
            return count;
        }

        vector<int> tmp(sizeJ);
        map<vector<int>, int> freq;
        char c;

        for (auto it = words.begin(); it < words.end(); it++)
        {
            i = 0;
            c = (*it)[0];
            for (auto jt = (*it).begin(); jt < (*it).end(); jt++, i++)
            {
                val = *jt - c;
                if (val < 0)
                    val += 26;
                tmp[i] = val;
            }
            freq[tmp]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            val = (*it).second;
            sum = val;
            sum *= val - 1;
            sum /= 2;
            count += sum;
        }

        return count;
    }
};