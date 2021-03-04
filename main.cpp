#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char* argv[]) {

    if (argc < 3) {
        printf("two parameters are necessary");
        return -1;
    }
    
    int size = atoi(argv[1]);
    int st = atoi(argv[2]);
    srand((unsigned)st);

    FILE *pFile;
    pFile = fopen("./data0", "w");

    if (pFile == NULL) {
        printf("open file failed!\n");
        return 1;
    }

    char buf[10];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 119304647; ++j) {
            int r = rand() % 1000000000;
            sprintf(buf, "%09d", r);
            fputs(buf, pFile);
        }
    }
    fclose(pFile);
    
    return 0;
}