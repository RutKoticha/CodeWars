/**
 * @file A_Divisible_Permutation.cpp
 * @author Rut Koticha
 * @date 2026-01-29
 */

#include <iostream>
#include <vector>

void Solve()
{
  int n;
  std::cin >> n;

  std::vector<int> pattern(n);

  int left = 1, right = n;
  bool takeFromRight = true;

  for (int i = n - 1; i >= 0; i--)
  {
    if (takeFromRight)
    {
      pattern[i] = right;
      right--;
    }
    else
    {
      pattern[i] = left;
      left++;
    }
    takeFromRight = !takeFromRight;
  }

  for (int number : pattern)
    std::cout << number << " ";

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
