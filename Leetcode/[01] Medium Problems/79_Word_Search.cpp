/**
 * @file 79_Word_Search.cpp
 * @author Rut Koticha
 * @date 2025-12-28
 * @brief Use backtracking to search the entire matrix for word match
 */

#include <vector>
#include <string>

class Solution {
private: /* <---------- Data ----------> */
  std::vector<std::vector<char>> m_Board;   // Board where we are searching for the word
  std::string m_Word;                       // Word that we are searching for
  std::vector<std::vector<bool>> m_Visited; // Visited board for marking places already visited

  size_t m_BoardLength;                     // Length of the board
  size_t m_BoardWidth;                      // Width of the board

private: /* <---------- Methods ----------> */
  bool DoesExist(int positionX, int positionY, size_t index)
  {
    if (m_Visited.at(positionX).at(positionY))
      return false;

    if (index >= m_Word.length())
      return true;

    if (m_Board.at(positionX).at(positionY) != m_Word.at(index))
      return false;

    if (index == m_Word.length() - 1)
      return true;

    m_Visited.at(positionX).at(positionY) = true;
    bool predicate = false;

    // Try right
    if (positionX < (m_BoardLength - 1))
      predicate |= DoesExist(positionX + 1, positionY, index + 1);

    // Try down
    if (!predicate && positionY > 0)
      predicate |= DoesExist(positionX, positionY - 1, index + 1);

    // Try left
    if (!predicate && positionX > 0)
      predicate |= DoesExist(positionX - 1, positionY, index + 1);

    // Try up
    if (!predicate && positionY < (m_BoardWidth - 1))
      predicate |= DoesExist(positionX, positionY + 1, index + 1);

    // m_Visited.at(positionX).at(positionY) = false;
    return predicate;
  }

public: /* <---------- Methods ----------> */
  bool exist(std::vector<std::vector<char>>& board, std::string word)
  {
    this->m_Board = board;
    this->m_Word = word;

    m_BoardLength = board.size();
    m_BoardWidth = board.at(0).size();

    this->m_Visited.resize(board.size(), std::vector<bool>(board.at(0).size(), false));

    for (int positionX = 0; positionX < m_BoardLength; positionX++)
    {
      for (int positionY = 0; positionY < m_BoardWidth; positionY++)
      {
        if (DoesExist(positionX, positionY, 0))
          return true;
      }
    }

    return false;
  }
};
