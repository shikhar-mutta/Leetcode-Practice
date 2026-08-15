// Link: https://leetcode.com/problems/snapshot-array/description/

#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
public:
    // TC: O(log m) for set and get operations, where m is the number of snapshots taken for a particular index
    // SC: O(n * m) where n is the length of the array and m is the number of snapshots taken for a particular index
    //   Approach:
    //    1. Use a vector of vectors to store the snapshots for each index. Each inner vector contains pairs of (snap_id, value) representing the value at that index for a particular snapshot.
    //    2. For the set operation, if the last snapshot for that index has the same snap_id, update the value. Otherwise, add a new entry with the current snap_id and value.
    //    3. For the snap operation, increment the snap_id and return the previous snap_id.
    //    4. For the get operation, perform a binary search on the inner vector for that index to find the largest snap_id that is less than or equal to the requested snap_id, and return the corresponding value. If no such snap_id exists, return 0.

    SnapshotArray(int _length) : snap_id(0), length(_length)
    {
        data.resize(_length);
    }

    void set(int index, int val)
    {
        if (!data[index].empty() && data[index].back().snap_id ==
                                        snap_id)
        { // in this case update value
            data[index].back().val = val;
            return;
        }

        data[index].emplace_back(snap_id, val);
    }

    int snap() { return snap_id++; }

    int get(int index, int _snap_id)
    {
        auto &vec = data[index];
        if (vec.empty())
            return 0;
        if (_snap_id < vec[0].snap_id)
            return 0;

        return bfind(vec, _snap_id);
    }

private:
    struct Entry
    {
        int snap_id;
        int val;
        Entry(int s, int v) : snap_id(s), val(v) {}
    };

    int bfind(const vector<Entry> &vec, int snap_id)
    {
        /*
            s
              e
            m
        0 1 2 3
        0 2 5 9
          3
            5
        */
        // assumes always exists
        int s = 0, e = vec.size() - 1;
        int idx = 0;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (vec[mid].snap_id == snap_id)
            {
                idx = mid;
                break;
            }
            else if (snap_id > vec[mid].snap_id)
            {
                idx = mid;
                s = mid + 1;
            }
            else // snap_id < vec[mid][0]
            {
                e = mid - 1;
            }
        }
        return vec[idx].val;
    }

    vector<vector<Entry>> data;
    int snap_id;
    int length;
};