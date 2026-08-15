// Link: https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static constexpr int nmax = 1000000000;
    inline static int nums[1554];
    inline static int _precomp = []()
    {
        unordered_map<int, int> f;
        for (int i = 1; 2 * i * i * i <= nmax; ++i)
        {
            int a = i * i * i;
            for (int j = i; a + j * j * j <= nmax; ++j)
            {
                int b = j * j * j;
                ++f[a + b];
            }
        }
        int i = 0;
        for (auto [num, freq] : f)
            if (freq > 1)
                nums[i++] = num;
        sort(nums, nums + 1554);

        return 0;
    }();

public:
    vector<int> findGoodIntegers(int n)
    {
        vector<int> ans;
        ans.reserve(1554);
        for (int i = 0; i < 1554 && nums[i] <= n; ++i)
            ans.push_back(nums[i]);
        return ans;
    }
};
