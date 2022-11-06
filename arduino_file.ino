#include <ESP8266MQTTClient.h>
#include <ESP8266WiFi.h>
#include <dht11.h>
#include <pt.h>
#include <ArduinoJson.h>
#define DHT11PIN D3
#define ledPin D4
dht11 DHT11;
MQTTClient mqtt;
static struct pt pt1, pt2; // each 
protothread needs one of these
void setup() {
 Serial.begin(115200);
 pinMode(ledPin, OUTPUT);
 
 WiFi.mode(WIFI_STA);
 WiFi.begin("POCO M3", "12345678");
 while (WiFi.status() != 
WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 PT_INIT(&pt1); // initialise the 
two
 PT_INIT(&pt2); // initialise the 
two
 while (WiFi.status() != 
WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 mqtt.onDisconnect([]() {
 Serial.printf("MQTT: 
Disconnected\r\n");
 });
 //topic, data, data is continuing
 mqtt.onData([](String topic, 
String data, bool cont) {
 Serial.printf("Data received, 
topic: %s, data: %s\r\n", 
topic.c_str(), data.c_str());
 led(topic.c_str(), 
data.c_str());
 });
 mqtt.onSubscribe([](int sub_id) {
 Serial.printf("Subscribe topic 
id: %d ok\r\n", sub_id);
 });
 mqtt.onConnect([]() {
 Serial.printf("MQTT: 
Connected\r\n");
 mqtt.subscribe("stiot/umeng/+", 
1);
 });
// 
mqtt.begin("ws://broker.mqttdashboar
d.com:8000/");
// 
mqtt.begin("ws://broker.emqx.io:8083
/mqtt");
 
mqtt.begin("ws://test.mosquitto.org:
8080", {.lwtTopic = "hello", .lwtMsg 
= "offline", .lwtQos = 0, .lwtRetain 
= 0});
}
void led(String topic, String data){
 if(topic == 
"stiot/umeng/publish1"){
 Serial.println("topik");
 if(data == "ON"){
 digitalWrite(ledPin, HIGH); 
 Serial.println("nyala");
 }else if(data == "OFF"){
 digitalWrite(ledPin, LOW); 
 Serial.println("mati");
 }
 }
}
static int protothread1(struct pt 
*pt, int interval) {
 static unsigned long timestamp = 
0;
 PT_BEGIN(pt);
 while(1) { // never stop
 PT_WAIT_UNTIL(pt, millis() -
timestamp > interval );
 timestamp = millis(); // take a 
new timestamp
 mqtt.publish("stiot/umeng/coba", 
"omen berhasil", 1, 1);
 }
 PT_END(pt);
}
static int protothread2(struct pt 
*pt, int interval) {
 static unsigned long timestamp = 
0;
 StaticJsonDocument<300> doc;
 JsonObject JSONencoder = 
doc.to<JsonObject>();
 PT_BEGIN(pt);
 while(1) { // never stop
 PT_WAIT_UNTIL(pt, millis() -
timestamp > interval );
 timestamp = millis(); // take a 
new timestamp
 int chk = DHT11.read(DHT11PIN);
 float humi = 
(float)DHT11.humidity;
 float temp = 
(float)DHT11.temperature;
 JSONencoder["temperature"] = 
humi;
 JSONencoder["humidity"] = temp;
 serializeJson(doc, Serial);
 // Serialize JSON document
 String json;
 serializeJson(doc, json);
 Serial.print("Humidity (%): ");
 Serial.println(humi, 2); 
 Serial.print("Temperature (C): 
");
 Serial.println(temp, 2);
 mqtt.publish("stiot/umeng/dht", 
json, 1, 1);
 }
 PT_END(pt);
}
void loop() {
 mqtt.handle();
 protothread1(&pt1, 10100); // 
schedule the two protothreads
 protothread2(&pt2, 10000); // 
schedule the two protothreads
}
