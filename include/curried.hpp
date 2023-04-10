#pragma once

#include "bind.hpp"
#include <functional>

namespace rd {
template <typename F> struct curried {
private:
  F f;

public:
  constexpr explicit curried(F &&f_p) noexcept : f(std::forward<F>(f_p)) {}

  template <typename... Xs>
    requires std::invocable<F, Xs...>
  constexpr auto operator()(Xs &&...xs) const {
    return std::invoke(f, std::forward<Xs>(xs)...);
  }

  template <typename... Xs> constexpr auto operator()(Xs &&...xs) const {
    using FType = decltype(rd::bind_back(f, std::forward<Xs>(xs)...));
    return curried<FType>{rd::bind_back(f, std::forward<Xs>(xs)...)};
  }
};

} // namespace rd
