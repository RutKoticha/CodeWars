/**
 * @file C1_Skibidus_and_Fanum_Tax_easy.cpp
 * @author Rut Koticha
 * @date 2026-01-15
 */

#include <iostream>
#include <vector>

void Solve()
{
  int n, m;
  std::cin >> n >> m;

  std::vector<int> arrayA(n), arrayB(m);
  for (int& element : arrayA)
    std::cin >> element;
  for (int& element : arrayB)
    std::cin >> element;
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
