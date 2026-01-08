/**
 * Author: Rut Koticha
 * Date: 2025-09-06 14:06
 */

#include <unordered_set>
#include <vector>

using Board = std::vector<std::vector<char>>;
using HashSet = std::unordered_set<char>;

class Solution {
private: /* Data */
  std::vector<HashSet> row_sets;
  std::vector<HashSet> col_sets;
  std::vector<std::vector<HashSet>> chunk_sets;

public: /* Methods */
  bool isValidSudoku(Board &board) {
    int size = 9;

    // Resize the hash sets
    row_sets.resize(9);
    col_sets.resize(9);
    chunk_sets.resize(3, std::vector<HashSet>(3));

    // Loop through all the values
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        char digit = board[i][j];

        // No need to check if the cell is empty
        if (digit == '.') {
          continue;
        }

        // Get the coresponding hash sets
        HashSet &row_set = row_sets[i];
        HashSet &col_set = col_sets[j];
        HashSet &chunk_set = chunk_sets[i / 3][j / 3];

        // Check if the number already exists
        bool in_row = (row_set.find(digit) != row_set.end());
        bool in_col = (col_set.find(digit) != col_set.end());
        bool in_chunk = (chunk_set.find(digit) != chunk_set.end());

        // If present then exit early
        if (in_row || in_col || in_chunk) {
          return false;
        }

        // If not already present
        // put the value in the sets
        row_set.insert(digit);
        col_set.insert(digit);
        chunk_set.insert(digit);
      }
    }

    return true;
  }
};
