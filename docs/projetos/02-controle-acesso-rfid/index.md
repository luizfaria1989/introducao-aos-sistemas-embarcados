# Controle de Acesso RFID

Um leitor que identifica cartões RFID, compara o identificador com uma lista
de cartões autorizados e aciona uma fechadura eletrônica.

## Objetivos de aprendizagem

- [x] Entender o barramento SPI e a função do pino de seleção (`SS`)
- [ ] Tratar eventos por interrupção em vez de varredura contínua
- [ ] Gravar dados que sobrevivem ao desligamento da placa

## Lista de materiais

| Componente | Qtd. | Observação |
| --- | --- | --- |
| ESP32 DevKit v1 | 1 | — |
| Módulo RFID-RC522 | 1 | 13,56 MHz, SPI |
| Cartão / chaveiro MIFARE | 2 | Acompanham o módulo |
| Módulo relé 1 canal | 1 | Optoacoplado |
| Buzzer passivo | 1 | Sinal sonoro |

!!! danger "Fechadura em tensão de rede"
    Nesta oficina o relé aciona apenas um LED de 5 V. **Não** conecte cargas
    em 127 V/220 V sem acompanhamento de um técnico responsável.

## Resultado esperado

Ao aproximar um cartão autorizado, o relé fecha por 3 segundos e o buzzer
emite um bipe curto. Cartão desconhecido gera dois bipes e nenhum
acionamento.
