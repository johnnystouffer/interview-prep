#include "../libraries.h"

using namespace std;

/**
 * 207. Course Schedule 
 * 
 * The classic topological sort problem
 * This one is easy to understand but slightly confusing to understand
 * in my opinion
 * 
 * Otherwise I am happy I finally did it in C++
 */
class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            if (prerequisites.empty()) { return true; }

            unordered_map<int, int> prereqs;
            unordered_map<int, vector<int> > nextCourses;

            // add all classes taken to the maps
            for (int cl = 0; cl < numCourses; cl++) {
                prereqs[cl] = 0;
                vector<int> nextCl;
                nextCourses[cl] = nextCl;
            }
    
            for (int i = 0; i < prerequisites.size(); i++) {
                // get the next class and the class you need to take it
                int nextClass = prerequisites[i][0], preClass = prerequisites[i][1];
                // add the next class to the prereq
                prereqs[nextClass] += 1;
                // add the next course to the pre classes list
                nextCourses[preClass].push_back(nextClass);
            }
    
            // make a queue and add all prereqs to it
            queue<int> q;
            for (const auto& kv : prereqs) {
                if (kv.second == 0) { q.push(kv.first); }
            }
    
            // go through the queue and add all the next values
            int count = 0;
            while(q.size() > 0) {
                int curr = q.front();
                q.pop();
    
                count += 1;
    
                for (int newClass : nextCourses[curr]) {
                    prereqs[newClass] -= 1;
                    if (prereqs[newClass] == 0) { q.push(newClass); }
                }
            }
            return count == numCourses;
        }
};