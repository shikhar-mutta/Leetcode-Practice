// Link: https://leetcode.com/problems/find-common-elements-between-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using hash sets + count_if
    // TC: O(n1*n2), SC: O(n1 + n2)
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        return {
            (int)count_if(nums1.begin(), nums1.end(), [&](int x)
                          { return s2.count(x); }),
            (int)count_if(nums2.begin(), nums2.end(), [&](int x)
                          { return s1.count(x); })};
    }

    // Using frequency arrays
    // TC: O(n1 + n2 + 101), SC: O(101)
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {
        vector<char> val1(101, 0);
        vector<char> val2(101, 0);
        for (int n1 : nums1)
        {
            val1[n1]++;
        }

        for (int n2 : nums2)
        {
            val2[n2]++;
        }

        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < 101; ++i)
        {
            if (val1[i] && val2[i])
            {
                count1 += val1[i];
                count2 += val2[i];
            }
        }

        return {count1, count2};
    }
};
