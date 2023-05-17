#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_tab - Prints an array of string
 * @tab: The array to print
 *
 * Return: nothing
 */
void print_tab(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; ++i)
    {
        printf("%s\n", tab[i]);
    }
}

/**
 * strtow - Split a string into words
 * @str: The input string
 *
 * Return: An array of strings (words)
 */
char **strtow(char *str)
{
    char **words = NULL;
    char *word = NULL;
    int word_count = 0;
    int i, j, k, len;

    if (str == NULL || *str == '\0')
        return NULL;

    len = strlen(str);

    /* Count the number of words */
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
            word_count++;
    }

    words = malloc((word_count + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    i = 0;
    j = 0;

    /* Split the string into words */
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            k = i;
            while (str[i] != ' ' && str[i] != '\0')
                i++;
            word = malloc((i - k + 1) * sizeof(char));
            if (word == NULL)
            {
                /* Free memory if allocation fails */
                for (i = 0; i < j; i++)
                    free(words[i]);
                free(words);
                return NULL;
            }

            strncpy(word, &str[k], i - k);
            word[i - k] = '\0';
            words[j] = word;
            j++;
        }
        else
        {
            i++;
        }
    }

    words[j] = NULL;  /* Set the last element to NULL */

    return words;
}

/**
 * main - check the code for ALX School students.
 *
 * Return: 1 if an error occurred, 0 otherwise
 */
int main(void)
{
    char **tab;

    tab = strtow("      ALX School         #cisfun      ");
    if (tab == NULL)
    {
        printf("Failed\n");
        return 1;
    }

    print_tab(tab);

    /* Free allocated memory */
    for (int i = 0; tab[i] != NULL; i++)
    {
        free(tab[i]);
    }
    free(tab);

    return 0;
}
