// Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    //  Approach: We use a hash map to store the frequency of each number in the array. Then, we iterate through the keys of the hash map and check for each key if there exists a key that is equal to the current key plus k. If k is 0, we check if the frequency of the current key is greater than or equal to 2. We count the number of such pairs and return it.
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;
        int pairs = 0;
        for (auto &[val, cnt] : freq)
        {
            if (k == 0)
                pairs += (cnt >= 2);
            else
                pairs += freq.count(val + k);
        }
        return pairs;
    }
};
