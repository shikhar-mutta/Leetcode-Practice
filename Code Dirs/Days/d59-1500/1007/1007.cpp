// Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the input array.
    // SC: O(1) as we are using constant space.
    //  Approach:
    //   1. We will try to make all the values in the tops or bottoms equal to the first value of tops or bottoms.
    //   2. We will create a helper function tryValue which will take the tops, bottoms and target value as input and will return the minimum number of rotations required to make all the values in tops or bottoms equal to the target value.
    //   3. In the tryValue function, we will iterate through the tops and bottoms and check if the current value is equal to the target value. If it is not equal to the target value, we will increment the count of rotations required for tops or bottoms.
    //   4. If the current value is not equal to the target value in both tops and bottoms, we will return -1 as it is not possible to make all the values equal to the target value.
    //   5. Finally, we will return the minimum number of rotations required to make all the values in tops or bottoms equal to the target value.
    int tryValue(vector<int> &tops, vector<int> &bottoms, int target)
    {
        int rotateTop = 0, rotateBottom = 0;
        int n = tops.size();
        for (int i = 0; i < n; i++)
        {
            if (tops[i] != target && bottoms[i] != target)
                return -1;
            if (tops[i] != target)
                rotateTop++;
            else if (bottoms[i] != target)
                rotateBottom++;
        }
        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int result = tryValue(tops, bottoms, tops[0]);
        if (result != -1)
            return result;
        return tryValue(tops, bottoms, bottoms[0]);
    }
};
