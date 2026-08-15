// Link: https://leetcode.com/problems/two-sum-iii-data-structure-design/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) add, O(distinct values) find  SC: O(n)
// Approach: hash map of value -> occurrence count; find checks each distinct value's complement,
// handling the doubled-value case (number == complement) by requiring count >= 2
class TwoSum {
public:
    TwoSum() {}

    void add(int number) {
        count[number]++;
    }

    bool find(int value) {
        for (auto& [num, cnt] : count) {
            int complement = value - num;
            if (complement == num) {
                if (cnt >= 2) return true;
            } else if (count.count(complement)) {
                return true;
            }
        }
        return false;
    }

private:
    unordered_map<int,int> count;
};
