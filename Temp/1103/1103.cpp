// Link: https://leetcode.com/problems/distribute-candies-to-people/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int give = 1, idx = 0;
        while (candies > 0) {
            int amt = min(give, candies);
            res[idx % num_people] += amt;
            candies -= amt;
            give++;
            idx++;
        }
        return res;
    }
};
