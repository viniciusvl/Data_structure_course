This directory has 4 variants of lists:

    - Simple: implemented with static array and maximum size predefined

    - Singly: size is dinamyc, i.e, implemented with pointers, where each node pointer to the next node

    - Doubly: size is dinamyc, eache node has 2 pointers: to the last and next node 

    - Circular: size is dinamyc, the last node apointers to the first node

----------------------------- GENERAL EXPLICATIONS -------------------------------

**Cache misses**: Lists are bad to perfomance because of cache miss, i.e. CPU can not make cache, because nodes in a list are not contiguos in memory. Therefore, CPU need more process to get the information 
