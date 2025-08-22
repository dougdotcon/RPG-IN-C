<div align="center">

```
╔══════════════════════════════════════════════════════════════════════╗
║                         CYBER RPG SYSTEM                            ║
║                      _____ _   _ ____  _____ ____                    ║
║                     / ____| \ | |  _ \|  ___/ ___|                   ║
║                    | |    |  \| | |_) | |_  \___ \                   ║
║                    | |___ | |\  |  _ <|  _|  ___) |                  ║
║                     \____|_| \_|_| \_\_|   |____/                   ║
║                                                                      ║
║                        ____  ____   ____                            ║
║                       |  _ \|  _ \ / ___|                           ║
║                       | |_) | |_) | |  _                            ║
║                       |  _ <|  __/| |_| |                           ║
║                       |_| \_\_|    \____|                           ║
║                                                                      ║
║                    [ NEURAL INTERFACE ACTIVATED ]                    ║
║                      [ SYSTEM STATUS: ONLINE ]                      ║
╚══════════════════════════════════════════════════════════════════════╝
```

<h1>🤖 CYBER RPG - Sistema Neural de Combate 🎮</h1>

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Terminal](https://img.shields.io/badge/Terminal-4D4D4D?style=for-the-badge&logo=windows-terminal&logoColor=white)](https://github.com/microsoft/terminal)
[![License](https://img.shields.io/badge/License-MIT-cyan?style=for-the-badge)](LICENSE)
[![Status](https://img.shields.io/badge/Status-ONLINE-brightgreen?style=for-the-badge)](README.md)

**Um RPG cyberpunk desenvolvido em C puro com interface neural futurista**

*Mergulhe em um mundo onde a tecnologia e a magia se encontram*

</div>

---

## 🌟 **OVERVIEW DO SISTEMA**

Este é um **sistema de RPG cyberpunk** desenvolvido em linguagem C, apresentando uma interface neural futurista e mecânicas de jogo avançadas. O projeto combina programação em C de baixo nível com uma experiência visual imersiva.

### 🎯 **Características Principais**
- 🧠 **Interface Neural**: Visual cyberpunk com cores ANSI
- ⚔️ **Sistema de Combate**: Mecânicas de RPG clássico
- 🎭 **13 Classes Únicas**: Cada uma com características especiais
- 🌍 **5 Áreas Exploráveis**: Mundos únicos com monstros específicos
- 💾 **Sistema de Save**: Persistência completa de dados
- 📊 **Progressão XP**: Sistema de level up balanceado

---

## 🚀 **QUICK START**

### 📋 **Pré-requisitos**
```bash
# Compilador GCC
sudo apt install gcc        # Ubuntu/Debian
brew install gcc            # macOS
# Windows: MinGW ou WSL
```

### ⚡ **Instalação Rápida**
```bash
# Clone o repositório
git clone https://github.com/elyz0/cyber-rpg.git
cd cyber-rpg

# Compile usando Makefile (recomendado)
make cyberpunk

# Execute o sistema
make run

# Ou compile manualmente
gcc src/Main.c src/Questionario.c src/Componentes.c src/Classes.c src/Areas.c src/CyberpunkStyle.c -o build/cyberpunk_rpg
./build/cyberpunk_rpg
```

### 🎮 **Primeira Execução**
1. **Inicie** o sistema neural
2. **Responda** ao questionário psicológico
3. **Descubra** sua classe ideal
4. **Explore** o mundo cyberpunk
5. **Evolua** seu personagem

---

## 🛠️ **COMPILAÇÃO AVANÇADA**

<details>
<summary>📦 <strong>Opções de Compilação</strong></summary>

### 🔥 **Versão Cyberpunk (Recomendada)**
```bash
make cyberpunk
# ou manualmente:
gcc src/Main.c src/Questionario.c src/Componentes.c src/Classes.c src/Areas.c src/CyberpunkStyle.c -o build/cyberpunk_rpg
```

### 📝 **Versão Clássica**
```bash
make classic
# ou manualmente:
gcc src/Main.c src/Questionario.c src/Componentes.c src/Classes.c src/Areas.c -o build/rpg_classic
```

### 🐛 **Versão Debug**
```bash
make debug
# ou manualmente:
gcc -g -Wall -Wextra src/Main.c src/Questionario.c src/Componentes.c src/Classes.c src/Areas.c src/CyberpunkStyle.c -o build/cyberpunk_debug
```

### ⚡ **Comandos de Compilação**

#### 🐧 **Linux/macOS (Makefile)**
```bash
make help          # Mostra todos os comandos disponíveis
make run           # Compila e executa versão cyberpunk
make run-classic   # Compila e executa versão clássica
make run-debug     # Compila e executa versão debug
make clean         # Remove executáveis
make clean-all     # Remove todos os arquivos gerados
```

#### 🪟 **Windows/Git Bash (Script)**
```bash
./build.sh help          # Mostra todos os comandos disponíveis
./build.sh run           # Compila e executa versão cyberpunk
./build.sh run-classic   # Compila e executa versão clássica
./build.sh run-debug     # Compila e executa versão debug
./build.sh clean         # Remove executáveis
./build.sh clean-all     # Remove todos os arquivos gerados

# Ou no CMD/PowerShell:
build.bat help           # Mostra comandos (Windows nativo)
build.bat run            # Compila e executa
```

</details>

---

## 🎭 **SISTEMA DE CLASSES**

<div align="center">

| 🛡️ **TANQUES** | ⚔️ **DPS** | 🏹 **RANGED** | 🔮 **MÁGICOS** |
|:---:|:---:|:---:|:---:|
| Guerreiro | Assassino | Atirador | Mago |
| Paladino | Bárbaro | Ranger | Bruxo |
| Cavaleiro | Ladino | - | Necromante |
| - | - | - | Clérigo |
| - | - | - | Druida |

</div>

### 🧬 **Análise Neural de Classes**
Cada classe é determinada através de um **questionário psicológico neural** que analisa:
- 🎯 **Protocolo de Combate**: Preferências táticas
- 🔫 **Sistema de Armamento**: Estilo de luta
- 🧠 **Perfil Psicológico**: Personalidade do operador

---

## 🌍 **ÁREAS EXPLORÁVEIS**

<table align="center">
<tr>
<th>🏰 Área</th>
<th>👹 Hostil</th>
<th>💎 Loot</th>
<th>🎭 Classes</th>
</tr>
<tr>
<td><strong>Castle Town</strong></td>
<td>Gárgula</td>
<td>Asas de Gárgula</td>
<td>Guerreiro, Ranger, Paladino</td>
</tr>
<tr>
<td><strong>Forest</strong></td>
<td>Dragão</td>
<td>Escama de Dragão</td>
<td>Druida</td>
</tr>
<tr>
<td><strong>Aetheria</strong></td>
<td>Manticore</td>
<td>Veneno</td>
<td>Bruxo, Mago</td>
</tr>
<tr>
<td><strong>Aztlan</strong></td>
<td>Gigante de Pedra</td>
<td>Cristais</td>
<td>Assassino, Bárbaro, Ladino</td>
</tr>
<tr>
<td><strong>Tenebris</strong></td>
<td>Peixe Abissal</td>
<td>Escama Sombria</td>
<td>Necromante</td>
</tr>
</table>

---

## 💻 **COMANDOS NEURAIS**

<div align="center">

```
╔══════════════════════════════════════════════════════════════════════╗
║                    [ COMANDOS NEURAIS ]                             ║
║                                                                      ║
║ hunt       - Engajar hostis na area atual                           ║
║ help       - Exibir interface de comandos                           ║
║ perfil     - Acessar dados do operador                              ║
║ inventario - Verificar inventario neural                            ║
║ usar       - Ativar item do inventario                              ║
║ area       - Escanear area atual                                    ║
║ salvar     - Salvar dados na memoria                                ║
║                                                                      ║
║                  [ INTERFACE ATIVA ]                                ║
╚══════════════════════════════════════════════════════════════════════╝
```

</div>

---

## 📊 **SISTEMA DE PROGRESSÃO**

### 🆙 **Level Up Neural**
```
[ LEVEL UP! ]
NEURAL ENHANCEMENT ACTIVATED
Level: 01 -> 02

VIDA: +05  |  FORCA: +02  |  DEFESA: +01

ENHANCEMENT COMPLETE
```

### 📈 **Mecânicas de XP**
- 🎯 **Base XP**: 15-24 por combate
- 📊 **Progressão**: XP necessário aumenta 50% por level
- ⚡ **Bonus**: Drop rate melhora com progresso
- 🔄 **Reset**: Vida restaurada ao subir de level

---

## 🎨 **INTERFACE CYBERPUNK**

### 🌈 **Sistema de Cores**
- 🔵 **NEON_CYAN**: Bordas e estrutura
- 🟣 **NEON_MAGENTA**: Títulos e headers
- 🟢 **NEON_GREEN**: Comandos e sucesso
- 🟡 **BRIGHT_YELLOW**: Avisos e input
- 🔴 **NEON_RED**: Erros e combate
- ⚪ **BRIGHT_WHITE**: Dados do usuário

### 🖼️ **Elementos Visuais**
- ✨ **ASCII Art**: Logo cyberpunk personalizado
- 📦 **Bordas**: Caracteres compatíveis universalmente
- 📊 **Barras**: Progresso visual com `[##########]`
- 🎭 **Temas**: Terminologia neural consistente

---

## 🏗️ **ARQUITETURA DO CÓDIGO**

<details>
<summary>📁 <strong>Estrutura de Arquivos</strong></summary>

```
cyber-rpg/
├── � src/                # Código fonte
│   ├── �📄 Main.c              # Loop principal e controle
│   ├── 🎭 Classes.c/.h        # Sistema de classes e XP
│   ├── 🌍 Areas.c/.h          # Definições de áreas
│   ├── ❓ Questionario.c/.h   # Sistema de análise neural
│   ├── 🔧 Componentes.c/.h    # Funções auxiliares
│   └── 🎨 CyberpunkStyle.c/.h # Interface visual
├── 📁 build/              # Executáveis compilados
├── 📁 saves/              # Arquivos de save do jogo
├── 📁 docs/               # Documentação e anotações
├── 📁 assets/             # Recursos (imagens, logos)
├── 🔧 Makefile            # Automação de compilação (Linux/macOS)
├── 📜 build.sh            # Script de compilação (Unix/Git Bash)
├── 📜 build.bat           # Script de compilação (Windows CMD)
├── 🚫 .gitignore          # Arquivos ignorados pelo git
└── 📖 README.md           # Documentação principal
```

</details>

<details>
<summary>🔧 <strong>Módulos Principais</strong></summary>

### 🧠 **CyberpunkStyle**
- Cores ANSI e formatação
- Funções de interface visual
- Compatibilidade multiplataforma

### 🎭 **Classes**
- Definições de 13 classes
- Sistema de XP e level up
- Balanceamento de atributos

### 🌍 **Areas**
- 5 áreas únicas
- Sistema de spawn por classe
- Monstros e drops específicos

### 🎮 **Componentes**
- Sistema de inventário
- Mecânicas de combate
- Save/Load de progresso

</details>

---

## ✅ **MELHORIAS IMPLEMENTADAS**

### 🐛 **Correções Críticas**
- [x] Bug do `(null)` na área de nascimento
- [x] Vazamento de memória no sistema de nomes
- [x] Inconsistências entre nomes de classes
- [x] Sistema de drop rate corrigido
- [x] Compatibilidade de caracteres especiais

### 🚀 **Novas Funcionalidades**
- [x] Sistema completo de XP e Level Up
- [x] Interface cyberpunk com cores ANSI
- [x] Sistema de save/load funcional
- [x] Sistema de uso de itens
- [x] Comando para visualizar área atual
- [x] Barra de progresso visual

### 🏗️ **Refatoração**
- [x] Separação modular de código
- [x] Headers limpos com apenas declarações
- [x] Eliminação de definições múltiplas
- [x] Arquitetura escalável

---

## 🤝 **CONTRIBUIÇÃO**

<div align="center">

### 🌟 **Como Contribuir**

1. 🍴 **Fork** o projeto
2. 🌿 **Crie** uma branch (`git checkout -b feature/nova-funcionalidade`)
3. 💾 **Commit** suas mudanças (`git commit -m 'Adiciona nova funcionalidade'`)
4. 📤 **Push** para a branch (`git push origin feature/nova-funcionalidade`)
5. 🔄 **Abra** um Pull Request

### 🐛 **Reportar Bugs**
Encontrou um bug? [Abra uma issue](https://github.com/elyz0/cyber-rpg/issues) com:
- 📝 Descrição detalhada
- 🔄 Passos para reproduzir
- 💻 Ambiente (OS, compilador)
- 📸 Screenshots se aplicável

</div>

---

## 📜 **LICENÇA**

<div align="center">

Este projeto está licenciado sob a **MIT License** - veja o arquivo [LICENSE](LICENSE) para detalhes.

```
Copyright (c) 2024 Cyber RPG System
Desenvolvido com 💙 em C
```

</div>

---

<div align="center">

### 🚀 **SISTEMA NEURAL ATIVO**

```
[ NEURAL INTERFACE ACTIVATED ]
[ SYSTEM STATUS: ONLINE ]
[ READY FOR COMBAT ]
```

**⭐ Se você gostou do projeto, deixe uma estrela!**

[![GitHub stars](https://img.shields.io/github/stars/elyz0/cyber-rpg?style=social)](https://github.com/elyz0/cyber-rpg/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/elyz0/cyber-rpg?style=social)](https://github.com/elyz0/cyber-rpg/network)

</div>