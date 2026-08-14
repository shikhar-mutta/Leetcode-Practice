// Link: https://leetcode.com/problems/count-tested-devices-after-test-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int dec = 0, cnt = 0;
        for (int b : batteryPercentages) {
            if (b - dec > 0) { cnt++; dec++; }
        }
        return cnt;
    }
};
