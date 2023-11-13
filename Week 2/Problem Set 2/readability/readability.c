#include <cs50.h>
#include <stdio.h>

float calcReadability(float word, float phrase);

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string phrase = get_string("Text: ");

    /*
    printf("%i letters\n", count_letters(phrase));
    printf("%i words\n", count_words(phrase));
    printf("%i sentences\n", count_sentences(phrase));
    */

    float countLetter = count_letters(phrase);
    float countWord = count_words(phrase);
    float countPhrase = count_sentences(phrase);

    // Calc avarage
    float avarageWord = (float) countLetter / (float) countWord * 100.0;
    float avaragePhrase = (float) countPhrase / (float) countWord * 100.0;
    float final_index = calcReadability(avarageWord, avaragePhrase);
    /*
    printf("Avarage Word: %.2f\n", avarageWord);
    printf("Avarage Phrase: %.2f\n", avaragePhrase);
    printf("\n");
    */
    if (final_index < 16 && final_index > 1)
        printf("Grade %.0f\n", final_index);
    else if (final_index <= 1)
        printf("Before Grade 1\n");
    else
        printf("Grade 16+\n");

    return 0;
}

float calcReadability(float word, float phrase)
{
    float index = 0.0588 * word - 0.296 * phrase - 15.8;

    return index;
}

int count_letters(string text)
{
    int countLetter = 0;
    int i = 0;
    while (text[i] != 0)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
            countLetter++;

        i++;
    }

    return countLetter;
}

int count_words(string text)
{
    int countWord = 1;
    int i = 0;
    while (text[i] != 0)
    {
        if (text[i] == 32 && text[i + 1] != 32)
            countWord++;
        i++;
    }

    return countWord;
}

int count_sentences(string text)
{
    int countPhrase = 0;
    int i = 0;
    while (text[i] != 0)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
            countPhrase++;
        i++;
    }

    return countPhrase;
}