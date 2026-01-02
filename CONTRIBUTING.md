# 👷 Guía de Contribución (Workflow de Ingeniería)

Bienvenido al equipo de desarrollo de **Sistemas Operativos**.

Este repositorio funciona bajo una metodología de **Open Source**. No vas a "enviar un correo con un zip"; vas a contribuir código mediante **Pull Requests**, tal como lo harías en una empresa de tecnología moderna o contribuyendo a proyectos como Linux, React o Kubernetes.

## 🔄 El Flujo de Trabajo (Git Flow)

Para entregar tus asignaciones, debes seguir estrictamente este ciclo. Cualquier entrega fuera de este flujo (correo, mensaje directo, etc.) será ignorada.

### Paso 1: Fork (Bifurcación)

No tienes permisos de escritura directa en este repositorio base.

1. Haz clic en el botón **Fork** (arriba a la derecha) en GitHub.
2. Esto creará una copia exacta del proyecto en **tu cuenta** (ej: `usuario/ula-web-server-project`).

### Paso 2: Clone (Clonado Local)

Descarga **tu fork** a tu máquina de desarrollo (Linux/WSL):

```bash
# OJO: Usa la URL de TU fork, no la del profesor
git clone https://github.com/TU_USUARIO/ula-web-server-project.git
cd ula-server-project

```

### Paso 3: Ramas (Branching)

**Nunca trabajes en la rama `main` directamente.**
Crea una rama específica para cada fase del proyecto usando la convención: `feat/faseX-nombre-apellido`.

```bash
# Ejemplo para la Fase 1
git checkout -b feat/fase1-pedro-perez

```

### Paso 4: Desarrollo y Commits

Escribe tu código en C. Haz commits pequeños y descriptivos ("Atomic Commits").

* ❌ **Mal commit:** "Arreglando cosas final final v2"
* ✅ **Buen commit:** "feat: implementar socket listener y bind en puerto 8080"
* ✅ **Buen commit:** "fix: corregir fuga de memoria en el parseo HTTP"

```bash
git add .
git commit -m "feat: descripción de lo que hiciste"
git push origin feat/fase1-pedro-perez

```

### Paso 5: Pull Request (La Entrega)

Cuando termines la fase y tu código pase los tests locales:

1. Ve a tu repositorio en GitHub.
2. Verás un botón amarillo/verde **"Compare & Pull Request"**.
3. Haz clic y llena la **Plantilla de Descripción** (ver abajo).
4. Envía el PR.

---

## 📝 Plantilla del Pull Request

Cuando abras el PR, debes copiar y llenar este formato en la descripción. **PRs vacíos no serán revisados.**

```markdown
## 📋 Resumen
Breve descripción de qué hace este código y qué fase estás entregando.

## 🛠️ Detalles Técnicos
- [ ] Implementé sockets TCP
- [ ] Implementé lectura de archivos
- [ ] Implementé Thread Pool (Solo Fase 3)
- [ ] Pasé el AddressSanitizer sin errores
- [ ] ...

## 🤖 Uso de IA (Política de Transparencia)
- **Herramienta usada:** (ChatGPT / Claude / Gemini)
- **Prompt:** "Explícame cómo funciona la función select() en C"
- **Cambios realizados:** La IA sugirió X, pero yo lo adapté a Y porque...

## 🛑 Dificultades
¿Qué fue lo más difícil? (ej. "Entender los punteros dobles", "Race conditions")

```

---

## 🤖 Política de IA: "Copilot, no Autopilot"

Se permite el uso de Asistentes de IA (ChatGPT, Gemini, Copilot), pero bajo estas reglas:

1. **Entendimiento Total:** Si usas código generado por IA, **debes ser capaz de explicar cada línea** durante la defensa oral. "Es que la IA lo puso así" es causal de reprobación inmediata.
2. **Cita tus Fuentes:** Declara en el PR qué le preguntaste a la IA.
3. **Responsabilidad:** La IA alucina. Si el código de la IA usa una librería que no existe o tiene un fallo de seguridad, la culpa es 100% tuya.

---

## ⚖️ Código de Conducta y Plagio

Al ser un proyecto Open Source (repositorios públicos), todos pueden ver el código de todos.

* **Inspiración:** Está bien ver cómo otros resolvieron un problema arquitectónico.
* **Plagio:** Copiar y pegar el código de un compañero (o de internet) cambiando solo los nombres de variables es plagio.
* **El Filtro:** Tu nota depende en un 60% de tu código y un 40% de tu **Defensa Oral**. Si el código es perfecto pero tú dudas al explicarlo, se asume plagio.

---

## 🚫 Proceso de Cierre (Nota del Profesor)

Una vez entregues tu PR:

1. Recibirás comentarios de Code Review ("Cambia esto", "Mejora aquello").
2. Una vez aprobado, recibirás tu calificación en el comentario del PR.
3. El profesor **CERRARÁ (Close)** el PR sin fusionarlo (Merge).
* *Nota:* Esto es normal. No queremos mezclar el código de 30 estudiantes en el repo base. Tu entrega cuenta como válida aunque el PR aparezca como "Closed".



¡Manos a la obra y feliz codificación! 🚀
