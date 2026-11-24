*This activity has been created as part of the 42 curriculum by maabboud.*

# Libft

## Description

Libft is my first C project at 42. The goal is to build a reusable static library, `libft.a`, by reimplementing common C library functions and writing helpers for later projects. The public interface is declared in `libft.h`.

The library contains 43 functions across the three mandatory parts.

| Category | Functions | What they do |
| --- | --- | --- |
| Character checks and conversion | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower` | Check character classes and convert ASCII letters between upper and lower case. |
| Memory and allocation | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` | Fill, copy, search, and compare memory by byte. `ft_memmove` supports overlapping regions, and `ft_calloc` allocates zero-initialized memory. |
| Standard string operations | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi`, `ft_strdup` | Measure, copy, append, search, and compare strings, convert a string to an integer, and allocate a string copy. |
| Additional string helpers | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri` | Extract, join, trim, split, and transform strings, or convert an integer to a string. `ft_strmapi` creates a new string, while `ft_striteri` applies a callback to the existing string. |
| File descriptor output | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a character, string, line, or integer to a file descriptor. |
| Singly linked lists | `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` | Create, insert, count, access, delete, and transform nodes. Each `t_list` node holds a `void *content` pointer and a pointer to the next node. The deletion and mapping functions accept a callback to clean up node contents. |

## Instructions

From the repository root, run `make`. This compiles the source files with `cc -Wall -Wextra -Werror` and uses `ar` to create `libft.a` in the same directory.

| Command | Result |
| --- | --- |
| `make` or `make all` | Build `libft.a`. |
| `make clean` | Remove the object files. |
| `make fclean` | Remove the object files and `libft.a`. |
| `make re` | Clean and rebuild the library. |

To use the library, include `libft.h` in your program. For example, save the following as `example.c` in the repository root.

```c
#include "libft.h"

int main(void)
{
    ft_putendl_fd("Hello from Libft", 1);
    return (0);
}
```

Build the library, link the example against it, and run the executable.

```sh
make
cc -Wall -Wextra -Werror example.c libft.a -o example
./example
```

## Resources

- [OpenBSD manual for `memmove(3)`](https://man.openbsd.org/memmove.3) for copying overlapping memory regions.
- [OpenBSD manual for `strlcpy(3)` and `strlcat(3)`](https://man.openbsd.org/strlcat) for buffer capacity and return values.
- [GNU Make manual](https://www.gnu.org/software/make/manual/html_node/Rule-Syntax.html) for targets, prerequisites, and recipes.

### AI usage

I wrote the Libft implementation myself. I used ChatGPT to create a standalone test program, check edge cases, and debug compiler errors and test failures.
