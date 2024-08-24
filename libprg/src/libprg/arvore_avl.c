    #include "libprg/libprg.h"
#define max(a,b) (((a) > (b)) ? (a) : (b))

no_avl *criar_no(int valor)
{
    no_avl *no = malloc(sizeof(no_avl));

    if(no)
    {
        no->valor = valor;
        no->esquerda = NULL;
        no->direita = NULL;
        no->altura = 0;
    }
    else
        no = NULL;

    return no;
}
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

no_avl *balancear(no_avl *v)
{
    int fb = fator_balanceamento(v);
    if (fb > 1) // nó desregulado tem filho desregulado à esquerda
    {
        if (fator_balanceamento(v->esquerda) > 0)   // caso esquerda−esquerda
            return rotacao_direita(v);
        else                                        // caso esquerda−direita
            return rotacao_dupla_direita(v);
    }
    else if (fb < -1)   // nó desregulado tem filho desregulado à direita
    {
        if (fator_balanceamento(v->direita) < 0) // caso direita−direita
            return rotacao_esquerda(v);
        else // caso direita−esquerda
            return rotacao_dupla_esquerda(v);
    }
    return v;
}

no_avl *inserir_no_avl(no_avl *v, int valor)
{
    if (v == NULL)
        v = criar_no(valor);
    else if (valor < v->valor)
        v->esquerda = inserir(v->esquerda, valor);
    else if (valor > v->valor)
        v->direita = inserir(v->direita, valor);

    v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
    v = balancear(v); // é necessário balancear após cada inserção
    return v;
}

no_avl *remover_no_avl(no_avl *raiz, int valor)
{
    if (raiz == NULL)
        return NULL;
    else if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else // valor == v−>valor
    {
        if (raiz->esquerda == NULL && raiz->direita == NULL) // nó folha (sem filhos)
        {
            free(raiz);
            return NULL;
        }
        else if (raiz->esquerda != NULL && raiz->direita != NULL) // nó com 2 filhos
        {
            no_avl *aux = raiz->esquerda;
            while (aux->direita != NULL)
                aux = aux->direita;
            raiz->valor = aux->valor;
            raiz->esquerda = remover(raiz->esquerda, aux->valor);
        }
        else // nó com apenas 1 filho
        {
            no_avl *aux;
            if(raiz->esquerda != NULL)
                aux = raiz->esquerda;
            else
                aux = raiz->direita;
            free(raiz);
            return aux;
        }
    }
    if (raiz != NULL) {
        raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));
        raiz = balancear(raiz); // é necessário balancear após cada remoção
    }
    return raiz;
}