#include <stdio.h>
#include <pthread.h>

typedef struct {
    char symbol;
    int spaces;
    int linesCount;
    int symsCount;
} Values; 

void *print_sym(void *args) {
    Values *vals = (Values*)args;

    for (int i = 0; i < vals->spaces; ++i) {
        printf(" ");
    }
    for (int i = 0; i < vals->symsCount; ++i) {
        printf("%c ", vals->symbol);
    }

    putchar(10);
    return NULL;
}

int main() {
    pthread_t threads;
    Values values;

    puts("Input pyramid's lines count");
    scanf("%d", &values.linesCount);
    fflush(stdin);
    puts("Input symbol for create");
    scanf("%c", &values.symbol);

    int spacesCount = values.linesCount;
    
    for (int i = 0; i < values.linesCount; ++i) {
        values.spaces = --spacesCount;
        values.symsCount = i + 1;
        pthread_create(&threads, NULL, print_sym, (void*)&values);
        pthread_join(threads, NULL);
    }

    return 0;
}