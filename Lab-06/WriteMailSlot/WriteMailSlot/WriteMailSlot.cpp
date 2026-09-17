#include <windows.h>
#include <iostream>
#include <string>

#define SLOT_NAME "\\\\.\\mailslot\\MyMailSlot"

void SendMessageToServer(const std::string& message) {
    HANDLE hSlot = CreateFileA(SLOT_NAME, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hSlot == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to open mailslot. Error: " << GetLastError() << std::endl;
        return;
    }

    DWORD bytesWritten;
    if (!WriteFile(hSlot, message.c_str(), message.size() + 1, &bytesWritten, NULL)) {
        std::cerr << "Failed to write to mailslot. Error: " << GetLastError() << std::endl;
    }
    else {
        std::cout << "Message sent: " << message << std::endl;
    }

    CloseHandle(hSlot);
}

int main() {
    std::string message;
    std::cout << "Enter messages to send to the server. Type 'exit' to quit.\n";

    while (true) {
        std::getline(std::cin, message);

        SendMessageToServer(message);

        if (message == "exit") {
            break;
        }
    }

    return 0;
}
