# Author: Amittai Aviram - aviram@bc.edu

	.file	"div.s"
	.text
	.globl	div_qr
	.type	div_qr, @function
div_qr:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movq	%rdx, -16(%rbp)
	movl	-4(%rbp), %eax
	cltd
	idivl	-8(%rbp)
	movq	-16(%rbp), %rcx
	movl	%edx, (%rcx)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
    
.LFE0:
	.size	div_qr, .-div_qr
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
