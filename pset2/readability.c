#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text;
    float L, S; // 注意L和S的数据类型和保留位数，否则后面计算会出错

    text = get_string("Text: ");
    L = (float) count_letters(text) * 100 / count_words(text); // 右边基于text的计算，因为text是int，所以返回也会是int，需要改成float
    S = (float) count_sentences(text) * 100 / count_words(text);

    float index_f = round(0.0588 * L - 0.296 * S - 15.8);
    int index = (int) index_f; // 注意index需要四舍五入，不能只保留int部分

    printf("%s\n", text);
    printf("%i letters\n", count_letters(text));
    printf("%i words\n", count_words(text));
    printf("%i sentences\n", count_sentences(text));
    printf("float L: %f\n", L);
    printf("float S: %f\n", S);
    printf("float: %f\n", index_f);
    printf("index: %i\n", index);

    // if loop for "Before Grade 1" and "Grade 16+"
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Count letters
int count_letters(string text)
{
    int len_letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            len_letters++;
        }
    }
    return len_letters;
}

// Count words by counting spaces (ASCII = 32), # of words = # of spaces + 1
int count_words(string text)
{
    int len_words = 1;
    for (int j = 0, n = strlen(text); j < n; j++)
    {
        if (text[j] == 32)
        {
            len_words++;
        }
    }
    return len_words;
}

// Count sentences by counting .!? (ASCII = 46, 33, 63)
int count_sentences(string text)
{
    int len_sentences = 0;
    for (int k = 0, n = strlen(text); k < n; k++)
    {
        if (text[k] == 46 || text[k] == 33 || text[k] == 63)
        {
            len_sentences++;
        }
    }
    return len_sentences;
}