#include <SPIFFS.h>

struct Angles {
    double th1;
    double th2;
    double th3;
};

// Function to initialize SPIFFS
void initSPIFFS() {
    if (!SPIFFS.begin(true)) {
        Serial.println("An error has occurred while mounting SPIFFS");
    } else {
        Serial.println("SPIFFS mounted successfully");
    }
}

// Function to create and write to a file
void writeFile(double th1,double th2,double th3) {
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
Angles readFile() {
    File file = SPIFFS.open("/angles.txt", FILE_READ);
    Angles angles = {0, 0, 0};

    if (!file) {
        Serial.println("Error opening file for reading!");
        return angles;
    }

    Serial.println("Reading file content:");
    String line1 = file.readStringUntil('\n');
    String line2 = file.readStringUntil('\n');
    String line3 = file.readStringUntil('\n');

    angles.th1 = line1.toFloat();
    angles.th2 = line2.toFloat();
    angles.th3 = line3.toFloat();

    file.close();
    return angles;
}
