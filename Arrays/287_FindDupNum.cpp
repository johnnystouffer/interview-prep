#include "../libraries.h"

using namespace std;

/**
 * 287. Find Duplicate Numbers
 * 
 * TODO: The tortoise and hare algorithm
 * 
 * Another good one, like it.
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (fast == slow) {
                break;
            };
        }
        
        int slow2 = nums[0];
        while(slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};