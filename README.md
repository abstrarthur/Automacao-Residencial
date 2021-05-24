<h2>Automação Residencial com ESP8266: acender lâmpadas com gestos e através do celular</h2>

Olá! Este é o projeto que eu e a [Gabrielle Baptista](https://github.com/theworldofbibi) fizemos para a disciplina de Objetos Inteligentes Conectados no curso de Sistemas de Informação da Universidade Presbiteriana Mackenzie.

O nosso projeto é uma adaptação de uma automação residencial feita pelo **Flávio Guimarães**, do canal [Brincando com Ideias](https://www.youtube.com/c/BrincandocomIdeias/featured) e do **Fernando Koyanagi**, do canal [Fernando K](https://www.youtube.com/c/FernandoKoyanagi/featured), que consiste no acionamento de uma lâmpada através da internet, utilizando o protocolo MQTT, e com um sensor de distância ultrassônico.

As tecnologias que utilizamos foram:
- [IBM Watson](https://cloud.ibm.com/developer/watson/documentation)
- [Node-RED](https://nodered.org/docs/)
- [Plataforma NodeMCU](https://nodemcu.readthedocs.io/en/release)

A nossa automação foi construída a partir da plataforma NodeMCU, utilizando o módulo [ESP8266](https://arduino-esp8266.readthedocs.io/en/latest). Toda a programação da aplicação foi feita nesse módulo e portanto todos os componentes do circuito atuam em função dele.

Esses foram os materiais que utilizamos no projeto:
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
