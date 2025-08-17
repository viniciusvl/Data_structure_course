#include <stdio.h>
#include "./lists/simple_lists/simpleLists.h"
#include "./lists/linked_lists/linkedLists.h"

int main(){
    LinkedList *l = create_linked_lst();

    insert_begin_lk(&l, 3);
    insert_begin_lk(&l, 4);
    insert_begin_lk(&l, 5);
    
    show_lk_rec_reverse(l);
}