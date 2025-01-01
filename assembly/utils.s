.text
.global write
.global exit
.global deepcopy


store_char:
    add     x3, x1, x2, lsr #3
    ret


write:
    // x0 = stdout
    // x1 = msg 주소
    // x2 = 길이(13)

    // x16 = 0x2000004 (Darwin write)
    movz    x16, #0x0004           // 하위 16비트 = 0x0004
    movk    x16, #0x0200, lsl #16  // 상위 16비트 = 0x0200
    svc     #0
    ret

exit:
    // x0 = 종료 코드(0)
    // x16 = 시스템 콜 번호(0x2000001, Darwin exit)

    mov     x0, #0                 
    movz    x16, #0x001
    movk    x16, #0x0200, lsl #16
    svc     #0
    ret



deepcopy:
    cmp     x2, #0              // 남은 길이가 0인지 확인
    beq     deepcopy_done       // 0이면 복사 종료

    ldrb    w4, [x1], #1        // x1이 가리키는 주소에서 1바이트 읽기
    strb    w4, [x3], #1        // x3이 가리키는 주소에 1바이트 쓰기
    subs    x2, x2, #1          // 복사할 남은 길이 감소
    b.ne    deepcopy            // 남은 길이가 0이 아니면 반복

deepcopy_done:
    ret                         // 함수 종료
