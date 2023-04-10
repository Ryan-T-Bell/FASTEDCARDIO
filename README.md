# FASTED CARDIO
Command Line Interface application to generate and C2 an implant or remote access tools.

## Tasker
In the CLI app, Client is the management interface for local actions.  This is used to start listeners, 
- exit (e) - Exit the application
- help (h) - Display help information
- list (ls) - List LP to agent connection of all active beacons, trigger, and RATs
- remove (rm) - remove reference to agent or lp
- use (u) - Select an implant/RAT to use

## Forge
Forge is the implant/RAT generation interface.
- exit (e) - Exit the application
- help (h) - Display help information
- forge (f) - Generate an implant/RAT
    f <beacon/trigger/rat> <exe/library> <os> <arch> <ip> <port>

    Examples:
    forge beacon exe windows x86 192.168.86.100 443
    forge trigger library windows x64
    forge rat library linux x64 192.168.86.100 8080

