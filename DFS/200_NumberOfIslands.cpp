#include "../libraries.h"

using namespace std;

/**
 * 200. Number of Islands
 * 
 * My favorite!! because it is self explanatory
 * and it teaches a more "advanced" (not really )
 * concept
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid.at(y).size(); x++) {
                if (grid.at(y).at(x) == '1') {
                    dfs(grid, x, y);
                    count += 1;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || y >= grid.size() || x >= grid.at(0).size()) {
            return;
        }

        if (grid.at(y).at(x) == '1') {
            grid.at(y).at(x) = '0';

            dfs(grid, x+1, y);
            dfs(grid, x, y+1);
            dfs(grid, x-1, y);
            dfs(grid, x, y-1);
        }
        return;
    }
};

/**
 * This attempt I did both dfs and bfs, but dfs is better... imo? maybe its a fact
 */

 class Solution {
    public:
        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    
        int numIslands(vector<vector<char>>& grid) {
            int numIslands = 0;
            for (int y = 0; y < grid.size(); ++y) {
                for (int x = 0; x < grid[0].size(); ++x) {
                    if (grid[y][x] == '1') {
                        ++numIslands;
                        exterminAte(grid, y, x);
                    }
                }
            }
            return numIslands;
        }
    
        void exterminate(vector<vector<char>>& grid, int y, int x) {
            if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size()) {
                return;
            }
    
            if (grid[y][x] == '0') { return; }
            grid[y][x] = '0';
    
            for (vector<int>& d : directions) {
                exterminate(grid, y+d[0], x+d[0]);
            }  
            return;
        }
    
        void exterminAte(vector<vector<char>>& grid, int y, int x) {
            queue<vector<int>> q;
            q.push({y, x});
            grid[y][x] = '0';
    
            while (!q.empty()) {
                int cy = q.front()[0], cx = q.front()[1]; q.pop();
    
                for (auto& d : directions) {
                    int ny = cy + d[0], nx = cx + d[1];
                    if (ny >= 0 && ny < grid.size() && nx >= 0 && nx < grid[0].size() && grid[ny][nx] == '1') { 
                        grid[ny][nx] = '0';
                        q.push({ny, nx});
                    }
                }
            }
        }
    };
