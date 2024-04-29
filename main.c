
#include "src/imc.c"


int main() {
  ListaAluno *listaAlunos = lerCSVParaLista("./imc_data.csv");
  if (listaAlunos == NULL) {
    return 1;
  }

  // Opcional: Imprima a lista
  imprimirLista(listaAlunos);

  // Utilize a listaAlunos para acessar os dados dos alunos

  // Libere a memória alocada
  ListaAluno *aux;
  while (listaAlunos != NULL) {
    aux = listaAlunos;
    listaAlunos = listaAlunos->proximo;
    free(aux);
  }

  return 0;
}