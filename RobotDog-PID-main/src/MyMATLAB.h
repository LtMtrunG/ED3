#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>
#include <WebServer.h>
#include <ArduinoJson.h>
// const char *ssid = "MauTung";    // Change to your wifi_name
// const char *pass = "a506s304"; // Password of wifi
const char *ssid = "Kitten";    // Change to your wifi_name
const char *pass = "123456789"; // Password of wifi

WebServer serverAPI(80);

double th1_ref, th2_ref, th3_ref;
double last_th1 = 0;
double last_th2 = 0;
double last_th3 = 0;
const double DEFAULT_ANGLES = 25;

void handleUpdate()
{
    if (serverAPI.method() == HTTP_POST)
    {
        // Serial.println("Start");
        // Create a JSON document to hold the incoming data
        StaticJsonDocument<200> doc;

        // Deserialize the JSON data
        DeserializationError error = deserializeJson(doc, serverAPI.arg("plain"));
        if (error)
        {
            serverAPI.send(400, "text/plain", "Invalid JSON");
            exit;
        }

        // Extract slider values
        float slider1Value = doc["value1"];
        float slider2Value = doc["value2"];
        float slider3Value = doc["value3"];

        if(last_th1 != slider1Value && last_th2 != slider2Value && last_th3 != slider3Value){
        // Print the values to the Serial Monitor
       Serial.printf("Tha1: %.2f, Tha2: %.2f, Tha3: %.2f\n", slider1Value, slider2Value, slider3Value);

        last_th1 = slider1Value;
        last_th2 = slider2Value;
        last_th3 = slider3Value;
        th1_ref = slider1Value + DEFAULT_ANGLES;
        th2_ref = slider2Value + DEFAULT_ANGLES;
        th3_ref = slider3Value + DEFAULT_ANGLES;
        }
         // Respond to the client
        serverAPI.send(200, "text/plain", "Slider values received");
    }
    else
    {
        serverAPI.send(405, "text/plain", "Method Not Allowed");
    }
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
