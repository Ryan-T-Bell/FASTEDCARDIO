# 13. Command and Control
This is the portion of the program to control blu/gray-space activity.
1) Forge: Generate agents and LPs
2) C2: Manage active agents and LPs

## Forge Commands
- exit (e) - Exit the application.
- forge - Generate an agent and corresponding listening post.
    forge -a <beacon/trigger/rat> -f <exe/library> -os <windows/linux> -arch <arch> -ip <ip> -p <port>

    Examples: <br/>
    forge -agent beacon -format exe -target x86_64-w64-mingw32 -ip 192.168.86.80 -port 443 <br/>
    forge -a trigger -f library -t windows <br/>
    forge -a rat -f library -t linux -ip 192.168.86.100 -p 8080 <br/>

- help (h) - Display help information.
- list (ls) - List LPs and agents for active connections of all active beacons, trigger, and RATs.
- remove (rm) - remove reference to agent or lp.
- use (u) - Select which connected agent (beacon/trigger/RAT) to use.

### 2 - LP: Listening Post
Listening posts are the servers that receive tasker commands and forwards them to the agents.  They are paired with agents to allow for communication between the two.
<br/><br/>
This is kept confidential via an underlying public/private key pair.

##### Commands
- exit (e) - Exit the application back to the C2 interface
- help (h) - Display help information.


### 3 - Agents: Beacons, Triggers, and RATs


##### Commands
- exit (e) - Exit the application back to the C2 interface
- help (h) - Display help information.
