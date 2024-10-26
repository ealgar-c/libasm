<h1 align='center'>libasm</h1>

*A 42 Advanced project where you will start to see the beautiness of the assembly language.*

(Even though there are multiple calling conventions, this project will be made based on the **SysV ABI for x86-64**)

---


Assembly is a low-level programming language that lets you write instructions for the computer in a way that's close to its actual machine code. It works by giving the computer direct, step-by-step instructions that tell it exactly what to do with its registers and memory.

## REGISTERS 
*Registers are small, high-speed storage locations within the CPU itself, and they play a critical role in assembly language programming. Each register can hold a small amount of data, like numbers or addresses, which the CPU needs immediately for processing.*

### The registers in our actual calling convention are used as follows:

RDI, RSI, RDX, RCX, R8, R9: Argument-passing registers.

RAX, RDX, XMM0, XMM1: Return values.
*(RDX will only be used if the return value is large and does not fit on RAX)*

RCX, RDX, R8, R9, R10, R11: Caller-saved, temporary registers.

RBX, RBP, R12, R13, R14, R15: Callee-saved, preserved across function calls.

RSP, RIP, RFLAGS: Special-purpose registers for stack, instruction tracking, and status flags.

Also, as a standard, we will use RCX as a so called counter register.

## INSTRUCTIONS
*As requested in the subject, we will be using the Intel syntax; meaning that in the instructions, the destination will be the left value and the source the right one*

### Movement instructions
- mov --> Moves data from one location to other

		mov rax, 1	;  Inserts the value 1 into rax

### Arithmetic instructions
- add --> Add two values, storing it in the destination

		add rdx, 3	;  Adds 3 to the value of the rdx reg, storing the result in rdx

- sub --> Substract two values, storing it in the destination

		sub rdx, 3	;  Substracts 3 to the value of the rdx reg, storing the result in rdx

- mul --> Multiply two values, storing it in the destination

		mul rdx, 3	;  Multiply by 3 the value of the rdx reg, storing the result in rdx

### Comparison and Conditional jumps
- cmp --> Compares two values and sets flags based on the result
- je --> Jump if equal
- jne --> Jump if not equal
- jz --> Jump if the zero flag is set

		cmp rdx, 7		;  Compares rdx to 7
		je eq_lbl		;  Jumps to the eq_lbl label if the previous comparation was equal
		jne n_eq_lbl	;  Jumps to the n_eq_lbl label if the previous comparation was not equal

### Function calls and Stack management

- call --> Calls a function (and saves the return value on the stack)
- ret --> Returns from a function (It returns the value on rax)
- pop --> Pops a value from the stack into a register or memory location
- push --> Pushes a value onto the stack

		push rdx				;  Push rdx onto the stack
		call my_function 	;  Call my_function
		pop rbx					;  Pop top of stack into rbx

### Other common instructions

- inc / dec --> Increment or decrement a value by 1

		inc rdx	;  increments in one the value of rdx