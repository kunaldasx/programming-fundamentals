// C program to check whether a character is a vowel or consonant
#include <stdio.h>

int main()
{
    char ch;
    printf("Enter an Alphabet \n");
    scanf("%ch", &ch);
    if ((ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'))

    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("Vowel \n");
            break;
        default:
            printf("Consonant \n");
        }
    }
    else
    {
        printf("Error!Non Alphabetic Character");
    }
    return 0;
}