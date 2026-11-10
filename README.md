*This project has been created as part of the 42 curriculum by abed-dyb.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf`. 
The goal of the project is to learn how to use **variadic functions** (`<stdarg.h>`) in C, 
and to design clean, extensible code that can dispatch on a format string.

The result is a static library, `libftprintf.a`, exposing a single function:

```c
int ft_printf(const char *format, ...);
```

Like the original, it writes to standard output and returns the number 
of characters printed (or `-1` on error).

### Supported conversions

Specifier and Description

=> `%c` : A single character
=> `%s` : A string (prints `(null)` for a NULL pointer)
=> `%p` : A pointer in hexadecimal (`0x...`)
=> `%d` : A signed decimal integer
=> `%i` : A signed integer (base 10)
=> `%u` : An unsigned decimal integer
=> `%x` : An unsigned hexadecimal integer (lowercase) 
=> `%X` : An unsigned hexadecimal integer (uppercase) 
=> `%%` : A literal percent sign                        

## Instructions

### What you need

- A C compiler (`cc` or `gcc`)
- `make`
- Linux or macOS

### 1. Compile the library

Open a terminal in the project folder and run:

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # rebuilds everything
```

After `make`, you will see a new file called `libftprintf.a`.
The project is compiled with the flags `-Wall -Wextra -Werror`.

### Project structure

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c        # main function and format parsing
├── printf_helper_one.c
├── printf_helper_two.c
├── README.md


```

## Resources

1. [Variadic functions in C (GeeksforGeeks)](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
2. [va_list in C: exploring ft_printf (Medium)](https://medium.com/@turman1701/va-list-in-c-exploring-ft-printf-bb2a19fcd128)
3. [What is the format of the x86-64 va_list structure? (Stack Overflow)](https://stackoverflow.com/questions/4958384/what-is-the-format-of-the-x86-64-va-list-structure)
4. [Using %x to print the hex address contained in a pointer (Stack Overflow)](https://stackoverflow.com/questions/25211015/using-x-to-print-the-hex-address-contained-in-a-pointer)

### Use of AI

I used AI to explain concepts, understand and debug errors, and search for relevant information to improve my knowledge.
