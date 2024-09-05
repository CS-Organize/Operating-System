# Interrupt

## CPU 동작
1. 명령어를 수행
2. `interrupt request line` 검사

### Interrupt 동작
1. I/O device가 이 라인에 신호를 보내면 CPU가 확인하여 각종 레지스터의 값과 상태정보를 저장한다음 (cs), 메모리 상의 `ISR (Interrupt Handler Routine)`으로 jump
2. `ISR`
	1. `interrupt handler`가 interrupt 발생 원인 조사
	2. 필요한 작업 수행
	3. interrupt 이전으로 복귀 명령
