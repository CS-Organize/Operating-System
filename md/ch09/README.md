- [Basic Hardware](#basic-hardware)
  - [CPU가 직접 접근할 수 있는 유일한 범용 저장장치](#cpu가-직접-접근할-수-있는-유일한-범용-저장장치)
  - [올바른 동작을 위한 메모리 관리](#올바른-동작을-위한-메모리-관리)
- [Address Binding](#address-binding)
- [Logical vs Physical Address Space](#logical-vs-physical-address-space)
- [Memory Allocation](#memory-allocation)
  - [메모리가 연속적일 때](#메모리가-연속적일-때)
    - [가변 파티션](#가변-파티션)
    - [External Fragmentation](#external-fragmentation)
    - [Internal Fragmentation](#internal-fragmentation)
  - [메모리가 불연속적일 때](#메모리가-불연속적일-때)
    - [Paging](#paging)

> **전반적인 명령어 실행**
>
> 1. 메모리로 부터 한 명령어 가져옴
> 2. 명령어를 해독
> 3. 메모리에서 피연산자를 가져와 피연산자에 대해 명령 실행
> 4. 계산 결과를 메모리에 다시 저장

# Basic Hardware

## CPU가 직접 접근할 수 있는 유일한 범용 저장장치

1. 메인 메모리 -> 버스를 통해 전송되므로 많은 CPU 클록 틱 사이클 소요 -> 데이터가 없어서 명령이 지연되는 stall 현상 발생 -> CPU와 메인 메모리 사이에 빠른 속도의 메모리인 cache 추가
2. 각 코어에 내장된 레지스터 -> accessible 1 cycle of the CPU clock

## 올바른 동작을 위한 메모리 관리

![](/img/mem-01.png)
물리 메모리의 접근 속도도 중요하지만 올바른 동작을 보장하는 것도 중요

- 사용자 프로그램으로부터 운영체제 영역 보호
- 사용자 프로그램 간 보호
  운영체제가 CPU와 메모리 간의 접근 중 개입 -> 성능 저하 -> 하드웨어가 지원

**각각의 프로세스가 독립된 메모리 공간을 가지도록 보장**
병행 실행을 위해 여러 프로세스가 메모리에 적재되게 하는 것이 필수적 -> base register and limit register 이용하여 특정 프로세스만 접근 가능한 legal memory space 설정

> `base register` <= `legal memory` <= `base register + limit register`

- 사용자 모드에서 illegal 접근을 한다면 운영체제는 치명적인 오류로 간주 -> trap 발생
- base register와 limit register는 운영체제의 특권 명령으로만 변경 가능

# Address Binding

`program` -> 디스크에 저장되어 있는 binary executable file

![](/img/mem-02.png)

- `source program`에서 주소는 숫자가 아닌 심볼 형태(변수)로 표현된다.
- `compiler`는 이 심볼 주소를 relocatable addresses(예를 들어 이 모듈의 첫 번째 바이트로부터 열네 번째 바이트 주소)로 바인딩
- `linker` or `loader` is binds `relocatable addresses` to `absolute addresses`

# Logical vs Physical Address Space

- Logical address: CPU가 생성하는 주소
- Physical Address Space: 메모리의 실제 주소 (메모리 주소 레지스터에 주어지는 주소)

프로그램 실행 시 가상 주소를 물리 주소로 변환하는 작업은 하드웨어 장치인 MMU(Memory Management Unit)에 의해 실행된다.

# Memory Allocation

## 메모리가 연속적일 때

### 가변 파티션

- 프로세스를 메모리의 가변 크기 파티션에 할당
- 각 파티션에는 정확히 하나의 프로세스만 적재
- 운영체제는 사용 가능, 불가능 부분을 나타내는 `hole` 테이블을 유지
  - `hole`: 하나의 큰 사용 가능한 메모리 블록
  - 메모리가 충분하지 않다면 프로세스가 거부하거나 대기큐에 넣어서 프로세스가 적재될 `hole`이 생긴다면 프로세스를 실행시킬 수 있다.
  - 5를 차지하는 A 프로세스가 `hole(0, 9)` 에 들어가면 `hole(0,4)`에 들어가고 `hole(5, 9)`가 새로운 `hole`이 왼다.

**동적 메모리 할당 문제**

- first-fit: `hole` 테이블을 순회하면서 첫 번째로 발견한 가용 공간을 할당
- best-fit: `hole` 테이블을 모두 순회하여 가장 로스가 적은 가용 공간을 할당
- worst-fit: 가장 큰 가용 공간을 할당 => 나머지 가용공간은 새로운 `hole`이 된다.

-> first-fit과 best-fit가 가장 비용이 적었다.

### External Fragmentation

- 프로세스들이 메모리에 적재되고 제거되는 일이 반복되다 보면 어떤 가용 공간은 너무 작은 조각이 되어버리는 문제, 모든 유휴공간을 합치면 충분한 공간이 되지만 여러 곳에 분산되어있을 때 발생
- 가변 파티션 방식은 모두 `External Fragmentation` 문제를 겪음
- first-fit 방식은 `50% rule` => 메모리의 $1/3$ 을 쓸 수 없게 될 수 있음
- 해결책: 모든 메모리를 한 군데로 몰고 모든 가용 공간을 큰 블록을 만드는 `compaction` 방식
  - 외부 단편화를 해결할 수 있으나 프로세스들의 재배치가 execution time에 동적으로 이루어지는 경우에만 가능
  - 위치를 옮기고 기준 레지스터만 변경 -> 비용이 큼

### Internal Fragmentation

- 프로세스의 크기에 딱 떨어지는 `hole`은 없으므로 엄청 작은 단위의 `hole`이 생길 수 있음, 이는 테이블에 기록해야 하기 때문에 더 큰 오버헤드가 됨
- 이 문제 때문에 메모리를 아주 작은 공간들로 분할하여 프로세스가 요청하면 할당을 항상 이 분할된 크기의 배수로 해주는 것이 일반적

## 메모리가 불연속적일 때

### Paging

- `frame`: 물리 메모리를 같은 크기의 블록으로 나눈 것
- `page`: `frame`에 대응되는 논리 메모리, 컴퓨터에 따라 4KB ~ 1GB의 크기를 가짐
- 저장장치는 `frame`혹은 `frame`의 묶음인 `cluster`와 동일한 고정 크기 블록으로 나누어짐
- 모든 Logical address는 페이지 번호 `p`와 페이지 오프셋 `d: offset` 두 개의 부분으로 나누어짐

-> 메모리에 대한 프로그래머의 인식이 실제 내용과 다름

**MMU가 logical address를 physical address로 변환하는 방법**

1. `p`를 추출하여 page table의 인덱스로 사용
2. page table에서 해당 frame 번호 `f`를 추출
3. logical address의 `p`를 `f`로 변환

**Internal Fragmentation**

- `page`의 배수로 프로세스에게 공간이 할당되기 때문에 External Fragmentation는 발생하지 않지만 Internal Fragmentation이 일어남
  - `page`의 크기가 작아지면 Internal Fragmentation이 완화되지만 page table의 크기가 커짐
  - `page`의 크기가 커지면 Internal Fragmentation이 악화되지만 디스크의 처리 속도가 올라감 (프로세스 크기가 올라감에 따라 채택)
