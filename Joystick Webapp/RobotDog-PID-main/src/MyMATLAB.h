#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>
#include <WebServer.h>
#include <ArduinoJson.h>
const char *ssid = "Kitten";    // Change to your wifi_name
const char *pass = "123456789"; // Password of wifi

WebServer serverAPI(80);

void Init_WenAPI()
{
        // Set CORS headers
    serverAPI.sendHeader("Access-Control-Allow-Origin", "*"); // Allow all origins
    serverAPI.sendHeader("Access-Control-Allow-Methods", "POST, OPTIONS"); // Allow POST and OPTIONS methods
    serverAPI.sendHeader("Access-Control-Allow-Headers", "Content-Type"); // Allow Content-Type header
}
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
            serverAPI.send(400, "plain/text", "Invalid JSON");
            return {1000,1000,1000};
        }

        float x = doc["x"]; 
        float y = doc["y"]; 


        // Print the values to the Serial Monitor
        // Serial.printf("Tha1: %.2f, Tha2: %.2f, Tha3: %.2f\n", slider1Value, slider2Value, slider3Value);
        Serial.printf("x : %.2f , y : %.2f\n", x , y);

        // angles.th1 = slider1Value;
        // angles.th2 = slider2Value;
        // angles.th3 = slider3Value;

        // String jsonString;
        // serializeJson(doc, jsonString);
        // Serial.println("Received JSON: " + jsonString);

        serverAPI.sendHeader("Access-Control-Allow-Origin", "*"); // Allow all origins
        serverAPI.sendHeader("Access-Control-Allow-Methods", "POST, OPTIONS"); // Allow POST and OPTIONS methods
        serverAPI.sendHeader("Access-Control-Allow-Headers", "Content-Type"); // Allow Content-Type header

        // Respond to the client
        serverAPI.send(200, "plain/text", "Slider values received");
        return angles;
    }
    else
    {
        serverAPI.send(405, "plain/text", "Method Not Allowed");
        return {1000, 1000, 1000};
    }
    return {1000, 1000, 1000};
}

void handleOptions() {
    // Handle preflight requests
    serverAPI.sendHeader("Access-Control-Allow-Origin", "*");
    serverAPI.sendHeader("Access-Control-Allow-Methods", "POST, OPTIONS");
    serverAPI.sendHeader("Access-Control-Allow-Headers", "Content-Type");
    serverAPI.send(204); // No content
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
    // serverAPI.on("/messageservice/async", handleUpdate);
    // serverAPI.begin();
    serverAPI.on("/messageservice/async", HTTP_POST, handleUpdate);
    serverAPI.on("/messageservice/async", HTTP_OPTIONS, handleOptions); // Handle OPTIONS preflight requests
    serverAPI.begin();
}

// void loop()
// {
//     serverAPI.handleClient();
// }
