#define atividade "2"  
#define nome "Savio de Carvalho" 
#define matricula "552882"
#include <cmath>

/*
Seja uma classe que representa um ponto no plano dada por,.  
*/

class ponto {
    float x; // abcissa
    float y; // ordenada

public:
    ponto (int x, int y){  // constrói ponto
        // cria ponto dadas coordenadas
        this->x = x;
        this->y = y;
    }
    ponto () {
        // alternativa de criação de ponto para construir um ponto (0,0)
        this->x = 0;
        this->y = 0; 
    }
    float dist (const ponto& p) {
        // determina a distância do ponto à este passaso como argumeto.
        float distance = sqrt(pow((p.x - this->x), 2) + pow((p.y - this->y), 2));
        return distance;
    }
    float& X() {
        //  retorna a referência para a abcissa
        return x;
    }
    float Y() {
        // Retorna referência para a ordenada
        return y;
    }
};

/* Implemente as funções a seguir usando a classe anterior */

float reta(ponto& p, ponto& q) {
    // retorna o coeficiente angular da reta que passa pelos pontos p e q
    float coeficiente_angular = (q.Y() - p.Y()) / (q.X() - p.X());
    return coeficiente_angular;
}

float minDist(const ponto& p, ponto kust[], int n) {
    // retorna a menor distância entre p e os pontos da lista list dada de comprimento n.
    float min_distance = kust[0].dist(p); // inicializa o min_distance com a distância entre p e o primeiro ponto da lista

    for (int i = 1; i < n; i++) {
        float distance = kust[i].dist(p); // calcula a distância entre p e o ponto atual na lista

        if (distance < min_distance) {
            min_distance = distance; // atualiza o min_distance se a distância atual for menor
        }
    }
     
    return min_distance;
}

