# Damas Turcas - Proyecto en C++

## Tabla de Contenidos
- [Descripción](#descripción)
- [Características](#características)
- [Reglas del Juego](#reglas-del-juego)
- [Compilación y Ejecución](#compilación-y-ejecución)
- [Estructura del Código](#estructura-del-código)
- [Autores](#autores)

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

## Compilación y Ejecución
```bash
# Compilar
g++ main.cpp fichas.cpp tablero.cpp -o damas_turcas

# Ejecutar
./damas_turcas
