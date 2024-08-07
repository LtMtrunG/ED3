#include <SPIFFS.h>

// Function to initialize SPIFFS
void initSPIFFS() {
    if (!SPIFFS.begin(true)) {
        Serial.println("An error has occurred while mounting SPIFFS");
    } else {
        Serial.println("SPIFFS mounted successfully");
    }
}

// Function to create and write to a file
void createFile(double th1,double th2,double th3) {
    File file = SPIFFS.open("/angles.txt", FILE_WRITE);

    if (!file) {
        Serial.println("Error opening file for writing!");
        return;
    }

    file.printf("%f\n", th1);
    file.printf("%f\n", th2);
    file.printf("%f\n", th3);

    file.close();
}

// Function to read from a file
void readFile() {
    File file = SPIFFS.open("/angles.txt", FILE_READ);

    if (!file) {
        Serial.println("Error opening file for reading!");
        return;
    }

    Serial.println("File content:");
    while (file.available()) {
        Serial.write(file.read());
    }
    Serial.println();

    file.close();
}
