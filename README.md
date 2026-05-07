*This project has been created as part of the 42 curriculum by kkhant-z*

# Description
`pipex` is a 42 project that deep dives into UNIX mechanisms: pipes, processes, and redirections. The goal is to replicate the behavior of the shell pipe command < infile cmd1 | cmd2 > outfile. This implementation handles multiple pipes, and here_doc redirections.

# Instructions
### Compilation
```
make
```
### Compilation (Bonus)
```
make bonus
```
### Re-compilation
```
make re
make re_bonus
```
Other Valid ```make``` commands - ```clean``` ```fclean```

## Testing pipex (Mandatory)
### Standard execution:
```
./pipex infile "ls -l" "wc -l" outfile
```
Should behave exactly like: < infile ls -l | wc -l > outfile

## Testing pipex (Bonus)
### Multiple pipes:
```
./pipex infile "cat" "grep hello" "wc -w" outfile
```
Should behave exactly like: < infile cat | grep hello | wc -w > outfile

### Here_doc execution:
```
./pipex here_doc LIMITER "cat" "wc -l" outfile
```
Should behave exactly like: cat << LIMITER | wc -l >> outfile
### Error Handling Check

Test with non-existent commands or invalid permissions:
```
./pipex infile "nonexistent_cmd" "wc -l" outfile
./pipex non_existent_file "ls" "wc" outfile
```
# Resources
- [Fork](https://www.geeksforgeeks.org/c/fork-system-call/)
- [Pipe](https://www.geeksforgeeks.org/c/pipe-system-call/)
- Man

### AI Usage
- Helping in implementation of process forking and fd redirection.
- Debugging
