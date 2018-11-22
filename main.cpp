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

void teste() {
	// Creating a vector of int;
	std::vector<std::string> vecOfStr;

	std::cout << "Size of Vector = " << vecOfStr.size() << std::endl;

	// Push an element in vector, it will be appended in the last
	vecOfStr.push_back("AAA");
	vecOfStr.push_back("BBB");
	vecOfStr.push_back("BBB");

	std::cout << "Size of Vector = " << vecOfStr.size() << std::endl;


        for(int  i = 0; i < vecOfStr.size(); i++){

            printf("%s\n", vecOfStr[0].c_str());

        }

	// Now lets print the content of vector,
	//for (std::string data : vecOfStr)
    //std::cout << data << std::endl;
}
/*
jogaProIndice(char * linha, int numDaLinha){
    //printf("%s\t%i \n", linha, strlen(linha));
    char palavra[strlen(linha)];
    string palFinal;
    int k = 0, init = 0;
    for ( int i = 0; i < strlen(linha); i++ ){
        if(linha[i] != ' ' && i < strlen(linha) - 1){
            palavra[k] = linha[i] ;
            k++;
        } else {
            k = 0;
            palFinal = palavra;
            palavra = memset(palavra, 0, sizeof(palavra));
             using std::begin, std::end;
            std::fill(begin(palavra), end(palavra), '\0');
            cout << "Palavra: "<< palFinal << "Tamanho: "<< strlen(palavra) << " Linha: "<< numDaLinha << " inicio da palavra: "<< i << endl;
        }
    }
    for(int i = 0; i < strlen(palavra); i++){
        //printf("%s\t%i \n", palavra[i], strlen(palavra));
    }
 }
*/

jogaProIndice(char * linha, int numDaLinha){
    //printf("%s\t%i \n", linha, strlen(linha));
    char palavra[strlen(linha)];
    int k = 0;

    for ( int i = 0; i <= strlen(linha); i++ ){
        if(linha[i] != ' ' && i!=strlen(linha)){
            palavra[k] = linha[i] ;
            k++;
        } else {
            for(int t=0; t<k; t++){
                cout<<palavra[t];
            }
            printf(", Linha: %i, Coluna: %i\n", numDaLinha, i);
            //GravaNoIndece(palavra, k, numDaLinha);
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
                //printf("%s\t%i \n", linha, strlen(linha));
                //texto.push_back(palavra);
                //texto.push_back("B");

            }
        }


        /*for(int  i = 0; i < texto.size(); i++){

            printf("%s\n", texto[i].c_str());

        }*/
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
