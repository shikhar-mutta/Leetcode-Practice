// Link: https://leetcode.com/problems/faulty-sensor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int n = sensor1.size();
        int i = 0;
        while (i < n && sensor1[i] == sensor2[i]) i++;
        if (i == n) return -1;

        bool cond1 = true; // sensor1[i+1..] == sensor2[i..n-2] => sensor2 faulty
        for (int k = i + 1; k < n; k++) {
            if (sensor1[k] != sensor2[k - 1]) { cond1 = false; break; }
        }
        bool cond2 = true; // sensor2[i+1..] == sensor1[i..n-2] => sensor1 faulty
        for (int k = i + 1; k < n; k++) {
            if (sensor2[k] != sensor1[k - 1]) { cond2 = false; break; }
        }

        if (cond2 && !cond1) return 1;
        if (cond1 && !cond2) return 2;
        return -1;
    }
};
