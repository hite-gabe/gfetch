// My first program ever in C.
// This is undoubtedly barebones, but a good start.
// As usual, this is open-source.

#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <time.h>

#define COLOR_TITLE   "\033[1;35m"
#define COLOR_LABEL   "\033[1;36m"
#define COLOR_RESET   "\033[0m"

int main() {
    printf(COLOR_TITLE "--- gFetch Info ---\n" COLOR_RESET);
    
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        printf(COLOR_LABEL "Operating System: " COLOR_RESET "%s\n", buffer.sysname);
        printf(COLOR_LABEL "Kernel Version:   " COLOR_RESET "%s\n", buffer.release);
    }
    
    char *username = getlogin();
    if (username == NULL) {
        username = getenv("USER");
    }
    if (username != NULL) {
        printf(COLOR_LABEL "Username:         " COLOR_RESET "%s\n", username);
    }
    
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf(COLOR_LABEL "System Time:      " COLOR_RESET "%s", asctime(timeinfo)); 

    struct sysinfo si;
    if (sysinfo(&si) == 0) {
        unsigned long long total_bytes = (unsigned long long)si.totalram * si.mem_unit;
        unsigned long total_ram = total_bytes / 1048576;
        printf(COLOR_LABEL "Total RAM:        " COLOR_RESET "%lu MB\n", total_ram);
    }

    struct statvfs vfs;
    if (statvfs("/", &vfs) == 0) {
        unsigned long long total_bytes = (unsigned long long)vfs.f_blocks * vfs.f_frsize;
        unsigned long total_gb = total_bytes / 1073741824;
        unsigned long long free_bytes = (unsigned long long)vfs.f_bavail * vfs.f_frsize;
        unsigned long free_gb = free_bytes / 1073741824;

        printf(COLOR_LABEL "Total Storage:    " COLOR_RESET "%lu GB\n", total_gb);
        printf(COLOR_LABEL "Free Storage:     " COLOR_RESET "%lu GB\n", free_gb);
        printf(COLOR_TITLE "-------------------\n" COLOR_RESET);
    }

    return 0;
}
