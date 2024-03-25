/* value of p pointer after free 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p;
    p = (int*)malloc(sizeof(int*));

    printf("%p\n", p);

    free(p);

    printf("%p\n", p);

    return 0;
}

/* output
000001CC53E67BC0
000001CC53E67BC0
*/