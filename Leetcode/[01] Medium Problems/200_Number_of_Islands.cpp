/**
 * @file 200_Number_of_Islands.cpp
 * @author Rut Koticha
 * @date 2026-01-01
 */

#include <vector>

struct Position {
  int row, col;
};

class Solution {
private: /* <---------- Data ----------> */
  std::vector<std::vector<char>> m_Grid;
  std::vector<std::vector<bool>> m_Visited;

  size_t m_Length;
  size_t m_Width;

private: /* <---------- Methods ----------> */
  bool CanGoUp(Position position);
  bool CanGoDown(Position position);
  bool CanGoLeft(Position position);
  bool CanGoRight(Position position);
  void VisitIsland(Position startingPosition);
  int GridValueAt(Position position);

public:/* <---------- Methods ----------> */
  int numIslands(std::vector<std::vector<char>>& grid);
};

bool Solution::CanGoUp(Position position)
{
  return position.row > 0;
}

bool Solution::CanGoDown(Position position)
{
  return position.row < m_Width - 1;
}

bool Solution::CanGoLeft(Position position)
{
  return position.col > 0;
}

bool Solution::CanGoRight(Position position)
{
  return position.col < m_Length - 1;
}

void Solution::VisitIsland(Position position)
{
  if (m_Visited.at(position.row).at(position.col))
    return;

  if (!GridValueAt(position))
    return;

  m_Visited.at(position.row).at(position.col) = true;

  if (CanGoRight(position))
  {
    VisitIsland({
        .row = position.row,
        .col = position.col + 1
      });
  }

  if (CanGoDown(position))
  {
    VisitIsland({
        .row = position.row + 1,
        .col = position.col
      });
  }

  if (CanGoLeft(position))
  {
    VisitIsland({
        .row = position.row,
        .col = position.col - 1
      });
  }

  if (CanGoUp(position))
  {
    VisitIsland({
        .row = position.row - 1,
        .col = position.col
      });
  }
}

int Solution::GridValueAt(Position position)
{
  return m_Grid.at(position.row).at(position.col) - '0';
}

int Solution::numIslands(std::vector<std::vector<char>>& grid)
{
  this->m_Grid = grid;
  this->m_Width = grid.size();
  this->m_Length = grid.front().size();

  this->m_Visited.resize(m_Width, std::vector<bool>(m_Length, false));

  unsigned int islands = 0;

  for (int row = 0;row < m_Width;row++)
  {
    for (int col = 0;col < m_Length;col++)
    {
      if (!m_Visited.at(row).at(col) && GridValueAt({ .row = row, .col = col }))
      {
        islands++;
        VisitIsland({ .row = row, .col = col });
      }
    }
  }

  return islands;
}
