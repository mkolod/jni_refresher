# hello_asm.s
# as hello_asm.s -o hello_asm.o
# ld hello_asm.o -e _main -o hello_asm
.section __DATA,__data
str:
  .asciz "Hello from assembly!\n"

.section __TEXT,__text
.globl _helloAsm
#_main
_helloAsm:
  movl $0x2000004, %eax           # preparing system call 4
  movl $1, %edi                   # STDOUT file descriptor is 1
  movq str@GOTPCREL(%rip), %rsi   # The value to print
  movq $100, %rdx                 # the size of the value to print
  syscall
  ret