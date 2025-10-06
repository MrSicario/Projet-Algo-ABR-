CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = abr_avance
OBJ = abr_base.o abr_operations.o abr_avance.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

abr_base.o: abr_base.c abr_base.h
	$(CC) $(CFLAGS) -c abr_base.c

abr_operations.o: abr_operations.c abr_operations.h abr_base.h
	$(CC) $(CFLAGS) -c abr_operations.c

abr_avance.o: abr_avance.c abr_avance.h abr_operations.h abr_base.h
	$(CC) $(CFLAGS) -c abr_avance.c

clean:
	rm -f $(TARGET) $(OBJ) arbre_sauvegarde.txt

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	valgrind ./$(TARGET)
