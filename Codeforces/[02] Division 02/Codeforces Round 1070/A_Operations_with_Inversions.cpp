/**
 * @file A_Operations_with_Inversions.cpp
 * @author Rut Koticha
 * @date 2026-01-08
 */

#include <iostream>

void Solve()
{
  int n;
  std::cin >> n;

  int max, number, operations = 0;
  std::cin >> max;

  for (int i = 1; i < n; i++)
  {
    std::cin >> number;
    if (number >= max)
      max = number;
    else
      operations++;
  }

  std::cout << operations << std::endl;
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
