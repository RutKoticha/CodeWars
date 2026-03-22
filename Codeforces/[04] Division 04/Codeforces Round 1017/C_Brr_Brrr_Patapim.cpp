/**
 * @file C_Brr_Brrr_Patapim.cpp
 * @author Rut Koticha
 * @date 2026-01-11
 */

#include <iostream>
#include <vector>

void Solve()
{
  int n;
  std::cin >> n;

  int firstValue = ((2 * n) * ((2 * n) + 1)) >> 1;

  std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      std::cin >> grid.at(i).at(j);
    }
  }

  std::vector<int> permutation(2 * n, firstValue);

  // Go along the first row
  for (int i = 0; i < n; i++)
  {
    permutation.at(i + 1) = grid.at(0).at(i);
    firstValue -= permutation.at(i + 1);
  }

  // Go along the last column
  for (int i = 1; i < n; i++)
  {
    permutation.at(i + n) = grid.at(i).at(n - 1);
    firstValue -= permutation.at(i + n);
  }

  permutation.front() = firstValue;

  for (int& number : permutation)
    std::cout << number << " ";

  std::cout << std::endl;
}

int main(int argc, char* argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tests{};
  std::cin >> tests;

  while (tests--)
    Solve();

  return 0;
}
