#include <stdio.h>
#include "./listas_simples/listasSimples.h"
#include "./linked_lists/linkedLists.h"

int main(){
    LinkedList *l = create_linked_lst();

    insert_begin_lk(&l, 3);
    insert_begin_lk(&l, 3);
    insert_begin_lk(&l, 3);
    
    l = remove_end_lk(l);

    show_lk(l);
}