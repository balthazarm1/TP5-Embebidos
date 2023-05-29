/************************************************************************************************
Copyright (c) 2023, Balthazar Martin <balthazarm8@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 ** \author Balthazar Martin
 ** \date 27/05/23
 ** \brief Implementacion publica para crear una calculadora
 **
 ** \addtogroup tp5 TP5-main.c
 ** \brief Quinto Trabajo Practico
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "calculadora.h"
#include <stdio.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int producto(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    return a / b;
}

//! Funcion Principal que crea la calculadora y realiza las operaciones
int main(void) {
    int resultado;

    calculadora_t calculadora = CrearCalculadora();

    resultado = Calcular(calculadora, "10+5");
    printf("El resultado de una suma sin agregar el operador es %i\n", resultado);

    AgregarOperacion(calculadora, '+', suma);
    resultado = Calcular(calculadora, "10+5");
    printf("El resultado de la suma agregando el operador es %i\n", resultado);

    AgregarOperacion(calculadora, '-', resta);
    resultado = Calcular(calculadora, "10-5");
    printf("El resultado de la resta es %i\n", resultado);

    AgregarOperacion(calculadora, '*', producto);
    resultado = Calcular(calculadora, "10*5");
    printf("El resultado del producto es %i\n", resultado);

    AgregarOperacion(calculadora, '/', division);
    resultado = Calcular(calculadora, "10/5");
    printf("El resultado del cociente es %i\n", resultado);

    return 0;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
