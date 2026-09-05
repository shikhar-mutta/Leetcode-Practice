// Link: https://leetcode.com/problems/elevator-requests-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int elevatorRequests(int n, vector<int> &requests)
    {
        int total = 0;
        int cur = 0;
        for (int floor : requests)
        {
            total += abs(floor - cur);
            cur = floor;
        }
        return total;
    }
};