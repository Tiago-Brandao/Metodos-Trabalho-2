#pragma once
#include "ldp.h"
#include "lu.h"
#include <array>
#include <climits>
#include <tabulate/table.hpp>
using namespace tabulate;
using Row_t = Table::Row_t;
#include <iostream>
using namespace std;

class View {
    private:

    public:
        void menu();
        void print_message(string messageToPrint);
        void print_input_matrice( double **matrice, int numberLinesAndColumns);
        void print_input_vector(double *vector, int numberLinesAndColumns);
        void printResultsOfMethods(double *LDPresolution, double *LUresolution, int numberOfX);
        void paintColumn(Table *table_of_results, int columnIndex, int redOrGreen, int numLin);
};

