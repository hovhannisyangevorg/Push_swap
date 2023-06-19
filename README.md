# Pushswap

Pushswap is a sorting algorithm project developed as part of the curriculum at 42, a coding school. The goal of this project is to implement a program that can sort a stack of integers using a limited set of operations.

## Installation

1. Clone the repository:
```bash
  git clone https://github.com/hovhannisyangevorg/push_swap.git
```
3. Navigate to the project directory:
```bash
  cd pushswap
```
4. Compile the program:
```bash
  make
```
## Usage

To sort a stack of integers, run the program with the following command:
```bash
  ./push_swap [integers]
```
Replace `[integers]` with the list of integers you want to sort. For example:
```bash
  ./push_swap 5 2 8 1 6
```

The program will output a list of operations that need to be performed on the stack to sort it. Each operation is represented by a single character:

- `sa`: Swap the first two integers at the top of stack A.
- `sb`: Swap the first two integers at the top of stack B.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the top integer from stack B to stack A.
- `pb`: Push the top integer from stack A to stack B.
- `ra`: Rotate stack A upwards, moving the first integer to the bottom.
- `rb`: Rotate stack B upwards, moving the first integer to the bottom.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Rotate stack A downwards, moving the last integer to the top.
- `rrb`: Rotate stack B downwards, moving the last integer to the top.
- `rrr`: Perform `rra` and `rrb` simultaneously.

To check if the generated list of operations correctly sorts the stack, you can use the `checker` program. First, compile it:
```bash
  make checker
```
Then, run it with the sorted integers and the list of operations:
```bash
  ./checker [integers] [operations]
```
For example:
```bash
  ./checker 1 2 5 6 8 `./push_swap 5 2 8 1 6`
```
If the stack is sorted and the list of operations is valid, the checker program will output "OK". Otherwise, it will output "KO".

## License

The Pushswap project is open-source software licensed under the MIT license. Feel free to use, modify, and distribute the code as per the terms of the license.