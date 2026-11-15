# simple_shell

A small UNIX command interpreter written in C for the ALX Software Engineering program. It reads a line, splits it into arguments, and either runs a builtin or forks and executes a program, in both interactive and non-interactive mode.

About 1,500 lines of C with its own string, memory, and tokenizer helpers in place of most of the standard library.

## Build

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

Interactive:

```
$ ./hsh
$ /bin/ls
AUTHORS  BL_H.c  Exe.c  main.c  shell.h ...
$ pwd
/home/user/simple_shell
$ cd /tmp
$ pwd
/tmp
$ exit
```

Non-interactive:

```bash
echo "/bin/ls" | ./hsh
```

## Features

- Runs programs by absolute path with arguments (`/bin/ls -l /tmp`)
- Looks commands up in `PATH` (`ls`, `pwd`)
- Builtins:

  | Builtin | Behavior |
  |---|---|
  | `exit [status]` | Leave the shell with an optional exit status |
  | `cd [dir]` | Change directory, updating `PWD` and `OLDPWD` |
  | `env` | Print the environment |
  | `history` | Print the command history, kept in `.simple_shell_history` |
  | `echo $?` | Exit status of the last command |
  | `echo $$` | Process ID |

- Error messages in the `sh` style: `./hsh: 1: nosuchcmd: ...`
- Prompt shown only when input is a terminal

## Known issues

- A command found through `PATH` loses its arguments (`ls -l` behaves like `ls` with a bad argument). Use the full path, e.g. `/bin/ls -l`, when passing arguments.
- `echo` with plain text (`echo hello`) crashes; use `/bin/echo hello`.
- `echo $PATH` prints the value and then aborts.
- `help` and `alias` are declared but not finished.

## Source layout

| File | Role |
|---|---|
| `main.c` | Main loop: prompt, read, parse, dispatch |
| `shell_prompt.c`, `G_Line.c` | Prompt and line reading |
| `input_parser.c`, `string_tokenizer.c` | Splitting input into arguments |
| `Exe.c`, `Exe_H.c` | Builtin dispatch, fork and exec |
| `P_H.c` | `PATH` search |
| `BL_H.c`, `BL_H1.c` | Builtin implementations |
| `his_H.c`, `aliases.c` | History and aliases |
| `F_H.c`, `more_F_H.c`, `more_F_Hs.c`, `mem.c`, `number_printer.c`, `outputH.c` | String, memory, and output helpers |
| `shell.h` | Prototypes and structs |

## Author

Mohamed Awad
