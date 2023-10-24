#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char ALPHAB[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score1 < score2)
        printf("Player 2 wins!\n");
    else if (score1 == score2)
        printf("Tie!\n");
    // TODO: Print the winner
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int count_String = 0;
    int letter_Num = 0;

    int i = 0;
    int j = 0;
    while (word[i] != 0)
    {
        if (word[i] > 64 && word[i] < 91)
            word[i] = word[i] + 32;

        if ((word[i] > 64 && word[i] < 91) || (word[i] > 96 && word[i] < 123))
        {
            j = 0;
            while (word[i] != ALPHAB[j])
            {
                j++;
            }

            letter_Num = ALPHAB[j];

            if (word[i] == ALPHAB[j])
            {
                letter_Num = POINTS[j];
                count_String += letter_Num;
            }
        }
        else if (word[i] > 32 && word[i] < 47)
            letter_Num += 0;

        i++;
        j = 0;
    }

    return count_String;
}