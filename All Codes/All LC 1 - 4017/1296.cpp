// Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + n) = O(nlogn), SC: O(n)
    //  Approach:
    //  1. If the size of the array is not divisible by k, return false
    //  2. Count the frequency of each number in the array using a map
    //  3. While the map is not empty, get the smallest number and its frequency
    //  4. For each number from the smallest number to the smallest number + k - 1, check if the number is present in the map and its frequency is greater than or equal to the frequency of the smallest number. If not, return false. If yes, decrement the frequency of the number in the map. If the frequency becomes 0, remove the number from the map
    //  5. If the map is empty, return true
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        if (nums.size() % k != 0)
            return false;

        map<int, int> cnt;
        for (int x : nums)
            cnt[x]++;

        // greedy: the smallest remaining value must start a set of k
        // consecutive numbers, so consume that run from its count
        while (!cnt.empty())
        {
            int start = cnt.begin()->first;
            int need = cnt.begin()->second;
            for (int v = start; v < start + k; v++)
            {
                auto it = cnt.find(v);
                if (it == cnt.end() || it->second < need)
                    return false;
                it->second -= need;
                if (it->second == 0)
                    cnt.erase(it);
            }
        }
        return true;
    }
};
