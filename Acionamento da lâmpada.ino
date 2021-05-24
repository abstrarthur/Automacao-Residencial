// Objetos Inteligentes Conectados - Turma: 05H11

// Arthur Lisboa Santana de Queiroz - 31749526
// Gabrielle Baptista da Silva Fonseca - 31745547

// Importação de bibliotecas
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

// Dados do dispositivo criado no IBM Watson
const String ORG_ID = "xxx";
const String DEVICE_TYPE = "xxx";
const String DEVICE_ID = "xxx";
#define DEVICE_TOKEN "xxx";

// Pinos no ESP8266
#define rele 5 // D1
#define trigger 12 // D6
#define echo 13 // D7

// Variáveis
int distance = 0;
boolean ligada = false;

// Constantes
const String CLIENT_ID = "d:" + ORG_ID + ":" + DEVICE_TYPE + ":" + DEVICE_ID;
const String MQTT_SERVER = ORG_ID + ".messaging.internetofthings.ibmcloud.com";

// Tópico do MQTT
#define topico_lampada "iot-2/cmd/lampada/fmt/json" 

WiFiClient wifiClient;
PubSubClient client(MQTT_SERVER.c_str(), 1883, wifiClient);

void setup() {
  Serial.begin(9600);

  pinMode(rele, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  // Configuração da rede WiFi
  WiFiManager wifiManager;
  wifiManager.setAPCallback(configModeCallback);
  wifiManager.setSaveConfigCallback(saveConfigCallback);

  // wifiManager.resetSettings(); // Descomente essa linha e compile o código para resetar as configurações da sua rede WiFi
  // Depois de ter resetado, faça a programação da nova rede e compile o código novamente, mas dessa vez com a linha comentada para não executar a função de novo

  wifiManager.autoConnect("WiFi de demonstração"); // O primeiro parâmetro é obrigatório, que será o nome da sua rede WiFi
  // Também é possível colocar um segundo parâmetro, separado por vírgula 
  // O segundo parâmetro é opcional, que será a senha da sua rede

  connectMQTTServer();
}

void loop() {
  client.loop();

  // Sensor de movimento
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);      
  digitalWrite(trigger, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  distance = pulseIn(echo, HIGH);    
  distance = distance/58; // Conversão da distância para centímetros

  // Acionamento da lâmpada pelo sensor de movimento
  if(distance <= 6 && ligada == false){
    digitalWrite(rele, HIGH);
    ligada = true;
    delay(1000); // Delay de 1 segundo para distinguir um movimento do outro
  }
  
  else if(distance <= 6 && ligada == true){
    digitalWrite(rele, LOW);
    ligada = false;
    delay(1000); // Delay de 1 segundo para distinguir um movimento do outro
  }
}

// Função responsável pela conexão ao servidor MQTT
// É importante que todos os dados do dispositivo criado no IBM Watson estejam declarados corretamente nas constantes no início do código!
void connectMQTTServer() {
  Serial.println("Conectando ao servidor MQTT...");

  if(client.connect(CLIENT_ID.c_str(), "use-token-auth", DEVICE_TOKEN)) {
     Serial.println("Conectado ao Broker MQTT...");
     client.setCallback(callback);

     // Inscrição no tópico MQTT
     client.subscribe(topico_lampada); 
  }
  else{
     Serial.print("Erro: ");
     Serial.println(client.state());
     connectMQTTServer();
  }
}

// Função responsável por receber os arquivos JSON e acionar a lâmpada de acordo com o valor recebido
void callback(char* topic, unsigned char* payload, unsigned int length) {
  StaticJsonBuffer<30> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(payload);

  // Valor recebido do pacote JSON
  int valor = root["value"];

  // Acionar o módulo relé em função do valor recebido do JSON
  if(strcmp(topic, topico_lampada) == 0){
    if(valor == 1){
      ligada = true; 
    }
    else{
      ligada = false;
    }
    digitalWrite(rele, valor);
  }
}

// Configuração da rede WiFi
void configModeCallback( WiFiManager *myWiFiManager) {
  Serial.println("Entrou no modo de configuração");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

// Salvar as configurações para o próximo acesso
void saveConfigCallback() {
  Serial.println("Configuração salva");
  Serial.println(WiFi.softAPIP());
}
