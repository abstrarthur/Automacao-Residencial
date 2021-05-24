<h2>Automação Residencial com ESP8266: acender lâmpadas com gestos e através do celular</h2>

Olá! Este é o projeto que eu e a [Gabrielle Baptista](https://github.com/theworldofbibi) fizemos para a disciplina de Objetos Inteligentes Conectados no curso de Sistemas de Informação da Universidade Presbiteriana Mackenzie.

O nosso projeto é uma adaptação de uma automação residencial feita pelo **Flávio Guimarães**, do canal [Brincando com Ideias](https://www.youtube.com/c/BrincandocomIdeias/featured) e do **Fernando Koyanagi**, do canal [Fernando K](https://www.youtube.com/c/FernandoKoyanagi/featured), que consiste no acionamento de uma lâmpada através da internet, utilizando a versão **3.1.1** do [protocolo MQTT](https://developer.ibm.com/br/technologies/iot/articles/iot-mqtt-why-good-for-iot/) com um ESP8266, e com um sensor de distância ultrassônico.

**Documentação das tecnologias utilizadas:**
- [IBM Watson](https://cloud.ibm.com/developer/watson/documentation)
- [Node-RED](https://nodered.org/docs/)
- [Plataforma NodeMCU](https://nodemcu.readthedocs.io/en/release)

**Documentação da versão do protocolo MQTT:**
- [MQTT versão 3.1.1](https://nodemcu.readthedocs.io/en/dev/modules/mqtt/)

**Documentação das bibliotecas utilizadas código-fonte:**
- [ESP8266WiFi](https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html)
- [PubSubClient](https://pubsubclient.knolleary.net/)
- [ArduinoJson](https://arduinojson.org/v6/doc)
- [DNSServer](https://github.com/zhouhan0126/DNSServer---esp32)
- [WebServer](https://github.com/zhouhan0126/WebServer-esp32)
- [WiFiManager](https://github.com/tzapu/WiFiManager)

**Documentação das bibliotecas utilizadas Node-RED:**
- [node-red-contrib-ibmconnections 1.7.0](https://flows.nodered.org/node/node-red-contrib-ibmconnections)
- [node-red-contrib-scx-ibmiotapp 0.0.49](https://flows.nodered.org/node/node-red-contrib-scx-ibmiotapp)
- [node-red-contrib-ibm-db2](https://flows.nodered.org/node/node-red-contrib-ibm-db2)

**Software utilizado para a programação:**
- [Arduino IDE](https://www.arduino.cc/en/software)

A nossa automação foi construída a partir da plataforma NodeMCU, utilizando o módulo [ESP8266](https://arduino-esp8266.readthedocs.io/en/latest). Toda a programação da aplicação foi feita nesse módulo e portanto todos os componentes do circuito atuam em função dele.

Lista de materiais:
- Módulo WiFi ESP8266 NodeMCU ESP-12
- Sensor de Distância Ultrassônico HC-SR04
- Módulo Relé 5V com 1 canal
- Arduino UNO R3
- Plugue Macho 2 Polos + Terra 10A
- Protoboard com 400 pontos
- Lâmpada LED Bulbo Luz Branca 4,8W
- **3** Cabos Flexíveis de 2,5 mm² 750v
- Plafon Turquia com Soquete
- **12** Cabos Jumper Macho-Fêmea
- **2** Cabos Jumper Macho-Macho

Para fazer o acionamento da lâmpada pela internet, nós criamos um aplicativo no Node-RED com a seguinte interface:

*Dashboard do aplicativo no Node-RED*
> ![Dashboard do aplicativo no Node-RED](https://raw.githubusercontent.com/abstrarthur/automacao_residencial/main/Dashboard%20Node-RED.png "Dashboard do aplicativo no Node-RED")

*Interface do aplicativo*
> ![Interface do aplicativo](https://raw.githubusercontent.com/abstrarthur/automacao_residencial/main/Interface%20do%20aplicativo.png "Interface do aplicativo")
