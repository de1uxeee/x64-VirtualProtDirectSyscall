EXTERN asm_ZwVirtProt : NEAR
EXTERN kernelBasePlusDE99E : QWORD
EXTERN openThreadTokenPlus40h : QWORD

.CODE
 
asm_VirtualProtect PROC

    mov rax, rsp
	mov [rax + 18h], rbx
	push rbp
	push rsi
	push rdi
	sub rsp, 30h
	mov rsi, r9
	mov [rax - 28h], r9
	mov r9d, r8d
	mov [rax + 08h], rdx
	mov ebp, r8d
	mov [rax + 10h], rcx
	lea r8, [rax + 08h]
	or rcx, -1h
	lea rdx, [rax + 10h]
	call asm_ZwVirtProt
	nop dword ptr [rax + rax + 0h]
	xor ebx, ebx
	mov edi, eax
	test eax, eax
	js label1
	mov ebx, 01h

	label2:
	mov eax, ebx
	mov rbx, [rsp + 60h]
	add rsp, 30h
	pop rdi
	pop rsi
	pop rbp
	ret

	label1:
	cmp eax, 0C0000045h
	je label3
	mov ecx, edi
	call openThreadTokenPlus40h
	jmp label2

	label3:
	jmp kernelBasePlusDE99E

asm_VirtualProtect ENDP
 
END