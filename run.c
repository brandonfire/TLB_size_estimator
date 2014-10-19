#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char command[20];
    strcpy(command,"./tlb 1 1000000000");
    system(command);
    strcpy(command,"./tlb 2 500000000");
    system(command);
    strcpy(command,"./tlb 4 250000000");
    system(command);
    strcpy(command,"./tlb 8 125000000");
    system(command);
    strcpy(command,"./tlb 16 6250000");
    system(command);
    strcpy(command,"./tlb 32 3125000");
    system(command);
    strcpy(command,"./tlb 64 1562500");
    system(command);
    strcpy(command,"./tlb 128 781250");
    system(command);
    strcpy(command,"./tlb 256 390625");
    system(command);
    strcpy(command,"./tlb 512 195315");
    system(command);
    strcpy(command,"./tlb 1024 97656");
    system(command);
    strcpy(command,"./tlb 2048 48828");
    system(command);
    return(0);

}
