Semáforo com Raspberry Pi Pico W no Wokwi

🏗️ Visão Geral

Este projeto apresenta uma implementação de semáforo utilizando o Raspberry Pi Pico W, aproveitando a API do Pico SDK para controlar temporizadores. O sistema gerencia a troca dos sinais vermelho, amarelo e verde em intervalos de 3 segundos, simulando o funcionamento de um semáforo real.

A simulação foi realizada na plataforma Wokwi, proporcionando um ambiente prático para testes de sistemas embarcados.

🔹 Características Principais

Alternância dos LEDs conforme a sequência padrão de um semáforo.

Utilização da função add_repeating_timer_ms() para alternar entre os estados de forma periódica.

Exibição de mensagens no monitor serial indicando o estado atual do semáforo.

O loop principal imprime atualizações a cada 1 segundo, sinalizando que o sistema está rodando corretamente.

🔧 Configuração de Hardware

Componentes Utilizados

Microcontrolador: Raspberry Pi Pico W

LEDs: Vermelho, Amarelo e Verde

Resistores: 330Ω para cada LED

Ligação dos LEDs ao Pico W

LEDs:

GPIO 11: Vermelho

GPIO 12:Amarelo

GPIO 13:Verde

📝 Estrutura do Código

O funcionamento do semáforo está definido no arquivo atividadeu4c05atv1.c, que faz uso da biblioteca Pico SDK para configurar os GPIOs e administrar o temporizador.

🚀 Como Rodar a Simulação no Wokwi

Acesse o VSC em conjunto com a extensao Wokwi e Raspberry Pi Pico Project e crie um novo projeto com o Raspberry Pi Pico W.

Carregue os arquivos do projeto (atividadeu4c05atv1.c, CMakeLists.txt e diagram.json).

Verifique o diagram.json para definir os LEDs e suas respectivas conexões.

Compile e inicie a simulação.

Acompanhe as mensagens no monitor serial para observar a mudança dos estados do semáforo.

▶️ Instruções de Uso

Iniciar a simulação: Assim que a simulação começar, o semáforo iniciará no estado vermelho.

Monitoramento via Serial: O monitor serial exibirá mensagens indicando qual cor do semáforo está ativa.

Ciclo do semáforo: A cada 3 segundos, a cor do LED será alterada na seguinte sequência:

Vermelho → Verde → Amarelo → Vermelho.

Parar a simulação: Para encerrar a execução, basta interromper a simulação no Wokwi.

📂 Estrutura do Projeto

├── atividadeu4c05atv1.c        # Código principal em C
├── CMakeLists.txt   # Arquivo de configuração do CMake
├── diagram.json     # Definição dos componentes no Wokwi
├── README.md        # Documentação do projeto
├──wokwi .toml       # Arquivo Toml

👤 Autor

Adrian Trajano de A. da S.

