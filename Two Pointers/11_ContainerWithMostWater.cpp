#include "../libraries.h"

using namespace std;

/**
 * 11. Container with Most Water
 * 
 * A very confusing one because of the problem statement
 * however one thing to remember is when in dont consider every solution
 * originally I just said "move if th enext one is bigger" but that does work for certain test cases.
 * instead 
 */

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i = 0, j = height.size() - 1;
            int maxArea = 0;
    
            while (i < j) {            
                maxArea = max(min(height[i], height[j]) * (j-i), maxArea);
                if (height[i] < height[j]) { ++i; }
                else { --j; }
            }
            return maxArea;
        }
    };