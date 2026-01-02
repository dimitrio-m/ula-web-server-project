# 🚀 ULA High-Performance Web Server (C-Project)

> **Materia:** Sistemas Operativos (ISPSOP) - Universidad de los Andes
> **Profesor:** Dimitrio Mandamadiotis

---

## 📖 Descripción del Escenario

**El problema:** El servidor de e-commerce de "ULA Store" ha colapsado debido al alto tráfico del Black Friday. Las soluciones tradicionales (Node.js, Apache) consumen demasiada memoria y el hardware actual no lo soporta.

**Tu misión:** Como Ingeniero de Sistemas, debes construir un **Servidor Web HTTP 1.1** desde cero, utilizando **C puro** y llamadas al sistema (System Calls). El servidor debe ser capaz de manejar múltiples conexiones concurrentes sin bloquearse, sirviendo archivos estáticos (HTML, CSS, Imágenes) de manera eficiente.

---

## 🎯 Objetivos de Aprendizaje

Este proyecto es la culminación del semestre e integra los siguientes conocimientos:

1. **Sockets & Networking:** Entender cómo funcionan TCP/IP y el protocolo HTTP a bajo nivel (Unidades I y VI).
2. **Gestión de Procesos e Hilos:** Implementación de un *Thread Pool* para concurrencia real (Unidad II).
3. **Sincronización:** Uso de `Mutex` y `Variables de Condición` para proteger memoria compartida (Unidad III).
4. **Sistemas de Archivos:** Manipulación de descriptores de archivo y lectura eficiente de disco (Unidad VII).

---

## 🏗️ Arquitectura del Sistema

El servidor no debe crear un hilo por cada cliente (eso es ineficiente). Debes implementar el patrón **Producer-Consumer** con un **Thread Pool** (Grupo de Hilos).

1. **Hilo Main (Producer):**
* Escucha en el puerto `8080`.
* Acepta nuevas conexiones (`accept()`).
* Coloca el *File Descriptor* del cliente en una **Cola de Tareas**.


2. **Hilos Workers (Consumers):**
* Son un número fijo de hilos (ej. 4 u 8) creados al inicio.
* Duermen hasta que hay algo en la cola.
* Despiertan, toman un socket, procesan la petición HTTP y vuelven a dormir.


3. **Sincronización:**
* El acceso a la Cola de Tareas debe estar protegido por un `pthread_mutex_t`.



---

## 📅 Hitos del Proyecto (Roadmap)

El desarrollo es incremental. No intentes hacerlo todo a la vez.

### 🟢 Fase 1: El "Hola Mundo" (Semana 12)

* **Objetivo:** Levantar el socket y responder a una petición.
* **Requisitos:**
* El servidor compila y corre con `make run`.
* Al entrar a `localhost:8080` desde el navegador, el servidor responde texto plano (ej: "Hola Mundo").
* **Nota:** En esta fase el servidor es *iterativo* (atiende uno a uno) o se cierra tras la primera respuesta.



### 🟡 Fase 2: El Bibliotecario (Semana 13-14)

* **Objetivo:** Servir archivos reales (`index.html`, `style.css`, imágenes).
* **Requisitos:**
* Parsear el string del Request HTTP: `GET /zapato.jpg HTTP/1.1`.
* Abrir el archivo correspondiente en la carpeta `public/`.
* Construir los Headers correctos:
* `Content-Type` (detectar si es `.html`, `.css` o `.jpg`).
* `Content-Length` (tamaño del archivo).


* Manejar errores **404 Not Found** si el archivo no existe.



### 🔴 Fase 3: "Heavy Traffic" (Semana 15-16 - Entrega Final)

* **Objetivo:** Concurrencia y Estabilidad.
* **Requisitos:**
* Implementar el **Thread Pool** completo.
* Implementar un **Log de Visitas** (`access.log`) donde todos los hilos escriben.
* **Prueba de Fuego:** El servidor debe resistir un ataque de estrés con **Apache Bench (`ab`)** sin colgarse y sin corromper el log.



---

## 🛠️ Requisitos Técnicos

1. **Lenguaje:** C estricto (Estándar C11).
2. **Sistema Operativo:** Linux (Nativo o WSL2).
3. **Prohibido:**
* Usar librerías HTTP externas (como `libcurl` o `microhttpd`). Debes parsear el texto tú mismo.
* Usar `system()` para llamar a comandos externos.


4. **Permitido:**
* Cualquier librería estándar (`stdio.h`, `stdlib.h`, `string.h`, `pthread.h`, `sys/socket.h`, etc.).


5. **Compilación:**
* El código debe compilar sin errores ni warnings usando los flags del `Makefile` proporcionado (`-Wall -Wextra -fsanitize=address`).
* **Importante:** `AddressSanitizer` está activado. Si tu código tiene fugas de memoria, el programa abortará y te dirá dónde. ¡Arréglalo!



---

## 🚀 Instrucciones de Ejecución

Este repositorio contiene un "esqueleto" funcional.

1. **Clonar el repositorio:**
```bash
git clone <URL_DEL_REPO>
cd ula-server-project

```


2. **Compilar y Ejecutar:**
Usamos `make` para automatizar todo.
```bash
make run

```


Verás: `🚀 Servidor iniciado en http://localhost:8080`
3. **Limpiar binarios (si algo falla):**
```bash
make clean

```



---

## 🤖 Política de Uso de IA

Se permite el uso de ChatGPT/Claude/Gemini/etc como **asistentes**, bajo las siguientes reglas:

1. **No Copy-Paste ciego:** Si el código tiene una función que no puedes explicar en la defensa oral, se asume plagio.
2. **Prompt Engineering:** En tu entrega (Pull Request), debes incluir los prompts que usaste para resolver los problemas más difíciles (ej. *"¿Cómo parsear un string HTTP en C sin usar strtok?"*).

---

## 📊 Evaluación

| Criterio | Peso | Descripción |
| --- | --- | --- |
| **Funcionalidad HTTP** | 30% | Sirve HTML, CSS e Imágenes correctamente. Maneja 404. |
| **Concurrencia** | 30% | Thread Pool funcional. Soporta múltiples clientes simultáneos. |
| **Calidad de Código** | 20% | Código modular, uso de structs, sin fugas de memoria (Valgrind/ASan clean). |
| **Defensa Oral** | 20% | Capacidad de explicar la arquitectura y responder preguntas sobre el código. |

---

> *"Talk is cheap. Show me the code."* - Linus Torvalds
