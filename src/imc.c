/* Copyright 2024 Thiago Kasper de Souza.  All rights reserved.
* Use of this source code is governed by a MIT style
* license that can be found in the LICENSE file.
* Created by Thiago Kasper de Souza on 25/04/24.
*/

#include "./lib/imc.h"
#include <math.h>
#include <stdio.h>

void calcular_imc(float peso, float altura) {
    float resultado = peso / pow(altura,2);
    printf("Seu IMC é %.2f\n", resultado);
    diagnostico_imc(resultado);
}

void diagnostico_imc(float resultado)
{
    // https://abeso.org.br/obesidade-e-sindrome-metabolica/calculadora-imc/
    if(resultado <= 18.5)  printf("[DIAGNOSTICO] - Abaixo do normal\n");
    else if(resultado >18.5 && resultado <= 24.9)  printf("[DIAGNOSTICO] - Normal\n");
    else if(resultado >24.9 && resultado <= 29.9)  printf("[DIAGNOSTICO] - Sobrepeso\n");
    else if(resultado >29.9 && resultado <= 34.9)  printf("[DIAGNOSTICO] - Obesidade grau I\n");
    else if(resultado >34.9 && resultado <= 40)  printf("[DIAGNOSTICO] - Obesidade grau II\n");
    else printf("[DIAGNOSTICO] - Obesidade grau III\n");
}