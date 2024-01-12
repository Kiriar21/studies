.code

suma proc
	
	xor rax,rax
	; rcx, rdx, r8  - kolumny
	mov r9, rcx; tablica
	mov r10, rdx; wiersze
	
	wiersze:
		mov r13, [r9+8*r10-8]
		mov r12, r8
		kolumny:
			movsxd r11, dword ptr[r13+4*r12-4]
			add rax, r11;
			dec r12
			jnz kolumny
		dec r10
		jnz wiersze
	ret
suma endp

end



xor rax,rax

	wiersze:
		mov r9, [rcx+8*rdx-8]
		mov r10, r8;
		
		kolumny:
			movsxd r11, dword ptr[r9+4*r10-4]
			add rax, r11;
			dec r10
			jnz kolumny
			dec rdx
			jnz wiersze

		ret;