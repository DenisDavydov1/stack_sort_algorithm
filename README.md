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



<details>
	<summary>Spoiler (Example)</summary>
	To illustrate the effect of some of these instructions, let’s sort a random list of integers.
In this example, we’ll consider that both stack are growing from the right.
<pre><code>Init a and b:
2
1
3
6
5
8
_ _
a b</pre></code>
<pre><code>Exec sa:
1
2
3
6
5
8
_ _
a b</pre></code>
<pre><code>Exec pb pb pb:
6 3
5 2
8 1
_ _
a b</pre></code>
<pre><code>Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b</pre></code>
<pre><code>Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b</pre></code>
<pre><code>Exec sa:
5 3
6 2
8 1
_ _
a b</pre></code>
<pre><code>Exec pa pa pa:
1
2
3
5
6
8
_ _
a b</pre></code>
</details>

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