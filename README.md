<p>
<img src="https://github.com/damiandania/damiandania/blob/main/Pics/Push_swap.png"
    alt="Project pic" width="150" height="150"/>
</p>

# Push_Swap 🔄

**Push_Swap** is an algorithm project at 42 school where the goal is to sort a list of random integers using a limited set of operations, aiming to perform the sorting with the fewest possible actions.

## Status

Completed on **05/09/2022** with a grade of **100%**.

## Usage

First, clone the repository and navigate into it. Then compile the program by running:

```bash
make
```

To execute the program, use the following syntax:

```
./push_swap <numbers>
```

The provided numbers can be positive or negative integers, but duplicates are not allowed. For example:

```
./push_swap 9 0 -217 2147483647 -2147483648
```

If the input is valid, the program will output the most efficient sequence of actions to sort the list.

## Checking the Program

You can check the program's output using the provided checker tool. For example:

```
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

Additionally, you can quickly test the program with preset values using the following commands:

```
make test3   # Test sorting 3 values
make test5   # Test sorting 5 values
make test100 # Test sorting 100 values
make test500 # Test sorting 500 values
```

You can also visualize the algorithm in action with O-reo's Push_Swap Visualizer.

## Push_Swap Rules and Grading

The program works with two stacks, A and B. Initially, all numbers are placed in stack A, while stack B is empty. You are allowed to perform the following operations:

- `pa` (push A): Move the top element from stack B to stack A. Does nothing if stack B is empty.
- `pb` (push B): Move the top element from stack A to stack B. Does nothing if stack A is empty.
- `sa` (swap A): Swap the top two elements of stack A. Does nothing if fewer than two elements are present.
- `sb` (swap B): Swap the top two elements of stack B. Does nothing if fewer than two elements are present.
- `ss`: Perform both `sa` and `sb` simultaneously.
- `ra` (rotate A): Shift all elements of stack A upwards by one, making the first element the last.
- `rb` (rotate B): Shift all elements of stack B upwards by one, making the first element the last.
- `rr`: Perform both `ra` and `rb` simultaneously.
- `rra` (reverse rotate A): Shift all elements of stack A downwards by one, making the last element the first.
- `rrb` (reverse rotate B): Shift all elements of stack B downwards by one, making the last element the first.
- `rrr`: Perform both `rra` and `rrb` simultaneously.

### Grading Criteria

The project’s grading depends on the efficiency of the sorting algorithm. Below are the grading standards:

- Sorting 3 Values:
	- Maximum of 3 actions.

- Sorting 5 Values:
	- Maximum of 12 actions.

- Sorting 100 Values:
	- Graded on a scale of 1 to 5 points based on the number of actions:
		- 5 points for fewer than 700 actions.
		- 4 points for fewer than 900 actions.
		- 3 points for fewer than 1100 actions.
		- 2 points for fewer than 1300 actions.
		- 1 point for fewer than 1500 actions.

- Sorting 500 Values:
	- Graded on a scale of 1 to 5 points based on the number of actions:
		- 5 points for fewer than 5500 actions.
		- 4 points for fewer than 7000 actions.
		- 3 points for fewer than 8500 actions.
		- 2 points for fewer than 10000 actions.
		- 1 point for fewer than 11500 actions.

A score of at least 80/100 is required to validate the project.

