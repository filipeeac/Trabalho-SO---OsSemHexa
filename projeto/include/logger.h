#ifndef LOGGER_H
#define LOGGER_H

int logger_init();
int logger_close();
void logger_flush();

void set_terminal(const int terminal);

void logger_putc(const char c);


#endif
