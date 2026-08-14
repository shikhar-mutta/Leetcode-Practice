// Link: https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        long long hours = 0;
        long long curEnergy = initialEnergy, curExp = initialExperience;
        int n = energy.size();
        for (int i = 0; i < n; i++) {
            if (curEnergy <= energy[i]) {
                hours += energy[i] - curEnergy + 1;
                curEnergy = energy[i] + 1;
            }
            if (curExp <= experience[i]) {
                hours += experience[i] - curExp + 1;
                curExp = experience[i] + 1;
            }
            curEnergy -= energy[i];
            curExp += experience[i];
        }
        return (int)hours;
    }
};
