// Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

#include <bits/stdc++.h>
using namespace std;

struct State
{
    int maxLength;        // The longest subarray ending at this state
    int suffixLink;       // A "fallback" pointer if our current match breaks
    int transitions[101]; // Next states based on the next number (0 to 100)

    State()
    {
        maxLength = 0;
        suffixLink = -1; // -1 means it points to nothing (the root)
        // Initialize all transitions to -1 (meaning no path exists yet)
        memset(transitions, -1, sizeof(transitions));
    }
};

// TC: O(n + m) and SC: O(n)
//   Approach:
//   1. We build a Suffix Automaton for the first array (nums1).
//   2. Then, we feed the second array (nums2) through the automaton to find the longest matching subarray.
//   3. The automaton allows us to efficiently track the longest subarray that appears in both arrays without having to check every possible subarray explicitly.
//   4. The Suffix Automaton is built in linear time relative to the size of nums1, and the matching process is linear relative to the size of nums2, resulting in an overall time complexity of O(n + m), where n and m are the lengths of nums1 and nums2 respectively.
//   5. The space complexity is O(n) due to the storage of the automaton states, which can be at most twice the size of nums1.
class Solution
{
    vector<State> automaton;
    int lastState;

    // Adds a new number to the automaton and updates the graph
    void extend(int number)
    {
        int currentState = automaton.size();
        automaton.emplace_back(); // Create a new empty state

        // The length of this new state is simply the previous longest + 1
        automaton[currentState].maxLength = automaton[lastState].maxLength + 1;

        int p = lastState;

        // Step 1: Follow suffix links backward.
        // If these previous states don't have a path for 'number', create one!
        while (p != -1 && automaton[p].transitions[number] == -1)
        {
            automaton[p].transitions[number] = currentState;
            p = automaton[p].suffixLink;
        }

        // Step 2: Did we reach the very beginning without finding this number?
        if (p == -1)
        {
            automaton[currentState].suffixLink = 0; // Link back to the root
        }
        else
        {
            // We found a state 'p' that already has a path for 'number'.
            int nextState = automaton[p].transitions[number];

            // Case A: The transition is a direct, continuous extension. Perfect!
            if (automaton[p].maxLength + 1 == automaton[nextState].maxLength)
            {
                automaton[currentState].suffixLink = nextState;
            }
            // Case B: The transition skips numbers. We must split the state!
            else
            {
                int cloneState = automaton.size();
                automaton.emplace_back();

                // The clone copies everything from nextState except the maxLength
                automaton[cloneState].maxLength = automaton[p].maxLength + 1;
                memcpy(automaton[cloneState].transitions, automaton[nextState].transitions, sizeof(automaton[nextState].transitions));
                automaton[cloneState].suffixLink = automaton[nextState].suffixLink;

                // Redirect paths that used to point to nextState to the new clone
                while (p != -1 && automaton[p].transitions[number] == nextState)
                {
                    automaton[p].transitions[number] = cloneState;
                    p = automaton[p].suffixLink;
                }

                // Both the current state and the old nextState now fall back to the clone
                automaton[nextState].suffixLink = cloneState;
                automaton[currentState].suffixLink = cloneState;
            }
        }

        lastState = currentState;
    }

public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        // Initialize the automaton with the root state
        automaton.emplace_back();
        lastState = 0;

        // ---------------------------------------------------------
        // PHASE 1: Build the Machine using nums1
        // ---------------------------------------------------------
        // A Suffix Automaton will never have more than 2 * N states.
        // Reserving memory prevents expensive vector reallocations.
        automaton.reserve(nums1.size() * 2);

        for (int num : nums1)
        {
            extend(num);
        }

        // ---------------------------------------------------------
        // PHASE 2: Feed nums2 through the Machine
        // ---------------------------------------------------------
        int longestMatch = 0;
        int currentLength = 0;
        int currentState = 0;

        for (int num : nums2)
        {
            // If the machine gets stuck (no path for 'num'), we follow the
            // suffix links backward until we find a path, or hit the root.
            while (currentState != -1 && automaton[currentState].transitions[num] == -1)
            {
                currentState = automaton[currentState].suffixLink;

                // If we fall back to a valid state, our new matching streak length
                // becomes the maximum length of that fallback state.
                if (currentState != -1)
                {
                    currentLength = automaton[currentState].maxLength;
                }
                else
                {
                    currentLength = 0;
                }
            }

            // If we found a valid path for 'num'
            if (currentState != -1)
            {
                currentState = automaton[currentState].transitions[num]; // Take the path
                currentLength++;                                         // Increase streak
                longestMatch = max(longestMatch, currentLength);         // Update max
            }
            // If we hit the root and STILL didn't find the number, reset to 0
            else
            {
                currentState = 0;
                currentLength = 0;
            }
        }

        return longestMatch;
    }
};