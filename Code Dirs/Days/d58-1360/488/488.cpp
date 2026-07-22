// Link: https://leetcode.com/problems/zuma-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^(N+M)) where N is the length of the board and M is the length of the hand. The worst case occurs when we have to try all possible combinations of insertions and removals, leading to an exponential number of states to explore.
// SC: O(2^(N+M)) for the memoization table. The memoization table stores the results of previously computed states, which can be up to 2^(N+M) in size, where N is the length of the board and M is the length of the
// Approach:
//  1. Identify the most frequent color in the hand to use as a separator for potential insertions.
//  2. Implement a recursive DFS function with memoization to explore all possible insertions and removals of balls on the board.
//  3. Use bit manipulation to represent the state of the board and hand, allowing for efficient state transitions and checks.
//  4. Implement a cascade removal function to handle the removal of groups of 3 or more consecutive balls of the same color, including chain reactions.
//  5. Return the minimum number of insertions needed to clear the board, or -1 if it's impossible.
class Solution
{
public:
    int findMinStep(string in_board, string in_hand)
    {
        // Identify the most frequent color
        unordered_map<char, int> ch2count;
        for (char c : in_hand)
            ++ch2count[c];
        auto count_ch = ch2count | ::views::transform([](const auto &ch_c)
                                                      { return make_pair(ch_c.second, ch_c.first); }) |
                        ::ranges::to<vector<pair<int, char>>>();
        ::sort(count_ch.begin(), count_ch.end());

        // Try the basic approach: insert + immediate shrink operations only
        int res = find_min_shrinks(in_board, in_hand);
        memo.clear();

        // Use the most frequent ball color as a "separator"
        // Insert it between adjacent identical balls to prevent potential
        // undesired shrinks. This is just a heuristic that passes all tests, no
        // proof if it covers all edge cases.
        const char sep = count_ch.back().second;
        string hand = in_hand;
        for (int i = 0; i < ssize(hand) && hand.length() == in_hand.length();
             ++i)
            if (hand[i] == sep) // Remove one instance of the separator - will
                                // immediately use it below
                hand.erase(i, 1);
        for (int i = 1; i < ssize(in_board); ++i)
        {
            if (in_board[i] == in_board[i - 1] && in_board[i - 1] != sep &&
                in_board[i] != sep)
            {
                string board = in_board;
                // If we have AA and insert B to get ABA, we might later add A's
                // to both sides to form AAABAA, creating removable groups
                board.insert(i, 1, sep);
                res = min(res, find_min_shrinks(board, hand) + 1);
                memo.clear();
            }
        }

        return res < kInfSteps ? res : -1;
    }

private:
    static constexpr int kMaxBoardLen = 17;
    static constexpr int kMaxHandSize = 5;
    static constexpr int kHandMaskBits = (1 << kMaxHandSize) - 1;
    static constexpr int kMaxMaskSize = 1 << (kMaxBoardLen + kMaxHandSize);

    static constexpr int kInfSteps = kMaxHandSize + 1;

    // Game state representation
    string board;
    string hand;
    array<int, kMaxHandSize> hand_ch_count; // Count of each color in hand
    array<int, kMaxHandSize>
        hand_ch_2_mask_beg; // Starting bit position for each color in hand mask

    // Memoization with offset technique.
    struct MemoData
    {
        int d[kMaxMaskSize];
        int offset = 0;
        MemoData() { memset(d, -1, sizeof(d)); }
        void clear()
        {
            offset += kInfSteps + 1;
        } // Invalidate all previous entries
    };

    static MemoData memo;

    // Core algorithm: Find minimum insertions needed using DFS with memoization
    int find_min_shrinks(string in_board, string in_hand)
    {
        board = ::move(in_board);
        hand = ::move(in_hand);
        // Normalize colors to integers 0-4 for efficient bit manipulation
        norm(board);
        norm(hand);

        ::sort(hand.begin(), hand.end());
        for (int c = 0, i = 0; c < kMaxHandSize; ++c)
        {
            int beg = i;
            while (i < ::ssize(hand) && hand[i] == c)
                ++i;
            hand_ch_count[c] = i - beg;
            hand_ch_2_mask_beg[c] = beg;
        }

        int full_board_mask = (1 << board.length()) - 1;
        int full_hand_mask = (1 << hand.length()) - 1;

        // State encoding: high bits = board mask, low bits = hand mask
        int res = dfs((full_board_mask << kMaxHandSize) | full_hand_mask);
        return res;
    }

    int dfs(int mask)
    {
        int hand_mask = mask & kHandMaskBits;
        int board_mask = mask >> kMaxHandSize;
        if (board_mask == 0)
            return 0; // Base case: all balls removed from board

        int &mres = memo.d[mask]; // Memoization lookup
        if (mres >= memo.offset)
            return mres - memo.offset;

        const int L = ::ssize(board);
        int res = kInfSteps;

        // Strategy 1: Insert ball between existing groups to form groups of 3+
        // char prev_ch = -1;
        for (int l = -1, r = 0; r < L; ++r)
        {
            int rbit = 1 << r;
            const char ch = board[r];
            if (board_mask & rbit)
            {
                // assert(prev_ch != 123);
                if (l < 0 || board[l] != ch)
                {
                    l = r;
                }
                else if (hand_ch_count[ch] > 0)
                {
                    // Found consecutive identical balls l, r and we have
                    // matching ball in hand Insert one ball to create group of
                    // 3+ for removal
                    int board_mask_back = board_mask;
                    // assert(board_mask & (1 << l));
                    --hand_ch_count[ch]; // Use one ball from hand
                    int hand_bit = 1 << hand_ch_2_mask_beg[ch];
                    // assert(hand_mask & hand_bit);
                    hand_mask ^= hand_bit;
                    ++hand_ch_2_mask_beg[ch];

                    // Simulate ball insertion and cascade removal
                    board_mask = wipe_cascade_group3x(board_mask, 1, l, r);
                    res = min(
                        res, 1 + dfs((board_mask << kMaxHandSize) | hand_mask));

                    // Backtrack: restore state
                    --hand_ch_2_mask_beg[ch];
                    hand_mask ^= hand_bit;
                    ++hand_ch_count[ch];
                    board_mask = board_mask_back;
                }
            }
            // if (board_mask & rbit)
            //     prev_ch = ch;
        }

        // Strategy 2: Insert 2 balls of same color next to existing ball
        for (int i = 0; i < L; ++i)
        {
            int ibit = 1 << i;
            const char ch = board[i];
            if ((board_mask & ibit) && hand_ch_count[ch] > 1)
            {
                // We have 2+ balls of same color as board position i
                int board_mask_back = board_mask;
                // assert(board_mask & ibit);
                hand_ch_count[ch] -= 2; // Use 2 balls from hand
                // assert(hand_mask & (1 << hand_ch_2_mask_beg[ch]));
                hand_mask ^= (1 << hand_ch_2_mask_beg[ch]);
                ++hand_ch_2_mask_beg[ch];
                // assert(hand_mask & (1 << hand_ch_2_mask_beg[ch]));
                hand_mask ^= (1 << hand_ch_2_mask_beg[ch]);
                ++hand_ch_2_mask_beg[ch];

                // Simulate insertion of 2 balls next to existing ball (creates
                // group of 3)
                board_mask = wipe_cascade_group3x(board_mask, 2, i, i + 1);
                res =
                    min(res, 2 + dfs((board_mask << kMaxHandSize) | hand_mask));

                // Backtrack: restore state
                --hand_ch_2_mask_beg[ch];
                hand_mask ^= (1 << hand_ch_2_mask_beg[ch]);
                --hand_ch_2_mask_beg[ch];
                hand_mask ^= (1 << hand_ch_2_mask_beg[ch]);
                hand_ch_count[ch] += 2;
                board_mask = board_mask_back;
            }
            // if (board_mask & ibit)
            //     prev_ch = ch;
        }

        mres = res + memo.offset; // Store result in memo with offset
        return res;
    }

    void norm(string &s)
    {
        for (char &c : s)
        {
            switch (c)
            {
            case 'R':
                c = 0;
                break;
            case 'Y':
                c = 1;
                break;
            case 'B':
                c = 2;
                break;
            case 'G':
                c = 3;
                break;
            case 'W':
                c = 4;
                break;
            }
        }
    }

    // Simulate cascade removal: remove groups of 3+ balls and handle chain
    // reactions This implements the core Zuma rule: when 3+ consecutive
    // same-color balls form, remove them Continue until no more groups can be
    // removed
    int wipe_cascade_group3x(int board_mask, int group_size, int l, int r)
    {
        const int L = board.length();

        int res_board_mask = board_mask;

        // Cascade removal loop: keep removing groups until no more groups of 3+
        // exist
        for (;; group_size = 0)
        {
            // Find leftmost ball in current group
            while (l >= 0 && !(board_mask & (1 << l)))
                --l;
            if (l < 0)
                break;
            board_mask ^= 1 << l;
            ++group_size;
            const char ch = board[l];

            // Expand group leftward: find all consecutive balls of same color
            --l;
            while (true)
            {
                while (l >= 0 && !(board_mask & (1 << l)))
                    --l;
                if (l < 0 || board[l] != ch)
                    break;
                board_mask ^= 1 << l;
                ++group_size;
                --l;
            }

            // Expand group rightward: find all consecutive balls of same color
            while (true)
            {
                while (r < L && !(board_mask & (1 << r)))
                    ++r;
                if (r >= L || board[r] != ch)
                    break;
                board_mask ^= 1 << r;
                ++group_size;
                ++r;
            }

            if (group_size < 3)
                break;                   // Check if group is large enough
            res_board_mask = board_mask; // Group removed, update result
        }

        return res_board_mask;
    }
};

Solution::MemoData Solution::memo{};