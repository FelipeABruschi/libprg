#include "libprg/libprg.h"
#define max(a,b) (((a) > (b)) ? (a) : (b))

// retorna a altura da subárvore
int altura(no_avl *v)
{
    if (v == NULL)
        return 0;
    else
        return v->altura;
}

// negativo se a subárvore direita for maior
int fator_balanceamento(no_avl *v)
{
    if (v == NULL)
        return 0;
    else
        return altura(v->esquerda) - altura(v->direita);
}

no_avl *rotacao_esquerda(no_avl *v)
{
    no_avl *u = v->direita;
    v->direita = u->esquerda;
    u->esquerda = v;
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;

    return u;
}

no_avl *rotacao_direita(no_avl *v)
{
    no_avl *u = v->esquerda;
    v->esquerda = u->direita;
    u->direita = v;
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;

    return u;
}

no_avl *rotacao_dupla_direita(no_avl *v)
{
    v->esquerda = rotacao_esquerda(v->esquerda);

    return rotacao_direita(v);
}

no_avl *rotacao_dupla_esquerda(no_avl *v)
{
    v->direita = rotacao_direita(v->direita);

    return rotacao_esquerda(v);
}