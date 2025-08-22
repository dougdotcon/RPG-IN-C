# Makefile para Cyber RPG System
# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O3 -DNDEBUG

# Diretórios
SRC_DIR = src
BUILD_DIR = build
SAVES_DIR = saves

# Arquivos fonte
SOURCES = $(SRC_DIR)/Main.c $(SRC_DIR)/Questionario.c $(SRC_DIR)/Componentes.c \
          $(SRC_DIR)/Classes.c $(SRC_DIR)/Areas.c $(SRC_DIR)/CyberpunkStyle.c

# Executáveis
CYBERPUNK_TARGET = $(BUILD_DIR)/cyberpunk_rpg
CLASSIC_TARGET = $(BUILD_DIR)/rpg_classic
DEBUG_TARGET = $(BUILD_DIR)/cyberpunk_debug

# Regra padrão
all: cyberpunk

# Versão cyberpunk (recomendada)
cyberpunk: $(CYBERPUNK_TARGET)

$(CYBERPUNK_TARGET): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) $(SOURCES) -o $@

# Versão clássica (sem CyberpunkStyle)
classic: $(CLASSIC_TARGET)

$(CLASSIC_TARGET): $(SRC_DIR)/Main.c $(SRC_DIR)/Questionario.c $(SRC_DIR)/Componentes.c $(SRC_DIR)/Classes.c $(SRC_DIR)/Areas.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) $^ -o $@

# Versão debug
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SOURCES) -o $@

# Criar diretórios necessários
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(SAVES_DIR):
	mkdir -p $(SAVES_DIR)

# Executar o jogo
run: cyberpunk | $(SAVES_DIR)
	./$(CYBERPUNK_TARGET)

run-classic: classic | $(SAVES_DIR)
	./$(CLASSIC_TARGET)

run-debug: debug | $(SAVES_DIR)
	./$(DEBUG_TARGET)

# Limpeza
clean:
	rm -f $(BUILD_DIR)/*.exe $(BUILD_DIR)/cyberpunk_rpg $(BUILD_DIR)/rpg_classic $(BUILD_DIR)/cyberpunk_debug

clean-all: clean
	rm -rf $(BUILD_DIR)/* $(SAVES_DIR)/*

# Instalar dependências (se necessário)
install:
	@echo "Verificando dependências..."
	@which gcc > /dev/null || (echo "GCC não encontrado. Instale o GCC." && exit 1)
	@echo "Todas as dependências estão instaladas."

# Ajuda
help:
	@echo "Cyber RPG System - Makefile"
	@echo ""
	@echo "Comandos disponíveis:"
	@echo "  make cyberpunk    - Compila versão cyberpunk (padrão)"
	@echo "  make classic      - Compila versão clássica"
	@echo "  make debug        - Compila versão debug"
	@echo "  make all          - Compila versão cyberpunk"
	@echo "  make run          - Compila e executa versão cyberpunk"
	@echo "  make run-classic  - Compila e executa versão clássica"
	@echo "  make run-debug    - Compila e executa versão debug"
	@echo "  make clean        - Remove executáveis"
	@echo "  make clean-all    - Remove todos os arquivos gerados"
	@echo "  make install      - Verifica dependências"
	@echo "  make help         - Mostra esta ajuda"

# Declarar targets que não são arquivos
.PHONY: all cyberpunk classic debug run run-classic run-debug clean clean-all install help
