/**
 * @file A_Skibidus_and_Amogu.cpp
 * @author Rut Koticha
 * @date 2026-01-12
 */

#include <iostream>
#include <string>

void Solve()
{
  std::string input;
  std::cin >> input;

  input.erase(input.size() - 1);
  input.back() = 'i';

  std::cout << input << std::endl;
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
