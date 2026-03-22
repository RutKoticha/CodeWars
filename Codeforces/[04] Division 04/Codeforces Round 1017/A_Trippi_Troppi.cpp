/**
 * @file A_Trippi_Troppi.cpp
 * @author Rut Koticha
 * @date 2026-01-11
 */

#include <iostream>
#include <string>

void Solve()
{
  std::string ancientName;
  for (int i = 0; i < 3; i++)
  {
    std::cin >> ancientName;
    std::cout << ancientName.front();
  }

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
