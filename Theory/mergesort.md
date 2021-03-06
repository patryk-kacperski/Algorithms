# Merge Sort

### Description of problem

Given an array _A_ of size _n_ we want to sort it with respect to a binary predicate _p_

### Input

- Array _A_ of size _n_
- Binary predicate _p_

### Output

- Array _A_ sorted with respect to predicate _p_

### Pseudocode

#### 1. Merge sort procedure
```python
mergesort(low, high):
  mid := floor((low + high) / 2)
  mergesort(low, mid)
  mergesort(mid + 1, high)
  merge(low, high)
```

#### 2. Merge procedure
```python
merge(low, high):
  v := []
  v.resize(high - low + 1)
  mid := floor((low + high) / 2)
  i := low
  j := mid + 1
  k := 0
  while i <= mid and j <= high:
    if p(S[i], S[j]):
      //ended here
```

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
  return low
```

### Complexity
time: O(log(n))
space: O(1)

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

so we assign

`high := mid = 5`

since

`low < high`

we assign

`mid := floor(0 + 5) / 2) = 2`

_A_ = [1(**low**), 2, 4(**mid**), 7, 12, 14(**high**), 17, 21, 25, 29, 31, 37]

now we check

`p(A[2], 7) = p(4, 7) = true`

so we assign

`low := mid + 1 = 3`

since

`low < high`

we assign

`mid := floor((3 + 5) / 2) = 4`

_A_ = [1, 2, 4, 7(**low**), 12(**mid**), 14(**high**), 17, 21, 25, 29, 31, 37]

now we check

`p(A[4], 7) = p(12, 7) = false`

so we assign

`high := mid = 4`

since 

`low < high`

we assign

`mid := floor((3 + 4) / 2) = 3`

_A_ = [1, 2, 4, 7(**low**)(**mid**), 12(**high**), 14, 17, 21, 25, 29, 31, 37]

now we check

`p(A[3], 7) = p(7, 7) = false`

so we assign

`high := mid = 3`

since 

`low = high`

we finished search algorithm. Now we need to check, weather object we found is the one we're looking for

since

`p(7, 7) = false`

so

`p(7, 7) or p(7, 7) = false`

and

`low = 3`

then the answer is 3, because element 7 has index 3 in array _A_

##### Example 2

Assume
- _A_ = [1(**low**), 2, 4, 7, 12, 14(**mid**), 17, 21, 25, 29, 31, 37(**high**)], so _n_ = 12
- _p_(a, b) = { a < b }
- _x_ = 32

We start with assigning

`low := 0`, `high := 11`

so

`mid := floor((0 + 11) / 2) = 5`

now we check

`p(A[5], 32) = p(14, 32) = true`

so we assign

`low := mid + 1 = 6`

since

`low < high`

we assign

`mid := floor(6 + 11) / 2) = 8`

_A_ = [1, 2, 4, 7, 12, 14, 17(**low**), 21, 25(**mid**), 29, 31, 37(**high**)]

now we check

`p(A[8], 32) = p(25, 32) = true`

so we assign

`low := mid + 1 = 9`

since

`low < high`

we assign

`mid := floor((9 + 11) / 2) = 10`

_A_ = [1, 2, 4, 7, 12, 14, 17, 21, 25, 29(**low**), 31(**mid**), 37(**high**)]

now we check

`p(A[10], 32) = p(31, 32) = true`

so we assign

`low := mid + 1 = 11`

since 

`low = high`

we finished search algorithm. Now we need to check, weather object we found is the one we're looking for

since

`p(37, 32) = false, p(32, 37) = true`

so

`p(37, 32) or p(32, 37) = true`

then the answer is -1, because element 32 does not appear in array _A_
