// Link: https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) for add and get, SC: O(n)
//  Approach: Use a set to store the items in sorted order based on score and name. The set will automatically maintain the order of the items. We can use an iterator to keep track of the current position in the set for the get() function. When we add a new item, we insert it into the set and adjust the iterator if necessary. The get() function simply returns the name of the item at the current iterator position and moves the iterator forward.
class SORTracker
{
private:
    set<pair<int, string>> items;

    set<pair<int, string>>::iterator it;

public:
    SORTracker() { it = items.end(); }

    void add(string name, int score)
    {
        pair<int, string> newItem = {-score, name};
        items.insert(newItem);

        if (it != items.end() && newItem < *it)
        {
            --it;
        }
    }

    string get()
    {
        if (it == items.end())
        {
            it = items.begin();
        }
        else
        {
            ++it;
        }

        return it->second;
    }
};
