// Link: https://leetcode.com/problems/maximum-number-of-removable-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(m)) where n is the length of the string s and m is the length of the removable array
// SC: O(n) where n is the length of the string s
//  Approach: Binary Search + Two Pointers
//    1. Create a copy of the string s and replace the characters at the indices specified in the removable array with a special character (e.g., '#') for the first k indices
//    2. Use two pointers to check if the string p is a subsequence of the modified string s. If it is, then we can remove the first k characters from s and still have p as a subsequence. If it is not, then we cannot remove the first k characters from s and still have p as a subsequence.
//    3. Use binary search to find the maximum value of k for which p is a subsequence of the modified string s. The maximum value of k is the answer to the problem.
//    4. Return the maximum value of k.
class Solution
{
public:
    bool longestCommonSubs(int k, string &s, string &p,
                           vector<int> &removable)
    {
        string copyS = s;
        int m = s.size();
        int n = p.size();
        for (int i = 0; i < k; i++)
        {
            copyS[removable[i]] = '#';
        }
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (copyS[i] == p[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return j == n;
    }
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int low = 0;
        int high = removable.size();
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (longestCommonSubs(mid, s, p, removable))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};