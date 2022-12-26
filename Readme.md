# Minitalk

we will create a communication program in the form of a client and a server. The server must be started first. After its launch, it has to print its PID.

The client takes two parametrs : > The server PID ; > The string to send.

The client must send the string passed as a parameter to the server. Once the string has benn received, the server must print it.

The server has to display the string pretty quickly. it must recieve strings from several clients in a row without needing to restart.

## Allowed functions :
### ◦ write
- man write :p
### ◦ ft_printf
- man printf :p
### ◦ signal
In the C programming language, the signal function is used to specify a function (called a signal handler) to be called when a particular signal is received by a process. It is important to note that the signal function has some limitations and is generally considered to be unreliable and non-portable. In modern C programming, it is often recommended to use the sigaction function

### ◦ Sigemptyset
In the C programming language, the sigemptyset function is used to initialize a signal set to the empty set. A signal set is a data type that represents a set of signals. It is used in the sigaction function and other functions related to signal handling to specify the set of signals that should be blocked while a signal handler is executing, or to specify the set of signals that a process is interested in receiving.
The sigemptyset function is usually used in conjunction with other functions that operate on signal sets, such as sigaddset, to specify the set of signals that a process is interested in receiving or that should be blocked while a signal handler is executing.

### ◦ Sigaddset
The sigaddset function is used to add a signal to a signal set. A signal set is a data type that represents a set of signals. It is used in the sigaction function and other functions related to signal handling to specify the set of signals that should be blocked while a signal handler is executing, or to specify the set of signals that a process is interested in receiving.

### ◦ Sigaction
The sigaction function is a more flexible and reliable way to specify signal handlers in the C programming language.The sigaction function is more reliable and portable than the signal function, and is generally the preferred way to specify signal handlers in C. It provides more control over the behavior of signal handlers and allows for the use of the sa_sigaction field to specify an alternate form of the signal handler that takes additional arguments.

### ◦ Kill
The kill function is used to send a signal to a process. It is a function provided by the operating system and is declared in the signal.h header file.It is important to note that the kill function can only be used to send signals to processes that the calling process has permission to signal. In addition, certain signals, such as SIGKILL and SIGSTOP, cannot be caught or ignored by the receiving process and will terminate or stop the process immediately.

### ◦ Getpid
The getpid function is used to retrieve the process ID of the calling process. It is a function provided by the operating system and is declared in the unistd.h header file.The process ID is a unique identifier assigned to each process by the operating system. It can be used to identify and communicate with a specific process, for example by using the kill function to send a signal to the process.

### ◦ malloc
- man malloc :P

### ◦ free
- man free :p

### ◦ pause
The pause function is used to suspend the execution of a process until a signal is received. It is a function provided by the operating system and is declared in the unistd.h header file. 

### ◦ sleep
the sleep function is used to suspend the execution of a process for a specified number of seconds. It is a function provided by the operating system and is declared in the unistd.h header file. 

### ◦ usleep
he usleep function is used to suspend the execution of a process for a specified number of microseconds. It is a function provided by the operating system and is declared in the unistd.h header file.
The usleep function is often used to implement very short delays or pause execution for a specific amount of time in a program. It can be useful for implementing real-time behavior or for testing purposes.

### ◦ exit
In the C programming language, the exit function is used to terminate the calling process and return a status code to the operating system. It is a function provided by the operating system and is declared in the stdlib.h header file. 
