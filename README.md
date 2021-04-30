# stack_sort_algorithm: effective stack sorting algorithm using another stack

It is an algorithm based on another sorting algorithm - insertion sort. The main task is to sort the sequence of unique integers pushed into the stack, given the second empty stack. To do this we have the following operations:

**sa** : *swap a* - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).

**sb** : *swap b* - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).

**ss** : **sa** and **sb** at the same time.

**pa** : *push a* - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.

**pb** : *push b* - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

**ra** : *rotate a* - shift up all elements of stack a by 1. The first element becomes
the last one.

**rb** : *rotate b* - shift up all elements of stack b by 1. The first element becomes
the last one.

**rr** : **ra** and **rb** at the same time.

**rra** : *reverse rotate a* - shift down all elements of stack a by 1. The last element
becomes the first one.

**rrb** : *reverse rotate b* - shift down all elements of stack b by 1. The last element
becomes the first one.

**rrr** : **rra** and **rrb** at the same time.

To illustrate the effect of some of these instructions, let’s sort a random list of integers.
In this example, we’ll consider that both stack are growing from the right.

```
Init a and b:
2
1
3
6
5
8
_ _
a b
```

```
Exec sa:
1
2
3
6
5
8
_ _
a b
```

```
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
```

```
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
```

```
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
```

```
Exec sa:
5 3
6 2
8 1
_ _
a b
```

```
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b
```

This example sort integers from a in 12 instructions.

Allowed functions: write, read, malloc, free, exit.

To run execute `make` and then `./push_swap 7 2 8 3 0 1` (numbers are example).

To check if sorting algorithm work as it should run:
`ARG="7 2 8 3 0 1"; ./push_swap $ARG | ./checker $ARG`

You can also run it with visualization flags:

- "-v" - visualize stacks on every step of sort
- "-c" - visualize and highlight current moving element (use with "-v")
- "-a" - color elements in ascending order with green, in descending in red (use with "-v")
- "-mX" - add animation to step-by-step stacks conditions while sort is going, where "X" is a positive integer from 1 to 100 describing animation speed, less is faster (use with "-v" or "-s")
- "-s" - another type of visualization, showing stacks as colored columns (use with "-mX")

For example: `./push_swap -s -m6 25 13 4 16 22 18 14 19 3 12 10 1 7 15 5 26 24 28 21 20`

![](https://raw.githubusercontent.com/mandarin10101/stack_sort_algorithm/main/example-s-m6.gif)



<details>
<summary>Spoiler (Results)</summary>
There are the worst  results of this algorithm in sorting:
<ul><li>3 numbers - 2 moves</li>
<li>4 numbers - 9 moves</li>
<li>5 numbers - 11 moves</li>
<li>6 numbers - 18 moves</li>
<li>10 numbers - 37 moves</li>
<li>50 numbers - 283 moves</li>
<li>100 numbers - 674 moves</li>
<li>500 numbers - 4894 moves</li>
<li>1000 numbers - 11530 moves</li>
</ul>
</details>