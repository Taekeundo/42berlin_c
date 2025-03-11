# get_next_line
[1) Description](#1-description)

[2) Background knowledge](#2-background-knowlege)

[3) Main function](#3-main-function-for-the-test)

[4) Reference](#4-reference)
<br><br>

## 1) Description
### (1) Goal for the project
```c
Function designed to read and return a single line from a file,
using newline as a separator.
= FD로부터 개행문자('\n')기준으로 한 줄 씩 읽는 함수를 만든다.
```

### (2) Allowed functions

```c
#include <unistd.h> // read
#include <stdlib.h>// malloc, free
```


### (3) Prototype

```c
char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_buffer;

	if (BUFFER_SIZE <= 0)
		return (0);
	static_buffer = read_and_cpy_file(fd, static_buffer);
	if (static_buffer == NULL)
		return (NULL);
	line = cpy_one_line_from_buffer(static_buffer);
	static_buffer = move_to_next_line(static_buffer);
	return (line);
}
```
<br>

## 2) Background knowlege

### (1) Free for Dynamic allocate memory
```c
1. Must use [f] free together,
when after using free and nothing is in inside.
= free를 함께 사용해야 하며, free해준 뒤에는 데이터가 없어진다.

2. Place to free is no problem,
but must free one time before program is finished.
= 전체 프로그램 중 어디서 해주든 크게 상관 없다. 한번만 해주면 된다.
```

### (2) Scope of the variables
```c
1. Local variable
- Declaration
    Inside a function or block.
- Stored
    In the stack.
- Access
    Only accessible within the function, where it is declared.
- Destroy
    Automatically destroyed when the function exits.

2. Global variable
- Declaration
    Outside of any function.
- Stored
    In the data segment.
- Access
    Accessible from anywhere in the program.
- Destory
    persists(='continue') to exist throughout the programs execution.

3. Static variable
- Stored
    In the data segment (Not on the stack or heap)
- Scope depends on where it is declared
    Inside a function:
        Accessible only within that function.
    Outside a function:
        Accessible only within the same file.
- Retains(maintain) its value between function calls.
```
<span style="color: red;">!! WHEN is STATIC variable used mostly !!</span><br>
함수 호출 간 값을 유지해야 할 때 사용<br>
지역 변수(local variable)는 함수가 끝날 때 소멸하지만,<br>
    static변수는 함수가 종료되어도 값을 유지한다.

### (3) Handling a flie by its descriptor
```c
FD: File Descriptor
- 0: Standard In
- 1: Standard Out
- 2: Standard Error

= Assign in ascending oder from 3.
```

### (4) read()
```c
1. Definition
- reading data from a file descriptor, such as a file or a device

2. Form
- ssize_t read(int fd, void *buf, size_t count);

3. Detail
- Reads from Param(1):"fd"
- as many as Param(3): "count"
- and stroes it it Param(2):"buf"

4. Parameter
- Param(1) fd
    file descriptor, represents the integer number,
    where the file is stored.
    Normally starts from '3'.

- Param(2) *buf
    point to the saving places address.

- Parma(3) count
    How many bytes do i want to read each time.

5. Return
- Success: the number of bytes, to read.
- Fail: -1
- Finish to read all data
    -> No more bytes to read
    -> return: 0

6. Memo
- It overlaps next file automatically.
- No need to init it everytime.
```

### (5) string literal
```c
1. Definition
    A sequence of characters enclosed in double quotation marks,
    such as "Hello" and always stored in “read-only” memory.

    A constant character array that represents a fixed,
    immutable sequence of characters.

2. Properties
    Can not directly modify. 
    For modify, there are two ways.

    a. Character array // declare array → strcpy → modify.
    b. Malloc // allocate memory → strcpy → modify.
```

### (6) pointer to NULL vs pointer to '\0'
```c
1. point to (NULL) == point to “nothing”.
2. point to ‘\0’ == point to “the null character based on ASCII”
3. printf (NULL) == “NULL”
4. printf ‘\0’ == “empty space”
```
<br>

## 3) Main function for the test

```c
#include <fcntl.h> // open
#include <stdio.h> // printf

int count_lines(const char *filename)
{
	int		n_line = 0;
    char	*res;

    int fd = open(filename, O_RDONLY);
    if (fd < 0)
	{
        perror("Can not open the files");
        return (-1);
    }    
    while ((res = get_next_line(fd)) != NULL)
	{
        n_line++;
        free(res);
    }
    close (fd);
    return (n_line);
}

int main(void)
{
	const char	*filename;
	int	total_lines;
	int	fd;
	char *res;
	int	i;

	filename = "test.txt";
	total_lines = count_lines(filename);
	printf("\nThere is \"%d\" lines in the file(= %s)\n\n", total_lines, filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Can not open the files");
		return (1);
	}
	i = 0;
	while (i < total_lines)
	{
		res = get_next_line(fd);
		if (res == NULL)
		{
			close (fd);
			return (1);
		}
		printf("Line[%i]: %s", i, res);
		free(res);
		i++;
	}
	close(fd);
	return (0);
}
```
<br>

## 4) Reference
1. https://code4human.tistory.com/130 <br>
2. https://velog.io/@tmdgks2222/getnextline <br>
3. https://80000coding.oopy.io/4d3eba5f-5d2d-4bec-b0a2-fa058d67c643 <br>
4. https://desinging-new.tistory.com/entry/42%EC%84%9C%EC%9A%B8-Get-Next-LineGNL-%EC%84%A4%EB%AA%85<br>