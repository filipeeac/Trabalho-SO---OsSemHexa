#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "findKeyboard.h"

char* findKeyboard() {
    static char path[256];

    FILE *proc = fopen("/proc/bus/input/devices", "r");
    if (proc == NULL) {
        return NULL;
    }

    char linha[512];
    char nome[256] = "";
    bool achou_teclado = false;

    while (fgets(linha, sizeof(linha), proc)) {
        // Verifica o Nome do dispositivo
        if (strncmp(linha, "N: Name=", 8) == 0) {
            // Copia o nome do dispositivo
            strcpy(nome, linha + 8);
            nome[strcspn(nome, "\n")] = 0;

            // Verifica se é um Teclado
            if (strstr(nome, "keyboard") || strstr(nome, "Keyboard") ||
                strstr(nome, "kbd") || strstr(nome, "KBD") ||
                strstr(nome, "AT Translated")) {
                achou_teclado = true;
            } else {
                achou_teclado = false;
            }
        }

        // Verifica o Handlers para obter o event
        if (achou_teclado && strncmp(linha, "H: Handlers=", 12) == 0) {
            // Procura por "event" na linha
            char *pos_event = strstr(linha, "event");

            // Obtem o numero do evento
            if (pos_event) {
                char numero[16];
                int i = 0;

                pos_event += 5;

                while (pos_event[i] >= '0' && pos_event[i] <= '9') {
                    numero[i] = pos_event[i];
                    i++;
                }
                numero[i] = '\0';

                // Monta o path completo
                snprintf(path, sizeof(path), "/dev/input/event%s", numero);

                fclose(proc);
                return path;
            }
        }
    }

    fclose(proc);
    return NULL;
}