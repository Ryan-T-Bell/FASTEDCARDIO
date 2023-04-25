# FASTEDCARDIO
Command Line Interface application to generate and C2 an implant or remote access tools.

## Description
FASTEDCARDIO is an all in one solution for conducting MITRE-Attack categorized tasks.  It is a command line interface application that allows the user to scan, conduct penetration/vulnerability testing, generate and C2 agents (beacon, trigger, RAT), and many more activities. </br></br> 

FACO is not meant to be used for malicious purposes.  It is meant to be used for educational purposes only.

## Installation
FASTEDCARDIO is meant to operate as a standalone tool.  When you run the binary on your system, it will create a directory .fastedcardio in your home dir (~/ on linux). <br/>

## Forge
Forge is the agent generation tool.  It is a command line interface application that allows the user to generate and C2 agents (beacon, trigger, RAT). </br></br>

## CLI
CLI is the command line interface section of the application.  This is the "UI" that is presented to the user.

## Usage: Start Application
chmod +x fastedcardio </br>
./fastedcardio </br>

## Usage: Forge
forge -a <beacon/trigger/rat> -f <exe/library> -os <windows/linux> -arch <arch> -ip <ip> -p <port> </br></br>

Example forge generation commands: </br>
forge -agent beacon -format exe -target x86_64-w64-mingw32 -ip 192.168.86.80 -port 443 <br/>
forge -a trigger -f library -t windows <br/>
forge -a rat -f library -t linux -ip 192.168.86.100 -p 8080 <br/>

## Usage: CLI
Throughout the App



## MITRE ATT&CK Coverage
### 1. Reconnaissance
N/A
### 2. Resource Development
N/A
### 3. Initial Access
N/A
### 4. Execution
### 5. Persistence
### 6. Privilege Escalation
### 7. Defense Evasion
### 8. Credential Access
### 9. Discovery
### 10. Lateral Movement
### 11. Collection
### 12. Exfiltration
### 13. Command and Control
### 14. Impact
N/A

