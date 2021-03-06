#include <stdio.h>
#include <stdlib.h>


#include "EstruturaVetores.h"

Elemento *vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){

    posicao--;
    int retorno = 0;
    
    if(posicao<0 || posicao>=TAM){     
        retorno = POSICAO_INVALIDA;
    }else if(tamanho < 1){
        retorno = TAMANHO_INVALIDO;
    }else if(existiEstrutura(posicao)){         
        retorno = JA_TEM_ESTRUTURA_AUXILIAR; 
    }else{

        for(int i = 0; i<tamanho ;i++){
            vetorPrincipal[posicao] = lst_cria(vetorPrincipal[posicao]);
        }

        if(vetorPrincipal[posicao] == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
        }else{
            retorno = SUCESSO;
        }
    }
    
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
    
    int retorno = 0;
    posicao--;

    if(posicao<0 || posicao>= TAM){
          retorno = POSICAO_INVALIDA;
    }else{
        // testar se existe a estrutura auxiliar
        if (existiEstrutura(posicao)){
           
            if (existiEspaco(posicao)){
                //insere
                lst_insercaoDeElementos(vetorPrincipal[posicao], valor);
                retorno = SUCESSO;
            }else{
                retorno = SEM_ESPACO;
            }
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int excluirNumeroDoFinaldaEstrutura(int posicao){
    posicao--;
    int retorno = 0;

    if(posicao<0 || posicao>=TAM){
        retorno = POSICAO_INVALIDA;
    }else if(existiEstrutura(posicao)){
        
        if (!temConteudo(vetorPrincipal[posicao])){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }else{
            Elemento* l = vetorPrincipal[posicao];
            Elemento* x;
            while (l != NULL){  
                x = l ->prox;              
                if(l->prox ==NULL || x->inicializada == 0){
                    vetorPrincipal[posicao] = lst_retira(vetorPrincipal[posicao],l->conteudo);
                    l =NULL;
                }else{
                    l = l -> prox;       
                }
                
            }

            realocamento(vetorPrincipal[posicao]);
            retorno = SUCESSO;
        }

    }else{
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    
    posicao--;
    int retorno = 0;

    if(posicao<0 || posicao>=TAM){
        retorno = POSICAO_INVALIDA;
    }else if(!existiEstrutura(posicao)){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
         if (!temConteudo(vetorPrincipal[posicao])){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }else{
            if(existeNumero(vetorPrincipal[posicao],valor)){
                vetorPrincipal[posicao] = lst_retira(vetorPrincipal[posicao],valor);
                realocamento(vetorPrincipal[posicao]);
                retorno = SUCESSO;
            }else{
                retorno = NUMERO_INEXISTENTE;
            }
            
        }
    }

    return retorno; 
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    posicao--;
    int retorno = 0, incremento =0;

    if(posicao<0 || posicao>=TAM){
        retorno = POSICAO_INVALIDA;
    }else if(!existiEstrutura(posicao)){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        Elemento * aux = vetorPrincipal[posicao];

        while(aux !=NULL){
            if(aux->inicializada == 1){
                vetorAux[incremento] = aux->conteudo;
                incremento++;
            }
            aux = aux->prox;
        }
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    
    int retorno = 0;
    int tamanho =0;
    retorno= getDadosEstruturaAuxiliar(posicao, vetorAux);

    if(retorno == SUCESSO){

        tamanho = getQuantidadeElementosEstruturaAuxiliar(posicao);
        ordenar(vetorAux, tamanho);   
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno = 0,incremento = 0;

    for(int i = 0 ; i< TAM; i++){
        Elemento* aux = vetorPrincipal[i];

        if(existiEstrutura(i)){
            while(aux !=NULL){
                if(aux->inicializada){
                    vetorAux[incremento] = aux->conteudo;
                    incremento++;
                }
                aux = aux->prox;
            }
        }
    }

    if(incremento){
        retorno = SUCESSO;
    }else{
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int tamanho = 0;
    int retorno =  getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if(retorno == SUCESSO){
       
        for(int i = 0 ; i<TAM;i++){
           if(vetorPrincipal[i] != NULL && vetorPrincipal[i]->inicializada){
               tamanho+=getQuantidadeElementosEstruturaAuxiliar(i+1);
           }
        }
        ordenar(vetorAux, tamanho); 
    }
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0, validade = 0;
    posicao--;
    novoTamanho = getTamanhoDaEstruturaAuxilia(posicao) + novoTamanho;
   
    if(posicao <0 || posicao>=TAM){
        retorno = POSICAO_INVALIDA;
    }else if(novoTamanho<1){
        retorno = NOVO_TAMANHO_INVALIDO;
    }else if(!existiEstrutura(posicao)){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{

        Elemento * aux = vetorPrincipal[posicao];
        vetorPrincipal[posicao] = NULL;

        for(int i = 0; i<novoTamanho ;i++){
            vetorPrincipal[posicao] = lst_cria(vetorPrincipal[posicao]);
        }

        if(vetorPrincipal[posicao] == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
            vetorPrincipal[posicao] = aux;
        }else{

            while(aux!= NULL){
                if(aux ->inicializada){
                    validade = inserirNumeroEmEstrutura(posicao +1,aux ->conteudo);

                    if(validade!=SUCESSO){
                        retorno = validade;
                        aux = NULL;
                    }else{
                       aux = aux ->prox;  
                    }
                }else{
                  aux = aux ->prox;  
                }
              
            }
            retorno = SUCESSO;
        }

    }
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    int retorno = 0, quantidade = 0;
    posicao --;

    if(posicao<0 || posicao>TAM){
        retorno = POSICAO_INVALIDA;
    }else if(!existiEstrutura(posicao)){
        retorno =SEM_ESTRUTURA_AUXILIAR;
    }else{
        Elemento* l = vetorPrincipal[posicao];

        while(l!=NULL){

            if(l->inicializada){
                quantidade++;
            }
            l = l->prox;
        }

        retorno = quantidade;
    }

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote(){
    No* lista = NULL;
    int tamanho = 0, validade;
 
    for(int i = 0 ; i<TAM;i++){
        if(vetorPrincipal[i] != NULL && vetorPrincipal[i]->inicializada){
            tamanho+=getQuantidadeElementosEstruturaAuxiliar(i+1);
        }
    }
   
    int vetor[tamanho];
    
    validade = getDadosDeTodasEstruturasAuxiliares(vetor);

    for(int i = tamanho-1 ; i>=0 ; i--){
        lista = no_insere(lista,vetor[i]);
    }

    return lista;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){
    No* l = inicio;
    int i = 0;

    while(l!=NULL){
        vetorAux[i] = l->conteudo;
        i++;
        l = l->prox; 
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio){
    
    No* p = *inicio;
    while(p !=NULL){
        No * t = p->prox;
        free(p);
        p = t;
    }

    *inicio = NULL;
}



No* no_insere(No* no , int i){

    No* novo = (No*) malloc (sizeof(No));
    novo->conteudo = i;
    novo ->prox = no;
    return novo; 
}


void inicializar(){
    for(int i = 0 ; i< TAM ; i++){
        vetorPrincipal[i] = NULL;
    }
}

void finalizar(){
    for(int i = 0 ; i<TAM ;i++){
        lst_libera(&vetorPrincipal[i]);
    }
}

void lst_libera(Elemento** l){
    Elemento* p = *l;
    while (p!= NULL){
        Elemento* t = p ->prox;
        free(p);
        p =t;
    }
    
}

int existiEstrutura(int posicao){return vetorPrincipal[posicao]!= NULL;}

int temConteudo(Elemento *l){return l->inicializada == 1;};

int existiEspaco(int posicao){
    int retorno = 0;
  
    Elemento* l = vetorPrincipal[posicao];
  
    while(l != NULL){
        if(l->inicializada == 0){
            retorno =1;
            break;
        }
        l = l->prox;
    }
    return retorno;
}

Elemento* lst_cria(Elemento *l){
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo ->inicializada = 0;
    novo ->prox = l;
    return novo;
}

void lst_insercaoDeElementos(Elemento *l, int numero){
    
    while(l != NULL){
        if(l->inicializada == 0){
            l ->conteudo = numero;
            l -> inicializada =1;
            break;
        }

        l = l->prox;
    }
}

void lst_retiraFinalElemento(Elemento* l){
    while (l != NULL){
        printf("a");
        if((l->inicializada == 1 && l->prox->inicializada ==0) || (l->prox ==NULL)){
            l = lst_retira(l,l->conteudo);
            break;
        }
        l = l->prox;
    }
}

int existeNumero(Elemento* l, int v){
    Elemento* ant = NULL; 
    Elemento* p = l;


    while(p!= NULL && p ->conteudo != v){
        ant = p;
        p = p ->prox;
    }

    if(p==NULL) return 0;
    else return 1;
}

Elemento* lst_retira(Elemento* l,int v){
    Elemento* ant = NULL; 
    Elemento* p = l;


    while(p!= NULL && p ->conteudo != v){
        ant = p;
        p = p ->prox;
    }

    if(p==NULL) return 0;

    if(ant == NULL){
        l = p->prox;
    }else{
        ant ->prox = p->prox;
    }

    free(p);
    return l;
}

void realocamento(Elemento* l){
    
    Elemento* ant = NULL;
    Elemento* p = l;
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    

    while(p != NULL){
        ant = p;
        p = p->prox;
    }

    novo ->inicializada = 0;
    novo ->prox = NULL;

    ant->prox = novo;
}

void ordenar(int vetor[], size_t tamanho) {
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = i + 1; j < tamanho; ++j) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int getTamanhoDaEstruturaAuxilia(int posicao){
    int quantidade = 0;
    Elemento * l = vetorPrincipal[posicao];

    while(l!=NULL){
        quantidade ++;
        l= l->prox;
    }

    return quantidade;
}