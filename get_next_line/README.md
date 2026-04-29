*This project has been created as part of the 42 curriculum by kkhant-z.*

# Description

`get_next_line` is a project from the 42 curriculum that requires implementing a function capable of reading a file descriptor line by line. The goal is to return one line at a time from a file descriptor, including the newline character (\n) if it exists. The function must manage memory correctly, and work with a defined `BUFFER_SIZE`.

# Instructions

To compile, use this command

```
cc -D BUFFER_SIZE=10 main.c get_next_line.c get_next_line_utils.c
```

# Resources

- man
- AI is used in planning and debugging

# Algorithm

- Buffer is allocated based on `BUFFER_SIZE`
- Check if static variable `leftover` has a delimiter in it and returns the string before delimiter (inclusive) if it does
- Read from the `fd` and fill the buffer
- Combine the buffer with static variable `leftover`
- If delimiter is in the combined buffer, the string before delimiter (inclusive) is returned and the remaining string is stored in a static variable `leftover`
- If there is nothing left to read, the remaining string in static variable `leftover` is returned and `leftover` is set to `NULL`

