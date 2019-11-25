# Simple Shell

## Introduction
This is a simple shell program modeled after the likes of early Unix shells such as the Thompson, Korn or C shells. It was written by Michelle Giraldo and Justin Majetich for a project via Holberton School. The shell provides an interface by which a user may interact with the kernel, as well as a number of built-in tools to ease this interaction. Running in interactive mode, the program solicits a command line from the user via the terminal, parses this input for valid commands, and executes them accordingly. Users may also pipe output from other commands into the shell, causing it to run in non-interactive mode. In this mode, the shell will not prompt the user for input and will automatically exit upon completion of the commands received. For further information regarding functionality and support, refer to the included man page.

## Installation
To install our shell on your Linux machine, clone the contents of this repository into a fresh directory and compile with the following command:

    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

## Usage
#### Interactive Mode

    user$ ./hsh
    $ ls
    a.out file0 file1 test.txt
    $ 
    $ exit
    user$ 

#### Non-Interactive Mode

    user$ echo "ls" | ./hsh
    a.out file0 file1 test.txt
    user$ 

## Contents

| File | Function |Description|
|--|--|--|
|**shell.h**|| *contains libraries, function prototypes, externs, and struct declarations*
|**shell.c**||
||main|	*directs the shell through its fundamental loop of parsing and executing commands*
||receive_sig|*prints prompt after user has interrupted loop with "ctrl + c" signal*
|**_getline.c**|||
||_getline|*reads input stream into buffer and parses into distinct command lines*
||check_buffer|*checks if read buffer is empty*
||copy_buffer|*copies from read buffer up to newline or null-byte*
||shift_buffer|*shifts read buffer contents left n bytes*
|**_strtok.c**||
||_strtok| *separates tab or space-delimited "words" from the command line into an array of distinct tokens*
||count_tokens| *counts the number of tokens in a command line*
||token_length| *takes the length of a given token in a command line*
|**executor.c**||
||exec_mngr|*directs a tokenized command line to either built-in or external execution*
||exec_builtin|*identify and execute a built-in command*
||exec_external|*execute a command-specified external program*
|**get_path.c**||
||get_path|*retrieve path values from the "PATH" environment variable*
||path_check|*determine if argument includes a path*
||path_count|*count number of paths listed in "PATH" variable*
||path_len|*take the length of a path*
|**err_mngr.c**||
||print_err|*format and print error message according to error number*
||case_three|*format error message in case erring built-in function*
|**builtin_exit.c**||
||builtin_exit|*allows user to exit the shell with or without arguments*
||_atoi|*converts number string to an integer*
||is_num|*determines if a string is a number*
|**builtin_env.c**||
||builtin_env|*prints the environment*
|**builtin_cd.c**||
||builtin_cd|*parse arguments to determine and call appropriate cd behavior*
||cd_HOME|*change current directory to home directory*
||cd_current|*change current directory to current directory*
||cd_prev|*change current directory to previous directory*
||cd_parent|*change current directory to parent directory*
|**cd_help.c**||
||cd_arg|*change current directory to path provided as argument*
||cd_user|*change current directory to user home directory*
||get_target| *copy path from an environment variable*
||set_PWD|*set the "PWD" environment variable*
||set_OLDPWD| *set the "OLDPWD" environment variable*
|**mem_help.c**||
||alloc_mngr|*direct dynamic memory allocations and store a pointer to each in linked list for eventual freeing*
||add_mem_node|*add node with pointer to new memory allocation to linked list
||free_mem_list|*free linked list of memory allocations*
||_realloc|*dynamically reallocate memory*
||_memset|*initialize n bytes of memory to designated value*
|**mem_help_2.c**||
||free_static_mem_list|*free linked list of memory allocations*
|**str_help.c**||
||_strlen|*take the length of a string*
||_strncpy|*copy n bytes from one string to another*
||_strcmp|*compare two strings*
||_strncmp|*compare n bytes of two strings*
||_strcat|*concatenate one string to another*
|**str_help_2.c**||
||_revstr|*reverse a string*
|**num_help.c**||
||_itoa|*convert integer to string number*
||count_digit|*count digits in number string*
