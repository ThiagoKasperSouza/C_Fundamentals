/* Copyright 2024 Thiago Kasper de Souza.  All rights reserved.
* Use of this source code is governed by a MIT style
* license that can be found in the LICENSE file.
* Created by Thiago Kasper de Souza on 25/04/24.
*/


#ifndef IMC_H
#define IMC_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Para usar o tipo bool
#include <math.h>

char DELIMITADOR[2] = ",";

typedef struct Aluno {
  char nome[50];
  float peso;
  float altura;
  float imc;
} Aluno;

typedef struct ListaAluno {
  Aluno aluno;
  struct ListaAluno *proximo;
} ListaAluno;

float calcular_imc(Aluno aluno);
void diagnostico_imc(float resultado);
FILE *abrirArquivo(char *nomeArquivo);
ListaAluno *lerCSVParaLista(char *nomeArquivo);
void imprimirLista(ListaAluno *lista);

#endif //IMC_H