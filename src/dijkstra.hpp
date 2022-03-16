#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <limits>
#include <queue>

using namespace std;

class Aresta{
    public:

        //Atributos
        int id;
        int origem;
        int destino;
        double peso;

        //Metodos
        Aresta(int id = -1, int origem = -1, int destino = -1, double peso = -1.0);
        ~Aresta();

        void printInfo();
};

class Vertice{
    public:

        //Atributos
        int id;
        bool fechado;
        list<int> adjacencia;
        double dt;
        int rot;

        //Metodos
        Vertice(int id, bool fechado = false);
        ~Vertice();

        void printInfo();
};

class Celula{
    public:
        //Atributos
        bool status; // TRUE caso tenha aresta de i para j e FALSE caso nao exista
        bool visitado;
        double peso;

        //Metodos
        Celula(bool status = false, bool visitado = false, double peso = 0.0);
        ~Celula();
};

class Grafo{
    public:

        //Atributos
        int qntd_vertices;
        int qntd_arestas;
        int vertice_inicial;
        bool direcionado;
        vector<Vertice> vertices;
        vector<Aresta> arestas;
        vector<vector<Celula>> matriz;

        //Metodos
        Grafo();
        Grafo(int qntd_vertices, int qntd_arestas, int vertice_inicial, bool direcionado);
        ~Grafo();

        void inicializaGrafo();
        int posicaoMenorDT();

        void dijkstra();

        void printInfo();
};

void percorreCaminho(Grafo grafo, int vertice, vector<int>* caminho);
void printFinal(Grafo* grafo);

#endif
