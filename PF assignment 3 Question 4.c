#include<stdio.h>
#include<string.h>

struct Book
{
    int id;
    int popularity;
    int recent;
};

void accessBook(struct Book shelf[], int size, int id, int *time)
{
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if(shelf[i].id == id)
        {
            (*time)++;
            shelf[i].recent = *time;

            printf("%d\n", shelf[i].popularity);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("-1\n");
    }
}

void addBook(struct Book shelf[], int *size, int capacity,
             int id, int popularity, int *time)
{
    for(int i = 0; i < *size; i++)
    {
        if(shelf[i].id == id)
        {
            shelf[i].popularity = popularity;

            (*time)++;
            shelf[i].recent = *time;

            return;
        }
    }

    if(*size < capacity)
    {
        shelf[*size].id = id;
        shelf[*size].popularity = popularity;

        (*time)++;
        shelf[*size].recent = *time;

        (*size)++;
    }
    else
    {
        int lru = 0;

        for(int i = 1; i < *size; i++)
        {
            if(shelf[i].recent < shelf[lru].recent)
            {
                lru = i;
            }
        }

        shelf[lru].id = id;
        shelf[lru].popularity = popularity;

        (*time)++;
        shelf[lru].recent = *time;
    }
}

int main()
{
    int capacity, Q;

    scanf("%d %d", &capacity, &Q);

    struct Book shelf[1000];

    int size = 0;
    int time = 0;

    for(int i = 0; i < Q; i++)
    {
        char operation[10];

        scanf("%s", operation);

        if(strcmp(operation, "ADD") == 0)
        {
            int id, popularity;

            scanf("%d %d", &id, &popularity);

            addBook(shelf, &size, capacity,
                    id, popularity, &time);
        }
        else if(strcmp(operation, "ACCESS") == 0)
        {
            int id;

            scanf("%d", &id);

            accessBook(shelf, size, id, &time);
        }
    }

    return 0;
}