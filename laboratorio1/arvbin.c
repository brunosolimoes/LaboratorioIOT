#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
  return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad)
{
  Arv* p=(Arv*)malloc(sizeof(Arv));
  p->info = c;
  p->esq = sae;
  p->dir = sad;
  return p;
}

int vazia(Arv* a)
{
  return a==NULL;
}

Arv* libera (Arv* a){
  if (!vazia(a)){
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}

void imprime_pre (Arv* a)
{
  if(!vazia(a)){
    printf("%d ", a->info);
    imprime_pre(a->esq);
    imprime_pre(a->dir);
  }
}

void imprime_in (Arv* a)
{
  if(!vazia(a)){
    imprime_in(a->esq);
    printf("%d ", a->info);
    imprime_in(a->dir);
  }
}

void imprime_pos (Arv* a)
{
  if(!vazia(a)){
    imprime_pos(a->esq);
    imprime_pos(a->dir);
    printf("%d ", a->info);
  }
}

Arv* busca(Arv* a, int num){
  if(a==NULL){return NULL;} 

  

  return NULL;
}

Arv* enxerta(Arv* aMae, Arv* aFilhoAdotivo, int num, int sentido){
  Arv* pontoDoEnxerto = busca(aMae,num);


  if(pontoDoEnxerto==NULL){
    return NULL;
    }

  if(sentido==0){
    if(pontoDoEnxerto->esq==NULL){
      pontoDoEnxerto->esq = aFilhoAdotivo;
      return pontoDoEnxerto;
      }
    else{printf("NO ja tem filho esquedo"); 
          return NULL;}
  }else{
    if(sentido==1){
      pontoDoEnxerto->esq = aFilhoAdotivo;
      return pontoDoEnxerto;
    }
    else{printf("NO ja tem filho esquedo"); 
          return NULL;}
  }

}

Arv* poda(Arv* a, int num){
  
}

int main()
{

  printf("--------Questao 2--------\n");

  Arv* g = cria(67,inicializa(), inicializa());
  Arv* f = cria(40,inicializa(), inicializa());
  Arv* e = cria(34,inicializa(), g);
  Arv* d = cria(12,inicializa(), inicializa());
  Arv* c = cria(80,inicializa(), f);
  Arv* b = cria(05, d, e);
  Arv* a = cria(45, b, c);

  printf("Pre-fixado\n");
  imprime_pre(a);
  printf("\n\n");

  printf("In-fixado\n");
  imprime_in(a);
  printf("\n\n");

  printf("Pos-fixado\n");
  imprime_pos(a);
  printf("\n\n");

  printf("--------Questao 3--------\n");

  Arv* j = cria(31,inicializa(), inicializa());
  Arv* i = cria(66,inicializa(), inicializa());
  Arv* h = cria(3,i,j);
  
  enxerta(a,h,12,0);

  printf("Pre-fixado\n");
  imprime_pre(a);
  printf("\n\n");

  printf("In-fixado\n");
  imprime_in(a);
  printf("\n\n");

  printf("Pos-fixado\n");
  imprime_pos(a);
  printf("\n\n");

  libera(a);

  return 0;
}
