#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H
#define TAM 10

enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };


typedef struct lst {
    int conteudo;
    int inicializada;
    struct lst *prox;
} Vetor;


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
void lst_libera(Vetor **l);

int existiEstrutura(int posicao);
int existiEspaco(int posicao);
int temConteudo(Vetor* l);
Vetor* criar_lista(Vetor* l);
Vetor* lst_retira(Vetor* l,int v); 
void inserir_elemento(Vetor *l, int numero);
void lst_retiraFinalElemento(Vetor* l);
void ordenar(int vetor[], size_t tamanho);
int existeNumero(Vetor* l, int v);
void realocamento(Vetor* l);




#endif  // TRABALHO2_ESTRUTURAVETORES_H