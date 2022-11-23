#include "../include/view.h"

void View::paintColumn(int rowIndex, int columnIndex, int redOrGreen, int numLin) {
  if (redOrGreen == 1) {
    for (int i = rowIndex; i < (numLin-1); i++ ) {
      table_of_results[i][columnIndex].format().background_color(Color::red);
    }
  }else {
    for (int i = rowIndex; i < (numLin-1); i++ ) {
      table_of_results[i][columnIndex].format().background_color(Color::green);
    }
  }
};


void View::printResultsOfMethods(double *LDPresolution, double *LUresolution, int numberOfX){
  bool willTheRocketFallbyLDP = false;
  bool willTheRocketFallbyLU = false;
  table_of_results.add_row({"", "Resultados dos", "métodos"});
  table_of_results.add_row({"", "Método LDP", "Método LU"});


table_of_results.format()

    .font_align(FontAlign::center)
    .font_color(Color::white)
    .corner(" ")
    .border_top("")
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
    /* table_of_results.column(1).format()
      .background_color(Color::red);

    table_of_results.column(2).format()
      .background_color(Color::red); */


  }else if (willTheRocketFallbyLDP && !willTheRocketFallbyLU) {
    table_of_results.add_row({"Resultado:", "cai", "não cai"});
    /* table_of_results.column(1).format()
      .background_color(Color::red);

    table_of_results.column(2).format()
      .background_color(Color::green); */


  }else if (!willTheRocketFallbyLDP && willTheRocketFallbyLU) {
    table_of_results.add_row({"Resultado:", "não cai", "cai"});
    table_of_results.column(1).format()
      .background_color(Color::green);

    table_of_results.column(2).format()
      .background_color(Color::red);
  } else {
    table_of_results.add_row({"Resultado:", "não cai", "não cai"});
    table_of_results.column(1).format()
      .background_color(Color::green);

    table_of_results.column(2).format()
      .background_color(Color::green);
  }


  /* table_of_results.add_row({"x1", "14.1", "44"});
  table_of_results.add_row({"x2", "14.55", "22"});
  table_of_results.add_row({"Erro relativo", "44", "33"});
  table_of_results.add_row({"Resultado", "caiu", "não caiu"}); */


  cout << table_of_results << endl;
};

void View::menu() {

}
