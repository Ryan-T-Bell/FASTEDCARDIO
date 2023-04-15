const char* x86_64_w64_mingw32 = "x86_64-w64-mingw32";             // 64-bit Windows using MinGW-w64 toolchain
const char* i686_w64_mingw32 = "i686-w64-mingw32";                 // 32-bit Windows using MinGW-w64 toolchain

const char* x86_64_pc_linux_gnu = "x86_64-pc-linux-gnu";           // 64-bit x86 Linux
const char* i686_pc_linux_gnu = "i686-pc-linux-gnu";               // 32-bit x86 Linux

const char* aarch64_linux_gnu = "aarch64-linux-gnu";               // 64-bit ARM (AArch64) Linux
const char* arm_linux_gnueabi = "arm-linux-gnueabi";               // ARM Linux with EABI (Embedded ABI)
const char* arm_linux_gnueabihf = "arm-linux-gnueabihf";           // ARM Linux with hard-float ABI


int load_compiler() {
    
    // char * command = malloc(1000);
    // sprintf(command, "gcc -march= %s, -o %s %s.c -lssl -lcrypto\n", target, agent, agent);
    // system(command);
    // free(command);
    
    return 1;
}