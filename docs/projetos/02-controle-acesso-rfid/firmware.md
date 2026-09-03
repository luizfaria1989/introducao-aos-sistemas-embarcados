# Firmware

## Bibliotecas necessárias

- `MFRC522` (de Miguel Balboa)

## Código

Carregado de `docs/codigo/controle_acesso.ino`:

```cpp title="controle_acesso.ino"
--8<-- "controle_acesso.ino"
```

## Cadastrando um cartão novo

1. Grave o firmware e abra o monitor serial a **115200 baud**.
2. Aproxime o cartão a ser cadastrado.
3. Copie o UID exibido, por exemplo `A1 B2 C3 D4`.
4. Acrescente-o ao vetor `uidsAutorizados` no código e grave novamente.

!!! tip "Próximo passo"
    Guardar a lista na memória não volátil evita ter que recompilar a cada
    cartão novo. A biblioteca `Preferences` do ESP32 resolve isso em poucas
    linhas.

## Problemas comuns

| Sintoma | Causa provável |
| --- | --- |
| UID nunca é lido | `SS` ou `RST` no pino errado |
| Leitura intermitente | Jumpers longos demais para SPI |
| Placa reinicia ao acionar o relé | Alimentação USB insuficiente |
