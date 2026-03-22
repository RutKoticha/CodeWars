/**
 * @file A_Square.cpp
 * @author Rut Koticha
 * @date 2026-01-10
 */

#include <iostream>
#include <array>
#include <set>
#include <print>

void Solve()
{
  std::array<int, 4> numbers;
  for (int& number : numbers)
    std::cin >> number;

  std::set<int> uniqueNumbers(numbers.begin(), numbers.end());
  if (uniqueNumbers.size() == 1)
    std::println("YES");
  else
    std::println("NO");
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
