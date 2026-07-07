## Keylogger

Esse arquivo descreve o funcionamento do módulo principal do projeto, o keylogger.

### Introdução e inspiração

A ideia do keylogger veio do seguinte vídeo da plataforma Youtube: [Coding a Keylogger in raw C](https://youtu.be/sw26Ptkdhuc).
Para este projeto, utilizaremos o SO Linux com uma distribuição Debian (como Ubuntu).
O objetivo do keylogger é receber entradas do teclado através de chamada de sistema e salvar automaticamente os caracteres decodificados em um arquivo persistente.

### Funcionamento

O keylogger segue os seguintes passos para cumprir o seu objetivo:
Teclado --> /dev/input/eventX --> read() --> input_event --> Decodificação --> Logger --> Arquivo

O acesso dos eventos do teclado são, normalmente, restritos pelo Sistema Operacional, para fins de segurança.
A chamada de sistema que utilizamos para captar esses dados é a chamada `read()`.

Após isso, temos que filtrar os dados e decodificar para obtermos os caracteres a partir desses dados. No linux, os eventos de entrada de dispositivos seguem a seguinte estrutura, que foi implementada no nosso código:
``` C
struct input_event{
  struct timeval time;
  __u16 type;
  __u16 code;
  __s32 value;
};
```

Em que os tipos `__u16` e `__s32` são equivalentes a um inteiro sem sinal de 16 bits e a um inteiro com sinal de 32 bits, respectivamente.

Logo, para dada uma variável `ie` dessa struct, nosso código faz
``` C
read(arquivo, &ie, sizeof(ie))
```

Para prosseguirmos, temos que dissertar brevemente sobre como os eventos do teclado são gerados e tratados, em geral. Por sorte, o próprio linux nos ajuda com isso.
No linux, existe um arquivo localizado em **/usr/include/linux/input-event-codes.h** que faz a definição de todas as macros usadas pelo sistema para o mapeamento das teclas do teclado.
Em especial, temos o valor `EV_KEY` do campo `type`. Esse será o nosso evento de interesse pois ele nos dará o código da tecla sendo pressionada no momento.
Outros eventos são acionados ao teclar uma tecla mas a `EV_KEY` é a de nosso maior interesse.

A partir do campo `code` do evento `EV_KEY`, podemos fazer o mapeamento das teclas do teclado para algum layout em específico, ao fazer manualmente (o caso desse projeto) ou usar uma biblioteca como `libxkbcommon` para mapeamento robusto para diversos layouts. Por fim, o valor do campo `value` nos informará se a tecla foi pressionada, se foi liberada ou se está sendo segurada.
Ao fazer o mapeamento do caractere, o resto do trabalho fica com o logger - módulo responsável de salvar os dados em outro arquivo e/ou apresentar no terminal após receber o caractere do keylogger.
