#include <iostream>
#include <cstdlib>

using namespace std;

int generateCode();

int main() {
    int code = generateCode();
    cout << "Your 4-digit code is: " << code << endl;

    // User code entry
    int Attempts = 3;
    bool bAccess = false;
    for (int i = 0; i < Attempts; i++) {
        int entryCode;
        cout << "Enter the code: ";
        cin >> entryCode;
        if (entryCode == code) {
            bAccess = true;
            break;
        }
        else {
            bAccess = false;
            cout << "Incorrect Code\n";
        }
    }

    if (bAccess) {
        cout << "ACCESS GRANTED\n";

        // Directions code
        int direction;
        cout << "Choose an option to get directions:\n";
        cout << "1. Accounts section: turn right\n";
        cout << "2. Rates section: turn left\n";
        cout << "3. Changing address section: continue straight\n";
        cin >> direction;

        switch (direction) {
        case 1:
            cout << "Turn right to go to the Accounts section.\n";
            break;
        case 2:
            cout << "Turn left to go to the Rates section.\n";
            break;
        case 3:
            cout << "Continue straight to go to the Changing address section.\n";
            break;
        default:
            cout << "Invalid option.\n";
            break;
        }
    }
    else {
        cout << "STOP! Too many attempts\n";
        while (true) {  // Infinite loop to keep playing the alarm
            system("start wmplayer /play /close \"C:\\Users\\ndaed\\Downloads\\Alarm.m4a\"");
            system("timeout /t 5 >nul"); // Adjust the timeout duration (in seconds) based on the audio length
        }
    }
}

int generateCode() {
    // Make unique code
    static int seed = reinterpret_cast<int>(&seed);
    srand(seed);
    // Generate random between 1000 and 9999
    return rand() % 9000 + 1000;
}
