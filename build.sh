#!/bin/bash
# Script de compilação para Cyber RPG System
# Alternativa ao Makefile para sistemas sem make

# Configurações
CC=gcc
CFLAGS="-Wall -Wextra -std=c99"
DEBUG_FLAGS="-g -DDEBUG"
RELEASE_FLAGS="-O3 -DNDEBUG"

SRC_DIR=src
BUILD_DIR=build
SAVES_DIR=saves

# Arquivos fonte
SOURCES="$SRC_DIR/Main.c $SRC_DIR/Questionario.c $SRC_DIR/Componentes.c $SRC_DIR/Classes.c $SRC_DIR/Areas.c $SRC_DIR/CyberpunkStyle.c"

# Executáveis
CYBERPUNK_TARGET="$BUILD_DIR/cyberpunk_rpg"
CLASSIC_TARGET="$BUILD_DIR/rpg_classic"
DEBUG_TARGET="$BUILD_DIR/cyberpunk_debug"

# Função para criar diretórios
create_dirs() {
    mkdir -p "$BUILD_DIR"
    mkdir -p "$SAVES_DIR"
}

# Função para compilar versão cyberpunk
build_cyberpunk() {
    echo "Compilando versão cyberpunk..."
    create_dirs
    $CC $CFLAGS $RELEASE_FLAGS $SOURCES -o "$CYBERPUNK_TARGET"
    if [ $? -eq 0 ]; then
        echo "Compilação concluída: $CYBERPUNK_TARGET"
    else
        echo "Erro na compilação!"
        exit 1
    fi
}

# Função para compilar versão clássica
build_classic() {
    echo "Compilando versão clássica..."
    create_dirs
    $CC $CFLAGS $RELEASE_FLAGS $SRC_DIR/Main.c $SRC_DIR/Questionario.c $SRC_DIR/Componentes.c $SRC_DIR/Classes.c $SRC_DIR/Areas.c -o "$CLASSIC_TARGET"
    if [ $? -eq 0 ]; then
        echo "Compilação concluída: $CLASSIC_TARGET"
    else
        echo "Erro na compilação!"
        exit 1
    fi
}

# Função para compilar versão debug
build_debug() {
    echo "Compilando versão debug..."
    create_dirs
    $CC $CFLAGS $DEBUG_FLAGS $SOURCES -o "$DEBUG_TARGET"
    if [ $? -eq 0 ]; then
        echo "Compilação concluída: $DEBUG_TARGET"
    else
        echo "Erro na compilação!"
        exit 1
    fi
}

# Função para executar versão cyberpunk
run_cyberpunk() {
    build_cyberpunk
    if [ $? -eq 0 ]; then
        echo "Executando versão cyberpunk..."
        ./"$CYBERPUNK_TARGET"
    fi
}

# Função para executar versão clássica
run_classic() {
    build_classic
    if [ $? -eq 0 ]; then
        echo "Executando versão clássica..."
        ./"$CLASSIC_TARGET"
    fi
}

# Função para executar versão debug
run_debug() {
    build_debug
    if [ $? -eq 0 ]; then
        echo "Executando versão debug..."
        ./"$DEBUG_TARGET"
    fi
}

# Função para limpeza
clean() {
    echo "Limpando executáveis..."
    rm -f "$BUILD_DIR"/*.exe "$BUILD_DIR"/cyberpunk_rpg "$BUILD_DIR"/rpg_classic "$BUILD_DIR"/cyberpunk_debug
    echo "Limpeza concluída."
}

# Função para limpeza completa
clean_all() {
    echo "Limpando todos os arquivos gerados..."
    rm -f "$BUILD_DIR"/*.exe "$BUILD_DIR"/cyberpunk_rpg "$BUILD_DIR"/rpg_classic "$BUILD_DIR"/cyberpunk_debug
    rm -f "$SAVES_DIR"/*.txt "$SAVES_DIR"/*.dat "$SAVES_DIR"/*.sav
    echo "Limpeza completa concluída."
}

# Função de ajuda
show_help() {
    echo "Cyber RPG System - Script de Compilação"
    echo ""
    echo "Comandos disponíveis:"
    echo "  ./build.sh cyberpunk    - Compila versão cyberpunk (padrão)"
    echo "  ./build.sh classic      - Compila versão clássica"
    echo "  ./build.sh debug        - Compila versão debug"
    echo "  ./build.sh run          - Compila e executa versão cyberpunk"
    echo "  ./build.sh run-classic  - Compila e executa versão clássica"
    echo "  ./build.sh run-debug    - Compila e executa versão debug"
    echo "  ./build.sh clean        - Remove executáveis"
    echo "  ./build.sh clean-all    - Remove todos os arquivos gerados"
    echo "  ./build.sh help         - Mostra esta ajuda"
    echo ""
    echo "Exemplos:"
    echo "  ./build.sh              - Compila versão cyberpunk"
    echo "  ./build.sh run          - Compila e executa"
    echo "  ./build.sh clean        - Limpa arquivos compilados"
}

# Processar argumentos
case "${1:-cyberpunk}" in
    cyberpunk)
        build_cyberpunk
        ;;
    classic)
        build_classic
        ;;
    debug)
        build_debug
        ;;
    run)
        run_cyberpunk
        ;;
    run-classic)
        run_classic
        ;;
    run-debug)
        run_debug
        ;;
    clean)
        clean
        ;;
    clean-all)
        clean_all
        ;;
    help)
        show_help
        ;;
    *)
        echo "Comando desconhecido: $1"
        show_help
        exit 1
        ;;
esac
