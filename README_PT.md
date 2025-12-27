# 🤖 CyberRpgSystem - Motor de Combate Neural

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Terminal](https://img.shields.io/badge/Terminal-4D4D4D?style=for-the-badge&logo=windows-terminal&logoColor=white)](https://github.com/microsoft/terminal)
[![License](https://img.shields.io/badge/License-MIT-cyan?style=for-the-badge)](LICENSE)
[![Status](https://img.shields.io/badge/Status-ONLINE-brightgreen?style=for-the-badge)](README.md)

**Um sistema de RPG cyberpunk desenvolvido em C puro, apresentando uma interface neural futurista e mecânicas de jogo avançadas.**

*Mergulhe em um mundo onde a tecnologia de baixo nível encontra a imersão de um RPG cyberpunk.*

---

## 🌟 **Visão Geral do Sistema**

O CyberRpgSystem é um **motor de RPG cyberpunk** desenvolvido em C puro, oferecendo uma experiência imersiva baseada em terminal. Ele combina programação eficiente de baixo nível com uma interface visual deslumbrante projetada para entusiastas do gênero.

### 🎯 **Características Principais**
- 🧠 **Interface Neural**: Visuais futuristas com códigos ANSI coloridos
- ⚔️ **Mecânicas de Combate**: Sistema de combate baseado em turnos clássico
- 🎭 **13 Classes Únicas**: Diferentes estilos de jogo e atributos especiais
- 🌍 **5 Áreas Exploráveis**: Ambientes diversos com inimigos específicos
- 💾 **Sistema de Save**: Persistência completa de dados (carregar/salvar)
- 📊 **Progressão de XP**: Sistema balanceado de nivelamento e crescimento

---

## 🚀 **Início Rápido**

### 📋 **Pré-requisitos**
bash
# Compilador GCC
sudo apt install gcc        # Ubuntu/Debian
brew install gcc            # macOS
# Windows: MinGW ou WSL


### ⚡ **Instalação**
bash
# Clone o repositório
git clone https://github.com/elyz0/cyber-rpg.git
cd cyber-rpg

# Compile usando o Makefile (Recomendado)
make cyberpunk

# Execute
./cyberpunk


### 🎮 **Compilação Manual**
Se você não possui o `make` instalado:
bash
gcc -o cyberpunk main.c game.c player.c combat.c utils.c -Wall


---

## 📂 **Estrutura do Projeto**


cyber-rpg/
├── main.c           # Ponto de entrada e loop principal
├── game.c           # Lógica do jogo e gerenciamento de estado
├── player.c         # Status do jogador e definições de classes
├── combat.c         # Motor de combate e IA
├── utils.c          # Gráficos ANSI e utilitários
├── save.dat         # (Gerado) Arquivo de save
└── Makefile         # Automação de build


---

## 🛠 **Detalhes Técnicos**

- **Linguagem**: C (Padrão C99)
- **Arquitetura**: Programação procedural modular
- **Gráficos**: Baseado em terminal com códigos de escape ANSI
- **Armazenamento**: E/S de arquivo binário para estados de save

---

## 🤝 **Contribuindo**

Contribuições são bem-vindas! Por favor, garanta que seu código siga o estilo existente.

1. Fork o projeto
2. Crie sua branch de funcionalidade (`git checkout -b feature/NovoFeature`)
3. Commite suas alterações (`git commit -m 'Adiciona NovoFeature'`)
4. Push para a branch (`git push origin feature/NovoFeature`)
5. Abra um Pull Request

---

## 📜 **Licença**

Distribuído sob a Licença MIT. Veja `LICENSE` para mais informações.
