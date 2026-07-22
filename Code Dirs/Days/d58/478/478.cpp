// Link: https://leetcode.com/problems/generate-random-point-in-a-circle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    //  Approach:
    //  1. To generate a random point uniformly within a circle, we can use polar coordinates.
    //  2. We generate a random angle (degree) between 0 and 2π and a random radius (len) that is scaled by the square root of a uniformly distributed random number to ensure uniform distribution within the circle.
    //  3. The x and y coordinates of the point can then be calculated using the cosine and sine of the angle, respectively, scaled by the random radius and offset by the center coordinates of the circle.
    //  4. The constructor initializes the radius and center coordinates of the circle, as well as precomputes 2π for efficiency.
    //  5. The randPoint method generates and returns a random point within the circle as a vector of doubles.
    Solution(double radius, double x_center, double y_center)
        : radius(radius), x_center(x_center), y_center(y_center),
          pi2(4 * acos(0.0)) {}

    vector<double> randPoint()
    {
        double degree = (static_cast<double>(rand()) / RAND_MAX) * pi2;
        double len = sqrt(static_cast<double>(rand()) / RAND_MAX) * radius;
        return {x_center + len * cos(degree), y_center + len * sin(degree)};
    }

private:
    double radius;
    double x_center;
    double y_center;
    double pi2;
};