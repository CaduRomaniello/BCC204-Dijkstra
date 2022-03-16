#include "dijkstra.hpp"

using namespace std;

/*
███████╗██╗   ██╗███╗   ██╗ ██████╗ ██████╗ ███████╗███████╗
██╔════╝██║   ██║████╗  ██║██╔════╝██╔═══██╗██╔════╝██╔════╝
█████╗  ██║   ██║██╔██╗ ██║██║     ██║   ██║█████╗  ███████╗
██╔══╝  ██║   ██║██║╚██╗██║██║     ██║   ██║██╔══╝  ╚════██║
██║     ╚██████╔╝██║ ╚████║╚██████╗╚██████╔╝███████╗███████║
╚═╝      ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝
*/

void percorreCaminho(Grafo grafo, int vertice, vector<int>* caminho){
    caminho->push_back(vertice);

    if (grafo.vertices[vertice - 1].rot == 0){
        return;
    }

    percorreCaminho(grafo, grafo.vertices[vertice - 1].rot, caminho);
}

void printFinal(Grafo* grafo){
    for (int i = 0; i < static_cast<int>(grafo->vertices.size()); i++){
        if (grafo->vertices[i].id == grafo->vertice_inicial){
            continue;
        }

        vector<int> aux;

        cout << grafo->vertices[i].id << " (" << grafo->vertices[i].dt << "): ";

        percorreCaminho(*grafo, grafo->vertices[i].id, &aux);
        for (int i = static_cast<int>(aux.size()) - 1; i >= 0; i--){
            if (i == 0){
                cout << aux[i] << endl;
            }
            else{
                cout << aux[i] << " ";
            }
        }
    }
}

/*
 █████╗ ██████╗ ███████╗███████╗████████╗ █████╗ 
██╔══██╗██╔══██╗██╔════╝██╔════╝╚══██╔══╝██╔══██╗
███████║██████╔╝█████╗  ███████╗   ██║   ███████║
██╔══██║██╔══██╗██╔══╝  ╚════██║   ██║   ██╔══██║
██║  ██║██║  ██║███████╗███████║   ██║   ██║  ██║
╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝
*/

Aresta::Aresta(int id, int origem, int destino, double peso){

    this->id = id;
    this->origem = origem;
    this->destino = destino;
    this->peso = peso;
}
Aresta::~Aresta(){}

void Aresta::printInfo(){
    cout << "--------- Aresta ---------\n";
    cout << "Id         : " << this->id << "\n" ;
    cout << "Origem     : " << this->origem << "\n" ;
    cout << "Destino    : " << this->destino << "\n" ;
    cout << "Peso       : " << this->peso << "\n\n" ;
}

/*
██╗   ██╗███████╗██████╗ ████████╗██╗ ██████╗███████╗
██║   ██║██╔════╝██╔══██╗╚══██╔══╝██║██╔════╝██╔════╝
██║   ██║█████╗  ██████╔╝   ██║   ██║██║     █████╗  
╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██║██║     ██╔══╝  
 ╚████╔╝ ███████╗██║  ██║   ██║   ██║╚██████╗███████╗
  ╚═══╝  ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝╚══════╝
*/

Vertice::Vertice(int id, bool fechado){
    this->id = id;
    this->fechado = fechado;
    this->dt = 0.0;
    this->rot = 0;
}
Vertice::~Vertice(){}

void Vertice::printInfo(){
    cout << "--------- Vertice ---------\n";
    cout << "Id                            : " << this->id << "\n" ;
    cout << "Fechado                       : " << this->fechado << "\n" ;
    cout << "Tamanho da lista de adjacencia: " << static_cast<int>(this->adjacencia.size()) << "\n\n" ;
}

/*
 ██████╗███████╗██╗     ██╗   ██╗██╗      █████╗ 
██╔════╝██╔════╝██║     ██║   ██║██║     ██╔══██╗
██║     █████╗  ██║     ██║   ██║██║     ███████║
██║     ██╔══╝  ██║     ██║   ██║██║     ██╔══██║
╚██████╗███████╗███████╗╚██████╔╝███████╗██║  ██║
 ╚═════╝╚══════╝╚══════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝
*/

Celula::Celula(bool status, bool visitado, double peso):status(status), visitado(visitado), peso(peso){}
Celula::~Celula(){}

/*
 ██████╗ ██████╗  █████╗ ███████╗ ██████╗ 
██╔════╝ ██╔══██╗██╔══██╗██╔════╝██╔═══██╗
██║  ███╗██████╔╝███████║█████╗  ██║   ██║
██║   ██║██╔══██╗██╔══██║██╔══╝  ██║   ██║
╚██████╔╝██║  ██║██║  ██║██║     ╚██████╔╝
 ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝      ╚═════╝ 
*/

Grafo::Grafo(){}
Grafo::Grafo(int qntd_vertices, int qntd_arestas, int vertice_inicial, bool direcionado):qntd_vertices(qntd_vertices), qntd_arestas(qntd_arestas), vertice_inicial(vertice_inicial), direcionado(direcionado){}
Grafo::~Grafo(){}

void Grafo::inicializaGrafo(){

    // Leitura dos dados iniciais
    int qntd_vertices, qntd_arestas, eh_direcionado, vertice_inicial;
    bool direcionado;

    cin >> qntd_vertices >> qntd_arestas >> eh_direcionado >> vertice_inicial;
    if (eh_direcionado == 1){
        direcionado = true;
    }
    else{
        direcionado = false;
    }

    this->qntd_arestas = qntd_arestas;
    this->qntd_vertices = qntd_vertices;
    this->direcionado = direcionado;
    this->vertice_inicial = vertice_inicial;

    // Lendo vertices
    for (int i = 1; i <= this->qntd_vertices; i++){
        Vertice v(i, false);

        if (i != this->vertice_inicial){
            v.dt = numeric_limits<double>::max();
            v.rot = 0;
        }
        else{
            v.dt = 0.0;
            v.rot = 0;
        }

        this->vertices.push_back(v);

        vector<Celula> vet;
        this->matriz.push_back(vet);
        for (int j = 1; j <= this->qntd_vertices; j++){
            this->matriz[i - 1].push_back(Celula());
        }
    }

    // Lendo arestas e criando listas de adjacencia
    int origem, destino;
    double peso;

    for (int i = 1; i <= this->qntd_arestas; i++){
        cin >> origem >> destino >> peso;
        
        Aresta a = Aresta(i, origem, destino, peso);
        this->arestas.push_back(a);

        if (this->direcionado){
            // Preenchendo lista de adjacencia
            this->vertices[origem - 1].adjacencia.push_back(i);

            // Preenchendo matriz com o peso correspondente da aresta
            this->matriz[origem - 1][destino - 1].status = true;
            this->matriz[origem - 1][destino - 1].peso = peso;
        }
        else{
            // Preenchendo lista de adjacencia do primeiro vertice
            this->vertices[origem - 1].adjacencia.push_back(i);

            // Preenchendo lista de adjacencia do segundo vertice
            this->vertices[destino - 1].adjacencia.push_back(i);

            // Preenchendo matriz com o peso correspondente da aresta indo da origem para o destino
            this->matriz[origem - 1][destino - 1].status = true;
            this->matriz[origem - 1][destino - 1].peso = peso;
            
            // Preenchendo matriz com o peso correspondente da aresta indo do destino para a origem
            this->matriz[destino - 1][origem - 1].status = true;
            this->matriz[destino - 1][origem - 1].peso = peso;
        }
    }
}

int Grafo::posicaoMenorDT(){
    int pos = -1;
    int dt = numeric_limits<int>::max();
    for (int i = 0; i < this->qntd_vertices; i++){
        if (this->vertices[i].fechado){
            continue;
        }

        if (this->vertices[i].dt < dt){
            dt = this->vertices[i].dt;
            pos = i;
        }
    }
    return pos;
}

void Grafo::dijkstra(){
    int verticeAtual;

    vector<Vertice>* vertices = &this->vertices;
    vector<vector<Celula>>* matriz = &this->matriz;

    vector<Vertice> f;

    // Em relacao ao BFS a condicao de parada foi trocada, pois a condicao do BFS iterava ate que a lista de vertices vizinhos nao visitados estivesse vazia, ja no dijkstra a iteracao deve ocorrer para cada um dos vertices do grafo
    while (f.size() != vertices->size()){

        int pos = this->posicaoMenorDT();
        Vertice* v = &vertices->at(pos);
        verticeAtual = v->id;
        f.push_back(*v);
        v->fechado = true;

        // O loop mais interno percorre a lista de adjacencia inteira da mesma forma o loop do BFS, a diferenca esta apenas no nome utilizado para variaveis. Como no BFS foi criada uma variavel auxiliar (Vertice* v) para facilitar a leitura do codigo
        for (auto it = v->adjacencia.begin(); it != v->adjacencia.end(); it++){

            Aresta a = this->arestas[*it - 1];// a obtencao da aresta eh identica a do BFS
            int vizinho;

            // no dijkstra nao eh necessario fazer a verificacao se o vertice eh direcionado, entao so eh necessario descobrir se o vizinho esta no atributo vizinho ou destino da aresta em questao da emsma forma que eh realizado no BFS
            if (a.origem == verticeAtual){
                vizinho = a.destino;
            }
            else{
                vizinho = a.origem;
            }

            if (vertices->at(vizinho - 1).fechado){
                continue;
            }

            // aqui esta a operacao exclusiva do dijkstra que atualiza o dt e o rot de cada vertice
            if ((vertices->at(verticeAtual - 1).dt + matriz->at(verticeAtual - 1).at(vizinho - 1).peso) < vertices->at(vizinho - 1).dt){
                vertices->at(vizinho - 1).dt = vertices->at(verticeAtual - 1).dt + matriz->at(verticeAtual - 1).at(vizinho - 1).peso;
                vertices->at(vizinho - 1).rot = verticeAtual;
            }
        }
    }
}

void Grafo::printInfo(){
    cout << "--------- Grafo ---------\n";
    cout << "Qntd vertices  : " << this->qntd_vertices << "\n" ;
    cout << "Qntd arestas   : " << this->qntd_arestas << "\n" ;
    cout << "Vertice inicial: " << this->vertice_inicial << "\n" ;
    cout << "Direcionado    : " << this->direcionado << "\n\n" ;
}
