#include "../include/imc.h"

float calcular_imc(Aluno aluno) {
    float resultado = aluno.peso / pow((aluno.altura/100),2);
    return resultado;
}

void diagnostico_imc(float resultado)
{
    // https://abeso.org.br/obesidade-e-sindrome-metabolica/calculadora-imc/
    if(resultado <= 18.5)  printf("[DIAGNOSTICO] - Abaixo do normal\n\n");
    else if(resultado >18.5 && resultado <= 24.9)  printf("[DIAGNOSTICO] - Normal\n\n");
    else if(resultado >24.9 && resultado <= 29.9)  printf("[DIAGNOSTICO] - Sobrepeso\n\n");
    else if(resultado >29.9 && resultado <= 34.9)  printf("[DIAGNOSTICO] - Obesidade grau I\n\n");
    else if(resultado >34.9 && resultado <= 40)  printf("[DIAGNOSTICO] - Obesidade grau II\n\n");
    else printf("[DIAGNOSTICO] - Obesidade grau III\n\n");
}
FILE *abrirArquivo(char *nomeArquivo) { 
    //obs: pra funcionar a função tem q ser um ponteiro
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
        return NULL;
    }
    if (fgetc(arquivo) == EOF) {
        printf("O arquivo está vazio.\n");
        fclose(arquivo);
        return NULL;
    }
    return arquivo;
}
ListaAluno *lerCSVParaLista(char *nomeArquivo) {
  FILE *arquivo;
  char linha[100];
  ListaAluno *inicioLista = NULL;
  ListaAluno *listaAtual = NULL;

  arquivo = abrirArquivo(nomeArquivo);

  // Ignora a primeira linha (cabeçalho)
  fgets(linha, sizeof(linha), arquivo);

  while (fgets(linha, sizeof(linha), arquivo)) {
    char *nome, *pesoStr, *alturaStr;
    ListaAluno *novoAluno;

    // Extrai os dados da linha
    nome = strtok(linha, DELIMITADOR);
    //depois da primeira coluna, NULL faz o ponteiro passar pro próximo
    pesoStr = strtok(NULL, DELIMITADOR);
    alturaStr = strtok(NULL, "\n");

    if (nome == NULL || pesoStr == NULL || alturaStr == NULL) {
      printf("Erro na linha do arquivo: %s\n", linha);
      continue;
    }

    novoAluno = malloc(sizeof(ListaAluno));
    if (novoAluno == NULL) {
      printf("Erro de alocação de memória\n");
      return NULL;
    }

    // Preenche os dados do aluno
    strcpy(novoAluno->aluno.nome, nome); // pra atribuir uma string noutra so com o strcpy
    novoAluno->aluno.peso = atof(pesoStr);
    novoAluno->aluno.altura = atof(alturaStr);
    novoAluno->aluno.imc = calcular_imc(novoAluno->aluno);

    // Insere o novo aluno no início da lista
    novoAluno->proximo = inicioLista;
    inicioLista = novoAluno;

    // Atualiza o ponteiro para o último elemento da lista
    if (listaAtual == NULL) {
      listaAtual = novoAluno;
    }
  }
  
  fclose(arquivo);
  return inicioLista;
}


void imprimirLista(ListaAluno *lista) {
  while (lista != NULL) {
    printf("Nome: %s\n", lista->aluno.nome);
    printf("Peso: %.2f kg\n", lista->aluno.peso);
    printf("Altura: %.2f cm\n", lista->aluno.altura);
    printf("Seu IMC é: %.2f\n", lista->aluno.imc);
    diagnostico_imc(lista->aluno.imc);
    lista = lista->proximo;
  }
}