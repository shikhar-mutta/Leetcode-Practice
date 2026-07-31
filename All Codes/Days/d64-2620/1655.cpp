// Link: https://leetcode.com/problems/distribute-repeating-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + mlogm + 2^m * n) where n is the size of nums and m is the size of quantity
// SC: O(n + m) where n is the size of nums and m is the size of quantity
// Approach: We can use a backtracking approach to try to distribute the quantities among the frequencies of the numbers in nums. First, we count the frequency of each number in nums and store it in a vector. Then, we sort both the frequency vector and the quantity vector in descending order. We then use a recursive function to try to assign each quantity to one of the frequencies. If we can assign all quantities successfully, we return true; otherwise, we return false.
class Solution
{
public:
    bool canDistribute(vector<int> &nums, vector<int> &quantity)
    {
        int maxnum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxnum = max(maxnum, nums[i]);
        }
        vector<int> freq(maxnum + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        vector<int> freq2;
        for (int f : freq)
        {
            if (f)
                freq2.push_back(f);
        }
        sort(freq2.rbegin(), freq2.rend());
        sort(quantity.rbegin(), quantity.rend());
        return solve(0, freq2, quantity);
    }
    bool solve(int ind, vector<int> &freq, vector<int> &quantity)
    {
        if (ind == quantity.size())
        {
            return true;
        }
        unordered_set<int> used;
        for (int i = 0; i < freq.size(); i++)
        {
            if (used.count(freq[i]))
                continue;
            used.insert(freq[i]);
            if (freq[i] >= quantity[ind])
            {
                freq[i] -= quantity[ind];
                if (solve(ind + 1, freq, quantity))
                    return true;
                freq[i] += quantity[ind];
            }
        }
        return false;
    }
};