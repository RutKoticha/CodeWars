/**
 * @file B_XOR_Array.cpp
 * @author Rut Koticha
 * @date 2026-01-09
 */

#include <iostream>
#include <vector>
#include <print>

void Solve()
{
  int n, l, r;
  std::cin >> n >> l >> r;

  std::vector<int> numbers(n);
  numbers.at(0) = 1;
  numbers.at(1) = 2;

  for (int i = 2; i < n; i++)
    numbers.at(i) = (i + 1);

  numbers.at(r - 1) = l - 1;

  for (int i = 0; i < n; i++)
    std::print("{} ", numbers.at(i));

  std::println("");
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
