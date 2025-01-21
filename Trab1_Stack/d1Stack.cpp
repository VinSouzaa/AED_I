//Nomes: Ana Beatriz Monteiro Fioravanti, Vinicius Souza Oliveira
//d1Stack.cpp
#include <iostream>
#include <cstring>
#include "Stack.h"
using namespace std;

int main(){

    Stack URL_warehouse; //cria-se o armazenador de URLs, que eh uma pilha

    string command = "inicio"; //variavel que guarda o comando do usuario
    string URL; //variavel que guarda as URLs

    cout<<"Bem vindo ao simulador de URLs! Digite sua primeira URL para iniciar o programa: ";
    cin >> URL;
    URL_warehouse.push(URL);

    //primeiro elemento da pilha eh inserido logo no inicio do programa para que ele tenha sentido

    cout<<endl<<"Agora escolha um dos comandos a seguir para que ele prossiga com sua respectiva funcao: "<<endl;
    cout<<"'novo' para inserir uma nova URL;"<<endl<<"'anterior' para voltar a URL digitada anteriormente (partindo da atual);"<<endl;
    cout<<"'posterior' para ir para a URL digitada posteriormente (partindo da atual);"<<endl<<"'sair' para encerrar o programa."<<endl<<endl;

    //comando determina o fluxo do programa que chamara o metodo especifico correspondente a funcao de cada comando

    while(command.compare("sair") != 0){

        cout<<endl<<"Digite seu novo comando: ";
        cin >> command;

        if(command.compare("sair") == 0){
        //encerra o programa
            cout<<endl<<"Programa encerrado.";
            abort();
        }

        else if(command.compare("novo") == 0){
        //insere uma nova URL, pode ou nao criar um novo fluxo, dependendo de onde o comando 'novo' eh dado
            URL_warehouse.stack_newflow();
            cout<<endl<<"Nova URL: ";
            cin >> URL;
            URL_warehouse.push(URL);
        }

        else if(command.compare("anterior") == 0){
        //mostra a URL dada anteriormente
            URL_warehouse.stack_back();
        }

        else if(command.compare("posterior") == 0){
        //mostra a URL dada posteriormente
            URL_warehouse.stack_further();
        }

        else{
        //metodo de contencao caso seja dada uma palavra que nao eh um dos comandos propostos
        cout<<endl<<"Comando invalido! Tente novamente."<<endl;
        }

    }
}
