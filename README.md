# Functional

This library contains some functional programming abstractions for C++.
The library is based on C++20 and may contain some abstractions that are part
of C++23 too.

# Table of contents

## rd::compose

Composes 2 functions as:

```cpp
auto gof = rd::compose(g, f); // g.f
```

Here `f` would be applied before `g`. `f` can accept any number of arguments.
`g` can accept only one argument whose type is type of output of `f`.
`gof` can accept same arguments as `f`.

Thanks to [@tartanllama's](https://github.com/tartanllama) ranges implementation.

## rd::bind_back

Bind arguments to last of function and returns the new function:

```cpp
auto sum = [](auto a, auto b, auto c){
  return a + b + c;
};

auto sum_1 = rd::bind_back(2, 3);
sum_1(1);
```

So, how it looks like:

```cpp
F :: (Arg1..., Arg2...) -> R

Then,

G = rd::bind_back(F, arg2...) :: G(Arg1...) -> R
```

## rd::curried

Makes a given function curried.

```cpp
auto sum = rd::curried([](auto a, auto b){
  return a + b;
});

auto sum_with_1 = sum(1);
// sum_with_1(2) == 3;
```

## rd::pipeable

Makes a function pipeable and **reverse curried** as well.

```cpp
auto f = rd::pipeable([](auto a, auto b, auto c){
  // ...
});

auto fc = f(c);
// call fc(a, b)

auto fbc = f(b);

int main(){
  a | f(b, c);
  a | fc(b);
  a | fbc();
  a | fbc;
}
```

## rd::flip

Returns a function such that last argument to given function is first argument
to returned function.

```
F(a, b...) => G(b..., a)
```
