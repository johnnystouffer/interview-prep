#include <vector>
#include <queue>

using namespace std;

/**
 * 1046. Last Reaining Stone
 * 
 * Use a priority queue, 
 */

 class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> pq(stones.begin(), stones.end());
    
            while (pq.size() > 1) {
                int left = pq.top();
                pq.pop();
                int right = pq.top();
                pq.pop();
    
                if (left != right) { pq.push(left - right); } 
            }
    
            return pq.empty() ? 0 : pq.top();
        }
};