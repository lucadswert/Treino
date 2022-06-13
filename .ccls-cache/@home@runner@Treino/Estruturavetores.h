#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H
#define TAM 10

// enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que voce de significado
// as suas constantes, para mais informacoes https://en.cppreference.com/w/c/language/enum
// as constantes do enum em sua inicialização vao representar o numero resultante da soma do valor da
// constante anterior mais 1, caso nao haja valor algum na primeira constante ela vai ser inicializada com 0
enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };


typedef struct lst {
    int conteudo;
    int inicializada;
    struct lst *prox;
} Elemento;


typedef struct reg {
    int conteudo;
    struct reg *prox;
} No;


void inicializar();
int criarEstruturaAuxiliar(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
int getTamanhoDaEstruturaAuxilia(int posicao);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
void finalizar();

No *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
No* no_insere(No* l , int i);
void destruirListaEncadeadaComCabecote(No **inicio);
void lst_libera(Elemento **l);

int existiEstrutura(int posicao);
int existiEspaco(int posicao);
int temConteudo(Elemento* l);
Elemento* lst_cria(Elemento* l);
Elemento* lst_retira(Elemento* l,int v); 
void lst_insercaoDeElementos(Elemento *l, int numero);
void lst_retiraFinalElemento(Elemento* l);
void ordenar(int vetor[], size_t tamanho);
int existeNumero(Elemento* l, int v);
void realocamento(Elemento* l);




#endif  // TRABALHO2_ESTRUTURAVETORES_H