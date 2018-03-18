/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <strings.h>
#include "dictionary.h"
unsigned int count = 0;
bool loaded = false;
//create node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
node* hashtable[65536];

//Hash function created by hathix
unsigned int hash_word(const char* word)
{
    unsigned long hash = 5381;
    for (const char* ptr = word; *ptr != '\0'; ptr++)
    {
        hash = ((hash << 5) + hash) + tolower(*ptr);
    }
    return hash % 65536;
}

char word[LENGTH + 1];
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int h = hash_word(word);
    node* cursor = hashtable[h];
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    for(int i = 0; i < 65536; i++)
    {
        hashtable[i] = NULL;
    }
    //open dictionary
    FILE* fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
        return false;
    }
    //iterate through the dictionary
    while(true)
    {
        //designate space for the word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        //scan for the word
        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;
        if(feof(fp))
        {
            free(new_node);
            break;
        }
        count++;
        //take each word and run it through the hash function
        int h = hash_word(new_node->word);
        node* head = hashtable[h];
        //place node into array
        if(head == NULL)
        {
            hashtable[h] = new_node;
        }
        //connect the node to the linked list
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
    }
    fclose(fp);
    loaded = true;
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if(loaded)
    {
        return(count);
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0; i < 65536; i++ )
    {
        node *cursor = hashtable[i];
        while(cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
    loaded = false;
}
