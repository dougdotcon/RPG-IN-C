#ifndef CYBERPUNK_STYLE_H
#define CYBERPUNK_STYLE_H

#include <stdio.h>

// Códigos de cores ANSI
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"

// Cores de texto
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Cores brilhantes
#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"

// Cores de fundo
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

// Cores temáticas cyberpunk
#define NEON_CYAN BRIGHT_CYAN BOLD
#define NEON_MAGENTA BRIGHT_MAGENTA BOLD
#define NEON_GREEN BRIGHT_GREEN BOLD
#define NEON_YELLOW BRIGHT_YELLOW BOLD
#define NEON_RED BRIGHT_RED BOLD
#define MATRIX_GREEN GREEN BOLD
#define CYBER_BLUE BRIGHT_BLUE BOLD
#define ELECTRIC_PURPLE MAGENTA BOLD

// Funções de estilo
void clear_screen();
void print_cyberpunk_header();
void print_cyberpunk_border();
void print_cyberpunk_border_end();
void print_cyberpunk_menu_header();
void print_cyberpunk_menu_footer();
void print_glitch_text(const char* text);
void print_neon_text(const char* text, const char* color);
void print_matrix_effect();
void print_loading_bar(int percentage);
void print_cyberpunk_menu();
void print_system_status();
void print_data_stream();

#endif
