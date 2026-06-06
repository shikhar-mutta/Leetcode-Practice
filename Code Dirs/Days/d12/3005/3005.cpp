// Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> freq(101, 0);
        for (int num : nums)
            freq[num]++;
        int maxFreq = *max_element(freq.begin(), freq.end());
        return count(freq.begin(), freq.end(), maxFreq) * maxFreq;
    }
};
