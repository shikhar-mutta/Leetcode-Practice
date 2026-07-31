// Link: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(n)
// Approach: Longest Increasing Subsequence
//  We can use the Longest Increasing Subsequence (LIS) algorithm to find the minimum number of operations needed to make the target array a subsequence of the arr array. We can map each value of the target array to its index and then replace the elements of the arr array with their corresponding indices in the target array. We can then find the length of the LIS in the mapped array and return the difference between the length of the target array and the length of the LIS as the answer.
class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        // Map every value of target to its index
        unordered_map<int, int> pos;
        pos.reserve(target.size() * 2); // avoid rehashing
        for (int i = 0; i < (int)target.size(); ++i)
            pos[target[i]] = i;

        // Keep only the elements of arr that are in target, replace with
        // indices
        vector<int> mapped;
        mapped.reserve(arr.size());
        for (int x : arr)
        {
            auto it = pos.find(x);
            if (it != pos.end())
                mapped.push_back(it->second); // index in target
        }

        // Longest Increasing Subsequence on 'mapped'
        vector<int> tail; // tail[i] = min last value of LIS length i+1
        for (int val : mapped)
        {
            auto it = lower_bound(tail.begin(), tail.end(), val);
            if (it == tail.end())
                tail.push_back(val);
            else
                *it = val;
        }

        int lisLen = (int)tail.size();
        return (int)target.size() - lisLen; // elements that need to be inserted
    }
};