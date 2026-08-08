// Link: https://leetcode.com/problems/fruit-into-baskets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> cnt;
        int left = 0, best = 0;
        for (int right = 0; right < (int)fruits.size(); right++) {
            cnt[fruits[right]]++;
            while (cnt.size() > 2) {
                cnt[fruits[left]]--;
                if (cnt[fruits[left]] == 0) cnt.erase(fruits[left]);
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
