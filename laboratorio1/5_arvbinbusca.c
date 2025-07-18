#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

int vazia(Arv* a)
{
  return a==NULL;
}

Arv* busca (Arv* r, int v)
{
  if (r == NULL) return NULL;
  else if (r->info > v) return busca(r->esq,v);
  else if (r->info < v) return busca(r->dir,v);
  else return r;
}


Arv* insere (Arv* a, int v)
{
  if (a==NULL) {
    a = (Arv*)malloc(sizeof(Arv));
    a->info = v;
    a->esq = a->dir = NULL;
  }
  else if (v < a->info)
    a->esq = insere(a->esq,v);
  else /* v < a->info */
    a->dir = insere(a->dir,v);
  return a;
}


Arv* libera (Arv* a){
  if (!vazia(a)){
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}


void imprime_in (Arv* r)
{
  if(!vazia(r)){
    
    if(r->esq != NULL){
      imprime_in(r->esq);
    }
    
    printf("%d ", r->info);

    if(r->dir != NULL){
      imprime_in(r->dir);
    }
    
  }
}



void main(void)
{
  Arv* a;
  a->info = 1;
  a->dir = NULL;
  a->esq = NULL;

  //insere(a,1);
  imprime_in(a);
  printf("\n\n");
 
  insere(a,2);
  imprime_in(a);
  printf("\n\n");

  insere(a,3);
  imprime_in(a);
  printf("\n\n");

  insere(a,5);
  imprime_in(a);
  printf("\n\n");
  
  insere(a,15);
  imprime_in(a);
  printf("\n\n");

  insere(a,7);
  imprime_in(a);
  printf("\n\n");


  if(busca(a,2) != NULL)
    printf("Elemento 2 encontrado na árvore.\n");
  else
    printf("Elemento 2 não encontrado na árvore.\n");

  if(busca(a,8) != NULL)
    printf("Elemento 8 encontrado na árvore.\n");
  else
    printf("Elemento 8 não encontrado na árvore.\n");
}
