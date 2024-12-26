// Date: Thu, 26 Dec 2024 06:50:43 +0000
// Language: C++ 23 (gcc 12.2)
#include <iostream>
#include <ranges>
#include <utility>
#include <vector>
int main() {
  unsigned N, M;
  std::cin >> N >> M;
  std::vector<std::pair<unsigned, unsigned>> AB(M);
  for (auto &i : AB) {
    auto &[A, B] = i;
    std::cin >> A >> B;
    A--;
    B--;
  }
  std::vector<int> parent(N, -1);
  for (auto i : std::views::iota(0u, N)) {
  }
  auto root = [&](auto self, int a) -> int {
    if (parent[a] < 0) return a;
    parent[a] = self(self, parent[a]);
    return parent[a];
  };
  auto same = [&](int a, int b) -> bool {
    return root(root, a) == root(root, b);
  };
  auto merge = [&](int a, int b) {
    a = root(root, a);
    b = root(root, b);
    parent[a] = b;
  };
  int ans = 0;
  for (auto [A, B] : AB) {
    if (same(A, B)) {
      ++ans;
      continue;
    }
    merge(A, B);
  }
  std::cout << ans << std::endl;
}
