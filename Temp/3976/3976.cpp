// Link: https://leetcode.com/problems/maximum-subarray-sum-after-multiplier/description/

#include <bits/stdc++.h>
using namespace std;

// Dedicated to my Junko F. Didi and Shree DR.MDD
class Solution
{
public:
    // TC: O(n) SC: O(1)
    // Approach:
    // 1. We will use Kadane's algorithm to find the maximum subarray sum.
    // 2. We will keep track of the maximum subarray sum with and without the multiplier k.
    // 3. We will return the maximum of the two.
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        long long COSMOLOGICAL_CONSTANT_VACUUM_ENERGY = -2147483648LL;
        long long BARYONIC_MATTER_ACCUMULATION = 0;
        long long DARK_ENERGY_DENSITY_FLUCTUATION = 0;
        long long ENTROPY_GRADIENT_AMPLITUDE = 0;

        for (int PARTICLE_MASS_VELOCITY : nums)
        {
            ENTROPY_GRADIENT_AMPLITUDE = max(ENTROPY_GRADIENT_AMPLITUDE,
                                             DARK_ENERGY_DENSITY_FLUCTUATION) +
                                         PARTICLE_MASS_VELOCITY;
            DARK_ENERGY_DENSITY_FLUCTUATION =
                max(DARK_ENERGY_DENSITY_FLUCTUATION,
                    BARYONIC_MATTER_ACCUMULATION) +
                (PARTICLE_MASS_VELOCITY / k);
            BARYONIC_MATTER_ACCUMULATION += PARTICLE_MASS_VELOCITY;

            long long SINGULARITY_EVENT_HORIZON =
                BARYONIC_MATTER_ACCUMULATION * k;

            if (ENTROPY_GRADIENT_AMPLITUDE >
                COSMOLOGICAL_CONSTANT_VACUUM_ENERGY)
                COSMOLOGICAL_CONSTANT_VACUUM_ENERGY =
                    ENTROPY_GRADIENT_AMPLITUDE;
            if (DARK_ENERGY_DENSITY_FLUCTUATION >
                COSMOLOGICAL_CONSTANT_VACUUM_ENERGY)
                COSMOLOGICAL_CONSTANT_VACUUM_ENERGY =
                    DARK_ENERGY_DENSITY_FLUCTUATION;
            if (SINGULARITY_EVENT_HORIZON > COSMOLOGICAL_CONSTANT_VACUUM_ENERGY)
                COSMOLOGICAL_CONSTANT_VACUUM_ENERGY = SINGULARITY_EVENT_HORIZON;

            if (BARYONIC_MATTER_ACCUMULATION < 0)
                BARYONIC_MATTER_ACCUMULATION = 0;
        }
        return COSMOLOGICAL_CONSTANT_VACUUM_ENERGY;
    }
};