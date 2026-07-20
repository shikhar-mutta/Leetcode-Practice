// Link: https://leetcode.com/problems/compare-version-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N) SC: O(1)
    //  Approach:
    //  1. We can use two pointers to compare the two version numbers. We can initialize two pointers, one for each version number. We can then iterate through the version numbers, comparing the numbers at the two pointers. If the numbers are equal, we can move both pointers to the next number. If the numbers are not equal, we can return -1 if the first number is less than the second number, or 1 if the first number is greater than the second number.
    //  2. We can continue this process until we reach the end of both version numbers or until we find a difference between the two version numbers. If we reach the end of both version numbers and have not found a difference, we can return 0.
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0, n = version1.size(), m = version2.size();
        while (i < n || j < m)
        {
            int v1 = 0;
            while (i < n && version1[i] != '.')
                v1 = v1 * 10 + (version1[i++] - '0');
            int v2 = 0;
            while (j < m && version2[j] != '.')
                v2 = v2 * 10 + (version2[j++] - '0');
            if (v1 != v2)
                return v1 < v2 ? -1 : 1;
            i++;
            j++;
        }
        return 0;
    }
};
