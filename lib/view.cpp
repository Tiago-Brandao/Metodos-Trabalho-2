#include "../include/view.h"

void View::paintColumn(Table *table_of_results,int columnIndex, int redOrGreen, int numLin) {
  cout << "asda\n";
  if (redOrGreen == 1) {
    for (int i = 1; i <= (numLin+2); i++ ) {
      table_of_results[i][columnIndex].format().font_color(Color::red);
    }
  }else {
    for (int i = 1; i <= (numLin+2); i++ ) {
      table_of_results[i][columnIndex].format().font_color(Color::green);
    }
  }
};


void View::print_input_matrice(double **matrice, int numberLinesAndColumns) {
  Table table_of_input;
  string row = " ";
  for (int i = 0; i < numberLinesAndColumns; i++) {
    for (int j = 0; j < numberLinesAndColumns; j++) {
      row += "    " + to_string(matrice[i][j]);
    };
    table_of_input.add_row({row});
    row = " ";
  }

  table_of_input.format()
  .corner("|")
  .hide_border_bottom()
  .hide_border_top()
  .padding_top(1)
  .padding_bottom(1)
  .padding_left(1.2)
  .padding_right(1.2);

  cout << table_of_input << endl;
};




void View::printResultsOfMethods(double *LDPresolution, double *LUresolution, int numberOfX){
  Table table_of_results;
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
    for (int i = 1; i <= (numberOfX+2); i++ ) {
      table_of_results[i][1].format().font_color(Color::red);
    }
    for (int i = 1; i <= (numberOfX+2); i++ ) {
      table_of_results[i][2].format().font_color(Color::red);
    }
  }else if (willTheRocketFallbyLDP && !willTheRocketFallbyLU) {
    table_of_results.add_row({"Resultado:", "cai", "não cai"});
    for (int i = 1; i <= (numberOfX+2); i++ ) {
      table_of_results[i][1].format().font_color(Color::red);
    }
    for (int i = 1; i <= (numberOfX+2); i++ ) {
      table_of_results[i][2].format().font_color(Color::green);
    }

  }else if (!willTheRocketFallbyLDP && willTheRocketFallbyLU) {
    table_of_results.add_row({"Resultado:", "não cai", "cai"});
    for (int i = 1; i <= (numberOfX+2); i++ ) {
      table_of_results[i][1].format().font_color(Color::green);
    }
    for (int i = 1; i <= (numberOfX+2); i++ ) {
      table_of_results[i][2].format().font_color(Color::red);
    }
  } else {
    table_of_results.add_row({"Resultado:", "não cai", "não cai"});
    for (int i = 1; i <= (numberOfX+2); i++ ) {
      table_of_results[i][1].format().font_color(Color::green);
    }
    for (int i = 1; i <= (numberOfX+2); i++ ) {
      table_of_results[i][2].format().font_color(Color::green);
    }
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
  Table inputMatriz;
  char resposta = ' ';
  bool continar = true;
  double* vetor;
  double* vetorLDP;
  int tamanhoMatriz;
  char pivotar;
  double** matriz;
  double* respostaLU;
  double* respostaLDP;
  int entradaDeNumeros;
  bool pedirMatrizEvetorB = true;
  bool pedirApenasVetorB = false;
  int i = 0;
  int j = 0;


  this->print_message("BEM VINDO AO SISTEMA DE RESOLUÇÃO");

  cout << "VAMOS COMEÇAR OS CÁLCULOS....\n";

  while (continar) {

    if (pedirMatrizEvetorB) {
      cout << "Digite o tamanho da matriz: ";
      cin >> tamanhoMatriz;

      if ( tamanhoMatriz <= 0 ) {
        cout << "Entrada inválida.\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        continue;
      }

      cout << "Deseja usar pivotação parcial para resolver? (S/N): ";
      cin >> pivotar;

      if (cin.fail() || tolower(pivotar) != 's' && tolower(pivotar) != 'n') {
        cout << "Entrada inválida.\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        continue;
      }

      if (toupper(pivotar) == 'N') pivotar = 0;

      /* Pedindo a entrada da matriz */

      matriz = inicializarMatriz(tamanhoMatriz);


      i = 0;
      while (i < tamanhoMatriz) {
        j = 0;
        while (j < tamanhoMatriz) {
          printf("Digite o valor na posição [%d][%d] da matriz: ", i, j);
          cin >> entradaDeNumeros;
          if (cin.fail()) {
            cout << "entrada inválida.\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');

          }else {
            matriz[i][j] = entradaDeNumeros;
            j += 1;
          }

        }
        i += 1;
      };
    }

    if (pedirApenasVetorB || pedirMatrizEvetorB) {
      vetor = (double*) malloc(sizeof(double) * tamanhoMatriz);

      i = 0;
      while (i < tamanhoMatriz) {
        printf("Digite o valor [%d] do vetor: ", i);
        cin >> entradaDeNumeros;
        if (cin.fail()) {
          cout << "entrada inválida.\n";
          cin.clear();
          cin.ignore(INT_MAX, '\n');

        }else {
          vetor[i] = entradaDeNumeros;
          vetorLDP[i] = entradaDeNumeros;
          i += 1;
        }
      }
    }



    /* for (int i = 0; i < tamanhoMatriz; i++){
      printf("Digite o valor [%d] do vetor: ", i);
      cin >> vetor[i];
    } */


    /* pedindo para o usuário checar se a matriz e o vetor estão como ele deseja */
    if (pedirMatrizEvetorB) {
      this->print_input_matrice(matriz, tamanhoMatriz);
      cout << "CONFIRA A SUA MATRIZ: \n";
    }

    cout << "==========================\n";
    this->print_input_vector(vetor, tamanhoMatriz);
    cout << "CONFIRA O VETOR: \n";
    cout << "==========================\n";
    cout << "PARA CONTINUAR DIGITE 'X', PARA REPETIR O PROCESSO DIGITE QUALUQUER OUTRA COISA: ";
    cin >> resposta;

    if ( cin.fail() || tolower(resposta) != 'x' ) {
      cout << "vamos tentar novamente.\n";
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      continue;
    }

    ldp = LDP(matriz, tamanhoMatriz, pivotar);
    lu = LU(matriz, tamanhoMatriz, pivotar);
    ldp.calcularLDP();
    respostaLU = lu.calcularMetodo(vetor);
    respostaLDP = ldp.calcularMetodo(vetorLDP);

    if ( !(lu.valido) ) {
      this->print_message("NÃO É POSSÍVEL RESOLVER O SISTEMA");
    }else {
      this->printResultsOfMethods(respostaLDP, respostaLU,  tamanhoMatriz);
    }


    bool respostaDeSaidaValida = false;


    while (!respostaDeSaidaValida) {
      cout << "PARA ENCERRAR O PROGAMA DIGITE 'X'.\n";
      cout << "PARA EXECUTAR NOVAMENTE MODIFICANDO APENAS O VETOR B DIGITE     B.\n";
      cout << "PARA EXECUTAR NOVAMENTE MODIFICANDO A MATRIZ E O VETOR B DIGITE M.\n";
      cin >> resposta;
      if (tolower(resposta) == 'x') {
        continar = false;
        respostaDeSaidaValida = true;
      }else if ( tolower(resposta) == 'b' ) {
        pedirMatrizEvetorB = false;
        pedirApenasVetorB = true;
        respostaDeSaidaValida = true;
      } else if ( tolower(resposta) == 'm' ) {
        pedirMatrizEvetorB = true;
        pedirApenasVetorB = false;
        respostaDeSaidaValida = true;
      }else {
        cout << "Entrada inválida.\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
      }
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');

  }
}


void View::print_input_vector( double *vector, int numberLinesAndColumns) {
  Table vector_b;
  for (int i = 0; i < numberLinesAndColumns; i++) {
    vector_b.add_row({to_string(vector[i])});
  }
  vector_b.format()
  .corner("|")
  .hide_border_bottom()
  .hide_border_top()
  .padding_top(1)
  .padding_bottom(1)
  .padding_left(1.2)
  .padding_right(1.2);

  cout << vector_b << endl;
};


void View::print_message( string messageToPrint) {
  Table table_of_menu;
  table_of_menu.add_row({messageToPrint});

  table_of_menu.format()
  .font_color(Color::white)
  .font_background_color(Color::red)
  .font_align(FontAlign::center)
  .padding(1)
  .hide_border()
  .corner(" ");

  cout << table_of_menu << endl;
};
