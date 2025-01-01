
.global _start
.align 2
.include "my_lib.inc"

.section __TEXT,__text

_start:
    // msg 주소 설정
    adrp    x1, msg@PAGE
    add     x1, x1, msg@PAGEOFF
    adrp    x3, buffer@PAGE
    add     x3, x3, buffer@PAGEOFF
    mov     x2, #14             // 복사할 길이 (14 바이트)
    bl      deepcopy            // msg → buffer 복사

    // buffer 데이터 수정
    mov     w2, #'J'            // 'J'로 변경
    strb    w2, [x3]            // buffer[0] = 'J'

    mov     w2, #'E'            // 'E'로 변경
    add     x4, x3, #7          // buffer[7] 위치로 이동
    strb    w2, [x4]            // buffer[7] = 'E'

    // 첫 번째 출력: msg
    mov     x0, #1              // stdout
    mov     x1, x1              // msg 주소
    mov     x2, #14             // 길이
    bl      write

    // 두 번째 출력: buffer
    mov     x0, #1              // stdout
    mov     x1, x3              // buffer 주소
    mov     x2, #14             // 길이
    bl      write

    // 종료
    bl      exit
// 이래서 assembly 잘 안쓰는 구나 rust로 가야할듯

.section __DATA,__data
.align 2

msg:
    .asciz "Hello World!\n"

buffer:
    .space 14                   // 14 바이트 크기의 빈 버퍼

