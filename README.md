<h2>Automação Residencial com ESP8266: acender lâmpadas com gestos e através do celular</h2>

Olá! Este é o projeto que eu e a [Gabrielle Baptista](https://github.com/theworldofbibi) fizemos para a disciplina de Objetos Inteligentes Conectados no curso de Sistemas de Informação da Universidade Presbiteriana Mackenzie.

O nosso projeto é uma adaptação de uma automação residencial feita pelo **Flávio Guimarães**, do canal [Brincando com Ideias](https://www.youtube.com/c/BrincandocomIdeias/featured) e do **Fernando Koyanagi**, do canal [Fernando K](https://www.youtube.com/c/FernandoKoyanagi/featured), que consiste no acionamento de uma lâmpada através da internet, utilizando o protocolo MQTT, e com um sensor de distância ultrassônico.

As tecnologias que utilizamos foram:
- [IBM Watson](https://cloud.ibm.com/developer/watson/documentation)
- [Node-RED](https://nodered.org/docs/)
- [Plataforma NodeMCU](https://nodemcu.readthedocs.io/en/release)

A nossa automação foi construída a partir da plataforma NodeMCU, utilizando o módulo [ESP8266](https://arduino-esp8266.readthedocs.io/en/latest). Toda a programação da aplicação foi feita nesse módulo e os demais os componentes do circuito atuam em função dele.
