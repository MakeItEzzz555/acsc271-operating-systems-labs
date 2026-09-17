#include <windows.h>
#include <iostream>
#include <string>

#define SLOT_NAME "\\\\.\\mailslot\\MyMailSlot"

void StartServer() {
    HANDLE hSlot = CreateMailslotA(SLOT_NAME, 0, MAILSLOT_WAIT_FOREVER, NULL);
    if (hSlot == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create mailslot. Error: " << GetLastError() << std::endl;
        return;
    }

    std::cout << "Mailslot server is running...\n";

    while (true) {
        char buffer[512];
        DWORD bytesRead;

        if (!ReadFile(hSlot, buffer, sizeof(buffer), &bytesRead, NULL)) {
            std::cerr << "Failed to read from mailslot. Error: " << GetLastError() << std::endl;
            break;
        }

        buffer[bytesRead] = '\0'; // Null-terminate the string
        std::cout << "Received message: " << buffer << std::endl;

        if (strcmp(buffer, "exit") == 0) {
            std::cout << "Exiting server...\n";
            break;
        }
    }

    CloseHandle(hSlot);
}

int main() {
    StartServer();
    return 0;
}
