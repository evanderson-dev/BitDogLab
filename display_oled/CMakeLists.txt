# Define a versão mínima do CMake necessária para este projeto
cmake_minimum_required(VERSION 3.13)

# Define o padrão C (C11) e C++ (C++17) para consistência
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Gera um arquivo compile_commands.json útil para ferramentas como IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == NÃO EDITE ESSAS LINHAS se estiver usando a extensão VS Code para Pico ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 1.5.1)               # Versão do SDK do Pico usada
set(toolchainVersion 13_3_Rel1)     # Versão do toolchain ARM (ajuste se usar outra, ex.: 13_2_Rel1)
set(picotoolVersion 2.0.0)          # Versão do picotool
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

# Define o tipo de placa Pico a ser usada
# - Altere 'pico_w' para 'pico' se estiver usando um Pico padrão sem Wi-Fi
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Inclui o arquivo de importação do SDK do Pico (deve estar no diretório do projeto)
# - Não altere a menos que o pico_sdk_import.cmake esteja em outro local
include(pico_sdk_import.cmake)

# Nomeia o projeto como 'display_oled' e define os tipos de linguagens (C, C++, ASM)
# - Mude 'display_oled' para outro nome se quiser renomear o projeto
project(display_oled C CXX ASM)

# Inicializa o SDK do Pico (necessário para usar suas funções e bibliotecas)
pico_sdk_init()

# Define o executável do projeto e lista os arquivos fonte
# - Adicione ou remova arquivos .c aqui se incluir novos módulos (ex.: 'novo_arquivo.c')
add_executable(display_oled
    ssd1306.c     # Driver do display OLED
    main.c        # Código principal da aplicação
)

# Define o nome do programa exibido em ferramentas de depuração
# - Altere "display_oled" para um nome diferente se quiser mudar a identificação do programa
pico_set_program_name(display_oled "display_oled")

# Define a versão do programa
# - Atualize "0.1" para outra versão conforme o desenvolvimento avança (ex.: "1.0")
pico_set_program_version(display_oled "0.1")

pico_enable_stdio_uart(display_oled 0)
pico_enable_stdio_usb(display_oled 1)

# Configurações de saída de depuração
# ALTERE AQUI para habilitar/desabilitar UART ou USB:
# 0 = desabilitado, 1 = habilitado
# Exemplo: pico_enable_stdio_uart(display_oled 1) para usar UART
pico_enable_stdio_uart(display_oled 0) # UART desabilitado
pico_enable_stdio_usb(display_oled 1)  # USB habilitado (saída via USB Serial)

# Vincula as bibliotecas necessárias ao executável
# ALTERE AQUI para adicionar mais bibliotecas do SDK se necessário:
# Exemplo: hardware_gpio, hardware_pwm, etc.
target_link_libraries(display_oled
    pico_stdlib    # Biblioteca padrão do Pico (inclui funções básicas como sleep_ms)
    hardware_i2c   # Biblioteca para suporte ao I2C (necessária para o SSD1306)
)

# Define os diretórios de inclusão para headers
# ALTERE AQUI se precisar incluir headers de outros diretórios:
# Exemplo: adicione "${CMAKE_CURRENT_LIST_DIR}/lib" para uma pasta "lib"
target_include_directories(display_oled PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}  # Inclui o diretório atual (onde estão ssd1306.h, etc.)
)

# Gera arquivos extras como .uf2 para flashing no Pico
# NÃO ALTERE AQUI a menos que queira desabilitar a geração de arquivos extras
pico_add_extra_outputs(display_oled)