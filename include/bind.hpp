#pragma once

#include <functional>

namespace rd {
template <class F, class... Args>
constexpr auto bind_back(F &&f, Args &&...args) {
  return [ f_ = std::forward<F>(f),
           ... args_ = std::forward<Args>(args) ](auto &&...other_args)
    requires std::invocable<F &, decltype(other_args)..., Args &...>
  {
    return std::invoke(f_, std::forward<decltype(other_args)>(other_args)...,
                       args_...);
  };
}
} // namespace rd
