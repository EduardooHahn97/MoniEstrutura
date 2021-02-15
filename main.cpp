#include <iostream>
#include <string.h>

#define m 11
using namespace std;

typedef struct item{
    int codigo;
    float valor;
}item;

int GeraHash(int v){
    return v % m;
}

void addHash(item *v, int pos,int cod, float valor){
    while(v[pos].codigo != 0 && pos < 11){
        if(pos == 10){
            pos = 0;
        }else{
            pos++;
        }
    }

    v[pos].codigo = cod;
    v[pos].valor = valor;
}

void Buscar(item *v, int codigo){
    int pos = GeraHash(codigo);
    if(v[pos].codigo == 0){
        cout << "Vetor nao possui o codigo " << codigo << endl;
    }else {
        cout << "Encontrado : "<<  v[pos].codigo << " - " << v[pos].valor << endl;
    }
}

int main()
{
    item a;
    a.codigo = 12;
    a.valor = 50;

    item b;
    b.codigo = 24;
    b.valor = 51;

    item c;
    c.codigo = 29;
    c.valor = 12;

    item *vetor;

    vetor = (item *)calloc(11, sizeof(item));

    addHash(vetor, GeraHash(a.codigo), a.codigo, a.valor);
    addHash(vetor, GeraHash(b.codigo), b.codigo, b.valor);
    addHash(vetor, GeraHash(c.codigo), c.codigo, c.valor);

    for(int i = 0; i < m; i++){
        cout << i << " - " << vetor[i].codigo << " - " << vetor[i].valor << endl;
    }

    Buscar(vetor, 12);
    Buscar(vetor, 11);
    Buscar(vetor, 24);
    Buscar(vetor, 29);


    return 0;
}
