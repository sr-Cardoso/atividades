#include<list>
#include <queue>
#include<stdio.h>
#include <locale.h>

using namespace std;

list<int> soma(list<int>, list<int>);
list<int> subtracao(list<int>, list<int>);
list<int> vezes10(list<int>*);

void printNumber(list<int> N){
    list<int>::iterator it;
    for (it = N.begin(); it != N.end(); it++)
    {
        printf("%d", *it);
    }
    printf("\n");
    
}

void zerosEsquerda(list<int>*A, list<int>*B){
    int v_A = (*A).size();
    int v_B = (*B).size();
    if(v_A > v_B){
        int add_zero = v_A - v_B;
        for(int i = 0; i < add_zero; i++){
            (*B).push_front(0);
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    list<int> N;
    int V[] = {1,2,1,2,1,4,5,2,3,8,6,4,5,8,9,5,3,1,3,5,7,9,1,5,4,1,0,9,0,8,7,6,7};
   /* Vetores para teste int V[] = {9,8,9,6,5,1};
    int V2[] = {6,0,1,6,7,9}; */

    for (size_t i = 0; i < 33; i++)
    {
        N.push_back(V[i]);
    }

    printf("Big number:");
    printNumber(N);
    list<int> C = soma(N, N);
    list<int> D = subtracao(N, N);
    printf("Soma dos bignumber: ");
    printNumber(C);
    printf("Subtracão dos bignumber: ");
    printNumber(D);
    printf("Multiplicação por 10: ");
    vezes10(&N);
    printNumber(N); 
}

list<int> vezes10(list<int> *N){
    (*N).push_back(0);
    return (*N);
}

list<int> soma(list<int> A, list<int> B){
    zerosEsquerda(&A, &B);
    list<int> C;
    list<int>::iterator itA;
    list<int>::iterator itB;
    int soma, x, y, aux=0;
    
    itA = A.end();
    itB = B.end();

    itA--;
    itB--;

    while(itA != A.begin()){
        x = *itA;
        y = *itB;
        soma = x + y + aux;
        aux = (soma > 9) ? 1 : 0;
        C.push_front(soma%10);
        itA--;
        itB--;
    }
    x = *itA;
    y = *itB;
    soma = x + y + aux;
    aux = (soma > 9) ? 1 : 0;
    C.push_front(soma);
    itA--;
    itB--;
    return C;
}
list<int> subtracao(list<int> A, list<int> B){
    zerosEsquerda(&A, &B);
    list<int> D;
    list<int>::iterator itA;
    list<int>::iterator itB;
    int sub, x, y, aux=0;
    
    itA = A.end();
    itB = B.end();

    itA--;
    itB--;

    while(itA != A.begin()){
        x = (*itA) - aux ;
        y = *itB;
    if(y > x){ //Técnica de "Pegar emprestado"
        x+=10;
        sub = x - y;
        aux = 1;
    } else{
    sub = x - y;
    aux = 0;
    }
    D.push_front(sub);
        itA--;
        itB--;
    }
        x = (*itA) - aux ;
        y = *itB;
    if(y > x){
        x+=10;
        sub = x - y;
        aux = 1;
    } else{
    sub = x - y;
    aux = 0;
    }
    D.push_front(sub);
        itA--;
        itB--;
    return D;
}
