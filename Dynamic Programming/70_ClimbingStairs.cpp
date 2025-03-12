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