#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {

            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> box;

            for(int j = 0; j < 9; j++) {

                // Check row
                if(board[i][j] != '.') {
                    if(row.count(board[i][j]))
                        return false;
                    row.insert(board[i][j]);
                }

                // Check column
                if(board[j][i] != '.') {
                    if(col.count(board[j][i]))
                        return false;
                    col.insert(board[j][i]);
                }

                // Check 3x3 box
                int box_row = 3 * (i / 3) + j / 3;
                int box_col = 3 * (i % 3) + j % 3;

                if(board[box_row][box_col] != '.') {
                    if(box.count(board[box_row][box_col]))
                        return false;
                    box.insert(board[box_row][box_col]);
                }
            }
        }

        return true;
    }
};
