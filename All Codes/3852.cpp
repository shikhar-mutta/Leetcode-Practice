// Link: https://leetcode.com/problems/smallest-pair-with-different-frequencies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), where n is the size of nums
    // SC: O(n), where n is the size of nums
    vector<int> minDistinctFreqPair(vector<int> &nums)
    {
        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        sort(freqVec.begin(), freqVec.end());

        vector<int> result(2, -1);
        int preFreq = freqVec[0].second;
        result[0] = freqVec[0].first;

        // Find sec elem with different freq
        for (int i = 0; i < freqVec.size(); i++)
            if (freqVec[i].second != preFreq)
            {
                result[1] = freqVec[i].first;
                break;
            }

        return result[1] == -1 ? vector<int>{-1, -1} : result;
    };

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
