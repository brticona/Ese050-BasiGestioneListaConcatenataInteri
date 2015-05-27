#include <stdio.h>
#include <stdlib.h>

struct s_elemento {
    int valore;
    struct s_elemento*next;
    
};
typedef struct s_elemento elemento;

elemento* AggiungiElementoinTesta(elemento*,int valore);
void StampaLista(elemento* primo);
void SvuotaLista(elemento* primo);

int main(int argc, char** argv) {
    int valore;
    elemento* primo=NULL;
    valore = 1;
    while (valore != 0){
        printf("Inserisci un numero (0 per terminare):");
        scanf ("%d",&valore);
        if(valore != 0){
            primo = AggiungiElementoinTesta(primo,valore);
            if(primo == NULL){
                fprintf(stderr,"Impossibile allocare la memoria richiesta");
                exit(1);
            }
        }
    }

    StampaLista(primo);
    
    SvuotaLista(primo);
    
    return (EXIT_SUCCESS);
    
}

elemento * AggiungiElementoinTesta(elemento *primo,int valore) {
    elemento* nuovoelemento;
    nuovoelemento = (elemento*)malloc(sizeof(elemento));
    if (nuovoelemento != NULL){
        nuovoelemento->valore = valore;
        nuovoelemento->next = primo;
    }
    
    primo = nuovoelemento;
    
    return primo;
    
}
    void StampaLista(elemento* primo){
        printf("\nStampa della lista\n");
    
    elemento* temp;
    temp = primo;
    
    while(temp != NULL ){
        printf("%d\n",temp->valore);        
        temp=temp->next;        
        ;
    }
}

void SvuotaLista(elemento* primo){
    elemento* temp=NULL;
    
    while(primo){
        temp=temp->next;
        free(temp);
        
    }
}

