#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char buffer[8];
int bytesRead;

void displayBuffer(void) {
    if (bytesRead < 0) {
        printf("No data to display\n");
        return;
    }
    if (bytesRead < 7)
        buffer[bytesRead] = '\0';
    else
        buffer[7] = '\0';
    printf("First 7 chars: %s\n", buffer);
}

int main() {
    char c = 'X';
    char orig;
    int fd;
    int offset;
    int n;

    fd = open("input.txt", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    /* save original byte at 5th position */
    offset = lseek(fd, 4, SEEK_SET);
    if (offset == -1) {
        perror("Error seeking file");
        close(fd);
        return 1;
    }
    n = read(fd, &orig, 1);
    if (n != 1) {
        perror("Error reading original byte");
        close(fd);
        return 1;
    }

    /* overwrite with 'X' */
    offset = lseek(fd, 4, SEEK_SET);
    if (offset == -1) {
        perror("Error seeking file");
        close(fd);
        return 1;
    }
    n = write(fd, &c, 1);
    if (n != 1) {
        perror("Error writing file");
        close(fd);
        return 1;
    }

    /* read first 7 bytes and display */
    offset = lseek(fd, 0, SEEK_SET);
    if (offset == -1) {
        perror("Error seeking file");
        close(fd);
        return 1;
    }
    bytesRead = read(fd, buffer, 7);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);
        return 1;
    }
    displayBuffer();

    /* restore original byte */
    offset = lseek(fd, 4, SEEK_SET);
    if (offset == -1) {
        perror("Error seeking file to restore");
        close(fd);
        return 1;
    }
    n = write(fd, &orig, 1);
    if (n != 1) {
        perror("Error restoring original byte");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
