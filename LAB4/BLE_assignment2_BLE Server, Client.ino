#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define BT_PIN 2
#define LED_R_PIN 12
#define LED_G_PIN 13
#define LED_B_PIN 14
#define LED_PIN 15

BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
char value_list[2] = {'N', 'F'};
uint8_t t_value;
uint8_t state = 0;

#define SERVICE_UUID           "6617b37c-6af6-47d7-8c2e-c3a083bfd9f9"
#define CHARACTERISTIC_UUID    "7c7a6f3c-215c-4ca8-96b6-15b3e2b12f14"
#define LED_PIN 15

class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        deviceConnected = true;
    }

    void onDisconnect(BLEServer* pServer) {
        deviceConnected = false;
    }
};

void setup() {
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
  digitalWrite(LED_R_PIN, LOW);
  digitalWrite(LED_G_PIN, HIGH);
  digitalWrite(LED_B_PIN, LOW);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  pinMode(BT_PIN, INPUT);

  Serial.begin(115200);

  BLEDevice::init("MyESP32_4_S_server");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );

  pCharacteristic->addDescriptor(new BLE2902());

  pService->start();
  pServer->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}

void loop() {
  uint8_t t_ON = 'n';
  uint8_t t_OFF = 'f';
  uint8_t t = 0;

  if (deviceConnected) {
    if (digitalRead(BT_PIN)) {
      Serial.println(digitalRead(BT_PIN));
      while (digitalRead(BT_PIN)) {
        Serial.println("bt on");
