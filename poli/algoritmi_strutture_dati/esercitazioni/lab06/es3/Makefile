all: run

# Nome dell'eseguibile finale
TARGET = client.out

# File sorgenti e oggetto
SRC = client.c character.c inventory.c
OBJ = $(SRC:.c=.o)

# Compilatore e flag
CC = gcc
CFLAGS = -Wall -g

# Regola principale
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Regola generica per compilare i .c in .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

# Pulizia dei file temporanei
clean:
	rm -f $(OBJ) $(TARGET)
