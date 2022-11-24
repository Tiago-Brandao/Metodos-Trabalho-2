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

}
