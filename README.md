# FASTED CARDIO
Command Line Interface application to generate and C2 an implant or remote access tools.

## Client
In the CLI app, Client is the management interface for local actions.  This is used to start listeners, 
- exit (e) - Exit the application
- help (h) - Display help information
- list (ls) - List beacon, trigger, and RATs
- listener (l / nc) - Start listener on a port to receive beacon or rat connections
    l <port> or nc <port>
- settings (s) - Display and edit settings
- use (u) - Select an implant/RAT to use

## Forge
Forge is the implant/RAT generation interface.
- exit (e) - Exit the application
- help (h) - Display help information
- forge (f) - Generate an implant/RAT
    f <beacon/trigger/rat> <exe/library> <os> <arch> <c2-ip> <c2-port>

    Examples:
    forge beacon exe windows x86 192.168.86.100 443
    forge trigger library windows x64
    forge rat library linux x64 192.168.86.100 8080

## Command and Control (C2)