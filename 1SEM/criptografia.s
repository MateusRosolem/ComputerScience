	.file	"criptografia.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "digte a frase desejada\0"
LC1:
	.ascii "%s\0"
	.align 4
LC2:
	.ascii "digite o A e B para a funcao ax+b \0"
LC3:
	.ascii "%i %i\0"
	.align 4
LC4:
	.ascii "\12 sua frase digitada em numeros eh: \0"
LC5:
	.ascii "%d \0"
	.align 4
LC6:
	.ascii "\12 sua frase digitada em numeros criptografados eh: \0"
	.align 4
LC7:
	.ascii "\12 sua frase digitada em frase criptografada eh: \0"
LC8:
	.ascii "%c \0"
	.align 4
LC9:
	.ascii "\12 sua frase criptografada digitada em numeros eh: \0"
	.align 4
LC10:
	.ascii "\12sua funcak inversa eh %dx+%d \12\0"
	.align 4
LC11:
	.ascii "\12 sua frase DEScriptografada digitada em numeros eh: \0"
	.align 4
LC12:
	.ascii "\12 sua frase digitada em frase DEScriptografada eh: \0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$496, %esp
	call	___main
	movl	$LC0, (%esp)
	call	_puts
	leal	418(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_scanf
	movl	$LC2, (%esp)
	call	_puts
	leal	468(%esp), %eax
	movl	%eax, 8(%esp)
	leal	472(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC3, (%esp)
	call	_scanf
	movl	$LC4, (%esp)
	call	_puts
	movl	$0, 484(%esp)
	jmp	L2
L3:
	leal	418(%esp), %edx
	movl	484(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movb	%al, 483(%esp)
	movsbl	483(%esp), %eax
	leal	-97(%eax), %edx
	movl	484(%esp), %eax
	movl	%edx, 216(%esp,%eax,4)
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	addl	$1, 484(%esp)
L2:
	leal	418(%esp), %edx
	movl	484(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L3
	movl	$LC6, (%esp)
	call	_puts
	movl	484(%esp), %eax
	movl	%eax, 476(%esp)
	movl	$0, 484(%esp)
	jmp	L4
L5:
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %edx
	movl	472(%esp), %eax
	imull	%eax, %edx
	movl	468(%esp), %eax
	leal	(%edx,%eax), %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$26, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	484(%esp), %edx
	movl	%eax, 216(%esp,%edx,4)
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	addl	$1, 484(%esp)
L4:
	movl	476(%esp), %eax
	cmpl	484(%esp), %eax
	jne	L5
	movl	$LC7, (%esp)
	call	_puts
	movl	$0, 484(%esp)
	jmp	L6
L7:
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	leal	97(%eax), %edx
	movl	484(%esp), %eax
	movl	%edx, 216(%esp,%eax,4)
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	addl	$1, 484(%esp)
L6:
	movl	476(%esp), %eax
	cmpl	484(%esp), %eax
	jne	L7
	movl	$10, (%esp)
	call	_putchar
	movl	$10, (%esp)
	call	_putchar
	movl	$LC9, (%esp)
	call	_puts
	movl	$0, 484(%esp)
	jmp	L8
L9:
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	leal	-97(%eax), %edx
	movl	484(%esp), %eax
	movl	%edx, 216(%esp,%eax,4)
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	addl	$1, 484(%esp)
L8:
	leal	418(%esp), %edx
	movl	484(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L9
	movl	$10, (%esp)
	call	_putchar
	movl	$10, (%esp)
	call	_putchar
	movl	$0, 484(%esp)
	jmp	L10
L11:
	movl	484(%esp), %eax
	movl	%eax, 492(%esp)
	addl	$1, 484(%esp)
L10:
	movl	472(%esp), %eax
	imull	492(%esp), %eax
	movl	%eax, %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$26, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	cmpl	$1, %eax
	jne	L11
	movl	$0, 484(%esp)
	jmp	L12
L13:
	movl	484(%esp), %eax
	movl	%eax, 488(%esp)
	addl	$1, 484(%esp)
L12:
	movl	472(%esp), %eax
	imull	488(%esp), %eax
	movl	%eax, %edx
	movl	468(%esp), %eax
	leal	(%edx,%eax), %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$26, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	jne	L13
	movl	488(%esp), %eax
	movl	%eax, 8(%esp)
	movl	492(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	$LC11, (%esp)
	call	_puts
	movl	$0, 484(%esp)
	jmp	L14
L15:
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	imull	492(%esp), %eax
	movl	%eax, %edx
	movl	488(%esp), %eax
	leal	(%edx,%eax), %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$26, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	484(%esp), %edx
	movl	%eax, 216(%esp,%edx,4)
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	addl	$1, 484(%esp)
L14:
	leal	418(%esp), %edx
	movl	484(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L15
	movl	$LC12, (%esp)
	call	_puts
	movl	$0, 484(%esp)
	jmp	L16
L17:
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	leal	97(%eax), %edx
	movl	484(%esp), %eax
	movl	%edx, 216(%esp,%eax,4)
	movl	484(%esp), %eax
	movl	216(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	addl	$1, 484(%esp)
L16:
	movl	476(%esp), %eax
	cmpl	484(%esp), %eax
	jne	L17
	movl	$0, %eax
	leave
	ret
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
