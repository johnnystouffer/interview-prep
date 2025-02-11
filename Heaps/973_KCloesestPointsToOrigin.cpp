#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/**
 * We are SO FUCKING BACK BABY WOOOOO
 * 
 * Anyways so guess what? yeah, thats right,
 * I did the heap problem without even having
 * to worry about it lets fucking goooo
 * almost first try too
 * 
 * Maybe this is a really easy medium but idc
 * cause I usued to be really scared of this problem
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k >= points.size()) {
            return points;
        }

        // create a min heap (priority queue)
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

        // for each point in points
        for (int point = 0; point < points.size(); point++) {
            // since we are guaranteed xi and yi we can use 0 and 1
            double currDis = calcDistance(points[point][0], points[point][1]);
            pq.push({currDis, point});
        }

        // make a vector to store all of them
        vector<vector<int>> finalVec;
        for (int i = 0; i < k; i++) {
            pair<double, int> newPoint = pq.top();
            pq.pop();

            finalVec.push_back(points[newPoint.second]);

            if (pq.empty()) {
                break;
            }
        }

        return finalVec;
    }

    double calcDistance(int x, int y) {
        return sqrt(pow(x, 2.0) + pow(y, 2.0));
    }
};