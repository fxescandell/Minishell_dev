En la **Fase 2: Lectura y UI**, convertiremos tu ejecutable estático en un programa interactivo real. Hasta ahora, `minishell` arranca y se apaga. El objetivo de esta fase es implementar el ciclo vital de cualquier intérprete de comandos, conocido como **REPL** (Read-Eval-Print Loop): Leer, Evaluar, Imprimir y Repetir.

Aquí tienes el mapa de lo que vamos a construir:

### 🗺️ Mapa de la Fase 2

**2.1. Interfaz Gráfica de Texto (`src/msx_ui.c`)** 📺
Aquí definiremos la personalidad de tu shell. En tu código, has optado por un estilo retro "MSX BASIC". [cite_start]Implementaremos la bienvenida y la función que muestra el prompt (`MSX> `) esperando órdenes[cite: 30, 31].

**2.2. Lectura de Líneas (`src/loop_io.c`)** ⌨️
El shell necesita "escuchar". Usaremos la poderosa librería `readline` para capturar lo que el usuario escribe. [cite_start]También aprenderemos a limpiar esa entrada (quitar espacios sobrantes) y a guardarla en el historial para que funcionen las flechas de dirección[cite: 70, 72].

**2.3. Segmentación Lógica (`src/loop_io_split.c`)** ✂️
A veces, el usuario quiere ejecutar varios comandos en una sola línea, separados por punto y coma (ej: `echo hola; ls`). [cite_start]Implementaremos una lógica inteligente que separe estos comandos sin romper cadenas que estén entre comillas[cite: 90].

**2.4. Bucles de Ejecución (`src/loop.c`, `src/loop_tty.c`)** 🔄
Finalmente, crearemos el bucle infinito (`while`) que mantiene el programa vivo. [cite_start]Diferenciaremos entre el modo **interactivo** (un humano escribiendo en el teclado) y el modo **no interactivo** (scripts o pipes), conectando todo esto con el `main` que creamos en la Fase 1[cite: 46, 54].

---

Al terminar esta fase, podrás ejecutar `./minishell`, ver tu prompt, escribir cosas, usar el historial y ver cómo el programa separa tus comandos, aunque todavía no sepa ejecutarlos.

¿Empezamos con el punto **2.1. Interfaz Gráfica de Texto** para darle cara a tu shell?