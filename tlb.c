#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <linux/futex.h>
int x, i;
long Numpages;
long loops;
int pagesize;
long long l_n;
double tim;
int main(int argc, char* argv[])
{
    if(argc != 3) {
        fprintf(stderr, "ERROR please input two arguments number of pages and trails \n");
        exit(1);
    }
    cpu_set_t my_set;    
    CPU_ZERO ( &my_set );   
    CPU_SET(3, &my_set); 
    sched_setaffinity(0, sizeof(cpu_set_t), &my_set);
    Numpages = atoi(argv[1]);
    loops = atoi (argv[2]);
    pagesize = getpagesize();
    l_n = loops*Numpages;
    long long timeu;
    int jump = pagesize /sizeof(int);
    int *a;
    const long long arraycount = Numpages*jump;
    a = malloc(sizeof(int) * arraycount);
    if (!a) { 
    perror("Error when allocating memory");
    abort();
    }
    //printf("page size = %d , pagenum = %ld , trails = %ld, jump = %d, arraysize = %lld \n", pagesize, Numpages, loops, jump, arraycount);
    struct timeval start, end;
    gettimeofday(&start,NULL);
    for (x=0; x<loops; x++) {
        for (i = 0; i<Numpages*jump; i+=jump) {
            a[i]+=1;
        }
    }
    gettimeofday(&end,NULL);
    x+=1;
    i+=1;
    timeu=(end.tv_sec * 1000000 + end.tv_usec)- (start.tv_sec * 1000000 + start.tv_usec);
    tim = (double)timeu/(double)l_n;
    //printf("For %ld pagenums.total check %ld trails in %lldus (%fus/pagetable lookup)\n",
    //       Numpages,loops, timeu, ((double)timeu / (double)l_n));
    printf("<%ld>, <%fns> \n",Numpages,tim*1000);
}
