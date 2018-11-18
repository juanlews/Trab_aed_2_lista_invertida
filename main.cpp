#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include<vector>
using namespace std;

struct palavra{

};

void stopWords(){

}

void pesquisa(){

}

void criaIndices(char * palavra){

}

void lerArquivos(){

    FILE *aux= fopen("teste.txt", "r");
    //char palavra[70];
    //string palavra;
    vector <string>palavra;
    if(aux){
        while(!feof(aux)){
            fscanf(aux, "%[^\n]\n", &palavra);
            printf("%s\n", palavra);
        }
    }

}


int main()
{
    lerArquivos();
    cout<<endl<<"deu bom!";
    return 0;
}
