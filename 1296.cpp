// Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
