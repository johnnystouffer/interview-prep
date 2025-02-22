#include "../libraries.h"

using namespace std;

/**
 * 130. Surrounded Regions
 * 
 * A difficult one for sure, because the solution is not a typical
 * one taht I usually do for leetcode. Regardless it is a good problem 
 * especially to think about.
 */

class Solution {
    public:
        /// directions for dfs
        vector<vector<int>> directions = {{1, 0},{0, 1}, {-1, 0}, {0, -1}};
    
        /// check if the coordinates are inBounds
        bool inBounds(int x, int y, vector<vector<char>>& board) {
            if (y < 0 || y >= board.size() ||
                x < 0 || x >= board[0].size()) {
                    return false;
                }
            return true;
        }
    
        /// search through
        void dfs(int x, int y, vector<vector<char>>& board) {
            if (!inBounds(x, y, board) || board[y][x] != 'O') return;
    
            board[y][x] = 'G';
            for (const vector<int>& direction : directions) {
                int nx = direction[0], ny = direction[1];
                dfs(x+nx, y+ny, board);
            }
        }
    
        void solve(vector<vector<char>>& board) {
            // iterate through the board and find any edges that are
            // 'O' then mark all the ones connected to it
            for (int y = 0; y < board.size(); ++y) {
                for (int x = 0; x < board[0].size(); ++x) {
                    if ((x == 0 || x == board[0].size()-1 ||
                        y == 0 || y == board.size() - 1) &&
                        board[y][x] == 'O') {
                            // then we want to mark all the 'O's
                            dfs(x, y, board);
                        }
                }
            }
    
            // now mark them correctly
            for (int y = 0; y < board.size(); ++y) {
                for (int x = 0; x < board[0].size(); ++x) {
                    if (board[y][x] == 'O') { board[y][x] = 'X'; }
                    if (board[y][x] == 'G') { board[y][x] = 'O'; }
                }
            } 
        }
    };