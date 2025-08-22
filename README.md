![Logo do C-RPG Engine](logo.png)

# C-RPG Engine

Este é um projeto de RPG desenvolvido em linguagem C, contendo sistemas básicos de gerenciamento de áreas, classes de personagens e componentes de jogo.

## Estrutura de Arquivos

- `Main.c`: Arquivo principal contendo a função `main()` e loop central do jogo
- `Questionario.c`: Implementação de sistemas de diálogo e questionários
- `Areas.h`: Definições de estruturas para áreas/mapas do jogo
- `Classes.h`: Definições de classes de personagens e atributos
- `Componentes.h`: Componentes gerais para mecânicas de jogo
- `output/`: Diretório contendo executáveis compilados

## Compilação e Execução

Para compilar o projeto, utilize o seguinte comando no terminal:

```bash
gcc Main.c Questionario.c -o output/rpg_game
```

Para executar o jogo:

```bash
./output/rpg_game
```

## Funcionalidades Principais

- Sistema de classes de personagens com atributos variados
- Mecânicas de exploração de áreas
- Sistema de diálogo interativo via questionários
- Gerenciamento de progressão do personagem

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests para melhorias no projeto.