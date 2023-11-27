<h1 align="center">Libft - 42</h1>
<p align="center"><strong>My very first own library</strong></p>

## 📑 About
---
> This project consists of creating our own library with some of the most used functions in the C language and others that are exclusive to it. It will be very useful, since we will use it in our next projects in C.
---

### Part 1 - Libc functions

| Name                                  | Description                                                                                                                 |
| ------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| [**ft_isalpha**](/libft/ft_isalpha.c) | checks if it is an alphabetic character                                                                                     |
| [**ft_isdigit**](/libft/ft_isdigit.c) | checks if it is a decimal digit character                                                                                   |
| [**ft_isalnum**](/libft/ft_isalnum.c) | checks if it is an alphanumeric character                                                                                   |
| [**ft_isascii**](/libft/ft_isascii.c) | checks if it is an ASCII character                                                                                          |
| [**ft_isprint**](/libft/ft_isprint.c) | checks if it is a printable character                                                                                       |
| [**ft_strlen**](/libft/ft_strlen.c)   | returns the length of the string                                                                                            |
| [**ft_memset**](/libft/ft_memset.c)   | fill the first `len` bytes of `b` with `c`                                                                                  |
| [**ft_bzero**](/libft/ft_bzero.c)     | erase `n` bytes of `s` with zeros                                                                                           |
| [**ft_memcpy**](/libft/ft_memcpy.c)   | copy `n` bytes from `src` to `dst` (the memory areas must not overlap)                                                      |
| [**ft_memmove**](/libft/ft_memmove.c) | copy `len` bytes from `src` to `dst` (The memory areas may overlap)                                                         |
| [**ft_strlcpy**](/libft/ft_strlcpy.c) | copy `dstsize - 1` characters from `src` to `dst`, ending with NULL                                                         |
| [**ft_strlcat**](/libft/ft_strlcat.c) | append the `dstsize - ft_strlen(dst) - 1` characters from `src` to `dst`, ending with NULL                                  |
| [**ft_toupper**](/libft/ft_toupper.c) | convert lowercase letters to uppercase                                                                                      |
| [**ft_tolower**](/libft/ft_tolower.c) | convert uppercase letters to lowercase                                                                                      |
| [**ft_strchr**](/libft/ft_strchr.c)   | returns a pointer to the first occurrence of the character `c` in the string `s`                                            |
| [**ft_strrchr**](/libft/ft_strrchr.c) | returns a pointer to the last occurrence of the character `c` in the string `s`                                             |
| [**ft_strncmp**](/libft/ft_strncmp.c) | compare the first `n` characters of strings `s1` and `s2` and return 0 if they are equal, otherwise return the difference between them |
| [**ft_memchr**](/libft/ft_memchr.c)   | return a pointer to the first instance of `c` in `s` until `n` bytes or NULL if the character does not occur in the given memory area |
| [**ft_memcmp**](/libft/ft_memcmp.c)   | compare the first `n` characters of the memory areas `s1` and `s2` and return 0 if they are equal, otherwise return the difference between them |
| [**ft_strnstr**](/libft/ft_strnstr.c) | copies the string `src`, including the terminating null byte, to the buffer `dest`                                          |
| [**ft_atoi**](/libft/ft_atoi.c)       | convert string `str` to int                                                                                                 |
| [**ft_calloc**](/libft/ft_calloc.c)   | allocate unused space for an array of `count`elements each of whose size in bytes is `size`.  The space shall be initialized to all bits 0 |
| [**ft_strdup**](/libft/ft_strdup.c)   | returns a pointer to a new string which is a duplicate of the string `s`                                                    |

### Part 2 - Additional functions

| Name                                         | Description                                                                                                          |
| -------------------------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| [**ft_substr**](/libft/ft_substr.c)         | returns a substring from the string `s`. The substring begins at index `start` and is of maximum size `len`          |
| [**ft_strjoin**](/libft/ft_strjoin.c)       | returns a new string, which is the result of the concatenation of `s1` and `s2`                                      |
| [**ft_strtrim**](/libft/ft_strtrim.c)       | returns a copy of `s1` with the characters specified in `set` removed from the beginning and the end of the string   |
| [**ft_split**](/libft/ft_split.c)           | returns an array of strings obtained by splitting `s` using the character `c` as a delimiter. The array must end with a NULL pointer |
| [**ft_itoa**](/libft/ft_itoa.c)             | returns a string representing the integer received as an argument                                                    |
| [**ft_strmapi**](/libft/ft_strmapi.c)       | Applies the function `f` to each character of the string `s`, and passing its index as first argument to create a new string resulting from successive applications of `f` |
| [**ft_striteri**](/libft/ft_striteri.c)     | Applies the function `f` on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to `f` to be modified if necessary |
| [**ft_putchar_fd**](/libft/ft_putchar_fd.c) | Outputs the character `c` to the given file descriptor                                                               |
| [**ft_putstr_fd**](/libft/ft_putstr_fd.c)   | Outputs the string `s` to the given file descriptor                                                                  |
| [**ft_putendl_fd**](/libft/ft_putendl_fd.c) | Outputs the string `s` to the given file descriptor followed by a newline                                            |
| [**ft_putnbr_fd**](/libft/ft_putnbr_fd.c)   | Outputs the integer `n` to the given file descriptor                                                                 |

### Bonus functions

| Name                                             | Description                                                                                                      |
| ------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------- |
| [**ft_lstnew**](/libft/ft_lstnew.c)             | returns a new node. The member variable `content` is initialized with the value of the parameter `content`. The variable `next` is initialized to NULL |
| [**ft_lstadd_front**](/libft/ft_lstadd_front.c) | Adds the node `new` at the beginning of the list                                                                 |
| [**ft_lstsize**](/libft/ft_lstsize.c)           | Counts the number of nodes in a list                                                                             |
| [**ft_lstlast**](/libft/ft_lstlast.c)           |Returns the last node of the list                                                                                 |
| [**ft_lstadd_back**](/libft/ft_lstadd_back.c)   | Adds the node `new` at the end of the list                                                                       |
| [**ft_lstdelone**](/libft/ft_lstdelone.c)       | Takes as a parameter a node and frees the memory of the node’s content using the function `del` given as a parameter and free the node. The memory of `next` must not be freed |
| [**ft_lstclear**](/libft/ft_lstclear.c)         | Deletes and frees the given node and every successor of that node, using the function `del` and free. Finally, the pointer to the list must be set to NULL |
| [**ft_lstiter**](/libft/ft_lstiter.c)           | Iterates the list `lst` and applies the function `f` on the content of each node                                 |
| [**ft_lstmap**](/libft/ft_lstmap.c)             | Iterates the list `lst` and applies the function `f` on the content of each node. Creates a new list resulting of the successive applications of the function `f`. The `del` function is used to delete the content of a node if needed |

## ⚙️ Usage

### Instructions

**1. Compiling the library**

Inside the repository, run:
```shell
make
```

**2. Using it in your code**

To use the library functions in your code, include the header:
```C
#include "libft.h"
```
and, when compiling your code, use the following flags:
```shell
-Lpath/to/libft.a -lft
```

### [**Makefile**](/libft/Makefile)

Command | Description
------- | -----------
**make** | compile the library
**make bonus** | compile the library with the bonus
**make clean** | delete all object files
**make fclean** | delete all object files and the library
**make re** | recompile the library
