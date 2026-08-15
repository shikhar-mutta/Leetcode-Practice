// Link: https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int sum = 0, count = 0;
        for (int w : weight) {
            if (sum + w > 5000) break;
            sum += w;
            count++;
        }
        return count;
    }
};
