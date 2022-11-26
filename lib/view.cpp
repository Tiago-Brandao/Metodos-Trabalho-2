#include "../include/view.h"

void View::paintColumn(int columnIndex, int redOrGreen, int numLin) {
  if (redOrGreen == 1) {
    for (int i = 1; i <= (numLin+2); i++ ) {
      this->table_of_results[i][columnIndex].format().font_color(Color::red);
    }
  }else {
    for (int i = 1; i <= (numLin+2); i++ ) {
      this->table_of_results[i][columnIndex].format().font_color(Color::green);
    }
  }
};


void View::print_input_matrice(double **matrice, int numberLinesAndColumns) {
  string row = " ";
  for (int i = 0; i < numberLinesAndColumns; i++) {
    for (int j = 0; j < numberLinesAndColumns; j++) {
      row += "    " + to_string(matrice[i][j]);
    };
    this->table_of_input.add_row({row});
    row = " ";
  }

  this->table_of_input.format()
  .corner("|")
  .hide_border_bottom()
  .hide_border_top()
  .padding_top(1)
  .padding_bottom(1)
  .padding_left(1.2)
  .padding_right(1.2);

  cout << this->table_of_input << endl;
};




void View::printResultsOfMethods(double *LDPresolution, double *LUresolution, int numberOfX){
  bool willTheRocketFallbyLDP = false;
  bool willTheRocketFallbyLU = false;
  table_of_results.add_row({" ", "Resultados dos métodos", " "});
  table_of_results.add_row({"  ", "Método LDP", "Método LU"});


table_of_results.format()
    .width(25)
    .font_align(FontAlign::center)
    .font_color(Color::white)
    .padding_bottom(1)
    .padding_top(1)
    .corner(" ")
    .border_top("_")
    .border_right(" ")
    .border_bottom(" ")
    .border_left(" ");

  for (int i = 0; i < numberOfX; i++) {
    if( LDPresolution[i] > 2.0 ){
      willTheRocketFallbyLDP = true;
    }

    if( LUresolution[i] > 2.0 ){
      willTheRocketFallbyLU = true;
    }

    string Xi = 'X' + to_string(i);
    table_of_results.add_row({Xi, to_string(LDPresolution[i]),to_string(LUresolution[i])});
  };

  if (willTheRocketFallbyLDP && willTheRocketFallbyLU) {
    table_of_results.add_row({"Resultado:", "cai", "cai"});
    paintColumn(1, 1, numberOfX);
    paintColumn(2, 1, numberOfX);

  }else if (willTheRocketFallbyLDP && !willTheRocketFallbyLU) {
    table_of_results.add_row({"Resultado:", "cai", "não cai"});
    paintColumn(1, 1, numberOfX);
    paintColumn(2, 2, numberOfX);

  }else if (!willTheRocketFallbyLDP && willTheRocketFallbyLU) {
    table_of_results.add_row({"Resultado:", "não cai", "cai"});
    paintColumn(1, 2, numberOfX);
    paintColumn(2, 1, numberOfX);

  } else {
    table_of_results.add_row({"Resultado:", "não cai", "não cai"});
    paintColumn(1, 2, numberOfX);
    paintColumn(2, 2, numberOfX);

  }

  table_of_results[0].format()
    .padding_top(1)
    .padding_bottom(1)
    .font_align(FontAlign::center)
    .font_background_color(Color::yellow);

  table_of_results[0][2].format().font_align(FontAlign::left);
  table_of_results[0][1].format().font_align(FontAlign::right);
  table_of_results[0][1].format().hide_border();
  table_of_results[0][2].format().hide_border();
  table_of_results[0][0].format().hide_border_bottom();
  table_of_results[0][0].format().hide_border_top();
  table_of_results[0][0].format().hide_border_right();
  table_of_results[0][0].format().border_left("  ");

  cout << table_of_results << endl;
};

void View::menu() {
  LDP ldp;
  LU lu;
  char resposta = ' ';
  bool continar = true;
  double* vetor;
  int tamanhoMatriz;
  char pivotar;
  double** matriz;
  double* respostaLU;


  this->print_message("BEM VINDO AO SISTEMA DE RESOLUÇÃO");

  cout << "VAMOS COMEÇAR OS CÁLCULOS....\n";

  while (continar) {
    cout << "Digite o tamanho da matriz: ";
    cin >> tamanhoMatriz;

    if (tamanhoMatriz <= 0 ) {
      cout << "Entrada inválida.\n";
      continue;
    }

    cout << "Deseja usar pivotação parcial para resolver? (S/N): ";
    cin >> pivotar;

    if (tolower(pivotar) != 's' && tolower(pivotar) != 'n') {
      cout << "Entrada inválida.\n";
      continue;
    }

    if (pivotar == 'N') pivotar = 0;

    /* Pedindo a entrada da matriz */

    matriz = inicializarMatriz(tamanhoMatriz);

    for (int i = 0; i < tamanhoMatriz; i++){
      for (int j = 0; j < tamanhoMatriz; j++){
        printf("Digite o valor na posição [%d][%d] da matriz: ", i, j);
        cin >> matriz[i][j];
      }
    }




    vetor = (double*) malloc(sizeof(double) * tamanhoMatriz);

    for (int i = 0; i < tamanhoMatriz; i++){
      printf("Digite o valor [%d] do vetor: ", i);
      cin >> vetor[i];
    }


    /* pedindo para o usuário checar se a matriz e o vetor estão como ele deseja */
    this->print_input_matrice(matriz, tamanhoMatriz);
    cout << "CONFIRA A SUA MATRIZ: \n";
    cout << "==========================\n";
    this->print_input_vector(vetor, tamanhoMatriz);
    cout << "CONFIRA O VETOR TAMBÉM: \n";
    cout << "==========================\n";
    cout << "PARA CONTINUAR DIGITE 'X', PARA REPETIR O PROCESSO DIGITE QUALUQUER OUTRA COISA: ";
    cin >> resposta;

    if ( tolower(resposta) != 'x' ) {
      return;
    }

    ldp = LDP(matriz, tamanhoMatriz, pivotar);
    lu = LU(matriz, tamanhoMatriz, pivotar);
    ldp.calcularLDP();
    ldp.substituicao(vetor);
    lu.calcLU();
    respostaLU = lu.calcularMetodo(vetor);

    if ( !(lu.valido) ) {
      this->print_message("NÃO É POSSÍVEL RESOLVER O SISTEMA");
    }else {
      this->printResultsOfMethods(ldp.vetorResolucao, respostaLU,  tamanhoMatriz);
    }

    cout << "PARA ENCERRAR O PROGAMA DIGITE 'X'.\n";
    cout << "PARA EXECUTAR NOVAMENTE DIGITE QUALQUER OUTRA COISA.\n";
    cin >> resposta;

    if (tolower(resposta) == 'x') {
      continar = false;
    }
  }
}


void View::print_input_vector(double *vector, int numberLinesAndColumns) {
  for (int i = 0; i < numberLinesAndColumns; i++) {
    this->vector_b.add_row({to_string(vector[i])});
  }
  this->vector_b.format()
  .corner("|")
  .hide_border_bottom()
  .hide_border_top()
  .padding_top(1)
  .padding_bottom(1)
  .padding_left(1.2)
  .padding_right(1.2);

  cout << this->vector_b << endl;
};


void View::print_message(string messageToPrint) {
  this->table_of_menu.add_row({messageToPrint});

  this->table_of_menu.format()
  .font_color(Color::white)
  .font_background_color(Color::red)
  .font_align(FontAlign::center)
  .padding(1)
  .hide_border()
  .corner(" ");

  cout << this->table_of_menu << endl;
};
