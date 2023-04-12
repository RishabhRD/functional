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

## rd::pipeable
