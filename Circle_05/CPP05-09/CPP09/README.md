# C++ Containers for CPP09

## Rule
1. Can use STL (Standard Library) in CPP09
2. Every exercise must use min.1 container // No duplicates
   ex00: container(1): map
	ex01: container(2): stack
	ex02: container(3): vector
         container(4): deque

---

## Ex00: Bitcoin Exchange

### Task
Store Bitcoin price data, match input dates to the closest date,
and calculate the Bitcoin value on that date.

### Recommended Container
**`std::map(key, value)`**
 1. It's ideal for storing both (key-value)pairs together.
 2. `std::map::lower_bound`.
    It's easy yo find the closest date by using this method.

### Logic
 1. Parsing the given file (= data.csv)
   (ex)
         date     |   value
      2011-01-03  |     3
      2011-01-03  |     2
      2011-01-03  |     1

### Caution
 1. Find the closest date not `lower date` but `upper date`
 2. Exceptional case for `input`
 3. Range: 0 - 1000

### Memo
- key: date
- value: Bitcoin price

---

## Ex01: Reverse Polish Notation (RPN)
   
### Task
Make the mathematical expression in Reverse Polish Notation,
by using a stack-based algorithm.

### Background
#### 1. Operands
피연산자

#### 2. RPN
3 4 + 5 6 + x == (3 + 4) x (5 + 6)
Operands Operands Operator -> Program execute -> Operands Operator Operands

### Recommended Container
- **`std::stack`**
1. It's ideal for handling 'LIFO', which is exactly what the RPN algorithm requires.
2. It simplifies the management of intermediate values during the calculation.

### Logic
 1. Push it onto the stack, when it's operands(Digit).
 2. When an operator is encounted,
    2-1. Pop 2times from the stack. // Get two operands
    2-2. Calculate it.
 3. Push back the calculated result onto the stack.





