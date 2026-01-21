/**
 * @file A_Social_Experiment.cpp
 * @author Rut Koticha
 * @date 2026-01-14
 */

#include <iostream>

void Solve()
{
  int n;
  std::cin >> n;

  if (n <= 3)
    std::cout << n << std::endl;
  else
    std::cout << (n & 1) << std::endl;
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
