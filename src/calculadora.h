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

#ifndef CALCULADORA_H
#define CALCULADORA_H

/**
 ** \author Balthazar Martin
 ** \date 26/05/23
 ** \brief Declaraciones publicas del modulo calculadora
 **
 ** \addtogroup calculadora Calculadora.h
 ** \brief Modulo para gestion de los operandos y operadores de la calculadora.
 ** @{ */

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

#include <stdint.h>
#include <stdbool.h>

/* === Public data type declarations =========================================================== */

//! Puntero a estructura que almacena las operaciones de la calculadora
typedef struct calculadora_s * calculadora_t;

//! Funcion de CallBack de la calculadora que recibe los operandos enteros y realiza la operacion
//! devolviendo un entero
typedef int (*funciont_t)(int, int);

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

//! Funcion que devuelve un puntero a la struct de calculadora y se encarga de crear una calculadora
//! vacia
calculadora_t CrearCalculadora(void);

//! Funcion que se encarga de verificar si ya existe la operacion en la calculadora y sino la agrega
//! @return true La operacion fue agregada a la calculadora
//! @return false La operacion no fue agregada a la calculadora
bool AgregarOperacion(calculadora_t calculadora, //!< Puntero a la calculadora
                      char operador,             //!< Caracter que contiene al operador
                      funciont_t funcion /*!< Funcion que realizara la operacion del operador*/);

//! Funcion que lleva a cabo la realizacion de la operacion con la calculadora que fue creada
int Calcular(calculadora_t calculadora, //!< Puntero a la calculadora
             char * cadena /*!< Puntero a la cadena que contiene a la operacion */);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* CALCULADORA_H */
