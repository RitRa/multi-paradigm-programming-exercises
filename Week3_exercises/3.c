#include <stdio.h>
#include <string.h>


int main()
{
    char* name;

    printf("What is your name?");

    //fgets(name,stdin);
    gets(name);

// strcmp ->string comparison
    if((strcmp(name, "Alice")==0) || (strcmp(name, "Bob")==0))
    {
        printf("Hello %s", name);
    } else
    {
        printf("Hello lowly peasants!");
    }

    return 0;
}
