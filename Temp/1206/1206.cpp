// Link: https://leetcode.com/problems/design-skiplist/description/

#include <bits/stdc++.h>
using namespace std;

class Skiplist {
    multiset<int> data;
public:
    Skiplist() {}

    bool search(int target) {
        return data.count(target) > 0;
    }

    void add(int num) {
        data.insert(num);
    }

    bool erase(int num) {
        auto it = data.find(num);
        if (it == data.end()) return false;
        data.erase(it);
        return true;
    }
};
