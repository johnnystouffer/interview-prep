#include "../libraries.h"

using namespace std;

/**
 * 70. Climbing Stairs
 * 
 * Memoization is how I did this... wooo... I need to get better with dynamic programming
 * it is really hard for me to visualize what I need to do.
 */

class Solution {
public:
    // map for memoization
    unordered_map<int, int> mapping {
        {2, 2},
        {1, 1},
    };

    int climbStairs(int n) {
        if (mapping.find(n) == mapping.end()) {
            mapping[n] = climbStairs(n-1) + climbStairs(n-2);
        }  
        return mapping[n];
    }
};

/**
 * I did it both ways, memoization and tabulation
 * memoization is more intuitive for me, however tabulization is better
 * so I want to get better at it.
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++) {
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n-1];
    }
};