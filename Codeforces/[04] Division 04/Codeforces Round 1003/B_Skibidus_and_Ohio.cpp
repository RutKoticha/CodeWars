/**
 * @file B_Skibidus_and_Ohio.cpp
 * @author Rut Koticha
 * @date 2026-01-15
 */

#include <iostream>
#include <string>

void Solve()
{
  std::string string;
  std::cin >> string;

  bool contiguousCharactersPresent = false;
  for (int i = 1; i < string.length(); i++)
  {
    if (string.at(i - 1) == string.at(i))
    {
      contiguousCharactersPresent = true;
      break;
    }
  }

  if (contiguousCharactersPresent)
    std::cout << 1 << std::endl;
  else
    std::cout << string.length() << std::endl;
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
