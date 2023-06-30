section .data
    hello db 'Hello, Holberton', 0
    format db '%s', 0
    newline db 10, 0

section .text
    global main
    extern printf

main:
    sub rsp, 8       ; Align stack

    mov rdi, format  ; Format string
    mov rsi, hello   ; String to print
    xor eax, eax     ; Clear eax register
    call printf      ; Call printf function

    mov rdi, format  ; Format string
    mov rsi, newline ; New line string
    xor eax, eax     ; Clear eax register
    call printf      ; Call printf function

    add rsp, 8       ; Restore stack
    mov eax, 0x60    ; Exit syscall number
    xor edi, edi     ; Exit status code
    syscall          ; Call kernel
