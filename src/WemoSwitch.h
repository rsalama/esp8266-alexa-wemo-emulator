#ifndef WemoSwitch_H
#define WemoSwitch_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include "CallbackFunction.h"


class WemoSwitch {
private:
        ESP8266WebServer *server = NULL;
        WiFiUDP UDP;
        String serial;
        String persistent_uuid;
        String device_name;
        int pin;
        unsigned int localPort;
        CallbackFunction callback;
        boolean reverse;

        void startWebServer();
        void handleEventservice();
        void handleUpnpControl();
        void handleRoot();
        void handleSetupXml();
public:
        WemoSwitch();
        WemoSwitch(String alexaInvokeName, int pin, unsigned int port, CallbackFunction cb, boolean rev = false);
        ~WemoSwitch();
        String getAlexaInvokeName();
        void serverLoop();
        void respondToSearch(IPAddress& senderIP, unsigned int senderPort);
};

#endif
