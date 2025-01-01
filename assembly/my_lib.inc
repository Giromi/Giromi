.extern write
.extern exit
.extern deepcopy


// Extern 선언

// 매크로 정의
.macro LOAD_IMMEDIATE reg, value
    mov \reg, #\value
.endm

// 상수 정의
.equ MY_CONSTANT, 42
