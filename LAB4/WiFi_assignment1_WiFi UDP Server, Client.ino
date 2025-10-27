#include <WiFi.h>
#include <WiFiUdp.h>
#include <string.h>

#define LED_R_PIN 12
#define LED_G_PIN 13
#define LED_B_PIN 14

const char *ssid = "Ajou Univ";
const char *pwd  = "";

const char *udpAddress = "172.21.55.149";
const int udpPort = 3333;

WiFiUDP udp;

void setup() {
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);

  digitalWrite(LED_R_PIN, LOW);
  digitalWrite(LED_G_PIN, LOW);
  digitalWrite(LED_B_PIN, HIGH);

  Serial.begin(115200);

  WiFi.begin(ssid, pwd);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  udp.begin(udpPort);

  digitalWrite(LED_B_PIN, LOW);
}

void loop() {
  uint8_t buffer[50] = "hello world";
  memset(buffer, 0, 50);

  udp.parsePacket();
  if (udp.read(buffer, 50) <= 0) {
    delay(100);
    return;
  }

  if (strcmp((const char*)buffer, "ON") == 0) {
    digitalWrite(LED_R_PIN, HIGH);
    Serial.println("receive message: ON");
  } 
  else if (strcmp((const char*)buffer, "OFF") == 0) {
    digitalWrite(LED_R_PIN, LOW);
    Serial.println("receive message: OFF");
  } 
  else {
    digitalWrite(LED_R_PIN, LOW);
    Serial.println("receive message: invalid");
  }

  delay(1000);
}
