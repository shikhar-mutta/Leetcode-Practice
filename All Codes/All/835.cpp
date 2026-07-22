// Link: https://leetcode.com/problems/image-overlap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^4), SC: O(n^2)
    //  Approach:
    //  1. We can use a brute force approach to check all possible translations of img1 over img2.
    //  2. For each translation, we can count the number of overlapping 1s by iterating through the pixels of img1 and img2 and checking if they are both 1s.
    //  3. We can keep track of the maximum number of overlapping 1s found so far and return that as the final answer.
    //  4. We can optimize this approach by only considering the positions of the 1s in img1 and img2, and using a frequency array to count the number of overlapping 1s for each translation.
    //  5. We can use a vector of pairs to store the positions of the 1s in img1 and img2, and then iterate through all pairs of positions to calculate the translation vector and update the frequency array.
    //  6. Finally, we can return the maximum value in the frequency array as the answer.
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int translation = 0, ans = 0, n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        for (int i = 0; i < img1.size(); i++)
        {
            for (int j = 0; j < img1[0].size(); j++)
            {
                if (img1[i][j])
                    ones1.push_back({i, j});
                if (img2[i][j])
                    ones2.push_back({i, j});
            }
        }

        vector<vector<int>> frequency(2 * n - 1, vector<int>(2 * n - 1, 0));

        for (auto &[r, c] : ones1)
        {
            for (auto &[r1, c1] : ones2)
            {
                int dr = (r1 - r + n - 1), dc = (c1 - c + n - 1);
                ans = max(ans, ++frequency[dr][dc]);
            }
        }

        return ans;
    }
};