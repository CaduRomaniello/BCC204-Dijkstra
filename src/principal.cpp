#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "dijkstra.hpp"

using namespace std;

int main(){

    // Criacao e inicializacao do grafo
    Grafo grafo = Grafo();
    grafo.inicializaGrafo();

    // Dijkstra
    grafo.dijkstra();

    // Print
    printFinal(&grafo);

    return 0;

}
