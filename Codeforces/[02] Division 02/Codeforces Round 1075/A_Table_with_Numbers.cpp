/**
 * @file A_Table_with_Numbers.cpp
 * @author Rut Koticha
 * @date 2026-01-23
 * @brief
 */

#include <iostream>
#include <print>
#include <vector>
#include <unordered_map>

void Solve()
{
  int n, h, l;
  std::cin >> n >> h >> l;

  std::vector<int> array(n);
  std::unordered_map<int, int> frequency;
  for (int& i : array)
  {
    std::cin >> i;
    frequency[i]++;
  }

  // Remove those which are > maxPossible
  int maxPossible = std::max(h, l);
  for (auto [number, _] : frequency)
  {
    if (number > maxPossible)
      frequency.erase(number);
  }

  int i = h;
  int j = l;
  int sum = 0;
  bool changed = true;

  while (changed)
  {
    changed = false;
    if (frequency[i] && frequency[j])
    {
      int common = std::max(frequency[i], frequency[j]);
      sum += common;

      frequency[i] -= common;
      frequency[j] -= common;
      i--;
      j--;
      changed = true;
    }
  }

  std::println("{}", sum);
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
