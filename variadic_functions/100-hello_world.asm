section .data
    msg db "Hello, World", 10  ; String with newline
    len equ $ - msg            ; Calculate length

section .text
    global _start              ; Entry point

_start:
    mov rax, 1                 ; syscall: write
    mov rdi, 1                 ; stdout
    mov rsi, msg               ; address of string
    mov rdx, len               ; length of string
    syscall                    ; invoke syscall

    mov rax, 60                ; syscall: exit
    xor rdi, rdi               ; exit code 0
    syscall                    ; invoke syscall
