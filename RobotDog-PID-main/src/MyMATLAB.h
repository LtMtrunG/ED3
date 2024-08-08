#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>
#include <WebServer.h>
#include <ArduinoJson.h>
const char *ssid = "...";    // Change to your wifi_name
const char *pass = "..."; // Password of wifi

WebServer serverAPI(80);

struct Angles1
{
    double th1;
    double th2;
    double th3;
};

Angles1 handleUpdate()
{
    if (serverAPI.method() == HTTP_POST)
    {
        // Serial.println("Start");
        // Create a JSON document to hold the incoming data
        StaticJsonDocument<200> doc;
        Angles1 angles = {0, 0, 0};

        // Deserialize the JSON data
        DeserializationError error = deserializeJson(doc, serverAPI.arg("plain"));
        if (error)
        {
            serverAPI.send(400, "text/plain", "Invalid JSON");
            return {1000,1000,1000};
        }

        // Extract slider values
        float slider1Value = doc["value1"];
        float slider2Value = doc["value2"];
        float slider3Value = doc["value3"];

        // Print the values to the Serial Monitor
        Serial.printf("Tha1: %.2f, Tha2: %.2f, Tha3: %.2f\n", slider1Value, slider2Value, slider3Value);

        angles.th1 = slider1Value;
        angles.th2 = slider2Value;
        angles.th3 = slider3Value;

        // Respond to the client
        serverAPI.send(200, "text/plain", "Slider values received");
        return angles;
    }
    else
    {
        serverAPI.send(405, "text/plain", "Method Not Allowed");
        return {1000, 1000, 1000};
    }
    return {1000, 1000, 1000};
}

void init_connection()
{
    Serial.begin(115200); // MAY CHANGE
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("Connecting...");
    }
    Serial.println("Connected");
    Serial.println(WiFi.localIP());
    serverAPI.on("/messageservice/async", handleUpdate);
    serverAPI.begin();
}

// void loop()
// {
//     serverAPI.handleClient();
// }
