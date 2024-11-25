#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //Memoria virtual:Permite executar programas que necessitam de mais memoria que a memoria disponivel.
 //Imitam a memoria principal do disco rigido.

 void paginacao(void);
 void TLB(void);
 void MP(void);

 int i, u=0, y=0, u, d, mv;  
 int my[];
 int tlb[];
 int mp[];
 char c, q;


int main(){
    printf("\t\tBem vindo a simulacao de MV\n");
    printf("\t\tEssa simulacao vai simular uma paginacao\n");
    printf("\t\t(Para fins praticos foi se reduzido por exemplo 64000 bits para o numero 64 como se fosse kbits)\n");
    printf("\t\tPara isso preciso que digite o numero de paginas em nosso programa:\n");
    printf("\t\tTenha em mente que cada pagina tem tamanho de 4 kbits então se for 5 paginas sera 20 kbits de memoria\n");
    scanf("%d", &mv);
    mv;
    paginacao();
    return 0;
}

void paginacao(void){
    for(i=0; i<=mv; i++){
        my[y]=i;
        y++;
    }
    printf("\t\tAgora o numero que foi inserido representa o numero de paginas criadas na MV\n");
    printf("\t\tCada pagina ocupa 4k bits então se voce digitou 16 kbits entao o numero de paginas sera 4");
    printf("\t\tEssas paginas são uma ilusao do tamanho da memoria principal\n");
    printf("\t\tElas sao entao enderecadas aos blocos na memoria principal\n");
    printf("\t\tNao sao todos os blocos que são preenchidos pelas paginas da MV na MP\n");
    printf("\t\tPor exemplo esse e o numero de paginas que voce digitou:\n");
    y=0;
    for(i=0; i<=mv; i++){
        printf("\t\t%d\n", my[y]);
        y++;
    }
    printf("\t\tAgora vamos para a proxima etapa a TLB:\n");
    TLB();
}

void TLB(void){
    printf("\t\tA TLB sao blocos na memoria cache enderecados as paginas da MV\n");
    for(i=0; i<=mv; i++){
        tlb[i]=my[y];
    }
    printf("\t\tAgora chegamos a parte final voce esta agora na memoria principal:\n");
    printf("\t\tComo ela e menor que a MV ou cache, voce precisa digitar os enderecos e parte disso sera carregado ate a nossa MP\n");
    printf("\t\tVoce pode no maximo chamar ate 20 paginas para a no mp\n");
    MP();
}

void MP(void){
        printf("\t\tDigite o numero da pagina\n");
        scanf("%d", &d);
        if(d>mv){
            printf("\t\tERRO: miss\n");
        }
        if(d<=mv){
            printf("\t\tAlocado a pagina na mp\n");
            mp[u]=my[d];
            u++;
        }
        if(d>mv){
            printf("\t\tERRO: tamanho excedido na mp\n");
        }
        printf("\t\tDeseja imprimir os enderecos da nossa mp?\n");
        printf("\t\tDigite 's' para sim e 'n' para nao\n");
        fflush(stdin);
        scanf("%c", &q);
        if(q=='s'){
            for(i=0; i<=u; i++){
                printf("\t\t%d\n", mp[i]);
            }
        }
        printf("\t\tDeseja continuar alocando?\n");
        printf("\t\tDigite 's' para sim e 'n' para nao\n");
        fflush(stdin);
        scanf("%c", &c);
        if(c=='s')&&(u<=20){
            MP();
        }
}