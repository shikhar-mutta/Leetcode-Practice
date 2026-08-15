// Link: https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_set st(nums1.begin(), nums1.end());
        for (auto it : nums2)
        {
            // early stop if the set is empty
            if (st.empty())
                break;
            // if the element is found, erase it from the set and add it to the answer
            if (st.erase(it))
                ans.push_back(it);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
