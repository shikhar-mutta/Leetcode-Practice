// Link: https://leetcode.com/problems/count-number-of-teams/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int total = 0;
        for (int j = 0; j < n; j++) {
            int leftLess = 0, leftGreater = 0, rightLess = 0, rightGreater = 0;
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) leftLess++;
                else if (rating[i] > rating[j]) leftGreater++;
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j]) rightLess++;
                else if (rating[k] > rating[j]) rightGreater++;
            }
            total += leftLess * rightGreater + leftGreater * rightLess;
        }
        return total;
    }
};
