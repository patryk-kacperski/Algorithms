# Binary search

### Description of problem

Given an array _A_ sorted with respect to a binary predicate _p_ we want to find an index of element _x_ if it is containded in _A_

### Input

- Array _A_ sorted with respect to binary predicate _p_
- Integer _n_ being the number of elements in _A_
- Element _x_ of type that is stored in _A_

### Output

- Integer _i_ being equal to
  - index of element _x_ in array _A_ if _A_ contains _x_
  - -1 otherwise

### Pseudocode

```python
low := 0
high := n - 1
while low < high:
  mid := floor((low + high) / 2)
  if p(A[mid], x):
    low := mid + 1
  else:
    high := mid
if p(A[low], x) or p(x, A[low]):
  return -1
else:
  return A[low]
```

### Examples

##### Example 1

Assume
- _A_ = [1(**low**), 2, 4, 7, 12, 14(**mid**), 17, 21, 25, 29, 31, 37(**high**)], so _n_ = 12
- _p_(a, b) = { a < b }
- _x_ = 7

We start with assigning

`low := 0`, `high := 11`

so

`mid := floor((0 + 11) / 2) = 5`

now we check

`p(A[5], 7) = p(14, 7) = false`
