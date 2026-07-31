// Link: https://leetcode.com/problems/next-greater-element-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
//  Approach: Use two stacks to keep track of the indices of the elements. The first stack keeps track of the indices of the elements that are greater than the current element. The second stack keeps track of the indices of the elements that are greater than the elements in the first stack. When we find an element that is greater than the top of the second stack, we pop the indices from the second stack and update the answer for those indices. We then pop the indices from the first stack and push them onto the second stack. Finally, we push the current index onto the first stack.
class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> st1;
        vector<int> st2;
        vector<int> ans(n, -1);
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            while (!st2.empty() && nums[i] > nums[st2.back()])
            {
                ans[st2.back()] = nums[i];
                st2.pop_back();
            }
            while (!st1.empty() && nums[i] > nums[st1.back()])
            {
                temp.push_back(st1.back());
                st1.pop_back();
            }
            while (!temp.empty())
            {
                st2.push_back(temp.back());
                temp.pop_back();
            }
            st1.push_back(i);
        }
        return ans;
    }
};
