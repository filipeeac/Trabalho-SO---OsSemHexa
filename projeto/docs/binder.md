# Binder

Esse arquivo descreve o funcionamento do arquivo de aglutinação.

### Introdução 

A ideia é fazer um arquivo que vai unir um arquivo de bait (isca), com o objetivo de enganar o alvo, e o nosso vírus - [keylogger](keylogger.md).

### Funcionamento

De início, devemos selecionar algum arquivo para ser a distração, no nosso caso, escolhemos um PDF - [gato.pdf](../dist/gato.pdf). Além disso, devemos escolher o tipo de vírus e desenvolver o seu arquivo - [keylogger](keylogger.md).

Sobre o binder, desenvolvemos um script `.sh` para aglutinar e executar os arquivos, permitindo que possamos esconder o programa principal.

Por fim, para a execução correta, é preciso que o [keylogger](keylogger.md) esteja compilado e linkado no [script.sh](../dist/script.sh). Para uma explicação mais clara dos comandos, acesse: [script.sh](../dist/script.sh).