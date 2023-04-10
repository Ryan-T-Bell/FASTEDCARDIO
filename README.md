# FASTED CARDIO
Command Line Interface application to generate and C2 an implant or remote access tools.

## Tasker
In the CLI app, Client is the management interface for local actions.

### CLI Commands
- exit (e) - Exit the application
- help (h) - Display help information
- list (ls) - List LP to agent connection of all active beacons, trigger, and RATs
- remove (rm) - remove reference to agent or lp
- use (u) - Select an implant/RAT to use

## Forge
Forge is the interface used to generate agents and their corresponding listening posts.
Agents are beaconing implants, triggerable implants, or remote access tools (RATs).

Listening posts are the servers that receive tasker commands and forwards them to the agents.
Additionaly, LPs are used to receive agent responses and forward them to tasker.

### CLI Commands
- exit (e) - Exit the application
- help (h) - Display help information
- forge (f) - Generate an agent and corresponding listening post.
    forge -a <beacon/trigger/rat> -f <exe/library> -os <windows/linux> -arch <arch> -ip <ip> -p <port>

    Examples:
    forge beacon exe windows x86 192.168.86.100 443
    forge trigger library windows x64
    forge rat library linux x64 192.168.86.100 8080


### Listening Posts
Listening posts are the servers that receive tasker commands and forwards them to the agents.  They are paired with agents to allow for communication between the two.
This is kept confidential via an underlying public/private key pair.