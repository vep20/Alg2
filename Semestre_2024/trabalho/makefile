CC     = gcc
CFLAGS = -Wall -Wextra -g -std=c99
LIB    = funcoes
BIN    = trabalho

# Gera o arquivo executável
$(BIN): main.o $(LIB).o
	$(CC) $(CFLAGS) -o $(BIN) main.o $(LIB).o -lm

# Gera os arquivos-objeto
main.o: main.c funcoes.h
	$(CC) $(CFLAGS) -c main.c

$(LIB).o: funcoes.c funcoes.h
	$(CC) $(CFLAGS) -c funcoes.c 

# Verificação de memória
valgrind: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

# Limpeza
clean:
	rm -f *.o *~ $(BIN)