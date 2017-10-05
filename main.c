#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
//#include  <conio.h>

//___________________________________________ Estrutura ________________________________________

typedef struct Lista{
    char info[50];
    struct Lista *ant;
    struct Lista *prox;
    int ocorrencias;
}Lista;


//___________________________________________ Funções ________________________________________
//Cria uma nova lista
Lista *criaLista(){

    Lista *lista = (Lista*) malloc (sizeof(Lista));
    lista->ant = NULL;
    lista->prox = NULL;
    return lista;
}


//Insere um nó no começo da lista    FUNFANDO
Lista *insere(Lista *lista, char nome[]){
  int contador=1;
  int jaesta = 0;
  Lista *novo;
  int i=1;

  Lista *iterador = lista;




  while(iterador != NULL)
  {
    if( strcmp(iterador->info, nome) == 0 )
    {
        iterador->ocorrencias++;
        jaesta = 1;
        break;
    }

    iterador = iterador->prox;
  }

  if(jaesta == 0)
  {
    novo=(Lista*) malloc(sizeof(Lista));

    strcpy(novo->info, nome);
    novo->ocorrencias = 1;
    novo->prox = lista;
    novo->ant = NULL;

    if(lista != NULL)
        lista->ant = novo;

    return novo;
  }
  else //jaesta == 1
  {
    return lista;
  }


}


//Imprime todos os valores dos nós da lista
void imprime(Lista *lista){
  Lista *aux;

    while (lista->prox!=NULL){

        printf("\n\n\t\t\t%s: %d",lista->info, lista->ocorrencias);

        lista=lista->prox;
    }
}




//___________________________________________ Funções ________________________________________


int main(int argc, char *argv[]) {

/*
Lista *lista, *ListaArq;
FILE *arquivo, *auxArq, *stopWord;
char palavra[50];
char word[50];
lista = criaLista();
int contador = 0;
*/
 /* Abre o arquivo para leitura */
/*arquivo = fopen(argv[1], "r");
stopWord = fopen(argv[2], "r");


if (arquivo == NULL)
   printf("Erro, não foi possivel abrir o arquivo\n");

else{

    while(fscanf(arquivo,"%s",word)!= EOF){

        auxArq = fopen(word, "r");

        // Enquanto o arquivo for diferente de EOF
            while(fscanf(auxArq,"%s",palavra)!= EOF){
                //strcpy(word, palavra);
                lista = insere(lista, palavra);
            }

    }

    fclose(arquivo);

    }



printf("\n\n");
imprime(lista);
printf("\n\n");

getchar();

*/


FILE *base, *stopwords, *doc;
char termo [500], nomeDoc[500];
int contador = 1;

stopwords = fopen(argv[2], "r");

if (stopwords == NULL)
   printf("Erro, não foi possivel abrir o arquivo de stopwords\n");

else{

    while ( !feof(stopwords)){
        fscanf(stopwords, "%s", termo);
        // insere a ser implementado
        //insere(listaStopWords, termo);
    }
}

base = fopen(argv[1], "r");

if (base == NULL)
   printf("Erro, não foi possivel abrir o arquivo da Base\n");

else{

    while ( !feof(base)){
        fscanf(base, "%s", nomeDoc);

        doc = fopen(nomeDoc, "r");

        while ( !feof(doc)){
            fscanf(doc, "%s", termo);

            // testar se o termo aparece em listaStopWords

            if(/*se não aparecer*/)
                //inserir(lista, termo, contador)

            contador ++;
        }

    }
}







return 0;
}
