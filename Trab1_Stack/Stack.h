//Nomes: Ana Beatriz Monteiro Fioravanti, Vinicius de Souza Oliveira
//Obs: implementamos todas as funcoes gerais (ensinadas em aula) do TAD pilha para deixa-la completa e coesa, porem nao utilizamos todas elas
//Stack.h
//Declaracao/interface para a pilha (no caso, eh a de implementacao dinamica)
#include <cstring>
using namespace std;

#ifndef STACK_H
#define STACK_H

typedef string StackEntry;
//especificacao dos valores uteis de entrada da pilha


class Stack{

    public:
        //declaracao de metodos
        Stack();
        ~Stack();
        void push(StackEntry x);
        void pop(StackEntry &x);
        bool stack_empty();
        bool stack_full();
        void stack_clear();
        int stack_size();
        void getTop(StackEntry &x);

        /*aqui abaixo estao metodos que criamos de maneira independente para fazer maipulacoes especificas na pilha,
        de acordo com as exigencias propostas pelo trabalho*/

        void stack_back();
        void stack_further();
        void stack_newflow();

    private:
        //declaracao de tipos
        struct StackNode; //declaracao forward
        typedef StackNode (* StackPointer); //StackPointer eh um ponteiro para estrutura StackNode
        struct StackNode{
            //declaracao dos campos do node
            StackEntry entry; //tipo de dado colocado na pilha
            StackPointer nextNode; //ligacao para proximo elemento na pilha
        };
        int stack_count; //contagem do tamanho da pilha
        StackPointer top; //topo da pilha

        /*aqui abaixo estao variaveis que criamos de maneira independente para auxiliar em maipulacoes especificas na pilha,
        de acordo com as exigencias propostas pelo trabalho*/

        StackPointer aux; //guia das paginas atuais
        StackPointer aux_furt; //desloca o guia das paginas atuais para a pagina posterior
        StackPointer aux_nf; //auxilia a delecao de nodes para iniciar um novo fluxo

};

#endif
