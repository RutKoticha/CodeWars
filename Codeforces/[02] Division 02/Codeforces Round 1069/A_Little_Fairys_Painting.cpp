/**
 * @file A_Little_Fairys_Painting.cpp
 * @author Rut Koticha
 * @date 2026-01-09
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void Solve()
{
  int n;
  std::cin >> n;

  std::vector<int> numbers(n, 0);
  for (int& number : numbers)
    std::cin >> number;

  std::set<int> currentUniqueNumbers(numbers.begin(), numbers.end());
  int currentTotalUnique = currentUniqueNumbers.size();

  int lastNumber = currentTotalUnique;
  while (!currentUniqueNumbers.contains(lastNumber))
  {
    currentUniqueNumbers.insert(lastNumber);
    lastNumber++;
  }

  std::cout << lastNumber << std::endl;
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
