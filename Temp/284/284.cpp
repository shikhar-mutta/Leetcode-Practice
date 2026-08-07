// Link: https://leetcode.com/problems/peeking-iterator/description/

#include <bits/stdc++.h>
using namespace std;

class Iterator {
    vector<int> data;
    int pos = 0;
public:
    Iterator(const vector<int>& nums) : data(nums) {}
    Iterator(const Iterator& iter) : data(iter.data), pos(iter.pos) {}
    int next() { return data[pos++]; }
    bool hasNext() const { return pos < (int)data.size(); }
};

// TC: O(1) per operation  SC: O(1) extra
// Approach: wrap base Iterator, cache the next value on first peek so
// repeated peek() calls don't advance the underlying iterator
class PeekingIterator : public Iterator {
    bool hasCache = false;
    int cache = 0;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {}

    int peek() {
        if (!hasCache) {
            cache = Iterator::next();
            hasCache = true;
        }
        return cache;
    }

    int next() {
        if (hasCache) {
            hasCache = false;
            return cache;
        }
        return Iterator::next();
    }

    bool hasNext() const {
        return hasCache || Iterator::hasNext();
    }
};
