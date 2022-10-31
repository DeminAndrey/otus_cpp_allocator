#include "allocator.h"
#include "list.h"

#include <map>
#include <functional>
#include <iostream>

int factorial(int number) {
    int ans = 1;
    for (int i = 2; i <= number; ++i)
        ans *= i;
    return ans;
}

void fillMap(std::map<int, int>& map) {
  for (int i = 0; i < 10; ++i) {
    map.emplace(i, factorial(i));
  }
}

void fillList(ForwardList<int>& list) {
  auto last = list.begin();
  for (int i = 0; i < 10; ++i) {
    last = list.insertAfter(last, i);
  }
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& stream, const std::pair<T, U>& pair) {
  stream << pair.first << ' ' << pair.second;
  return stream;
}

template <typename Container>
void printContainer(const Container& container) {
  for (const auto& element : container) {
    std::cout << element << '\n';
  }
}

int main() {
  std::map<int, int> map_std_alloc;

  std::map<
      int,
      int,
      std::less<int>,
      Allocator<std::pair<const int, int>, 10>> map_my_alloc;

  ForwardList<int> list_std_alloc;
  ForwardList<int, Allocator<int, 10>> list_my_alloc;
/*
  fillMap(map_std_alloc);
  fill_map(map_my_alloc);
  fillList(list_std_alloc);
  fillList(list_my_alloc);

  std::cout << "\nmap_std_alloc:\n";
  printContainer(map_std_alloc);
  std::cout << "\nmap_my_alloc:\n";
  print_container(map_my_alloc);
  std::cout << "\nlist_std_alloc:\n";
  printContainer(list_std_alloc);
  std::cout << "\nlist_my_alloc:\n";
  printContainer(list_my_alloc);
  */
}
