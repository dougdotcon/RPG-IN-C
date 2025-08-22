@echo off
REM Script de compilação para Cyber RPG System (Windows)
REM Alternativa ao Makefile para sistemas Windows

setlocal

REM Configurações
set CC=gcc
set CFLAGS=-Wall -Wextra -std=c99
set DEBUG_FLAGS=-g -DDEBUG
set RELEASE_FLAGS=-O3 -DNDEBUG

set SRC_DIR=src
set BUILD_DIR=build
set SAVES_DIR=saves

REM Arquivos fonte
set SOURCES=%SRC_DIR%\Main.c %SRC_DIR%\Questionario.c %SRC_DIR%\Componentes.c %SRC_DIR%\Classes.c %SRC_DIR%\Areas.c %SRC_DIR%\CyberpunkStyle.c

REM Executáveis
set CYBERPUNK_TARGET=%BUILD_DIR%\cyberpunk_rpg.exe
set CLASSIC_TARGET=%BUILD_DIR%\rpg_classic.exe
set DEBUG_TARGET=%BUILD_DIR%\cyberpunk_debug.exe

REM Criar diretórios se não existirem
if not exist %BUILD_DIR% mkdir %BUILD_DIR%
if not exist %SAVES_DIR% mkdir %SAVES_DIR%

REM Verificar argumentos
if "%1"=="" goto cyberpunk
if "%1"=="cyberpunk" goto cyberpunk
if "%1"=="classic" goto classic
if "%1"=="debug" goto debug
if "%1"=="run" goto run
if "%1"=="run-classic" goto run_classic
if "%1"=="run-debug" goto run_debug
if "%1"=="clean" goto clean
if "%1"=="clean-all" goto clean_all
if "%1"=="help" goto help
goto help

:cyberpunk
echo Compilando versão cyberpunk...
%CC% %CFLAGS% %RELEASE_FLAGS% %SOURCES% -o %CYBERPUNK_TARGET%
if %errorlevel% equ 0 (
    echo Compilação concluída: %CYBERPUNK_TARGET%
) else (
    echo Erro na compilação!
)
goto end

:classic
echo Compilando versão clássica...
%CC% %CFLAGS% %RELEASE_FLAGS% %SRC_DIR%\Main.c %SRC_DIR%\Questionario.c %SRC_DIR%\Componentes.c %SRC_DIR%\Classes.c %SRC_DIR%\Areas.c -o %CLASSIC_TARGET%
if %errorlevel% equ 0 (
    echo Compilação concluída: %CLASSIC_TARGET%
) else (
    echo Erro na compilação!
)
goto end

:debug
echo Compilando versão debug...
%CC% %CFLAGS% %DEBUG_FLAGS% %SOURCES% -o %DEBUG_TARGET%
if %errorlevel% equ 0 (
    echo Compilação concluída: %DEBUG_TARGET%
) else (
    echo Erro na compilação!
)
goto end

:run
call :cyberpunk
if %errorlevel% equ 0 (
    echo Executando versão cyberpunk...
    %CYBERPUNK_TARGET%
)
goto end

:run_classic
call :classic
if %errorlevel% equ 0 (
    echo Executando versão clássica...
    %CLASSIC_TARGET%
)
goto end

:run_debug
call :debug
if %errorlevel% equ 0 (
    echo Executando versão debug...
    %DEBUG_TARGET%
)
goto end

:clean
echo Limpando executáveis...
if exist %BUILD_DIR%\*.exe del /q %BUILD_DIR%\*.exe
echo Limpeza concluída.
goto end

:clean_all
echo Limpando todos os arquivos gerados...
if exist %BUILD_DIR%\*.exe del /q %BUILD_DIR%\*.exe
if exist %SAVES_DIR%\*.txt del /q %SAVES_DIR%\*.txt
if exist %SAVES_DIR%\*.dat del /q %SAVES_DIR%\*.dat
if exist %SAVES_DIR%\*.sav del /q %SAVES_DIR%\*.sav
echo Limpeza completa concluída.
goto end

:help
echo Cyber RPG System - Script de Compilação (Windows)
echo.
echo Comandos disponíveis:
echo   build.bat cyberpunk    - Compila versão cyberpunk (padrão)
echo   build.bat classic      - Compila versão clássica
echo   build.bat debug        - Compila versão debug
echo   build.bat run          - Compila e executa versão cyberpunk
echo   build.bat run-classic  - Compila e executa versão clássica
echo   build.bat run-debug    - Compila e executa versão debug
echo   build.bat clean        - Remove executáveis
echo   build.bat clean-all    - Remove todos os arquivos gerados
echo   build.bat help         - Mostra esta ajuda
echo.
echo Exemplos:
echo   build.bat              - Compila versão cyberpunk
echo   build.bat run          - Compila e executa
echo   build.bat clean        - Limpa arquivos compilados
goto end

:end
endlocal
