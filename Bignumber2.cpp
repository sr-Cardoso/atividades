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

int main(){
    setlocale(LC_ALL, "Portuguese");
    list<int> N1, N2;
    //int V[] = {1,2,1,2,1,4,5,2,3,8,6,4,5,8,9,5,3,1,3,5,7,9,1,5,4,1,0,9,0,8,7,6,7};
    int V[] = {9,8,9,6,5,1};
    int V2[] = {6,0,1,6,7,9}; 

    for (size_t i = 0; i < 6; i++)
    {
        N1.push_back(V[i]);
    }

    for (size_t i = 0; i < 6; i++)
    {
        N2.push_back(V2[i]);
    }

    printf("Big number:");
    printNumber(N1);
    printNumber(N2);
    list<int> C = soma(N1, N2);
    list<int> D = subtracao(N1, N2);
    printf("Soma dos bignumber: ");
    printNumber(C);
    printf("Subtracão dos bignumber: ");
    printNumber(D);
/*   printf("Multiplicação por 10: ");
    vezes10(&N1);
    printNumber(N1); */
}

list<int> vezes10(list<int> *N){
    (*N).push_back(0);
    return (*N);
}

list<int> soma(list<int> A, list<int> B){
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
    if(y > x){//Técnica de "Pegar emprestado"
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
