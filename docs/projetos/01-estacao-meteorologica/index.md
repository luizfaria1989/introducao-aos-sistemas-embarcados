# Estação Meteorológica

Uma estação que lê temperatura, umidade e pressão atmosférica a cada 30
segundos e publica os valores em um painel acessível pela rede local.

## Objetivos de aprendizagem

- [x] Entender o barramento I²C e o conceito de endereço de dispositivo
- [x] Ler um sensor digital usando uma biblioteca de terceiros
- [ ] Conectar a placa a uma rede Wi-Fi
- [ ] Servir uma página HTML a partir do microcontrolador

## Lista de materiais

| Componente | Qtd. | Observação |
| --- | --- | --- |
| ESP32 DevKit v1 | 1 | Qualquer variante com 30 pinos |
| Sensor BME280 | 1 | Módulo I²C, 3,3 V |
| Display OLED 128×64 | 1 | SSD1306, também I²C |
| Resistor 4,7 kΩ | 2 | Pull-up do barramento |

!!! warning "Atenção à tensão"
    O BME280 opera em **3,3 V**. Ligá-lo ao pino de 5 V danifica o sensor
    de forma permanente.

## Resultado esperado

Ao final, o display mostra as três grandezas e o endereço IP da placa. Ao
abrir esse endereço no navegador, os mesmos dados aparecem em uma página que
se atualiza sozinha.
