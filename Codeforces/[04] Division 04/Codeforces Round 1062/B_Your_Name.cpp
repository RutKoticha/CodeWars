/**
 * @file B_Your_Name.cpp
 * @author Rut Koticha
 * @date 2026-01-10
 */

#include <iostream>
#include <unordered_map>
#include <print>

void Solve()
{
  int n;
  std::cin >> n;

  std::unordered_map<char, int> frequency;
  char character;
  for (int i = 0; i < n; i++)
  {
    std::cin >> character;
    frequency[character]++;
  }

  for (int i = 0; i < n; i++)
  {
    std::cin >> character;
    frequency[character]--;
  }

  for (auto [_, characterFrequency] : frequency)
  {
    if (characterFrequency)
    {
      std::println("NO");
      return;
    }
  }
  std::println("YES");
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
