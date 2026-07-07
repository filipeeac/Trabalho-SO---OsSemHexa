# MAWARE DIDÁTICO e sistema de arquivos XFS

## Sistema de arquivos
Para separarmos os tópicos da apresentação, decidimos explicar sobre o sistema de arquivos xfs em outro documento, acesse:

* [XFS](SA\docs\README.md)
  
---

## Índice

* [Capa](#-maware-didático)

--- 

## Descrição do projeto

Projeto desenvolvido para a diciplina de Sistemas Operacionais. O projeto visa a construção de um maware didático que irá ser instaldo atravez de um arquivo executavel na maquina do hospedeiro e ficará em segundo plano lendo o teclado de salvando em um arquivo.

---

## EQUIPE: OS-- Sem hexa

integrantes:

* SAVLIO CARVALHO PONTES - 567715
* FILIPE ALCÂNTARA DA COSTA - 568346
* GUSTAVO OLIVEIRA SEABRA - 567464

---

## Objetivos

Nosso objetivo com esse projeto é criar um entendimento sobre estruturas a baixo nivel do computador. Queremos entender como ocorre a comunicação de disposivos com o Sistema operacional. Além de entender o funcionamento de chamadas de sistema, eventos, processos em segundo plano, entre outros.

Para tanto, nossa ideia foi criar um arquivo executavel, que irá usar essas chamadas de sistema para criar um processo em segundo plano, o qual será o nosso virus. Esse por sua vez ficará lendo eventos do computador, usando syscalls para salvar em um arquivo secundário.

---

## Diagrama de blocos

![Texto descritivo da imagem](projeto/docs/diagrama_blocos.png)

---

## Explicações do código

Para melhor visibilidade, as documentações que explicam sobre os códigos especificos de cada arquivo estarão listadas a seguir:

* Arquivo responsável por ser executado pelo usuario e inicializar o arquivo bait e o keylogger: [executavel](projeto/docs/keylogger.md)

---

## como utilizar o projeto

## Testes

## Uso de IA
