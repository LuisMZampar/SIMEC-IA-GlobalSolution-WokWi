# SIMEC: Sistema Integrado de Monitoramento de Energia Corporativa

O SIMEC é um sistema projetado para empresas, com o objetivo de monitorar e gerenciar o consumo de energia de forma eficiente, promovendo práticas sustentáveis e engajando colaboradores por meio de gamificação. Com este sistema, as empresas podem acompanhar, em tempo real, o consumo de energia por setores ou dispositivos, obter recomendações personalizadas e relatórios detalhados para tomada de decisão.

## 🌟 Funcionalidades Principais
- **Monitoramento em Tempo Real**: Acompanhe o consumo de energia por setores ou dispositivos da empresa.
- **Dicas Personalizadas**: Receba insights específicos para otimizar o uso de energia.
- **Relatórios Detalhados**: Acesse relatórios mensais com dados históricos para acompanhar e melhorar os resultados.

## 🎯 Objetivos
1. Monitorar o consumo de energia por setor ou dispositivo.
2. Fornecer recomendações para promover eficiência energética.
3. Oferecer uma interface intuitiva e relatórios detalhados.

## 💡 Benefícios
- **Redução de Custos**: Identifique e elimine desperdícios, reduzindo o consumo e os custos de energia.
- **Conscientização Sustentável**: Engaje colaboradores para adotarem práticas de consumo conscientes.
- **Competição Saudável**: Use a gamificação para promover hábitos energéticos responsáveis e estimular a colaboração entre equipes.

## 🛠️ Tecnologias Utilizadas
- **ESP32**: Para coleta de dados e conexão com a rede.
- **MQTT**: Para troca de mensagens entre dispositivos e o sistema.
- **NTP Client**: Para sincronização de horários.
- **LiquidCrystal_I2C**: Para exibição de dados em displays LCD.
- **Wokwi**: Ambiente de simulação para prototipação.

---

## 📊 Estrutura do Sistema
1. **Monitoramento de Dados**:
   - O consumo de energia é capturado em tempo real por dispositivos ESP32.
2. **Publicação no Servidor MQTT**:
   - Dados coletados são enviados para análise e armazenamento.
3. **Visualização e Gamificação**:
   - Interface amigável exibe os dados e permite que equipes acompanhem seu desempenho.
4. **Relatórios Mensais**:
   - Informações consolidadas para acompanhamento de metas de sustentabilidade.

---

## 🚀 Como Usar
1. Clone o repositório:
   ```bash
   git clone https://github.com/LuisMZampar/SIMEC-IA-GlobalSolution-WorkWi.git


## Arquivo JSON do NODE-RED

[flows.json](https://github.com/user-attachments/files/17835724/flows.json)
