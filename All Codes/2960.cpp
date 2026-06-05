// Link: https://leetcode.com/problems/count-tested-devices-after-test-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countTestedDevices(vector<int> &batteryPercentages)
    {
        int count = 0;
        for (int x : batteryPercentages)
            if (x - count > 0)
                count++;
        return count;
    }
};
