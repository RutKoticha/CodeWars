/**
 * @file D_Tung_Tung_Sahur.cpp
 * @author Rut Koticha
 * @date 2026-01-11
 */

#include <iostream>

void Solve()
{
  std::string input, heard;
  std::cin >> input >> heard;

  int i = 0;
  int j = 0;
  while (i < input.size())
  {
    char symbol = input.at(i);

    // Count how many possible occurences can a symbol have
    int minPossible = 0;
    int maxPossible = 0;

    while (i < input.size() && input.at(i) == symbol)
    {
      minPossible++;
      maxPossible += 2;

      i++;
    }

    // Check if total heard are in the range [minPossible, maxPossible]
    // Count how many possible occurences can a symbol have
    int occurence = 0;

    while (j < heard.size() && heard.at(j) == symbol)
    {
      occurence++;
      j++;
    }

    if (occurence > maxPossible || occurence < minPossible)
    {
      std::cout << "NO" << std::endl;
      return;
    }
  }

  if (j != heard.size())
    std::cout << "NO" << std::endl;
  else
    std::cout << "YES" << std::endl;
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
