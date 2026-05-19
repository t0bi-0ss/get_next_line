*This project has been created as part of 42 curriculum by tsordo-o.*

## Description

get_next_line() is a function created with the purpose of extracting each line from a text separated by a delimiter ('\n' for default in this case), each time it is called.

The intention for this project is to improve further on my coding skills while learning new concepts needed to acomplish the recreation of the `get_next_line` function, like `static variables`.


## Instructions

### Requirements

A `C` compiler must be installed.

### Usage

In order to use this function one way to use it is by writing a program that calls it with "get_next_line.h" as source, and all files should be compiled as following:

```
cc -Wall -Wextra -Werror your_program.c get_next_line.c get_next_line_utils.c
```

#### Notes

* There are other ways to use it, but in this case your program should call get_next_line(fd) function replacing `fd` with a variable declared to be used as a `file descriptor` if to `open` a file is the way you decide to use it with. 

* If you want to work with different `file descriptors` simultaneously, the compilation should be the same as before with the addtion of `_bonus` to each of `get_next_line()` files. For example:

```
cc -Wall -Wextra -Werror your_program.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

##### Prototype

```
char	*get_next_line(int fd);
```


##### Utilization:

Reads from text pointed by fd `(file descriptor)` and extracts a `new line` that ends with a `delimiter`('\n' by default), or with '\0' `(for the last line, if '\0' is not set to be the delimiter, that is)`.

In order to change the delimiter every line from `get_next_line.c` or `get_next_line_bonus.c` where `\n` is found should be change to desired delimiter. 
Lines where `\n` is found:
* 34
* 58
* 59
* 62

`get_next_line()` found in `get_next_line_bonus.c` can be used to work with multiple `file descriptors` simultaneously. The function is set to `remember` where it left off from the text it read from on last call, `discriminating` from each file descriptor.

##### Arguments:

`get_next_line()` function takes a `file descriptor` as single `argument`.

###### File descriptor:

A unique, non-negative integer used by an operating system to identify and interact with open resources, such as files, network sockets, or pipes.

#### Return value:

`get_next_line` function will return a "new line" each time it is called. "New line" refers to a unique line from the text it is called to work with, that either ends with a `delimiter`('\n' by default), or with `\0`(for the last line, if '\0' is not set to be the delimiter, that is).

---
## Notes

### Algorithm justification

In order to comply with the requirements for this project, I had work my logic and functions around the `read()` function. Therefore, I had to consider control errors in the case it fails, the `fd` passed is invalid or when the `EOF` is reached.

I rewrote some functions from the `libft` with some little useful `tweaks` for `get_next_line()`, like `ft_strdup()` that now has a `stop` character, so that it can duplicate a string from the start until the "stop" character is found (included), but, most of them, with new early exit cases where a `NULL char *` passed to them.

My main approach for this project was to use a new type of variable for me, called `static variables`, as they `hold` their value until the program ends running, instead of losing it like local variables declared inside a function, as they could be used to `remember` where the function left off from the text it was working with in the last iteration.

The bonus part works just the same as the main one, with the addition of an array of the struct I defined in the `.h` file, as each of the indexes can be related to the fd `get_next_line()` is called to work with.

---
## Resources
*The following resources have been used in order to successfully finish this project.*

42's get_next_line <a href="https://cdn.intra.42.fr/pdf/pdf/188953/es.subject.pdf">subject.pdf</a>:
> The main guide to determined project's content and requirements.

Francinette a.k.a Paco (git repository <a href="https://github.com/xicodomingues/francinette">here</a>):
> Unofficial tester tool, used exclusively to help to debug and check for errors.

<a href="https://claude.ai/login">Claude</a>:
> A next-generation AI assistant, used exclusively to understand new concepts and their functionality, static variables.
