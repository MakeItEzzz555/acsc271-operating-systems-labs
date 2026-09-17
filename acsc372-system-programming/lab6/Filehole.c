#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Create file (write only, create if not exists, truncate if exists)
    fd = open("file_with_a_hole.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }

    // Write first string
    if (write(fd, "FREDERICK", 9) != 9) {
        perror("write error");
        exit(1);
    }

    // Move file offset forward by 50 bytes (creates the hole)
    if (lseek(fd, 50, SEEK_CUR) == -1) {
        perror("lseek error");
        exit(1);
    }

    // Write second string
    if (write(fd, "UNIVERSITY", 10) != 10) {
        perror("write error");
        exit(1);
    }

    close(fd);
    return 0;
}