.CODE
 
asm_ZwVirtProt PROC

    mov r10, rcx
    mov eax, 50h
    syscall
    ret

asm_ZwVirtProt ENDP
 
END