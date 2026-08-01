// Link: https://leetcode.com/problems/count-number-of-trapezoids-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n), SC: O(n^2)
//  Approach:
//  1. For each pair of points, we can create an edge.
//  2. We can represent the edge as a line equation in the form of ax + by = c, where a = y2 - y1, b = x1 - x2
//  3. We can sort the edges based on their slope (a/b) and length
//  4. For each group of edges with the same slope, we can count the number of trapezoids and parallelograms formed by these edges.
//  5. The number of trapezoids formed by edges with the same slope is equal to the number of pairs of edges with the same slope, which is (n * (n - 1)) / 2, where n is the number of edges with the same slope.
//  6. The number of parallelograms formed by edges with the same slope is equal to the number of pairs of edges with the same length, which is (m * (m - 1)) / 2, where m is the number of edges with the same length.
//  7. The final answer is the number of trapezoids formed by edges with the same slope minus the number of parallelograms formed by edges with the same length divided by 2, since each parallelogram is counted twice.
class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        class Edge
        {
        public:
            int a;
            int b;
            int c;

            Edge(const std::vector<int> &point_1,
                 const std::vector<int> &point_2)
            {
                a = point_2[1] - point_1[1];
                b = point_1[0] - point_2[0];
                c = a * point_1[0] + b * point_1[1];
                if ((b == 0 && a < 0) || b < 0)
                {
                    a = -a;
                    b = -b;
                    c = -c;
                }
            }

            auto operator<=>(const Edge &other) const
            {
                if (const auto compare_1 = ((a * other.b) <=> (other.a * b));
                    compare_1 != 0)
                    return compare_1;
                if (b == 0)
                    return (static_cast<long long>(c) * other.a) <=>
                           (static_cast<long long>(other.c) * a);
                return (static_cast<long long>(c) * other.b) <=>
                       (static_cast<long long>(other.c) * b);
            }

            int length2() const { return a * a + b * b; }
        };

        const int point_count = points.size();
        std::vector<Edge> edges;
        edges.reserve(point_count * (point_count - 1) / 2);
        for (int i = 0; i < point_count; ++i)
        {
            for (int j = i + 1; j < point_count; ++j)
            {
                edges.emplace_back(points[i], points[j]);
            }
        }
        std::sort(edges.begin(), edges.end());
        int trapezoid_count = 0;
        int parallelogram_count = 0;
        int same_slope_count = 0;
        std::unordered_map<int, int> length2_count;
        int left = 0;
        while (left < edges.size())
        {
            int right = left;
            while (right + 1 < edges.size() && edges[right + 1] <=> edges[left] == 0)
                ++right;
            trapezoid_count += same_slope_count * (right - left + 1);
            for (int i = left; i <= right; ++i)
            {
                if (const auto entry = length2_count.find(edges[i].length2());
                    entry != length2_count.end())
                    parallelogram_count += entry->second;
            }
            if (right + 1 == edges.size() ||
                edges[left].a * edges[right + 1].b !=
                    edges[right + 1].a * edges[left].b)
            {
                same_slope_count = 0;
                length2_count.clear();
            }
            else
            {
                same_slope_count += (right - left + 1);
                for (int i = left; i <= right; ++i)
                    ++length2_count[edges[i].length2()];
            }
            left = right + 1;
        }
        return trapezoid_count - parallelogram_count / 2;
    }
};
