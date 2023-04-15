const char* aarch64_linux_gnu = "aarch64-linux-gnu";               // 64-bit ARM (AArch64) Linux
const char* arm_linux_gnueabi = "arm-linux-gnueabi";               // ARM Linux with EABI (Embedded ABI)
const char* arm_linux_gnueabihf = "arm-linux-gnueabihf";           // ARM Linux with hard-float ABI
const char* i686_pc_linux_gnu = "i686-pc-linux-gnu";               // 32-bit x86 Linux
const char* x86_64_pc_linux_gnu = "x86_64-pc-linux-gnu";           // 64-bit x86 Linux
const char* mips_linux_gnu = "mips-linux-gnu";                     // MIPS Linux
const char* mips64_linux_gnuabi64 = "mips64-linux-gnuabi64";       // 64-bit MIPS Linux with ABI64
const char* powerpc_linux_gnu = "powerpc-linux-gnu";               // PowerPC Linux
const char* powerpc64le_linux_gnu = "powerpc64le-linux-gnu";       // 64-bit PowerPC Linux with little-endian byte order
const char* riscv32_linux_gnu = "riscv32-linux-gnu";               // 32-bit RISC-V Linux
const char* riscv64_linux_gnu = "riscv64-linux-gnu";               // 64-bit RISC-V Linux
const char* sparc_linux_gnu = "sparc-linux-gnu";                   // SPARC Linux
const char* sparc64_linux_gnu = "sparc64-linux-gnu";               // 64-bit SPARC Linux
const char* x86_64_w64_mingw32 = "x86_64-w64-mingw32";             // 64-bit Windows using MinGW-w64 toolchain
const char* i686_w64_mingw32 = "i686-w64-mingw32";                 // 32-bit Windows using MinGW-w64 toolchain
const char* avr = "avr";                                           // Atmel AVR microcontrollers


int compile(char ** arguments) {
    char * agent = arguments[0];
    char * format = arguments[1];
    char * target = arguments[2];
    char * ip = arguments[3];
    char * port = arguments[4];
    
    char * command = malloc(1000);
    sprintf(command, "gcc -march= %s, -o %s %s.c -lssl -lcrypto\n", target, agent, agent);
    system(command);
    free(command);
    
    return 1;
}