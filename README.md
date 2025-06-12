# Damas Turcas - Proyecto en C++

## Tabla de Contenidos
- [Descripción](#descripción)
- [Características](#características)
- [Reglas del Juego](#reglas-del-juego)
- [Estructura del Código](#estructura-del-código)
- [Autores](#autores)
- [Compilación y Ejecución](#compilación-y-ejecución)

---

## Descripción
Implementación del juego de Damas Turcas en C++ para terminal. El juego sigue las reglas tradicionales con un tablero de 8x8, donde dos jugadores compiten para capturar las fichas del oponente.

## Características
Tablero 8x8 visualizado en terminal  
Sistema de turnos para 2 jugadores  
Coronación de fichas (Damas)  
Capturas obligatorias y múltiples  
Detección automática de fin del juego  

## Reglas del Juego
### Movimiento básico
- Fichas normales: 
  - `X` (Jugador 1) mueve hacia arriba
  - `O` (Jugador 2) mueve hacia abajo
  - 1 casilla en vertical/horizontal (no diagonal)

### Coronación
- Al llegar al extremo opuesto:
  - `X` → `+` (Dama)
  - `O` → `Q` (Dama)
- Damas pueden moverse cualquier distancia en línea recta

### Capturas
- Salto sobre ficha enemiga a casilla vacía
- Capturas múltiples son obligatorias
- Damas pueden capturar a distancia

### Fin del juego
- Cuando un jugador pierde todas sus fichas
- Empate si:
  - Ambos tienen 1 ficha
  - 16 movimientos sin capturas


## Estructura del Código

El proyecto está organizado en los siguientes archivos clave:

### Archivos Principales

| Archivo       | Descripción                                                                 |
|---------------|-----------------------------------------------------------------------------|
| `main.cpp`    | Punto de entrada principal, inicia el juego llamando a `Jugando()`          |
| `fichas.h`    | Cabecera con declaraciones de funciones y estructuras para la lógica del juego |
| `fichas.cpp`  | Implementación completa de las reglas y mecánicas del juego                  |
| `tablero.h`   | Definiciones para la manipulación del tablero                                |
| `tablero.cpp` | Funciones para inicializar y mostrar el tablero gráficamente                 |

### Componentes Clave

1. **Gestión del Tablero**:
   - `llenaTablero()`: Inicializa el estado inicial del juego
   - `ImprimeTablero()`: Muestra el tablero en consola

2. **Lógica del Juego**:
   - `Jugando()`: Control principal del flujo del juego
   - `realizaJ1()`/`realizaJ2()`: Manejan los turnos de cada jugador
   - `intercambio()`: Gestiona el movimiento de fichas

3. **Validaciones**:
   - `cumpleTodo()`: Verifica movimientos válidos
   - `RevisaEnCruz()`: Detecta posibles capturas

4. **Reglas Especiales**:
   - `coronacion()`: Maneja la conversión a damas
   - `MovRealeza()`: Controla movimientos de fichas coronadas

## Autores

Este proyecto fue desarrollado por:

- **Tomas Silva**  
- **Alexander Aponte**  

## Compilación y Ejecución
```bash
# Compilar
g++ main.cpp fichas.cpp tablero.cpp -o damas_turcas

# Ejecutar
./damas_turcas
