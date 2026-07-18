// Link: https://leetcode.com/problems/largest-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(n)
    // Approach: We convert the integers to strings and sort them based on the concatenation
    string largestNumber(vector<int> &nums)
    {
        vector<string> strs;
        strs.reserve(nums.size());
        for (int x : nums)
            strs.push_back(to_string(x));

        // a before b if the concatenation a+b beats b+a
        sort(strs.begin(), strs.end(), [](const string &a, const string &b)
             { return a + b > b + a; });

        if (strs[0] == "0")
            return "0"; // all zeros
        string res;
        for (auto &s : strs)
            res += s;
        return res;
    }
};
