# libft

## My standard library for the C programming language
> Reinventing the wheel **like a boss**

Libft is the first project of the 42 school. The goal is to recreate a subset of the standard C library, along with additional utility functions that will serve as a foundation for future projects.
This library includes memory manipulation, string handling, character checks, conversions, and a custom linked list implementation.

---

## 🚀 Features

### ✔️ Rewrites of the standard C library
These functions mirror the behavior of their standard library equivalents:

- **isalpha** — Returns non-zero if the character is a letter
- **isdigit** — Returns non-zero if the character is a digit
- **isalnum** — Returns non-zero if the character is alphanumeric
- **isascii** — Returns non-zero if the character is within the ASCII table (0–127)
- **isprint** — Returns non-zero if the character is printable
- **strlen** — Returns the length of a string *(undefined behavior if NULL — might change soon)*
- **memset** — Sets n bytes of memory to a given value
- **bzero** — Sets n bytes of memory to zero
- **memcpy** — Copies n bytes from src to dest
- **memmove** — Copies n bytes while handling overlap safely
- **strlcpy** — Safely copies strings with size limits
- **strlcat** — Safely concatenates strings with size limits
- **toupper** — Converts a lowercase letter to uppercase
- **tolower** — Converts an uppercase letter to lowercase
- **strchr** — Finds the first occurrence of a character in a string
- **strrchr** — Finds the last occurrence of a character in a string
- **strncmp** — Compares two strings up to n characters
- **memchr** — Scans memory for a specific byte
- **memcmp** — Compares two memory areas
- **strnstr** — Finds a substring within the first n characters
- **atoi** — Converts a string to an integer
- **calloc** — Allocates and zeroes memory
- **strdup** — Creates a duplicate of a string

---

### 🛠️ Original utility functions
Additional tools not found in the C standard library:

- **substr** — Extracts a substring from a string
- **strjoin** — Concatenates two strings into a new one
- **strtrim** — Trims characters from the start and end of a string
- **split** — Splits a string into an array using a delimiter
- **itoa** — Converts an integer to a string
- **strmapi** — Applies a function to each character of a string (mapped)
- **striteri** — Applies a function to each character (in place)
- **putchar_fd** — Writes a char to a file descriptor
- **putstr_fd** — Writes a string to a file descriptor
- **putendl_fd** — Writes a string followed by a newline to a file descriptor
- **putnbr_fd** — Writes an integer to a file descriptor

---

### 🔗 Bonus: Singly-linked list utilities
A small linked list API:

- **lstnew_bonus** — Creates a new list node
- **lstadd_front_bonus** — Adds a node at the beginning of the list
- **lstsize_bonus** — Counts the number of nodes
- **lstlast_bonus** — Returns the last node
- **lstadd_back_bonus** — Adds a node at the end of the list
- **lstdel_one_bonus** — Deletes a node
- **lstclear_bonus** — Deletes and frees an entire list
- **lstiter_bonus** — Applies a function to each node
- **lstmap_bonus** — Creates a new list by applying a function to each node

---

## 📦 Compilation

To build the library:

```bash
make
```
This will generate libft.a, which you can compile along with your programs:
```bash
gcc your_program.c -L. -lft -o your_program
```

---

## 📜 License

This project is part of the 42 curriculum. You are free to explore, learn, and adapt it.
