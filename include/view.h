#pragma once
#include <array>
#include <tabulate/table.hpp>
using namespace tabulate;
using Row_t = Table::Row_t;
#include <iostream>
using namespace std;

class View {
    private:
        Table table_of_results;
        Table table_of_menu;

    public:
        void menu();
        void printResultsOfMethods(double *LDPresolution, double *LUresolution, int numberOfX);
        void paintColumn(int columnIndex, int redOrGreen, int numLin);
};
