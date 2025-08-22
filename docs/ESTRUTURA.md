# 📁 Estrutura do Projeto - Cyber RPG System

## 🎯 **Visão Geral**

Este documento descreve a nova estrutura organizacional do projeto Cyber RPG System, implementada para melhorar a manutenibilidade, escalabilidade e profissionalismo do código.

## 📂 **Estrutura de Diretórios**

```
cyber-rpg/
├── 📁 src/                    # Código fonte principal
│   ├── 📄 Main.c              # Loop principal e controle do jogo
│   ├── 📄 Main.h              # (se necessário)
│   ├── 🎭 Classes.c/.h        # Sistema de classes e progressão XP
│   ├── 🌍 Areas.c/.h          # Definições de áreas e spawns
│   ├── ❓ Questionario.c/.h   # Sistema de análise neural/quiz
│   ├── 🔧 Componentes.c/.h    # Funções auxiliares e utilitários
│   └── 🎨 CyberpunkStyle.c/.h # Interface visual e cores ANSI
│
├── 📁 build/                  # Executáveis compilados
│   ├── cyberpunk_rpg.exe     # Versão principal (cyberpunk)
│   ├── rpg_classic.exe       # Versão clássica (sem visual)
│   ├── cyberpunk_debug.exe   # Versão debug
│   └── .gitkeep              # Manter diretório no git
│
├── 📁 saves/                  # Arquivos de save do jogo
│   ├── *.txt                 # Saves em formato texto
│   ├── *.dat                 # Saves em formato binário
│   └── .gitkeep              # Manter diretório no git
│
├── 📁 docs/                   # Documentação e anotações
│   ├── 📝 Anotação.txt        # Anotações de desenvolvimento
│   ├── 📋 Perfil.txt          # Perfis de teste
│   ├── ⚙️ config.txt          # Configurações
│   ├── 📖 padrao.md           # Padrões de código
│   └── 📁 ESTRUTURA.md        # Este documento
│
├── 📁 assets/                 # Recursos e mídia
│   ├── 🖼️ logo.png            # Logo do projeto
│   └── (futuros recursos)     # Imagens, sons, etc.
│
├── 🔧 Makefile                # Automação de compilação (Linux/macOS)
├── 📜 build.sh                # Script de compilação (Unix/Git Bash)
├── 📜 build.bat               # Script de compilação (Windows CMD)
├── 🚫 .gitignore              # Arquivos ignorados pelo git
└── 📖 README.md               # Documentação principal
```

## 🛠️ **Compilação**

### **Opção 1: Makefile (Linux/macOS)**
```bash
make cyberpunk    # Compila versão principal
make classic      # Compila versão clássica
make debug        # Compila versão debug
make run          # Compila e executa
make clean        # Limpa executáveis
```

### **Opção 2: Script Shell (Git Bash/WSL)**
```bash
./build.sh cyberpunk    # Compila versão principal
./build.sh classic      # Compila versão clássica
./build.sh debug        # Compila versão debug
./build.sh run          # Compila e executa
./build.sh clean        # Limpa executáveis
```

### **Opção 3: Script Batch (Windows CMD)**
```cmd
build.bat cyberpunk    # Compila versão principal
build.bat classic      # Compila versão clássica
build.bat debug        # Compila versão debug
build.bat run          # Compila e executa
build.bat clean        # Limpa executáveis
```

### **Opção 4: Compilação Manual**
```bash
# Versão cyberpunk completa
gcc src/Main.c src/Questionario.c src/Componentes.c src/Classes.c src/Areas.c src/CyberpunkStyle.c -o build/cyberpunk_rpg

# Versão clássica (sem visual cyberpunk)
gcc src/Main.c src/Questionario.c src/Componentes.c src/Classes.c src/Areas.c -o build/rpg_classic

# Versão debug
gcc -g -Wall -Wextra src/Main.c src/Questionario.c src/Componentes.c src/Classes.c src/Areas.c src/CyberpunkStyle.c -o build/cyberpunk_debug
```

## 🎯 **Benefícios da Nova Estrutura**

### ✅ **Organização**
- **Separação clara** entre código fonte, executáveis, documentação e recursos
- **Facilita navegação** e localização de arquivos
- **Estrutura profissional** seguindo padrões da indústria

### ✅ **Manutenibilidade**
- **Código fonte centralizado** no diretório `src/`
- **Documentação organizada** no diretório `docs/`
- **Builds isolados** no diretório `build/`

### ✅ **Escalabilidade**
- **Fácil adição** de novos módulos em `src/`
- **Espaço dedicado** para recursos em `assets/`
- **Sistema de build** automatizado e flexível

### ✅ **Colaboração**
- **`.gitignore` configurado** para ignorar arquivos desnecessários
- **Scripts de build** para diferentes plataformas
- **Documentação clara** da estrutura

## 🔄 **Migração da Estrutura Antiga**

### **Antes:**
```
RPG-IN-C/
├── Main.c
├── Classes.c/.h
├── Areas.c/.h
├── Questionario.c/.h
├── Componentes.c/.h
├── CyberpunkStyle.c/.h
├── output/
├── Anotação.txt
├── Perfil.txt
├── config.txt
├── logo.png
└── README.md
```

### **Depois:**
```
RPG-IN-C/
├── src/           # Todos os .c/.h
├── build/         # Antigo output/
├── docs/          # Arquivos .txt e .md
├── assets/        # logo.png e recursos
├── saves/         # Saves do jogo
├── Makefile       # Automação
├── build.sh/.bat  # Scripts multiplataforma
└── README.md      # Atualizado
```

## 📋 **Próximos Passos**

1. **Testar compilação** em diferentes plataformas
2. **Adicionar testes** automatizados
3. **Melhorar documentação** do código
4. **Implementar CI/CD** se necessário
5. **Adicionar recursos** em `assets/` conforme necessário

## 🤝 **Contribuição**

Para contribuir com o projeto:

1. **Mantenha a estrutura** de diretórios
2. **Use os scripts de build** fornecidos
3. **Documente mudanças** em `docs/`
4. **Teste em múltiplas plataformas**
5. **Siga os padrões** estabelecidos

---

*Estrutura implementada em 2024 para melhorar a organização e profissionalismo do projeto.*
