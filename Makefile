# Compilador y Flags
CC = gcc
# Flags Explicados:
# -Wall -Wextra: Muestra todos los warnings (disciplina).
# -pthread: Habilita la librería de hilos POSIX.
# -fsanitize=address: Detecta fugas de memoria y buffer overflows en vivo.
# -g: Añade símbolos de debug para usar con GDB/VSCode.
CFLAGS = -Wall -Wextra -std=c11 -pthread -fsanitize=address -Wunused-variable -Wunused-parameter -g

# Carpetas
SRC_DIR = src
BIN_DIR = bin
PUBLIC_DIR = public

# Nombre del ejecutable final
TARGET = $(BIN_DIR)/server

# Regla por defecto
all: clean build

# Crear carpeta bin y compilar
build:
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_DIR)/server.c -o $(TARGET)
	@echo "✅ Compilación exitosa. Ejecuta: ./$(TARGET)"

# Limpiar binarios antiguos
clean:
	rm -rf $(BIN_DIR)
	@echo "🧹 Limpieza completada."

# Regla para probar rapido
run: build
	./$(TARGET)
