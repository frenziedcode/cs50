#include <cs50.h>
#include <stdio.h>

string replace(string a);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR\n");
        return 1;
    }
    else
    {
        string final = argv[1];
        printf("%s\n", replace(final));
    }

    return 0;
}

string replace(string a)
{
    int i = 0;
    while (a[i] != 0)
    {
        if (a[i] == 'a')
            a[i] = '6';
        else if (a[i] == 'e')
            a[i] = '3';
        else if (a[i] == 'i')
            a[i] = '1';
        else if (a[i] == 'o')
            a[i] = '0';
        ++i;
    }

    return a;
}