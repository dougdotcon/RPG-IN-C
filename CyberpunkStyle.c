#include "CyberpunkStyle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
    #include <windows.h>
    #define sleep_ms(x) Sleep(x)
#else
    #include <unistd.h>
    #define sleep_ms(x) usleep((x)*1000)
#endif

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_cyberpunk_header() {
    printf(NEON_CYAN);
    printf("+======================================================================+\n");
    printf("|" NEON_MAGENTA "                         CYBER RPG SYSTEM                         " NEON_CYAN "|\n");
    printf("|" NEON_MAGENTA "                      _____ _   _ ____  _____ ____                  " NEON_CYAN "|\n");
    printf("|" NEON_MAGENTA "                     / ____| \\ | |  _ \\|  ___/ ___|                 " NEON_CYAN "|\n");
    printf("|" NEON_MAGENTA "                    | |    |  \\| | |_) | |_  \\___ \\                 " NEON_CYAN "|\n");
    printf("|" NEON_MAGENTA "                    | |___ | |\\  |  _ <|  _|  ___) |                " NEON_CYAN "|\n");
    printf("|" NEON_MAGENTA "                     \\____|_| \\_|_| \\_\\_|   |____/                 " NEON_CYAN "|\n");
    printf("|                                                                      |\n");
    printf("|" NEON_GREEN "                        ____  ____   ____                           " NEON_CYAN "|\n");
    printf("|" NEON_GREEN "                       |  _ \\|  _ \\ / ___|                          " NEON_CYAN "|\n");
    printf("|" NEON_GREEN "                       | |_) | |_) | |  _                           " NEON_CYAN "|\n");
    printf("|" NEON_GREEN "                       |  _ <|  __/| |_| |                          " NEON_CYAN "|\n");
    printf("|" NEON_GREEN "                       |_| \\_\\_|    \\____|                          " NEON_CYAN "|\n");
    printf("|                                                                      |\n");
    printf("|" BRIGHT_YELLOW "                    [ NEURAL INTERFACE ACTIVATED ]                    " NEON_CYAN "|\n");
    printf("|" BRIGHT_RED "                      [ SYSTEM STATUS: ONLINE ]                       " NEON_CYAN "|\n");
    printf("+======================================================================+\n");
    printf(RESET);
}

void print_cyberpunk_border() {
    printf(NEON_CYAN "+======================================================================+\n" RESET);
}

void print_cyberpunk_border_end() {
    printf(NEON_CYAN "+======================================================================+\n" RESET);
}

void print_glitch_text(const char* text) {
    printf(NEON_RED);
    for (int i = 0; text[i] != '\0'; i++) {
        if (rand() % 10 == 0) {
            printf(BRIGHT_MAGENTA "%c" NEON_RED, text[i]);
        } else if (rand() % 15 == 0) {
            printf(BRIGHT_CYAN "%c" NEON_RED, text[i]);
        } else {
            printf("%c", text[i]);
        }
        fflush(stdout);
        sleep_ms(50); // 50ms delay
    }
    printf(RESET);
}

void print_neon_text(const char* text, const char* color) {
    printf("%s%s%s", color, text, RESET);
}

void print_loading_bar(int percentage) {
    printf(NEON_CYAN "[" RESET);
    int filled = percentage / 5;
    for (int i = 0; i < 20; i++) {
        if (i < filled) {
            printf(NEON_GREEN "#" RESET);
        } else {
            printf(DIM "." RESET);
        }
    }
    printf(NEON_CYAN "] %d%%" RESET, percentage);
}

void print_system_status() {
    printf(NEON_CYAN "║ " BRIGHT_GREEN "● NEURAL LINK" NEON_CYAN "    ║ " BRIGHT_GREEN "● MEMORY CORE" NEON_CYAN "     ║ " BRIGHT_GREEN "● DATA STREAM" NEON_CYAN "    ║\n" RESET);
    printf(NEON_CYAN "║ " BRIGHT_YELLOW "● COMBAT SYS" NEON_CYAN "     ║ " BRIGHT_YELLOW "● INVENTORY" NEON_CYAN "       ║ " BRIGHT_YELLOW "● SAVE MODULE" NEON_CYAN "    ║\n" RESET);
}

void print_data_stream() {
    printf(MATRIX_GREEN);
    const char* data[] = {"01001000", "11100101", "00110011", "10101010", "01010101"};
    for (int i = 0; i < 5; i++) {
        printf("%s ", data[rand() % 5]);
    }
    printf(RESET);
}

void print_cyberpunk_menu_header() {
    printf(NEON_CYAN "+======================================================================+\n");
    printf("|" NEON_MAGENTA "                        [ COMMAND INTERFACE ]                        " NEON_CYAN "|\n");
    printf("|                                                                      |\n");
    printf(RESET);
}

void print_cyberpunk_menu_footer() {
    printf(NEON_CYAN "|                                                                      |\n");
    printf("|" BRIGHT_YELLOW "                    [ AWAITING INPUT COMMAND ]                     " NEON_CYAN "|\n");
    printf("+======================================================================+\n");
    printf(RESET);
}

void print_matrix_effect() {
    printf(MATRIX_GREEN);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 70; j++) {
            if (rand() % 3 == 0) {
                printf("%c", '0' + (rand() % 2));
            } else {
                printf(" ");
            }
        }
        printf("\n");
        sleep_ms(100);
    }
    printf(RESET);
}
