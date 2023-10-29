#include <iostream>
#include <Windows.h>
#include <XInput.h>

#pragma comment(lib, "XInput.lib")

int main() {
    XINPUT_STATE state;
    ZeroMemory(&state, sizeof(XINPUT_STATE));

    // Get the state of the first controller
    DWORD dwResult = XInputGetState(0, &state);

    if (dwResult == ERROR_SUCCESS) {
        // Controller is connected

        while (true)
        {
            // Mise à jour de l'état du contrôleur
            dwResult = XInputGetState(0, &state);

            if (dwResult == ERROR_SUCCESS) {
                // Controller is still connected
                std::cout << "Controller connected" << std::endl;

                // Get the values of the left thumbstick
                float lx = state.Gamepad.sThumbLX;
                float ly = state.Gamepad.sThumbLY;

                std::cout << "Left thumbstick X value: " << lx << std::endl;
                std::cout << "Left thumbstick Y value: " << ly << std::endl;
            }
            else {
                // Controller has been disconnected
                std::cout << "Controller disconnected" << std::endl;
                break;
            }

            Sleep(50);
            system("cls");
        }
    }


    return 0;
}
