#include <functional>

namespace rd {
constexpr auto flip = []<typename F>(F &&f) {
  return [f = std::forward<F>(f)]<typename A, typename... B>(A && a, B && ...bs)
    requires std::invocable<F, B..., A>
  {
    return std::invoke(f, std::forward<B>(bs)..., std::forward<A>(a));
  };
};
}
