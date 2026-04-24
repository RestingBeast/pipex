*This project has been created as part of the 42 curriculum by kkhant-z.*

# Description
`ft_printf` is a project from 42 School that consists of recreating the standard C `printf` function.
The goal is to understand variadic functions, formatting, and low-level output handling in C.
This implementation supports several format specifiers such as `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`, following the behavior of the original `printf`.
Bonus: supports the `#`, `space`, `+`, `-`, `0`, `.`, and minimum field width flags.

# Instructions
### Compilation
```
make
```
### Compilation (with Bonus)
```
make bonus
```
### Usage with main.c file
```
cc main.c libftprintf.a
```
Other Valid ```make``` commands - ```clean``` ```fclean``` ```re```

# Resources
- man
- [va_list](https://medium.com/@turman1701/va-list-in-c-exploring-ft-printf-bb2a19fcd128)
- AI used in planning the data structures and understanding what to do for bonus.

# Algorithm & Data Structure

## Data Structures
### t_buffer
A structure used to optimize output operations.
It contains:
`char *data`: a fixed-size character buffer
& `int index`: the current position in the buffer

### t_flag (bonus)
A structure used to store formatting flags.
Each flag is represented as an int, where `1` means the flag is present and `0` means it is not.

## Buffer Management
- Characters are first stored in a buffer with a fixed size instead of being written directly to the output.
- When the buffer becomes full during copying, it is flushed (written to the screen using write) and the buffer index is reset to 0.
- This approach reduces the number of system calls and improves performance.

## Conversion Algorithm
- The format string is processed character by character.
- Regular characters are copied directly into the buffer.
- When a % is encountered:
- Flags are parsed and stored in the t_flag structure.
- Based on the conversion specifier, a string representation of the corresponding value is created.
- Flags are applied to the generated string (padding, alignment, signs, precision, etc.).
- The final formatted string is copied into the buffer.
- The process continues until the entire format string is parsed, flushing the buffer as needed.
- At the end of the program, the buffer is flushed one last time.
