// Link: https://leetcode.com/problems/interval-list-intersections/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the size of firstList and m is the size of secondList.
    // SC: O(n + m) where n is the size of firstList and m is the size of secondList.
    // Approach:
    //  1. We will use two pointers i and j to traverse the firstList and secondList respectively.
    //  2. For each pair of intervals firstList[i] and secondList[j], we will find the intersection of the two intervals by taking the maximum of the start points and the minimum of the end points.
    //  3. If the intersection is valid (i.e., the start point is less than or equal to the end point), we will add it to the result list.
    //  4. We will then move the pointer of the interval that ends first, since it cannot intersect with any future intervals from the other list.
    //  5. We will continue this process until we have traversed both lists completely.
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < (int)firstList.size() && j < (int)secondList.size())
        {
            int lo = max(firstList[i][0], secondList[j][0]);
            int hi = min(firstList[i][1], secondList[j][1]);
            if (lo <= hi)
                result.push_back({lo, hi});
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return result;
    }
};
