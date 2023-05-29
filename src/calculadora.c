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
 ** \date 26/05/23
 ** \brief Implementacion del modulo calculadora
 **
 ** \addtogroup Calculadora Calculadora.c
 ** \brief Modulo para crear la calculadora, identificar operandos y operadores, almacenar operandos
 ** y llevar a cabo el calculo de la operacion
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

//! Puntero a estructura que almacena los datos de las operacionesa de la calculadora
typedef struct operacion_s * operacion_t;

//! Estructura que almacena la funcion, el operador y la operacion siguiente de una calculadora
struct operacion_s {
    char operador;                   //!< Caracter que contiene al operador
    funciont_t funcion;              //!< Funcion que realizara la operacion del operador
    operacion_t operacion_siguiente; //!< Puntero a estructura de la operacion subsiguiente
};

//! Estructura que almacena las operaciones de la calculadora
struct calculadora_s {
    operacion_t operaciones; //!< Puntero a la estructura de las operaciones de la calculadora
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

//! Funcion que devuelve un puntero a la estructura operacion y se encarga de verificiar si ya
//! existe el operador en la calculadora
static operacion_t BuscarOperador(calculadora_t calculadora, //!< Puntero a la calculadora
                           char operador /*!< Caracter que contiene al operador*/);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static operacion_t BuscarOperador(calculadora_t calculadora, char operador) {
    operacion_t operacion = NULL;
    for (operacion_t operacion_actual = calculadora->operaciones; operacion_actual != NULL;
         operacion_actual = operacion_actual->operacion_siguiente) {
        if (operacion_actual->operador == operador) {
            operacion = operacion_actual;
            break;
        }
    }
    return operacion;
}

/* === Public function implementation ========================================================== */

calculadora_t CrearCalculadora(void) {
    calculadora_t calculadora = malloc(sizeof(struct calculadora_s));
    if (calculadora) {
        // limpia y libera todas las estructuras(no hay operaciones definidas)
        memset(calculadora, 0, sizeof(struct calculadora_s));
    }
    return calculadora;
}

bool AgregarOperacion(calculadora_t calculadora, char operador, funciont_t funcion) {
    operacion_t operacion = NULL;
    operacion = malloc(sizeof(struct operacion_s));
    if (operacion && !BuscarOperador(calculadora, operador)) {
        operacion->operador = operador;
        operacion->funcion = funcion;
        operacion->operacion_siguiente = calculadora->operaciones;
        calculadora->operaciones = operacion;
    }
    return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena) {
    int resultado = 0, a, b;
    char operador;
    for (int index = 0; index < strlen(cadena); index++) {
        if (cadena[index] < '0') {
            a = atoi(cadena);
            b = atoi(cadena + index + 1);
            operador = cadena[index];
        }
    }
    operacion_t operacion = BuscarOperador(calculadora, operador);
    if (operacion) {
        resultado = operacion->funcion(a, b);
    }
    return resultado;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
