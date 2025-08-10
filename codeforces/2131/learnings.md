# A
- Just understand simple problems quickly and focus on relevant aspects, ignore rest

# B
- product of two neighbours must be $<0$ means always alternating $-$ and $+$
- lexicographically smaller array means that first element should also be smaller
- in `for (int i = 0; i < n - 2; i += 2)` instead of using `i += 2` when iterating over always two elements you can also do `i < (n - 1) / 2; i++`
- instead of `if (n % 2 == 1)` you can use shorter `if (n & 1)` odd check. It returns `true` when the last bit is 1, which we only really care about.

# C
- identify invariants (what can the operations not change)
- build equivalence classes of possible residues after operations
- compare two different arrays equivalence classes by taking canonical representative in same way and them comparing the count of values in each class
- always consider just calculating stuff live already through incrementing and decrementing for counts for example

# D
- turning tree into star: 1. choose center vertex 2. attach other vertex if not already part of neighbourhood
- to get minimal operations you find the center vertex with best value for #total leaves - #leaves in neighbourhood
- always think of the goal shape and then backwards how it could have turned into that

# E
- with XOR you already know what you need for the element you XOR with