// Link: https://leetcode.com/problems/convert-the-temperature/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32.0};
    }
};
