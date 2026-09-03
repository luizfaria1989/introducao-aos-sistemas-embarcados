# Firmware

## Bibliotecas necessárias

Instale pelo gerenciador de bibliotecas da IDE:

- `Adafruit BME280 Library`
- `Adafruit SSD1306`

## Código

O trecho abaixo é carregado automaticamente do arquivo
`docs/codigo/estacao_meteorologica.ino`:

```cpp title="estacao_meteorologica.ino"
--8<-- "estacao_meteorologica.ino"
```

## Gravando na placa

=== "Arduino IDE"

    1. Selecione **Ferramentas → Placa → ESP32 Dev Module**.
    2. Escolha a porta serial correspondente.
    3. Clique em **Carregar** (++ctrl+u++).

=== "PlatformIO"

    ```bash
    pio run --target upload
    pio device monitor --baud 115200
    ```

## Verificando o funcionamento

Abra o monitor serial a **115200 baud**. As leituras devem aparecer a cada
30 segundos, junto com o IP obtido pela placa.
