> https://github.com/jlevy/the-art-of-command-line/tree/master

- [Command Structure](#command-structure)
- [Shortcut](#shortcut)
- [Command](#command)
  - [Manual](#manual)
    - [type](#type)
    - [which](#which)
    - [help](#help)
    - [man](#man)
  - [Basic](#basic)
    - [clear](#clear)
    - [date](#date)
    - [cal](#cal)
    - [ncal](#ncal)
    - [history](#history)
  - [User](#user)
    - [whoami](#whoami)
    - [id](#id)
    - [su](#su)
    - [adduser](#adduser)
    - [deluser](#deluser)
    - [passwd](#passwd)
    - [who](#who)
    - [addgroup](#addgroup)
    - [groups](#groups)
  - [File System](#file-system)
    - [open](#open)
    - [pwd](#pwd)
    - [ls](#ls)
    - [cd](#cd)
    - [touch](#touch)
    - [file](#file)
    - [mkdir](#mkdir)
    - [rm](#rm)
    - [rmdir](#rmdir)
    - [mv](#mv)
    - [cp](#cp)
    - [cat](#cat)
    - [less](#less)
    - [tac](#tac)
    - [rev](#rev)
    - [head](#head)
    - [tail](#tail)
    - [wc](#wc)
    - [sort](#sort)
    - [pbcopy](#pbcopy)
    - [pbpaste](#pbpaste)
    - [tr](#tr)
    - [sed](#sed)
    - [awk](#awk)
    - [du](#du)
    - [df](#df)
    - [tee](#tee)
    - [find](#find)
    - [xargs](#xargs)
    - [grep](#grep)
    - [egrep](#egrep)
  - [Network](#network)
    - [ifconfig](#ifconfig)
  - [Process](#process)
    - [ps](#ps)
    - [lsof](#lsof)
    - [ulimit](#ulimit)
    - [time](#time)
- [Redirection](#redirection)
  - [기본 사용법](#기본-사용법)
  - [Default Value](#default-value)
  - [File Descriptor](#file-descriptor)
  - [stream이란](#stream이란)
  - [Redirecting stdout stream](#redirecting-stdout-stream)
    - [overwrite (\>)](#overwrite-)
    - [append (\>\>)](#append-)
    - [Example](#example)
      - [명령어의 결과를 file.txt에 남기기](#명령어의-결과를-filetxt에-남기기)
      - [특정 스크립트 실행 결과와 에러를 같은 파일에 남기기](#특정-스크립트-실행-결과와-에러를-같은-파일에-남기기)
      - [특정 스크립트 실행 결과와 에러를 분리해서 저장하기](#특정-스크립트-실행-결과와-에러를-분리해서-저장하기)
      - [stdout은 overwrite, stderr는 append하기](#stdout은-overwrite-stderr는-append하기)
    - [정리](#정리)
- [Pipe](#pipe)
- [Expansion](#expansion)
- [Regex (Regular Expression)](#regex-regular-expression)
- [File Attributes](#file-attributes)
  - [chmod](#chmod)
  - [su](#su-1)
  - [sudo](#sudo)
  - [chown](#chown)
- [Environment](#environment)
  - [Environment Variables](#environment-variables)
    - [export](#export)
    - [printenv](#printenv)
  - [Shell Variables](#shell-variables)
  - [Special Variables](#special-variables)
  - [Startup Files](#startup-files)
  - [Alias](#alias)
- [Shell Script](#shell-script)
  - [curl](#curl)
- [Cron](#cron)
  - [Syntax](#syntax)
  - [Error Resolution](#error-resolution)
  

# Command Structure

```bash
> command [options] [arguments]
```

- `command` : command name
- `options` : option
  - `-` : short option
  - `--` : long option

# Shortcut

- `⌘ + ←, →` : Move cursor to the beginning(or end) of the line
- `⌥ + ←, →` : Move cursor to the beginning(or end) of the word
- `⌘ + K` : Clear terminal
- `⌃ + A, E` : Move cursor to the beginning(or end) of the line
- `⌃ + L` : Clear terminal
- `⌃ + U` : Delete line
- `⌃ + K` : Delete from cursor to the end of the line
- `⌃ + W` : Delete word
- `⌃ + Y` : Paste deleted text
- `⌃ + R` : Search history
- `⌃ + G` : Cancel search history
- `⌃ + D` : Delete character
- `⌃ + F` : Move cursor forward
- `⌃ + B` : Move cursor backward
- `⌃ + P, ↑` : Show previous command
- `⌃ + N, ↓` : Show next command

# Command

## Manual

### type

4 command types
- executable program(binary)
- shell built-in command
- shell function
- alias

### which

`which` command is used to find executable program(binary) path

### help

`help` command is used instead of `man` for shell built-in command
(zsh doesn't support `help` command, so use `man zshbuiltins`)

### man

```bash
> man [command name]
```

- `q` : quit
- `h` : help
- `space(or f)` : forward page
- `b` : back page
- `/` : search
- `n` : next search
- `N` : previous search

```bash
> man echo

echo [-n] [string ...]
```

- `[]` : optional
- `...` : repeatable

## Basic

### clear

```bash
> clear
```

### date

```bash
> date
Wed Jan 31 18:19:27 KST 2024
```

### cal

```bash
> cal
    January 2024      
Su Mo Tu We Th Fr Sa  
    1  2  3  4  5  6  
 7  8  9 10 11 12 13  
14 15 16 17 18 19 20  
21 22 23 24 25 26 27  
28 29 30 31  
```

### ncal

```bash
> ncal
    January 2024      
Mo  1  8 15 22 29   
Tu  2  9 16 23 30   
We  3 10 17 24 31   
Th  4 11 18 25      
Fr  5 12 19 26      
Sa  6 13 20 27      
Su  7 14 21 28     
```

### history

`history` command is used to show command history

- `![history number]` : command is used to execute command history
- `!!` : command is used to execute previous command
- `$HISTSIZE` : environment variable is used to set command history size

## User

### whoami

`whoami` command is used to print the user name

```bash
> whoami
seunan
```

### id

`id` command is used to print real and effective user and group IDs

```bash
> id
uid=501(seunan) gid=20(staff) groups=20(staff),12(everyone),61(localaccounts),79(_appserverusr),80(admin),81(_appserveradm),98(_lpadmin),701(com.apple.sharepoint.group.1),33(_appstore),100(_lpoperator),204(_developer),250(_analyticsusers),395(com.apple.access_ftp),398(com.apple.access_screensharing),399(com.apple.access_ssh)
```

### su

`su` command is used to switch user

```bash
> su [options] [user]
su - # switch to root
```

### adduser

`adduser` command is used to add user

```bash
> adduser [option] [user] [group]
adduser seunan
```

- `/etc/passwd` : user account information
- `/etc/shadow` : user password information
- `/etc/group` : group information

### deluser

`deluser` command is used to delete user

```bash
> deluser [options] [user]
deluser seunan
```

`deluser --remove-home [user]` : delete user and home directory

### passwd

`passwd` command is used to change user password

```bash
> passwd [options] [user]
passwd seunan
```

### who

`who` command is used to show who is logged on

```bash
> who
seunan console  Jan 31 18:19
```

### addgroup

`addgroup` command is used to add group

```bash
> addgroup [options] [group]
addgroup seunan
```

### groups

`groups` command is used to print the groups a user is in

```bash
> groups
staff everyone localaccounts _appserverusr admin _appserveradm _lpadmin com.apple.sharepoint.group.1 _appstore _lpoperator _developer _analyticsusers com.apple.access_ftp com.apple.access_screensharing com.apple.access_ssh
```

## File System

### open

`open` command is used to open file or directory 

- `/` : root directory
- `~` : home directory
- `.` : current directory
- `..` : parent directory

### pwd

Print working directory

### ls

List directory contents

### cd 

Change directory

### touch

`touch` command is used to create file

### file

`file` command is used to check file type
Warning : [Characters to watch out for when naming files](https://en.wikipedia.org/wiki/Filename)

### mkdir

MaKe DIRectory

### rm

ReMove file or directory

### rmdir

ReMove DIRectory

### mv

MoVe file or directory

```bash
> mv <source...> <destination>
mv abc.txt def.txt # abc.txt 파일을 def.txt로 이름을 바꾸어 이동, 파일 이름을 바꾸는 것과 결과가 같습니다.

mv abc.txt xyz
# xyz라는 디렉토리가 없다면 abc.txt 파일을 xyz로 이름을 바꾸어 이동합니다.
# xyz라는 디렉토리가 있다면 xyz 디렉토리 안으로 abc.txt 파일을 이동합니다.

mv abc.txt xyz/def.txt
# abc.txt 파일을 xyz 디렉토리 안으로 def.txt로 이름을 바꾸어 이동합니다.

mv abc xyz
# abc가 디렉토리이고 xyz라는 디렉토리가 없다면, abc 디렉토리를 xyz로 이름을 바꾸어 이동합니다.
# abc가 디렉토리이고 xyz라는 디렉토리가 있다면, abc 디렉토리를 xyz 디렉토리 안으로 이동합니다. 즉 xyz/abc가 됩니다.

mv abc xyz/zzz
# abc가 디렉토리이고 xyz/zzz라는 디렉토리가 없다면, abc 디렉토리를 xyz 디렉토리 안으로 zzz로 이름을 바꾸어 이동합니다.
# abc가 디렉토리이고 xyz/zzz라는 디렉토리가 있다면, abc 디렉토리를 xyz/zzz 디렉토리 안으로 이동합니다. 즉 xyz/zzz/abc가 됩니다.
```

### cp

CoPy file or directory

```shell
cp abc.txt def.txt #abc.txt 파일을 def.txt로 이름을 바꾸어 복사합니다.

cp abc.txt xyz
# xyz라는 디렉토리가 없다면 abc.txt 파일을 xyz 파일로 복사합니다.
# xyz라는 디렉토리가 있다면 xyz 디렉토리 안에 abc.txt 파일을 복사합니다.

cp abc.txt xyz/def.txt # abc.txt 파일을 xyz 디렉토리 안에 def.txt라는 이름으로 복사합니다.

cp -r abc xyz
# abc가 디렉토리이고 xyz라는 디렉토리가 없다면, abc 디렉토리를 xyz로 이름을 바꾸어 복사합니다.
# abc가 디렉토리이고 xyz라는 디렉토리가 있다면, abc 디렉토리를 xyz 디렉토리 안에 복사합니다. 즉 xyz/abc가 됩니다.

cp -r abc xyz/zzz
# abc가 디렉토리이고 xyz/zzz라는 디렉토리가 없다면, abc 디렉토리를 xyz 디렉토리 안에 zzz로 이름을 바꾸어서 복사합니다.
# abc가 디렉토리이고 xyz/zzz라는 디렉토리가 있다면, abc 디렉토리를 xyz/zzz 디렉토리 안에 복사합니다. 즉 xyz/zzz/abc가 됩니다.
```

### cat

conCATenate files and print on the standard output

### less

`less` command is used to show file contents

### tac

`cat` command is used to show file contents reversely

### rev

REVerse lines of a file

### head

`head` command is used to show first 10 lines of file

### tail

`tail` command is used to show last 10 lines of file

### wc

Word Count

### sort

`sort` command is used to sort lines of text files

```
> sort -k2 -n 
strawberry 5$
apple 2$  
banana 1.5$
grape 3$
---output---
banana 1.5$
apple 2$  
grape 3$
strawberry 5$
```

### pbcopy

`pbcopy` 명령어는 표준 입력을 클립보드에 복사합니다.

```shell
echo "Hello World" | pbcopy
```

### pbpaste

`pbpaste` 명령어는 클립보드의 내용을 표준 출력으로 복사합니다.

```shell
pbpaste > hello.txt
```

### tr

TRanslate or delete characters

```bash
> tr [options] [set1] [set2]
tr a-z A-Z # a-z를 A-Z로 바꿉니다.
tr -d a-z # a-z를 삭제합니다.
tr -s a-z # a-z를 하나로 합칩니다.
tr -c a-z # a-z를 제외한 문자를 삭제합니다.
```

### sed

Stream EDitor

```bash
> sed [options] [script] [inputfile]
sed 's/abc/xyz/' # abc를 xyz로 바꿉니다.
sed 's/abc/xyz/g' # abc를 xyz로 바꿉니다. (모든 문자열)
sed 's/abc/xyz/2' # abc를 xyz로 바꿉니다. (2번째 문자열)
sed 's/abc/xyz/2g' # abc를 xyz로 바꿉니다. (2번째 문자열부터 모든 문자열)
sed 's/abc/xyz/gi' # abc를 xyz로 바꿉니다. (대소문자 구분 없이 모든 문자열)
sed 's/abc/xyz/giw' # abc를 xyz로 바꿉니다. (단어 단위로 대소문자 구분 없이 모든 문자열)
```

### awk

```bash
> awk [options] [script] [inputfile]
awk '{print $1}' # 첫 번째 문자열을 출력합니다.
awk '{print $1, $2}' # 첫 번째 문자열과 두 번째 문자열을 출력합니다.
```

### du

Disk Usage

```bash
> du [options] [file or directory]
du -h # 사람이 읽기 쉬운 형태로 출력합니다.
du -s # 디렉토리의 용량을 출력합니다.
du -a # 디렉토리의 용량을 출력합니다. (파일 단위)
du -d # 디렉토리의 용량을 출력합니다. (깊이 단위)
du -c # 디렉토리의 용량을 출력합니다. (합계)
```

### df

Disk Free

```bash
> df [options] [file or directory]
df -h # 사람이 읽기 쉬운 형태로 출력합니다.
df -i # inode의 사용량을 출력합니다.
df -T # 파일 시스템의 종류를 출력합니다.
df -t # 파일 시스템의 종류를 출력합니다. (특정 파일 시스템)
df -a # 파일 시스템의 종류를 출력합니다. (모든 파일 시스템)
```

### tee

`tee` 명령어는 표준 입력을 표준 출력과 파일에 복사합니다.

```shell
echo "Hello World" | tee hello.txt
```

### find

`find` command is used to search for files in a directory hierarchy

```bash
> find [options] [path] [expression]
find <path> -name "*.txt" # 현재 디렉토리에서 txt 파일을 찾습니다.
find <path> -type f # 현재 디렉토리에서 파일을 찾습니다.
find <path> -size +1M # 현재 디렉토리에서 1MB 이상의 파일을 찾습니다.
find <path> -user root # 현재 디렉토리에서 소유자가 root인 파일을 찾습니다.
find <path> -group root # 현재 디렉토리에서 그룹이 root인 파일을 찾습니다.
a : access time
m : modify time
c : change time
find <path> -atime +1 # 현재 디렉토리에서 1일 이상 접근하지 않은 파일을 찾습니다.
find <path> -mtime -1 # 현재 디렉토리에서 1일 이내 변경한 파일을 찾습니다.
find <path> -ctime 1 # 현재 디렉토리에서 1일 이내 변경한 파일을 찾습니다.
find <path> -perm 644 # 현재 디렉토리에서 퍼미션이 644인 파일을 찾습니다.
> find -exec command {} \;
find <path> -ok command {} \; # 실행 여부를 물어봅니다
find <path> -type f -name "*.html" -exec cp {} '{}_copy' \; # html 파일을 찾아서 _copy를 붙여 복사합니다.
```

### xargs

`xargs` command is used to build and execute command lines from standard input

```bash
> xargs [options] [command]
xargs -t # 실행되는 명령어를 출력합니다.
xargs -I {} <command> {} # 명령어에 {}를 인자로 전달합니다.
```

### grep 

`grep` command is used to print lines matching a pattern

```bash
> grep [options] [pattern] [file or directory]
grep -i # 대소문자 구분 없이 검색합니다.
grep -v # 검색 결과를 제외합니다.
grep -n # 검색 결과의 줄 번호를 출력합니다.
grep -r # 하위 디렉토리까지 검색합니다.
grep -c # 검색 결과의 개수를 출력합니다.
grep -w # 단어 단위로 검색합니다.
grep -A<lines> # 검색 결과의 윗 줄을 출력합니다.
grep -B<lines> # 검색 결과의 아랫 줄을 출력합니다.
grep -C<lines> # 검색 결과의 윗 줄과 아랫 줄을 출력합니다.
```

### egrep

- `egrep` command is used to print lines matching a pattern, extended regular expression
- equal to `grep -E`

```bash
> egrep [options] [pattern] [file or directory]
egrep [abcdef]{2} <file> # character class
```

## Network

### ifconfig

ifconfig | grep inet => ip address
ifconfig | grep ether => MAC address

- [a](https://blockdmask.tistory.com/509)
- [b](https://ss64.com/osx/ifconfig.html)

## Process

### ps

`ps aux | grep Z` 좀비 프로세스 잡기
- [ref](https://www.linode.com/docs/guides/use-the-ps-aux-command-in-linux/)

### lsof

`lsof` 명령어도 특정 포트를 사용하는 프로세스를 확인하는 데 사용

`sudo lsof -i :포트번호`

예를 들어, 포트 8080을 사용하는 프로세스를 확인하려면 다음과 같이 입력합니다:

`sudo lsof -i :8080`

`lsof` 명령어는 루트 권한이 필요할 수 있으므로 `sudo`를 사용하여 실행하는 것이 일반적입니다. 이 명령어는 해당 포트를 사용 중인 프로세스와 해당 프로세스의 세부 정보를 표시합니다.

이러한 명령어를 사용하여 특정 포트가 이미 사용 중인지 확인할 수 있습니다. 포트가 사용 중이면 관련된 프로세스 정보도 확인할 수 있습니다.

lsof -p [Process ID] => 열려있는 fd 확인
0u
1u
2u 는 디폴트
3...

### ulimit

프로세스의 리소스 제한 설정
ulimit -a

변경은 현재 세션에서만 반영되기 때문에 쉘 초기화 파일(.zshrc)에 해당 명령을 추가하면 된다.

### time

time [commend]
commend가 걸리는 시간 측정

# Redirection

FD에 할당된 번호를 프로그래머가 원하는 쪽으로 redirect하는 것

shell도 프로세스기 때문에 redirection을 할 때 이와 같은 FD 번호를 사용한다.

## 기본 사용법

```shell
$ cat infile
hello
world
$ wc 0< infile 1> outfile
$ cat outfile
  2  2 12
```
왼쪽에 FD, 오른쪽에는 FD나 파일의 이름을 위치시키면 된다.

## Default Value

위의 예시에서 infile을 FD 0(stdin)에 연결해서 입력으로 사용했고
FD 1(stdout)을 outfile에 연결하여 출력이 outfile에 저장되게 했다.
redirection 기호를 사용할 때 FD 번호를 적지 않으면 standard stream이 사용된다.

## File Descriptor

우리가 사용하는 파일들은 우리가 알아보기 쉬운 이름으로 보여지지만, 실제 프로그램 실행 시에는 FD라는 양의 정수 번호에 의해 처리가 된다.

| FD  | Description     |
| --- | --------------- |
| 0   | standard input  |
| 1   | standard output |
| 2   | standard error  |

- 운영체제는 프로세스에게 3개의 기본 FD를 할당한다.
- 프로세스가 내부적으로 다른 파일을 open하게 되면 FD(3, 4, 5 ...)를 할당한다.

## stream이란

- UNIX 이전의 OS에서는 명령어를 입력하고 출력을 보기 위해서는 프로그래머가 직접 입/출력장치를 설정해야 했다.
- 하지만 UNIX부터는 *data stream*이라는 개념을 이용하여 프로그래머가 어떤 장치를 사용하는 지와 관계없이 open, read, write를 할 수 있게 했다. 또한 자동으로 입/출력 장치를 연결하여 많은 부담을 덜게 되었다.

`stream` 이란 디스크 상의 파일이나 컴퓨터에 연결되는 여러 장치들을 통일된 방식으로 다루기 위한 가상적인 개념이다.
- 데이터가 어디서 나와서 어디로 가는 지 신경 쓸 필요없이 장치, 프로세스, 파일들과 연결되어 많은 편리성을 제공해준다.
- 프로세스가 생성되는 기본적으로 입출력을 위한 채널을 가지게 되는데, 이를 standard stream이라고 한다.

UNIX에서는 모든 장치를 파일로 관리한다.
즉, standard stream도 각각 `/dev/stdin` `/dev/stdout` `/dev/stderr`에 파일로 존재한다.

## Redirecting stdout stream

- 데이터 흐름의 방향을 나타냄
- '>' 출력(overwrite)
- '>>' 출력(append)

### overwrite (>)

```shell
output > file.txt
```

- file.txt가 존재하지 않으면 새로 생성
- 이미 존재하면 덮어씌워짐

### append (>>)

```shell
output >> file.txt
```

- file.txt가 존재하지 않으면 새로 생성
- 이미 존재하면 기존의 내용 뒤에 덧붙임

### Example

#### 명령어의 결과를 file.txt에 남기기

```shell
ls > file.txt
```

- 표준 출력으로 출력되는 ls 의 결과값을 파일에 저장

#### 특정 스크립트 실행 결과와 에러를 같은 파일에 남기기

```shell
test.sh > file.txt 2> file.txt
test.sh > file.txt 2>&1
test.sh &> file.txt
test.sh &>> file.txt
```

#### 특정 스크립트 실행 결과와 에러를 분리해서 저장하기

```shell
test.sh > file.txt 2> errfile.txt
```

#### stdout은 overwrite, stderr는 append하기

```shell
test.sh > file.txt 2>> errfile.txt
```

### 정리

- 프로그램의 stdin, stdout, stderr를 파일이나 다른 스트림으로 전달할 때 사용

# Pipe

- 한 프로세스의 표준 출력을 다른 프로세스의 표준 입력으로 사용

# Expansion

- `*` : Wildcard
- `?` : Single Character
- `~` : Home Directory
- `{}` : Brace Expansion
  - `{a,b}` : a or b
  - `{a..z}` : a to z
  - `{a..z..2}` : a to z with step 2
  - `mkdir -p {Mon,Tue,Wed,Thu,Fri,Sat,Sun}/{Breakfast,Lunch,Dinner}` 
  - `{x,y{1..5},z}` : x, y1, y2, y3, y4, y5, z
- `$(())` : Arithmetic Expansion
  - `$(($a + $b))` : a + b
  - `$(($a - $b))` : a - b
- `` : Command Substitution
- $(command) : Command Substitution
  - `$(ls)`
  - `$(ls -l | grep txt)`
- `''` : Single Quote
  - Do not expand anything
- `""` : Double Quote
  - Expand variables
  - Do not expand wildcard

# Regex (Regular Expression)

- `.` : Any Character
- `*` : Zero or More
- `+` : One or More
- `?` : Zero or One
- `^` : Start of String
- `$` : End of String
- `[]` : Character Class
- `[^]` : Negated Character Class
- `[a-z]` : Range
- `\` : Escape Character

# File Attributes

`drw-r--r-- 1 seunan root 0 Jan 31 18:19 file.txt`

- `d` : file type (`-` : regular file, `d` : directory, `l` : symbolic link, `c` : character special file)
- `rw-` : owner permission (`r` : read, `w` : write, `x` : execute)
- `r--` : group permission
- `r--` : other permission
- `1` : number of hard links
- `seunan` : owner
- `root` : group
- `0` : file size
- `Jan 31 18:19` : last modified date
- `file.txt` : file name

## chmod

Change file mode bits

```bash
> chmod [options] [mode] [file or directory]
chmod u+x <file> # user에게 실행 권한을 줍니다.
chmod g-x <file> # group에게 실행 권한을 빼앗습니다.
chmod o-rwx <file> # other에게 읽기, 쓰기, 실행 권한을 빼앗습니다.
chmod 755 <file> # user에게 -rwxr-xr-x 권한을 줍니다.
```

- `u` : user
- `g` : group
- `o` : other
- `a` : all
- `+` : add
- `-` : remove
- `=` : assign

| Octal | Binary | Permission |
| ----- | ------ | ---------- |
| 0     | 000    | ---        |
| 1     | 001    | --x        |
| 2     | 010    | -w-        |
| 3     | 011    | -wx        |
| 4     | 100    | r--        |
| 5     | 101    | r-x        |
| 6     | 110    | rw-        |
| 7     | 111    | rwx        |

## su

Switch User

```bash
> su [options] [user]
su - # root로 전환합니다.
su - seunan # seunan으로 전환합니다.
su --login seunan # HOME을 변경합니다.
```

## sudo

Super User DO

```bash
> sudo [options] [command]
sudo -l # sudo 권한을 확인합니다.
sudo cat /etc/sudoers # root 권한으로 파일을 읽습니다.
```

## chown

CHange OWNer

```bash
> chown USER[:GROUP] FILE(s)
chown seunan <file> # file owner를 seunan으로 변경합니다.
chown seunan:root <file> # file owner를 seunan, group을 root로 변경합니다.
```

# Environment

- `$VAR` Replacing environment variables

## Environment Variables

Variables valid in the current shell and all child shells

### export

`export` command is used to set environment variables

```bash
> export [options] [name[=value] ...]
export KEY=VALUE
```

### printenv

`env` and `printenv` command is used to print all or part of environment

## Shell Variables

Variables valid only in the current shell section

```bash
> KEY=VALUE
```

## Special Variables

- `$PS1` : primary prompt
  - man bash, /PROMPTING
  - PS1="\u@\h:\w\$ " user@hostname:current directory$

## Startup Files

- `/etc/zshrc` : global zshrc
- `~/.zshrc` : user zshrc

## Alias

`alias` is used to create a shortcut for a command

```bash
> alias [name[=value] ...]
alias ll='ls -l'
unalias ll # ll alias를 삭제합니다.
```

# Shell Script

- `#!/bin/bash` : shebang
  - interpreter를 지정
- 문법 `shell_script`에 정리

## curl

`curl` command is used to transfer data from or to a server

```bash
> curl [options] [URL]
curl -O [URL] # file download
curl -X POST -d "name=seunan" [URL] # POST request
```

# Cron

- `crontab` command is used to schedule commands to be executed periodically
- `tar`을 이용하여 백업을 하거나, `rsync`를 이용하여 파일을 동기화하거나, `find`를 이용하여 파일을 삭제하는 등의 작업을 자동화할 수 있다.

```bash
crontab -l # list crontab
crontab -e # edit crontab
crontab -r # remove crontab
```

## Syntax

```bash
a b c d e command
```

| Field | Description |
| ----- | ----------- |
| a | minute (0 - 59) |
| b | hour (0 - 23) |
| c | day of month (1 - 31) |
| d | month (1 - 12) |
| e | day of week (0 - 6) |
| command | command to execute |

- `*` : any
- `*/n` : every n
- `5,6` : 5 or 6
- `1-4` : 1 to 4
- [crontab.guru](https://crontab.guru/)

## Error Resolution

2>&1 : stderr to stdout
log에서 stderr를 볼 수 있게 하여 에러를 확인할 수 있다.

```bash
a b c d e command >> /tmp/cron.log < 2>&1 >
```
