// Link: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the number of orders.
// SC: O(n) for storing the food items and tables in sets and the final answer
// Approach:
// 1. Use a set to store the unique food items and tables from the orders.
// 2. Create a 2D vector to store the final answer with the first row as the food items and the first column as the table numbers.
// 3. Use unordered maps to map food items to their respective column indices and table numbers to their respective row indices in the answer vector.
// 4. Iterate through the orders and populate the answer vector with the count of each food item for each table.
// 5. Finally, replace any empty cells in the answer vector with "0" to indicate that the table did not order that food item.
class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        set<string> foods;
        set<int> tables;
        for (auto &it : orders)
        {
            foods.insert(it[2]);
            tables.insert(stoi(it[1]));
        }
        int m = foods.size();
        int n = tables.size();
        vector<vector<string>> ans(n + 1, vector<string>(m + 1, ""));
        ans[0][0] = "Table";
        unordered_map<string, int> foodCol;
        int col = 1;
        for (auto &food : foods)
        {
            ans[0][col] = food;
            foodCol[food] = col;
            col++;
        }
        unordered_map<int, int> tableRow;
        int row = 1;
        for (int table : tables)
        {
            ans[row][0] = to_string(table);
            tableRow[table] = row;
            row++;
        }
        for (auto &it : orders)
        {
            int table = stoi(it[1]);
            string food = it[2];
            int r = tableRow[table];
            int c = foodCol[food];
            if (ans[r][c] == "")
                ans[r][c] = "1";
            else
                ans[r][c] = to_string(stoi(ans[r][c]) + 1);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (ans[i][j] == "")
                    ans[i][j] = "0";
            }
        }

        return ans;
    }
};