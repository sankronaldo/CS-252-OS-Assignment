## Some System Calls in strace_log

- Line 1
 ` int execve(const char *pathname, char *const argv[],char *const envp[]);`

execve() executes the program referred to by pathname.  This causes the program that is currently being run by the calling process to be replaced with a new program, with newly initialized stack, heap, and (initialized and uninitialized) data segments.

---
- Line 2
`int brk(void *addr);`

change data segment size

---

- Line 3
`int syscall(SYS_arch_prctl, int code, unsigned long addr);`

`int syscall(SYS_arch_prctl, int code, unsigned long *addr);`

arch_prctl() sets architecture-specific process or thread state. code selects a subfunction and passes argument addr to it; addr is interpreted as either an unsigned long for the "set" operations, or as an unsigned long *, for the "get" operations.


---

- Line 4
`int access(const char *pathname, int mode);`

access() checks whether the calling process can access the file pathname. The mode specifies the accessibility check(s) to be performed, and is either the value F_OK, or a mask consisting of the bitwise OR of one or more of R_OK, W_OK, and X_OK.  

---

- Line 5
`int openat(int dirfd, const char *pathname, int flags);`

The open() system call opens the file specified by pathname. If the specified file does not exist, it may optionally (if O_CREAT is specified in flags) be created by open().  The argument flags must include one of the following access modes: O_RDONLY, O_WRONLY, or O_RDWR.  These request opening the file read-only, write-only, or read/write, respectively.

---

- Line 6
`int fstat(int fd, struct stat *statbuf);`

It is used to get file status. fstat() is identical to stat(), except that the file about which information is to be retrieved is specified by the file descriptor fd.

---

- Line 7
` void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);`

mmap() creates a new mapping in the virtual address space of the calling process.  The starting address for the new mapping is specified in addr.  The length argument specifies the length of the mapping (which must be greater than 0).

 ---

- Line 8
`int close(int fd);`

close() closes a file descriptor, so that it no longer refers to any file and may be reused.

  ---

- Line 10
`ssize_t read(int fd, void *buf, size_t count);`

read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.

  ---

- Line 11
`ssize_t pread(int fd, void *buf, size_t count, off_t offset);`

pread() reads up to count bytes from file descriptor fd at offset offset (from the start of the file) into the buffer starting at buf.  The file offset is not changed.

   ---

- Line 20
` int mprotect(void *addr, size_t len, int prot);`

mprotect() changes the access protections for the calling process's memory pages containing any part of the address range in the interval [addr, addr+len-1]. 

Some prot flags:

*PROT_NONE* : The memory cannot be accessed at all.

*PROT_READ* : The memory can be read.

*PROT_WRITE* : The memory can be modified.

*PROT_EXEC* : The memory can be executed.

---

- Line 35
` ssize_t write(int fd, const void *buf, size_t count);`

write() writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor fd.

---

- Line 52
`off_t lseek(int fd, off_t offset, int whence);`

lseek() repositions the file offset of the open file description associated with the file descriptor fd to the argument offset according to the directive whence as follows:

*SEEK_SET* : The file offset is set to offset bytes.

*SEEK_CUR* : The file offset is set to its current location plus offset bytes.

*SEEK_END* : The file offset is set to the size of the file plus offset bytes.

---

- Line 53
`noreturn void syscall(SYS_exit_group, int status);`

exit all threads in a process
