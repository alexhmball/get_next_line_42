# Get Next Line - Simplifying Reading from File Descriptors

The Get Next Line project challenged me to implement a convenient function that reads a line from a given file descriptor in C. This project not only added a valuable function to my collection but also introduced me to a fascinating new concept in C programming: static variables.

## Learning Goals
The Get Next Line project provided me with several learning objectives related to file handling and C programming:

1. **File Descriptor Reading:** I learned how to read lines from a file descriptor using the get_next_line() function. By repeatedly calling this function, I was able to read a text file line by line.

2. **Static Variables:** I delved into the concept of static variables in C programming. Understanding static variables allowed me to efficiently manage state and retain data across function calls.

3. **Dynamic Memory Allocation:** I practiced allocating and freeing heap memory properly to avoid memory leaks. Ensuring that all allocated memory was appropriately freed was crucial to the project's success.

4. **Buffer Size Configuration:** I implemented the get_next_line() function with configurable buffer size using the -D BUFFER_SIZE=n compiler flag. This allowed flexibility in choosing the buffer size for read().

5. **Handling Special Cases:** I learned how to handle edge cases, such as reaching the end of the file without a terminating \n character and reading from standard input.

## Function Details
The mandatory part of the project required implementing the get_next_line() function with the following specifications:

Prototype: 
``` c
char *get_next_line(int fd);
```
Files to turn in: get_next_line.c, get_next_line_utils.c, get_next_line.h
External functions allowed: read, malloc, free
The get_next_line() function reads a line from the file descriptor specified by fd and returns the line as a string. If there is nothing else to read or if an error occurs, the function returns NULL. The returned line includes the terminating \n character, except when the end of the file is reached without it.

I adhered to several requirements while developing get_next_line():

Implemented the function to work with both file descriptors and standard input.
Used static variables to manage the function's state effectively.
Handled edge cases, such as reading binary files and encountering changes in the file descriptor since the last call.
Reflection
The Get Next Line project was an enriching experience that deepened my understanding of C programming and file handling. Implementing a function with static variables allowed me to optimize memory usage and manage state efficiently. Configuring the buffer size added flexibility to the function's usage.

During the development process, I encountered various challenges related to handling edge cases and ensuring the correct functioning of the get_next_line() function. Writing comprehensive tests helped me verify its correctness and robustness.

Overall, the Get Next Line project enhanced my skills in C programming, memory management, and file handling. It was a valuable addition to my programming toolkit, and I look forward to applying the knowledge gained from this project to future endeavors.
