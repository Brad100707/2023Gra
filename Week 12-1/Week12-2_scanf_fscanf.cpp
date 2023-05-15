#include <stdio.h>
int main()
{
    FILE * fin = fopen("file.txt", "r");

    char line[100];
    fscanf(fin, "%s", line);
    printf("從file.txt讀到了: %s\n", line);

    ///應為遇到空格會斷掉所以在加一行
    fscanf(fin ,"%s", line);
    printf("從file.txt讀到了: %s\n", line);
}
