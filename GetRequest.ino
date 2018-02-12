/*
  Simple GET client for ArduinoHttpClient library
  Connects to server once every five seconds, sends a GET request

 

  created 14 Feb 2016
  by Tom Igoe
  
  this example is in the public domain
 */
#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoHttpClient.h>
/////// Ethernet Settings ///////
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 222);


char serverAddress[] = "192.168.1.51";  // server address
int port = 80;

EthernetClient ethr;
HttpClient client = HttpClient(ethr, serverAddress, port);
String response;
int statusCode = 0;

void setup() {
  Serial.begin(9600);

  Serial.println("Attempting to connect to Network.");

  Ethernet.begin(mac, ip);

  Serial.println("Success.");

}

void loop() {
  Serial.println("making GET request");
  client.get("/get.php?tag=160196116163179&pin=");

  // read the status code and body of the response
  statusCode = client.responseStatusCode();
  response = client.responseBody();
  
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);
  Serial.println("Wait five seconds");
  delay(5000);
}
