// Link: https://leetcode.com/problems/maximize-sum-of-at-most-k-distinct-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(k) + O(k/2) ~ O(nlogn). SC: O(k) for set and ans vector.
    vector<int> maxKDistinct(vector<int> &arr, int k)
    {
        set<int> s;
        vector<int> ans;
        sort(arr.begin(), arr.end()); // sort
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            s.insert(arr[i]); // insert into set till size is k
            if (s.size() == k)
                break;
        }
        for (int t : s) // push into ans vector
            ans.push_back(t);

        for (int i = 0; i < ans.size() / 2; i++) // reverse the ans vector to make sorted in desc
            swap(ans[i], ans[ans.size() - 1 - i]);

        return ans;
    }
};
