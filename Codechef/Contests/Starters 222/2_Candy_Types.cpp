/**
 * @file 2_Candy_Types.cpp
 * @author Rut Koticha
 * @date 2026-01-21
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

bool Comparator(std::pair<int, int> a, std::pair<int, int> b)
{
  if (a.second != b.second)
    return a.second > b.second;

  return a.first < b.first;
}

void Solve()
{
  int n;
  std::cin >> n;

  std::vector<int> numbers(n);
  std::unordered_map<int, int> frequency;

  for (int& number : numbers)
  {
    std::cin >> number;
    frequency[number]++;
  }

  std::pair<int, int> desired = { numbers.front(), frequency[numbers.front()] };

  for (auto candidate : frequency)
  {
    if (Comparator(candidate, desired))
      desired = candidate;
  }

  std::cout << desired.first << std::endl;
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
