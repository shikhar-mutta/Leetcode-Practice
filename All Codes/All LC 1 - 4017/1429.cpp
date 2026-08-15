// Link: https://leetcode.com/problems/first-unique-number/description/

#include <bits/stdc++.h>
using namespace std;

class FirstUnique {
public:
    list<int> order;
    unordered_map<int, list<int>::iterator> pos;
    unordered_map<int,int> count;

    FirstUnique(vector<int>& nums) {
        for (int x : nums) add(x);
    }

    int showFirstUnique() {
        return order.empty() ? -1 : order.front();
    }

    void add(int value) {
        count[value]++;
        if (count[value] == 1) {
            order.push_back(value);
            pos[value] = prev(order.end());
        } else if (count[value] == 2) {
            if (pos.count(value)) {
                order.erase(pos[value]);
                pos.erase(value);
            }
        }
    }
};
