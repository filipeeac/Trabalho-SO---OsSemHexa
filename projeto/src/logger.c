#include <stdio.h>

#define FILEOUTPUT "/tmp/logs.log"

static int _isOpen = 0;
static FILE* _f;
static int _terminal_bool = 0;

int logger_init(){
    _f = fopen(FILEOUTPUT, "a+");
    if (!_f) {
        fprintf(stderr, "Falha na inicialização do logger...\n");
        return 1;
    }
    _isOpen = 1;
    return 0;
}

int logger_close(){
    if(_isOpen != 1) return 1;
    int rc = fclose(_f);
    if(rc != 0) fprintf(stderr, "Erro em fechar arquivo de log com erro: %d", rc);
    _isOpen = 0;
    return rc;
}

void logger_flush(){
    fflush(_f);
    if(_terminal_bool) fflush(stdout);
}

void set_terminal(const int terminal){
    if(terminal == 1 || terminal == 0) _terminal_bool = terminal;
}

void logger_putc(const char c){
    if(_isOpen != 1) return;
    putc(c, _f);
    if(_terminal_bool){
        putc(c, stdout);
    }
}
