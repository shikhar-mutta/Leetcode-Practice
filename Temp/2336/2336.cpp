// Link: https://leetcode.com/problems/smallest-number-in-infinite-set/description/

#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    int next = 1;
    set<int> addedBack;
public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if (!addedBack.empty()) {
            int v = *addedBack.begin();
            addedBack.erase(addedBack.begin());
            return v;
        }
        return next++;
    }

    void addBack(int num) {
        if (num < next) addedBack.insert(num);
    }
};
