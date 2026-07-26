// Link: https://leetcode.com/problems/convert-the-temperature/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: apply the fixed Celsius-to-Kelvin and Celsius-to-Fahrenheit
// conversion formulas directly.
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32.0};
    }
};
