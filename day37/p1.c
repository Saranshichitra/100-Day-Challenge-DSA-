#include <stdio.h>
#include <string.h>

int var[100];
int size = 0;

void insert(int x)
{
    var[size] = x;
    size++;
}

void deletePQ()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }
    int min = 0;
    for(int i = 1; i < size; i++)
    {
        if(var[i] < var[min])
            min = i;
    }
    printf("%d\n", var[min]);
    for(int i = min; i < size-1; i++)
        var[i] = var[i+1];
    size--;
}

void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }
    int min = 0;
    for(int i = 1; i < size; i++)
    {
        if(var[i] < var[min])
            min = i;
    }
    printf("%d\n", var[min]);
}

int main()
{
    int n, x;
    char op[10];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);
        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0)
        {
            deletePQ();
        }
        else if(strcmp(op, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}