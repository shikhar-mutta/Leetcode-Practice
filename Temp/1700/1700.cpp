// Link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;
        for (int s : students) { if (s == 0) count0++; else count1++; }
        int i = 0;
        while (i < (int)sandwiches.size()) {
            if (sandwiches[i] == 0) {
                if (count0 == 0) break;
                count0--;
            } else {
                if (count1 == 0) break;
                count1--;
            }
            i++;
        }
        return count0 + count1;
    }
};
