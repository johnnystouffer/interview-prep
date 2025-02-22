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

/**
 * Update solution
 * 
 * does not look as glamorous but that is okay 
 * because it does the same thing and is easier to figure
 * out than the thing above it.
 */
class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> q;
            for (int stone : stones) {
                q.push(stone);
            }
    
            while(!q.empty()) {
                if (q.size() == 1) {
                    int val = q.top();
                    q.pop();
                    return val;
                }
    
                int left = q.top();
                q.pop();
                int right = q.top();
                q.pop();
    
                left -= right;
                if (left > 0) {
                    q.push(left);
                }
            }
            return 0;
        }
        
    };

