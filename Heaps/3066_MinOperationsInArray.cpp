#include "../libraries.h"

using namespace std;

/**
 * 3066. Minimum Operations to Exceed Threshold Value II
 * 
 * So this one will be special to me, I did not know what kind
 * of problem it will be but I knew what to do based on the sitation
 * I want to be able to do this more. This felt very good.
 */

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            // make the minheap so the lowest numbers are always in front
            priority_queue<long long, vector<long long>, greater<long long> > orderedNums;
            // counter for each operation
            int count = 0;
    
            // order the numbers
            for (int i = 0; i < nums.size(); ++i) {
                orderedNums.push((long long)nums[i]);
            }
    
    
            while(orderedNums.size() >= 2) {
                long long first = orderedNums.top(); orderedNums.pop();
                long long second = orderedNums.top(); orderedNums.pop();
    
                if (first >= k) {
                    return count;
                }
    
                ++count;
                long long newNum = min(first, second) * 2 + max(first, second);
                
                orderedNums.push(newNum);
            }
            return count;
        }
    };