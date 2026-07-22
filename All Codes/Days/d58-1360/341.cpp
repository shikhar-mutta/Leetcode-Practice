// Link: https://leetcode.com/problems/flatten-nested-list-iterator/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation

 */

class NestedInteger
{
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    // TC: O(n) where n is the total number of integers in the nested list.
    // SC: O(n) where n is the total number of integers in the nested list. We store all the integers in a vector during the flattening process.
    // Approach:
    //  1. We can use a recursive approach to flatten the nested list. We iterate through each NestedInteger in the input list. If it is an integer, we add it to a vector. If it is a list, we recursively call the flatten function on that list. This way, we can flatten the entire nested list into a single vector of integers.
    //  2. We maintain an index to keep track of the current position in the flattened vector. The next() function returns the integer at the current index and increments the index. The hasNext() function checks if there are more integers to return by comparing the index with the size of the flattened vector.
    //  3. This approach ensures that we can iterate through the nested list in a linear fashion, returning each integer in the order they appear in the original nested structure.
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten(nestedList);
    }

    int next()
    {
        return values[idx++];
    }

    bool hasNext()
    {
        return idx < (int)values.size();
    }

private:
    vector<int> values;
    int idx = 0;

    void flatten(const vector<NestedInteger> &list)
    {
        for (const auto &ni : list)
        {
            if (ni.isInteger())
                values.push_back(ni.getInteger());
            else
                flatten(ni.getList());
        }
    }
};
