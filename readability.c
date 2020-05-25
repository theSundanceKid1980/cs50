#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(int length, string s);
int count_words(string s);
int count_sent(string s);

int main(void)
{
    int slen; /* total # of characters in string, including spaces and non-alpha characters */
    int txtlen=0; /* total # of alpha characters in the string */
    string txt = get_string("Text: ");
    slen = strlen(txt);

    int letters = count_letters(slen,txt);
    int words = count_words(txt);
    int sent = count_sent(txt);

    float avglet = (float) (100*letters)/words;
    float avgsent = (float) (100*sent)/words;

    int index = round(0.0588*avglet - 0.296*avgsent - 15.8);

    /* for debugging only
    printf("%i letter(s)\n", letters);
    printf("%i word(s)\n", words);
    printf("%i sentence(s)\n", sent);
    printf("Avg letters: %f\n", avglet);
    printf("Avg sentences: %f\n", avgsent);
    printf("raw index: %f\n", 0.0588*avglet - 0.296*avgsent - 15.8);
    */

    if (index < 16 && index > 1)
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

/* function to calculate total # of alpha characters in the string */
int count_letters(int length, string s)
{
    int txtlen=0;
    for (int i=0; i < length; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            txtlen++;
        }
    }
    return txtlen;
}

/* function to count the # of words in a text */
int count_words(string s)
{
    int len = strlen(s);
    int wordcount = 0;
    for (int i=0; i <= len; i++)
    {
        if ((s[i]==' ') || (s[i]=='\0'))
        {
            wordcount++;
        }
    }
    return wordcount;
}

/* function to count sentences in a text */
int count_sent(string s)
{
    int len = strlen(s);
    int sentcount = 0;
    for (int i=0; i <= len; i++)
    {
        if ((s[i]=='.') || (s[i]=='!') || (s[i]=='?'))
        {
            sentcount++;
        }
    }
    return sentcount;
}
