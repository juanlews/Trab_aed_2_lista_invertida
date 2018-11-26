#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<vector>
#include <fstream>
#include <sstream>

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


void gravaNoIndice(const char * palavra, int tam, int col, int numDaLinha, char * nomeArquivo = "teste"){
   // printf(", Fim da palavra: %i Inicio da palavra: %i tamanho da palavra: %i \n", col, (col - tam), (tam));
    bool finded = false;
    printf("\n Pesquisando: %s \n", palavra);
    FILE * arqIndex = fopen( "teste.indice","r+");
    char indice[512];
    char xablau[2048];

    if(arqIndex){
        fscanf( arqIndex, "%[^<]<", &indice );
        //cout<< " " << strcmp(indice, palavra);
        while( !feof(arqIndex) ){
            if( !feof(arqIndex) ){

                if(strcmp(indice, palavra) == 1){
                    cout <<" " << indice <<" = "<< palavra << " ";
                    finded = true;
                    fscanf(arqIndex, "%[^\n]\n", &xablau);
                    //cout << " on "<< xablau << " " ;
                    break;

                } else {
                    fscanf(arqIndex, "%[^\n]\n", &xablau);
                    //cout << " " << xablau;
                    fscanf( arqIndex, "%[^<]<", &indice );
                    //cout<<strcmp(indice, palavra);
                    cout <<" indice: " << indice;

                }
            }
        }
    }

    fclose(arqIndex);
   /* if(!finded){
        int test;
        string toSave = "";
        stringstream convertNumLin, convertWord;
        //-----------formatar a string de indice--------------------------
        toSave.append(palavra);
        toSave.append(" <teste.txt, ");
        convertNumLin << numDaLinha;
        convertWord << (col - tam);
        toSave.append(convertNumLin.str()+", "+ convertWord.str()+">\n");
        //----------------------------------------------------------------
        //cout << endl<< toSave <<endl;
        fflush(stdin);
        std::ofstream out;
        out.open( "teste.indice", std::ios::app);
        out << toSave.c_str();
        out.close();
    }*/
}

void jogaProIndice(char * linha, int numDaLinha){
    //printf("%s\t%i \n", linha, strlen(linha));
    char palavra[strlen(linha)];
    int k = 0;
    const char * converted_string_to_char;
    string word;
    for ( int i = 0; i <= strlen(linha); i++ ){
        if(linha[i] != ' ' && i != strlen(linha)){
            palavra[k] = linha[i] ;
            k++;
        } else {
            word = "";
            for(int t=0; t<k; t++){
                word += palavra[t];
            }
            converted_string_to_char = word.c_str();
            gravaNoIndice(converted_string_to_char, k, i, numDaLinha);
            k=0;
            fflush(stdin);

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
    fclose(aux);
}

int main()
{
    //teste();
    lerArquivos();
    cout<<endl<<"deu bom!";

    system("PAUSE");
    return 0;
}
