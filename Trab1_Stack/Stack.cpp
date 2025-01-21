//Nomes: Ana Beatriz Monteiro Fioravanti, Vinicius de Souza Oliveira
//Stack.cpp
//Implementacao dos metodos da pilha
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "Stack.h"
using namespace std;


Stack::Stack(){
//pre-condicao: nenhuma
//pos-condicao: pilha eh criada e iniciada como vazia e o contador de tamanho eh iniciado com o valor 0

    top = NULL;
    stack_count = 0;

}

void Stack::stack_clear(){
//pre-condicao: nenhuma
//pos-condicao: todos os itens da pilha são descartados e ela torna-se uma pilha vazia; contador de tamanho recebe valor 0

    StackPointer p;
    while(top != NULL){
        p = top;
        top = top->nextNode;
        delete p; }
    stack_count = 0;

}

Stack::~Stack(){
//pre-condicao: nenhuma
//pos-condicao: pilha eh finalizada, deixando de ocupar espaço na memoria

    stack_clear();

}

bool Stack::stack_empty(){
//pre-condicao: nenhuma
//pos-condicao: funcao retorna true se a pilha esta vazia; false caso contrario

    return (top == NULL);

}

bool Stack::stack_full(){
//pre-condicao: nenhuma
//pos-condicao: funcao retorna false

    return false;

}

void Stack::getTop(StackEntry &x){
//pre-condicao: pilha nao esta vazia
//pos-condicao: a variavel x recebe uma copia do item no topo da pilha; a pilha permanece inalterada

    if(top == NULL){
        cout << "Pilha vazia";
        abort();
    }
    x = top->entry;

}

void Stack::push(StackEntry x){
//pre-condicao: pilha nao esta cheia
//pos-condicao: o item x eh armazenado no topo da pilha e o contador de tamanho tem seu valor incrementado

    StackPointer p;
    p = new StackNode;
    if(p == NULL){
    cout << "Memoria insuficiente";
    abort();
    }
    p->entry = x;
    p->nextNode = top;
    top = p;
    stack_count++;

    aux = top;

    cout<<"URL atual: "<<p->entry<<endl;

}

void Stack::pop(StackEntry &x){
//pre-condicao: pilha nao esta vazia
//pos-condicao: o item no topo da pilha eh removido e seu valor eh retornado na variavel x; o contador de tamanho tem seu valor decrementado

    StackPointer p;
    if (stack_empty()){
        cout << "Pilha Vazia";
        abort();
    }
    x = top->entry;
    p = top;
    top = top->nextNode;
    delete p;
    stack_count--;
}

int Stack::stack_size(){
//pre-condicao: nenhuma
//pos-condicao: funcao retorna o numero de itens na pilha

    return stack_count;

}

void Stack::stack_back(){
//pre-condicao: pilha nao esta vazia e o progrma nao esta no primeiro elemento
//pos-condicao: uma mensagem de erro eh retornada caso esteja no primeiro elemento e, caso nao seja, o elemento anterior eh impresso

    if(aux->nextNode == NULL){
        cout<<"Erro! Comando invalido, voce ja esta na primeira URL, nao ha anteriores, tente outros comandos."<<endl;
    }

    else{
    aux = aux->nextNode;
    cout<<"URL atual: "<<aux->entry << endl;
    }
}

void Stack::stack_further(){
//pre-condicao: pilha nao esta vazia nem cheia e nao ha apenas um elemento nela, o programa nao esta no ultimo elemento (topo da pilha)
/*pos-condicao: uma mensagem de erro eh retornada caso haja um unico elemento ou se o programa esta no ultimo elemento (topo da pilha) e,
caso haja mais de um, o elemento posterior eh impresso*/

    if(aux == top){
        cout<<"Erro! Comando invalido, voce ja esta na ultima URL, nao ha posteriores, tente outros comandos."<<endl;
    }

    else{
        aux_furt = top;
        while (aux_furt->nextNode != aux){
            aux_furt = aux_furt->nextNode;
        }
        aux = aux_furt;
        aux_furt = NULL;
        cout<<"URL atual: "<<aux->entry<<endl;
    }
}

void Stack::stack_newflow(){
//pre-condicao: a pilha esta criada
//pos-condicao: os elementos desde o topo ate o posterior em relacao ao atual são apagados

    while(top != aux){
        aux_nf = top;
        top = top->nextNode;
        delete aux_nf;
    }
}
