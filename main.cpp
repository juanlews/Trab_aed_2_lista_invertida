#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<vector>
using namespace std;
vector<string> texto;

struct palavra{

};

void stopWords(){

}

void pesquisa(){

}

void criaIndices(char * palavra){

}


void gravaNoIndice(char * palavra, int tam, int col, int numDaLinha){
     printf(", Fim da palavra: %i Inicio da palavra: %i tamanho da palavra: %i \n",
                            col,                  (col - tam), (tam));


}

void jogaProIndice(char * linha, int numDaLinha){
    //printf("%s\t%i \n", linha, strlen(linha));
    char palavra[strlen(linha)];
    int k = 0;

    for ( int i = 0; i <= strlen(linha); i++ ){
        if(linha[i] != ' ' && i != strlen(linha)){
            palavra[k] = linha[i] ;
            k++;
        } else {
            for(int t=0; t<k; t++){
                cout << palavra[t];
            }

            gravaNoIndice(palavra, k, i, numDaLinha);
            k=0;
        }
    }
}

void lerArquivos( char * arq = "teste.txt" ){
    FILE * aux = fopen(arq, "r");
    char linha[512];
    unsigned int numDaLinha = 0;

    if(aux){
        while(!feof(aux)){
            if(!feof(aux)){
                fscanf(aux, "%[^\n]\n", &linha);
                jogaProIndice(linha, numDaLinha);
                numDaLinha++;
            }
        }
    }
}

int main()
{
    //teste();
    lerArquivos();
    cout<<endl<<"deu bom!";

    system("PAUSE");
    return 0;
}
