// tac.c — stampa le righe di un file in ordine inverso
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line {
    char *s;
    struct line *next;
};

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Missing file name\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File does not exist\n");
        return 1;
    }

    char buf[1024];
    struct line *head = NULL;

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        struct line *l = malloc(sizeof(struct line));
        if (!l) return 1;

        size_t linelen = strlen(buf);
        l->s = malloc(linelen + 1);
        if (!l->s) return 1;

        for (size_t j = 0; j <= linelen; j++) {
            l->s[j] = buf[j];          // copia inclusivo del '\0'
        }

        l->next = head;                // push in testa per invertire l’ordine
        head = l;
    }
    fclose(fp);

    while (head != NULL) {
        printf("%s", head->s);

        struct line *next = head->next;
        free(head->s);
        free(head);
        head = next;
    }

    return 0;
}
