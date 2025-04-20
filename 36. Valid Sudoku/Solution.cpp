class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to keep track of seen numbers in rows, columns, and boxes
        bool rowSeen[9][9] = {false};
        bool colSeen[9][9] = {false};
        bool boxSeen[9][9] = {false};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1'; // Convert to 0-8 index
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    
                    // Check if the number has been seen in the current row, column, or box
                    if (rowSeen[i][num] || colSeen[j][num] || boxSeen[boxIndex][num]) {
                        return false;
                    }
                    
                    // Mark the number as seen in the current row, column, and box
                    rowSeen[i][num] = true;
                    colSeen[j][num] = true;
                    boxSeen[boxIndex][num] = true;
                }
            }
        }
        return true;
    }
};