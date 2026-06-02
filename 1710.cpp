// Link: https://leetcode.com/problems/maximum-units-on-a-truck/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 return a[1] > b[1]; // Sort by units per box in descending order
             });

        int totalUnits = 0;

        for (const auto &boxType : boxTypes)
        {
            int numberOfBoxes = boxType[0];
            int unitsPerBox = boxType[1];

            if (truckSize >= numberOfBoxes)
            { // We can take all boxes of this type
                totalUnits += numberOfBoxes * unitsPerBox;
                truckSize -= numberOfBoxes;
            }
            else
            { // We can only take part of the boxes of this type
                totalUnits += truckSize * unitsPerBox;
                break; // Truck is full
            }
        }

        return totalUnits;
    }
};
