# Alpine Linux
> Small. Simple. Secure.
>
> [Alpine Linux](https://www.alpinelinux.org/about/)

설명대로 진짜 작은 리눅스다. `Virtual aarch64` 기준 70MB 정도(`alpine-setup` 후에는 161MB 정도다.)\
`imbedded`나 `container`에 적합하며, 독자적인 패키지 관리자인 `apk`를 사용한다.\

[Installing Alpine in a virtual machine - Alpine Linux](https://wiki.alpinelinux.org/wiki/Installing_Alpine_in_a_virtual_machine)
[How to install Alpine Linux](https://linuxiac.com/how-to-install-alpine-linux/)
~~다른 배포판과는 다르게 **하나부터 열까지 다 직접 설치**해야 한다.~~\
~~심지어 root 비밀번호, 네트워크 설정까지도.~~

`setup-alpine` 명령어로 간단하게 설치할 수 있다.

[Github](https://github.com/ninoCan/Aarm64-ArchLinux-on-M1-Mac-installation-guide)에 어떤 사람이 설치 가이드를 올려놨다.

[Alpine Linux에서 고정 IP를 만드는 방법](https://ko.linux-console.net/?p=13619)


https://www.hasanaltin.com/error-unable-to-select-packages-error-on-alpine-linux/
[How To Install Nginx web server on Alpine Linux - nixCraft](https://www.cyberciti.biz/faq/how-to-install-nginx-web-server-on-alpine-linux/)\
[How to install OpenSSH server on Alpine Linux (including Docker) - nixCraft](https://www.cyberciti.biz/faq/how-to-install-openssh-server-on-alpine-linux-including-docker/)

## Troubleshooting
### 재부팅 후 `iso` 파일을 clear하면 부트가 안되고, clear하지 않으면 초기화되는 문제
`setup-alpine` 명령어로 셋업 후 `poweroff`로 종료하고, `iso` 파일을 clear하고 다시 부팅하면 된다. **이래서 꼭 공식 문서를 읽어야 한다.**

### `vscode`에서 `remote-ssh`로 접속이 안되는 문제
#### 문제 상황
`vscode`의 `remote-ssh` 익스텐션을 사용해 접속하려고 하면 에러가 발생했다. \
\
`remote-ssh`로 접속 시 `Could not establish connection to "192.168.64.20".`라는 문구와 함께 나오는 에러 메시지는 다음과 같다.
```
[00:26:16.043] Log Level: 2
[00:26:16.050] SSH Resolver called for "ssh-remote+192.168.64.20", attempt 1
[00:26:16.051] "remote.SSH.useLocalServer": true
[00:26:16.051] "remote.SSH.useExecServer": true
[00:26:16.053] "remote.SSH.path": undefined
[00:26:16.054] "remote.SSH.configFile": undefined
[00:26:16.054] "remote.SSH.useFlock": true
[00:26:16.054] "remote.SSH.lockfilesInTmp": false
[00:26:16.054] "remote.SSH.localServerDownload": auto
[00:26:16.054] "remote.SSH.remoteServerListenOnSocket": false
[00:26:16.054] "remote.SSH.showLoginTerminal": false
[00:26:16.054] "remote.SSH.defaultExtensions": []
[00:26:16.054] "remote.SSH.loglevel": 2
[00:26:16.054] "remote.SSH.enableDynamicForwarding": true
[00:26:16.054] "remote.SSH.enableRemoteCommand": false
[00:26:16.054] "remote.SSH.serverPickPortsFromRange": {}
[00:26:16.054] "remote.SSH.serverInstallPath": {}
[00:26:16.056] VS Code version: 1.89.0
[00:26:16.056] Remote-SSH version: remote-ssh@0.110.1
[00:26:16.056] darwin arm64
[00:26:16.057] SSH Resolver called for host: 192.168.64.20
[00:26:16.057] Setting up SSH remote "192.168.64.20"
[00:26:16.059] Acquiring local install lock: /var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-remote-ssh-b34e3688-install.lock
[00:26:16.060] Looking for existing server data file at /Users/anseungwon/Library/Application Support/Code/User/globalStorage/ms-vscode-remote.remote-ssh/vscode-ssh-host-b34e3688-b58957e67ee1e712cebf466b995adf4c5307b2bd-0.110.1-es/data.json
[00:26:16.061] Using commit id "b58957e67ee1e712cebf466b995adf4c5307b2bd" and quality "stable" for server
[00:26:16.065] Install and start server if needed
[00:26:16.068] PATH: /Users/anseungwon/Library/Caches/fnm_multishells/31893_1715262240977/bin:/Users/anseungwon/Library/Caches/fnm_multishells/31870_1715262240967/bin:/Users/anseungwon/Library/Application Support/fnm:/Users/anseungwon/bin:/Users/anseungwon/.npm-global/bin:/usr/local/bin:/Library/Frameworks/Python.framework/Versions/3.12/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Library/Apple/usr/bin:/Library/Frameworks/Mono.framework/Versions/Current/Commands
[00:26:16.068] Checking ssh with "ssh -V"
[00:26:16.075] > OpenSSH_9.6p1, LibreSSL 3.3.6

[00:26:16.080] askpass server listening on /var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-ssh-askpass-5290db5383c0c1f54d597a9417d7e45a3c8da233.sock
[00:26:16.080] Spawning local server with {"serverId":1,"ipcHandlePath":"/var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-ssh-askpass-8892b8a5361500a47ec5295f8bab3b6d824b4776.sock","sshCommand":"ssh","sshArgs":["-v","-T","-D","53854","-o","ConnectTimeout=15","192.168.64.20"],"serverDataFolderName":".vscode-server","dataFilePath":"/Users/anseungwon/Library/Application Support/Code/User/globalStorage/ms-vscode-remote.remote-ssh/vscode-ssh-host-b34e3688-b58957e67ee1e712cebf466b995adf4c5307b2bd-0.110.1-es/data.json"}
[00:26:16.080] Local server env: {"SSH_AUTH_SOCK":"/private/tmp/com.apple.launchd.6xiStbcIDY/Listeners","SHELL":"/bin/zsh","DISPLAY":"1","ELECTRON_RUN_AS_NODE":"1","SSH_ASKPASS":"/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/local-server/askpass.sh","VSCODE_SSH_ASKPASS_NODE":"/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)","VSCODE_SSH_ASKPASS_EXTRA_ARGS":"","VSCODE_SSH_ASKPASS_MAIN":"/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/askpass-main.js","VSCODE_SSH_ASKPASS_HANDLE":"/var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-ssh-askpass-5290db5383c0c1f54d597a9417d7e45a3c8da233.sock"}
[00:26:16.081] Spawned 56801
[00:26:16.182] > local-server-1> Running ssh connection command: ssh -v -T -D 53854 -o ConnectTimeout=15 192.168.64.20
[00:26:16.184] > local-server-1> Spawned ssh, pid=56813
[00:26:16.187] stderr> OpenSSH_9.6p1, LibreSSL 3.3.6
[00:26:16.250] stderr> debug1: Server host key: ssh-ed25519 SHA256:tvORvNkA0lDZ41AcdZ1zwMWnbHgaRyrl5PIFjVF/Bss
[00:26:16.459] Got askpass request: {"request":" alpineuser@192.168.64.20's password:"}
[00:26:16.460] Showing password prompt
[00:26:16.461] Listening for interwindow password on /var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-ssh-askpass-608878bcd01aa8cc0b5d39f36d79289250ef2a05.sock
[00:26:16.461] Writing password prompt to globalState
[00:26:24.023] Got password response
[00:26:24.023] Interactor gave response: ************
[00:26:24.024] Cleaning up other-window auth server
[00:26:24.058] stderr> Authenticated to 192.168.64.20 ([192.168.64.20]:22) using "password".
[00:26:24.067] > ready: b4516d9710c2
[00:26:24.070] > Linux 6.6.30-0-virt #1-Alpine SMP Mon, 06 May 2024 07:55:42 +0000
[00:26:24.070] Platform: linux
[00:26:24.071] > /bin/ash
[00:26:24.071] Shell: ash
[00:26:24.071] Creating bash subshell inside "ash"
[00:26:24.127] > bash version:  5.2.21(1)-release
[00:26:24.142] > b4516d9710c2: running
[00:26:24.152] > Installing to /home/alpineuser/.vscode-server...
[00:26:24.156] > b4516d9710c2%%1%%
[00:26:24.162] > printenv:
[00:26:24.162] >     SHELL=/bin/ash
>     CHARSET=UTF-8
>     PWD=/home/alpineuser/.vscode-server
>     LOGNAME=alpineuser
>     HOME=/home/alpineuser
>     LANG=C.UTF-8
>     VSCODE_AGENT_FOLDER=/home/alpineuser/.vscode-server
>     SSH_CONNECTION=192.168.64.1 53855 192.168.64.20 22
>     USER=alpineuser
>     SHLVL=2
>     PAGER=less
>     SSH_CLIENT=192.168.64.1 53855 22
>     LC_COLLATE=C
>     PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
>     MAIL=/var/mail/alpineuser
>     _=/bin/printenv
>     OLDPWD=/home/alpineuser
[00:26:24.163] > Neither wget nor curl is installed
> Trigger local server download
> b4516d9710c2:trigger_server_download
> artifact==cli-alpine-arm64==
> destFolder==/home/alpineuser/.vscode-server==
> destFolder2==/vscode-cli-b58957e67ee1e712cebf466b995adf4c5307b2bd.tar.gz==
> b4516d9710c2:trigger_server_download_end
> Waiting for client to transfer server archive...
> Waiting for /home/alpineuser/.vscode-server/vscode-cli-b58957e67ee1e712cebf466b995adf4c5307b2bd.tar.gz.done and vscode-server.tar.gz to exist
>  
[00:26:24.163] Got request to download on client for {"artifact":"cli-alpine-arm64","destPath":"/home/alpineuser/.vscode-server/vscode-cli-b58957e67ee1e712cebf466b995adf4c5307b2bd.tar.gz"}
[00:26:24.164] Downloading VS Code server locally...
[00:26:24.343] Downloaded VS Code server to /var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/30196a8f-a564-402a-a2a8-59c0c50e799f
[00:26:24.344] Renamed VS Code server to /var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode_server_1715268384343/vscode-cli-b58957e67ee1e712cebf466b995adf4c5307b2bd.tar.gz
[00:26:24.349] PATH: /Users/anseungwon/Library/Caches/fnm_multishells/31893_1715262240977/bin:/Users/anseungwon/Library/Caches/fnm_multishells/31870_1715262240967/bin:/Users/anseungwon/Library/Application Support/fnm:/Users/anseungwon/bin:/Users/anseungwon/.npm-global/bin:/usr/local/bin:/Library/Frameworks/Python.framework/Versions/3.12/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Library/Apple/usr/bin:/Library/Frameworks/Mono.framework/Versions/Current/Commands
[00:26:24.349] Checking ssh with "ssh -V"
[00:26:24.358] > OpenSSH_9.6p1, LibreSSL 3.3.6

[00:26:24.359] Testing scp with "scp"
[00:26:24.366] scp exited with code: 1
[00:26:24.366] Got stderr from scp: usage: scp [-346ABCOpqRrsTv] [-c cipher] [-D sftp_server_path] [-F ssh_config]
           [-i identity_file] [-J destination] [-l limit] [-o ssh_option]
           [-P port] [-S program] [-X sftp_option] source ... target
[00:26:24.366] Copying file to remote with scp -o ConnectTimeout=15 'vscode-cli-b58957e67ee1e712cebf466b995adf4c5307b2bd.tar.gz' 'vscode-cli-b58957e67ee1e712cebf466b995adf4c5307b2bd.tar.gz.done' '192.168.64.20':'/home/alpineuser/.vscode-server'
[00:26:24.366] Using cwd: file:///var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode_server_1715268384343
[00:26:24.669] > alpineuser@192.168.64.20's password: 
[00:26:24.669] Showing password prompt
[00:26:27.167] >  
[00:26:30.170] >  
[00:26:33.026] Got password response
[00:26:33.027] "Copy server to host" wrote data to terminal: "************"
[00:26:33.044] > 
[00:26:33.067] > vscode-cli-b58957e67ee1e712cebf466b995adf4c53   0%    0     0.0KB/s   --:-- ETA
[00:26:33.171] >  
[00:26:33.245] > vscode-cli-b58957e67ee1e712cebf466b995adf4c53 100% 7826KB  42.3MB/s   00:00    
> vscode-cli-b58957e67ee1e712cebf466b995adf4c53   0%    0     0.0KB/s   --:-- ETAvscode-cli-b58957e67ee1e712cebf466b995adf4c53 100%    9    30.2KB/s   00:00    
[00:26:33.496] "Copy server to host" terminal command done
[00:26:36.175] > Found flag and server on host
[00:26:36.180] > b4516d9710c2%%2%%
> tar --version:
[00:26:36.181] > tar (busybox) 1.36.1
[00:26:36.392] > code 1.89.0 (commit b58957e67ee1e712cebf466b995adf4c5307b2bd)
[00:26:36.393] > Starting VS Code CLI... "/home/alpineuser/.vscode-server/code-b58957e67ee1e712cebf466b995adf4c5307b2bd" command-shell --cli-data-dir "/home/alpineuser/.vscode-server/cli" --on-port --parent-process-id 2748 &> "/home/alpineuser/.vscode-server/.cli.b58957e67ee1e712cebf466b995adf4c5307b2bd.log" < /dev/null
> printenv:
[00:26:36.393] >     SHELL=/bin/ash
>     CHARSET=UTF-8
>     PWD=/home/alpineuser
>     LOGNAME=alpineuser
>     HOME=/home/alpineuser
>     LANG=C.UTF-8
>     VSCODE_AGENT_FOLDER=/home/alpineuser/.vscode-server
>     SSH_CONNECTION=192.168.64.1 53855 192.168.64.20 22
>     USER=alpineuser
>     SHLVL=2
>     PAGER=less
>     SSH_CLIENT=192.168.64.1 53855 22
>     LC_COLLATE=C
>     PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
>     MAIL=/var/mail/alpineuser
>     _=/bin/printenv
>     OLDPWD=/home/alpineuser/.vscode-server
[00:26:36.395] > Spawned remote CLI: 2799
[00:26:36.396] stderr> ps: unrecognized option: p
[00:26:36.398] stderr> BusyBox v1.36.1 (2023-11-07 18:53:09 UTC) multi-call binary.
[00:26:36.398] stderr> 
[00:26:36.398] stderr> Usage: ps [-o COL1,COL2=HEADER] [-T]
[00:26:36.398] stderr> 
[00:26:36.398] stderr> Show list of processes
[00:26:36.398] stderr> 
[00:26:36.398] stderr> 	-o COL1,COL2=HEADER	Select columns for display
[00:26:36.398] stderr> 	-T			Show threads
[00:26:36.398] > Exec server process not found
[00:26:36.399] > b4516d9710c2: start
> SSH_AUTH_SOCK====
> DISPLAY====
> listeningOn====
> osReleaseId==alpine==
> arch==aarch64==
> vscodeArch==arm64==
> bitness==64==
> tmpDir==/tmp==
> platform==linux==
> unpackResult==success==
> didLocalDownload==1==
> downloadTime====
> installTime==0==
> serverStartTime==0==
[00:26:36.399] > execServerToken==11111111-a1a1-1aaa-1111-a1aa1111a111==
> b4516d9710c2: end
[00:26:36.399] Received install output: 
SSH_AUTH_SOCK====
DISPLAY====
listeningOn====
osReleaseId==alpine==
arch==aarch64==
vscodeArch==arm64==
bitness==64==
tmpDir==/tmp==
platform==linux==
unpackResult==success==
didLocalDownload==1==
downloadTime====
installTime==0==
serverStartTime==0==execServerToken==11111111-a1a1-1aaa-1111-a1aa1111a111==

[00:26:36.400] Failed to parse remote port from server output
[00:26:36.400] Terminating local server
[00:26:36.402] Resolver error: Error: 
	at g.Create (/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:499181)
	at t.handleInstallOutput (/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:496503)
	at e (/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:557639)
	at process.processTicksAndRejections (node:internal/process/task_queues:95:5)
	at async /Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:579548
	at async t.withShowDetailsEvent (/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:583207)
	at async /Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:554344
	at async T (/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:552395)
	at async t.resolveWithLocalServer (/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:553884)
	at async k (/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:576765)
	at async t.resolve (/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:580578)
	at async /Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/extension.js:2:846687
[00:26:36.405] ------




[00:26:36.407] Local server exit: 15
[00:26:36.812] Opening exec server for ssh-remote+192.168.64.20
[00:26:36.818] Acquiring local install lock: /var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-remote-ssh-b34e3688-install.lock
[00:26:36.818] Initizing new exec server for ssh-remote+192.168.64.20
[00:26:36.831] Looking for existing server data file at /Users/anseungwon/Library/Application Support/Code/User/globalStorage/ms-vscode-remote.remote-ssh/vscode-ssh-host-b34e3688-b58957e67ee1e712cebf466b995adf4c5307b2bd-0.110.1-es/data.json
[00:26:36.832] Using commit id "b58957e67ee1e712cebf466b995adf4c5307b2bd" and quality "stable" for server
[00:26:36.833] Install and start server if needed
[00:26:36.835] askpass server listening on /var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-ssh-askpass-7d723ddd0897dc555f2ec5ba229652cbc7bb4205.sock
[00:26:36.835] Spawning local server with {"serverId":2,"ipcHandlePath":"/var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-ssh-askpass-426faa2c27be9ca6614bf0a366df08e566001e8c.sock","sshCommand":"ssh","sshArgs":["-v","-T","-D","53854","-o","ConnectTimeout=15","192.168.64.20"],"serverDataFolderName":".vscode-server","dataFilePath":"/Users/anseungwon/Library/Application Support/Code/User/globalStorage/ms-vscode-remote.remote-ssh/vscode-ssh-host-b34e3688-b58957e67ee1e712cebf466b995adf4c5307b2bd-0.110.1-es/data.json"}
[00:26:36.835] Local server env: {"SSH_AUTH_SOCK":"/private/tmp/com.apple.launchd.6xiStbcIDY/Listeners","SHELL":"/bin/zsh","DISPLAY":"1","ELECTRON_RUN_AS_NODE":"1","SSH_ASKPASS":"/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/local-server/askpass.sh","VSCODE_SSH_ASKPASS_NODE":"/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper (Plugin).app/Contents/MacOS/Code Helper (Plugin)","VSCODE_SSH_ASKPASS_EXTRA_ARGS":"","VSCODE_SSH_ASKPASS_MAIN":"/Users/anseungwon/.vscode/extensions/ms-vscode-remote.remote-ssh-0.110.1/out/askpass-main.js","VSCODE_SSH_ASKPASS_HANDLE":"/var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-ssh-askpass-7d723ddd0897dc555f2ec5ba229652cbc7bb4205.sock"}
[00:26:36.836] Spawned 56929
[00:26:36.926] > local-server-2> Running ssh connection command: ssh -v -T -D 53854 -o ConnectTimeout=15 192.168.64.20
[00:26:36.928] > local-server-2> Spawned ssh, pid=56941
[00:26:36.931] stderr> OpenSSH_9.6p1, LibreSSL 3.3.6
[00:26:36.998] stderr> debug1: Server host key: ssh-ed25519 SHA256:tvORvNkA0lDZ41AcdZ1zwMWnbHgaRyrl5PIFjVF/Bss
[00:26:37.199] Got askpass request: {"request":" alpineuser@192.168.64.20's password:"}
[00:26:37.199] Showing password prompt
[00:26:37.200] Listening for interwindow password on /var/folders/1z/6x0hzvts0plcgn9l599pgcc80000gn/T/vscode-ssh-askpass-f99de6dfa7d300cc4270f6ed1c45e1126d4c33f9.sock
[00:26:37.200] Writing password prompt to globalState
[00:26:45.660] Password dialog canceled
[00:26:45.660] Interactor signaled cancel
[00:26:45.661] Cleaning up other-window auth server
[00:26:45.680] stderr> Permission denied, please try again.
[00:26:45.782] Got askpass request: {"request":" alpineuser@192.168.64.20's password:"}
[00:26:45.797] stderr> Permission denied, please try again.
[00:26:45.882] Got askpass request: {"request":" alpineuser@192.168.64.20's password:"}
[00:26:45.897] stderr> Received disconnect from 192.168.64.20 port 22:2: Too many authentication failures
[00:26:45.897] stderr> Disconnected from 192.168.64.20 port 22
[00:26:45.897] > local-server-2> ssh child died, shutting down
[00:26:45.899] Local server exit: 0
[00:26:45.900] Received install output: local-server-2> Running ssh connection command: ssh -v -T -D 53854 -o ConnectTimeout=15 192.168.64.20
local-server-2> Spawned ssh, pid=56941
OpenSSH_9.6p1, LibreSSL 3.3.6
debug1: Server host key: ssh-ed25519 SHA256:tvORvNkA0lDZ41AcdZ1zwMWnbHgaRyrl5PIFjVF/Bss
Permission denied, please try again.
Permission denied, please try again.
Received disconnect from 192.168.64.20 port 22:2: Too many authentication failures
Disconnected from 192.168.64.20 port 22
local-server-2> ssh child died, shutting down

[00:26:45.900] Exec server for ssh-remote+192.168.64.20 failed: Error: Too many authentication failures
[00:26:45.900] Error opening exec server for ssh-remote+192.168.64.20: Error: Too many authentication failures
```

#### 접근 방법
원격 서버에 대한 연결을 테스트하기 위해 터미널에서 `ssh` 또는 `telnet`을 사용했다.

1. **`ssh` 명령어의 옵션을 이용한 테스트**
   - `-p <port>`: 특정 포트로의 연결을 시도
   - `-vvv`: 연결 시도 과정에서 발생하는 모든 세부 정보 출력 (Verbose Mode)

문제없이 접속이 되는 것을 확인했다.

2. **`telnet`을 사용한 연결 테스트**
   - `telnet 192.168.64.20 22`: 특정 호스트의 특정 포트로의 연결 시도
   - `echo quit | telnet 192.168.64.20 22`: 연결 상태 확인을 위한 방법

`telnet`은 원격 서버의 특정 포트로의 연결을 테스트하는 데 사용할 수 있는 또 다른 도구 \
하지만 `telnet`은 암호화되지 않으므로, 민감한 정보가 오고 가는 네트워크에서는 사용하지 않고 주로 포트가 열려 있는지 간단히 확인하는 용도로 사용\

```bash
> echo quit | telnet 192.168.64.20 22
Trying 192.168.64.20...
Connected to 192.168.64.20.
Escape character is '^]'.
Connection closed by foreign host.
```
연결이 성공적으로 이루어졌으며, `Connection closed by foreign host`라는 메시지가 표시되었다.\

`remote-ssh`로 접속 시 발생하는 문제는 `ssh`로 접속 시 발생하지 않는다.\

#### 검색 후 다른 방법 시도
Search `vscode remote ssh Could not establish connection to alpine`\
[VS Code Remote SSH Connection not working - Stack Overflow](https://stackoverflow.com/questions/64034813/vs-code-remote-ssh-connection-not-working)\

1. `~/.vscode-server` 폴더 삭제: 파일이 애초에 없었음
2. `vscode command pallett`에서 `Remote-SSH: Kill VS Code Server on Host` 실행: 실행 후 동일한 문제 발생
3. `vscode settings.json`에서 `remote.SSH.useLocalServer`를 `false`로 변경: 실행 후 동일한 문제 발생
4. `.ssh/know_hosts` 에서 해당 호스트 삭제: 실행 후 동일한 문제 발생

### apk add 명령어로 패키지 설치 시 `ERROR: Unable to select packages` 에러 발생

#### 문제 상황
`sudo` 패키지를 설치하려고 `apk add sudo` 명령어를 실행했지만, 다음과 같은 에러가 발생했다.
```bash
> apk add sudo
ERROR: unable to select packages:
    sudo (no such package):
        required by: world[sudo]
```

#### 해결 방법
[virtual machine - How to install sudo on Alpine 3.17 VM? - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/743567/how-to-install-sudo-on-alpine-3-17-vm)
```bash
> cat retc/apk/repositories
#/media/cdron/apks
http://dl-cdn.alpinelinux.org/alpine/u3.19/main
#http://dl-cdn.alpinelinux.org/alpine/u3.19/community
```

`/etc/apk/repositories` 파일을 열어서 주석 처리된 `community` 레포지토리를 주석 해제하고, 다시 `sudo` 패키지를 설치하니 정상적으로 설치되었다.

### sudo 명령어 사용이 안되는 문제

#### 문제 상황
```bash
> sudo mkdir a
[sudo] password for alpineuser:
alpineuser is not in the sudoers file.
This incident has been reported to the administrator.
```

#### 접근 방법
`alpineuser`이 `sudo` 그룹에 속해있지 않아서 발생하는 문제라고 생각해 `sudo` 그룹에 추가했다.
```bash
> su
> addgroup sudo
> adduser alpineuser sudo
```
그래도 동일한 문제가 발생했다.

[linux - "'Username' is not in the sudoers file. This incident will be reported" - Stack Overflow](https://stackoverflow.com/questions/47806576/username-is-not-in-the-sudoers-file-this-incident-will-be-reported)

`/etc/sudoers` 파일에 `alpineuser ALL=(ALL) ALL` 라인을 추가해서 문제를 해결했다.
