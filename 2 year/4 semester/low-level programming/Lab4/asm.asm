.code

public zad1
zad1 proc

mov r8, rcx;
mov r9, rdx;

petla:
	cmp r9, 1;
	jl pomin
	movsxd r10, dword ptr[r8+4*r9-4]
	imul r10, r10;
	mov dword ptr[r8+4*r9-4], r10d
	dec r9
	jmp petla
pomin:
ret
zad1 endp

public zad2
zad2 proc

mov r8, rcx;
mov r9, rdx;
mov r11, 2

petla:
	xor rdx, rdx
	xor rax, rax
	cmp r9, 1;
	jl pomin
	movsxd rax, dword ptr[r8+4*r9-4]
	idiv r11
	cmp rdx, 0
	jg skocz
		movsxd r10, dword ptr[r8+4*r9-4]
		imul r10, r10;
		mov dword ptr[r8+4*r9-4], r10d
	skocz:
	dec r9
	jmp petla
pomin:
ret
zad2 endp

public zad3
zad3 proc

mov r8, rcx;
mov r9, rdx;

petla:
	cmp r9, 1
	jl pomin
		mov dword ptr[r8+4*r9-4],0
	sub r9,2
	jmp petla
pomin:
ret
zad3 endp

public zad4
zad4 proc

mov r8, rcx;
mov r9, rdx;
mov r10, rdx;
xor rax, rax;

petla:
	cmp r9, 1
	jl pomin
		movsxd rcx, dword ptr[r8+4*r9-4];
		add rax, rcx
	dec r9
	jmp petla
pomin:
xor rdx, rdx
div r10
ret
zad4 endp

public zad5
zad5 proc

mov r8, rcx;
mov r9, rdx;

movsxd rax, dword ptr[r8+4*r9-4];
dec r9
petla:
	cmp r9,1
	jl pomin
	movsxd r10, dword ptr[r8+4*r9-4]
	cmp rax, r10
	jle skocz
	mov rax, r10
	skocz:
	dec r9
	jmp petla
pomin:
ret
zad5 endp


public zad6
zad6 proc

mov r8, rcx;
mov r9, rdx;

movsxd rax, dword ptr[r8+4*r9-4];
dec r9
petla:
	cmp r9,1
	jl pomin
	movsxd r10, dword ptr[r8+4*r9-4]
	cmp rax, r10
	jge skocz
	mov rax, r10
	skocz:
	dec r9
	jmp petla
pomin:
ret
zad6 endp


public zad7
zad7 proc
; zrobic
zad7 endp

public zad8
zad8 proc

mov r9, rcx; tab
mov r10, rdx; tab1


petla:
	cmp r8, 1
	jl pomin

		movsxd r11, dword ptr[r9+4*r8-4]
		movsxd rax, dword ptr[r10+4*r8-4]
		add r11, rax
		mov dword ptr[r9+4*r8-4], r11d;

	dec r8
	jmp petla
pomin:
ret
zad8 endp

public zad9
zad9 proc


; r8 tab2
mov r10, rcx; tab
mov r11, rdx; tab1
; r9 rozmiar

petla:
	cmp r9, 1
	jl pomin

	movsxd rax, dword ptr[r10+4*r9-4];
	movsxd r12, dword ptr[r11+4*r9-4];
	xor rdx, rdx
	idiv r12;
	mov r12, rax;
	mov dword ptr[r8+4*r9-4], r12d;
	dec r9
	jmp petla
pomin:
ret
zad9 endp

public zad10
zad10 proc


mov r8, rcx; tab
mov r9, rdx; rozmiar

petla:
	cmp r9, 1
	jl pomin
	
	movsxd rax, dword ptr[r8+4*r9-4];
	mov r11, rax;

	drugapetla:
		cmp r11, 2
		jl koniecdrugiej
		movsxd r12, dword ptr[r8+4*r9-4];
		add rax, r12
		dec r11
		jmp drugapetla
	koniecdrugiej:
	mov r10, rax;
	mov dword ptr[r8+4*r9-4],r10d;
	dec r9
	jmp petla
pomin:
ret
zad10 endp

end