#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
char buffer[26];
int fd;
int bytesRead;
int offset;

    void displayBuffer() {
        buffer[bytesRead] = '\0'; // Null-terminate the string
        printf("Read from file: %s\n", buffer);
        printf("\n");
    }

int main() {
    


    fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }


    bytesRead = read(fd, buffer, 5);
    displayBuffer();

    offset = lseek(fd, 10, SEEK_SET); // Move the file pointer to the 5th byte
    bytesRead = read(fd, buffer, 5);
    displayBuffer();

    offset = lseek(fd, 3, SEEK_CUR); // Get the current file pointer position
    bytesRead = read(fd, buffer, 4);
  
    displayBuffer();

    offset = lseek(fd, -5, SEEK_END); // Move the file pointer to 2 bytes before the end of the file
    bytesRead = read(fd, buffer, 5);
    displayBuffer();
    
    close(fd);

    return 0;
}