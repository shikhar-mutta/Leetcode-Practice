// Link: https://leetcode.com/problems/smallest-pair-with-different-frequencies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the size of nums
    // SC: O(1), since the freq vector has a fixed size of 101 (0 to 100)
    vector<int> minDistinctFreqPair(vector<int> &nums)
    {
        vector<int> freq(101, 0);

        for (int num : nums)
            freq[num]++;

        vector<int> result(2, -1);
        int cnt = 2, preFreq = -1;
        for (int i = 0; i < freq.size() && cnt > 0; i++)
            if (freq[i] > 0 && freq[i] != preFreq)
            {
                preFreq = freq[i];
                result[2 - cnt] = i;
                cnt--;
            }

        return result[1] == -1 ? vector<int>{-1, -1} : result;
    };
};
