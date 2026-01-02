/**
 * ULA-HighPerf-Server
 * Skeleton Code para la materia de Sistemas Operativos
 * * Este servidor debe ser capaz de:
 * 1. Escuchar conexiones entrantes (Sockets)
 * 2. Servir archivos estáticos (I/O)
 * 3. Manejar múltiples clientes a la vez (Hilos/Pool)
 * 4. Registrar tráfico en logs de forma segura (Sincronización)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>

// Configuración del Servidor
#define PORT 8080
#define BUFFER_SIZE 4096
#define THREAD_POOL_SIZE 4

// TODO: Definir estructura para la Cola de Tareas (Thread Pool)
// typedef struct { ... } TaskQueue;

// TODO: Definir Mutex y Variables de Condición Globales
// pthread_mutex_t lock = ...

/**
 * Función que ejecutarán los Hilos Trabajadores (Workers)
 * Debe sacar conexiones de la cola y procesarlas.
 */
void *thread_function(void *arg) {
    while (1) {
        // TODO: Bloquear mutex
        // TODO: Esperar a que haya trabajo (cond_wait)
        // TODO: Sacar un socket de la cola
        // TODO: Desbloquear mutex
        
        // TODO: Llamar a handle_client(socket)
    }
    return NULL;
}

/**
 * Función para manejar una conexión individual (Lectura/Escritura)
 */
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    
    // 1. Leer la petición del navegador
    // ssize_t bytes_read = read(client_socket, buffer, BUFFER_SIZE - 1);
    
    // 2. Parsear el archivo solicitado (ej: GET /index.html)
    // ... Lógica de strings aquí ...

    // 3. Abrir el archivo solicitado en 'public/'
    // ... open(), read() ...

    // 4. Enviar Header HTTP y Contenido
    // char *header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    // write(client_socket, header, strlen(header));
    // write(client_socket, file_content, file_size);

    // 5. Cerrar conexión
    close(client_socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // --- PASO 1: Crear el Socket (Dominio, Tipo, Protocolo) ---
    // AF_INET = IPv4, SOCK_STREAM = TCP
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("❌ Error al crear socket");
        exit(EXIT_FAILURE);
    }

    // Configurar opciones del socket (para reutilizar puerto rápido)
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("❌ Error en setsockopt");
        exit(EXIT_FAILURE);
    }

    // --- PASO 2: Bind (Enlazar puerto e IP) ---
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Escuchar en cualquier interfaz
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("❌ Error en bind (¿Puerto ocupado?)");
        exit(EXIT_FAILURE);
    }

    // --- PASO 3: Listen (Poner en modo escucha) ---
    if (listen(server_fd, 10) < 0) {
        perror("❌ Error en listen");
        exit(EXIT_FAILURE);
    }

    printf("🚀 Servidor iniciado en http://localhost:%d\n", PORT);
    printf("📂 Sirviendo archivos desde ./public\n");

    // TODO: Inicializar el Thread Pool aquí (crear hilos)

    // --- PASO 4: Main Loop (Aceptar conexiones) ---
    while (1) {
        printf("💤 Esperando conexión...\n");
        
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("❌ Error en accept");
            continue;
        }

        printf("✨ Nueva conexión recibida: Socket FD %d\n", new_socket);

        // MODO SIMPLE (BLOQUEANTE) - Solo para probar Fase 1
        // handle_client(new_socket);

        // TODO: En lugar de procesar aquí, agregar 'new_socket' a la Cola de Tareas
        // y avisar a los hilos (cond_signal).
    }

    return 0;
}
