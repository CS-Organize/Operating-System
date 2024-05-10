#!/bin/bash

WHITE='\033[97m'
RESET='\033[0m'

# SSH 연결 테스트
echo "${WHITE}Testing SSH connection to alpineuser@92.168.64.20...${RESET}"
ssh -vvv alpineuser@192.168.64.20

# Telnet 연결 테스트
echo "${WHITE}Testing Telnet connection to 192.168.64.20 on port 22...${RESET}}"

echo quit | telnet 192.168.64.20 22

# SSH 포트 변경 시 테스트
echo "${WHITE}Testing SSH connection on port 2222...${RESET}"
ssh -vvv -p 2222 alpineuser@192.168.64.20
