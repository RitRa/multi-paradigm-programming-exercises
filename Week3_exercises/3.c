#include <stdio.h>
int main()
{
    char name;
    printf("What is your name?");
    //fgets(name,20,stdin);
    fgets(name);

    if(strcmp(name, "Alice")==0)
    {
        printf("Hello %s\n", name);
    } else
    {
        printf("Hello lowly peasants!";
    }

    return 0;
}


 ⁨Users⁩/⁨ritaraher/Dropbox⁩/SWO-prototype⁩/⁨05_code⁩/scrapping
