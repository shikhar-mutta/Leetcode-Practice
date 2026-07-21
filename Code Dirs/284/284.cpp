// Link: https://leetcode.com/problems/peeking-iterator/description/

#include <bits/stdc++.h>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
    bool hasNextVal;
    int nextVal;

    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        hasNextVal = Iterator::hasNext();
        if (hasNextVal)
            nextVal = Iterator::next();
    }

    int peek()
    {
        return nextVal;
    }

    int next()
    {
        int cur = nextVal;
        hasNextVal = Iterator::hasNext();
        if (hasNextVal)
            nextVal = Iterator::next();
        return cur;
    }

    bool hasNext() const
    {
        return hasNextVal;
    }
};
