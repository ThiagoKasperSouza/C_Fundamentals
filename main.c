
#include "src/imc.c"



int main() {
  ListaAluno *listaAlunos = lerCSVParaLista("./imc_data.csv");
  if (listaAlunos == NULL) {
    return 1;
  }

  imprimirLista(listaAlunos);
  clearHeap(listaAlunos);

  return 0;
}