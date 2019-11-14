#include <stdio.h>
#include <stdlib.h>

struct heap_node    //struct for min. node for hoffmann tree(with all information)
{
    char ch;        //what character corrsponds to the node
    unsigned freq;     // how often used related to all characters
    struct heap_node* left, *right;
};
typedef struct heap_node just_node;

struct min_heap     //minimalnaja ku4a vseh listjev dereva, nuzna dlj9 organizacii priority queue
{
    unsigned size; // actual size of ku4a
    unsigned capacity;
    just_node** array;   //heap_node pointers
};
typedef struct min_heap min_heap;

unsigned int freq[256] = {0};
just_node symbols[256] = {0}; //init array of all possible nodes
int uniq_sym_qounter = 0; //variable for count how much uniq simbols are used
int all_sym_counter = 0;

int compare(const void* a, const void* b);
void fill_symbol_arr(just_node* psymbols, unsigned int* parr);


int main()
{
    FILE *fp; //*fpbt, *fpe;
    char* filename = "/home/slava/Systemprogramming/hoffman/hoffman_coding/abc.txt";
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Cannot open file\n");
        return 0;
    }

    int ch=0; //where we read character from file
    while ((ch = fgetc(fp)) != EOF) {
        freq[(unsigned)ch]++;
    }
    fill_symbol_arr(symbols, freq);
    qsort(symbols, 256, sizeof (symbols[0]), compare);
    for(int i=0; i<256; i++)
    {
        if(symbols[i].freq != 0)
        {
            printf("%d\n",symbols[i].freq);
        }
    }
    return 0;
}

int compare(const void* a, const void* b)
{
    const unsigned* ia = (const unsigned*)a;
    const unsigned* ib = (const unsigned*)b;
    return *ia - *ib;
}

void fill_symbol_arr(just_node* psymbols, unsigned int* parr)
{
    int i =0, j=0;
    for(;i<256;i++)
    {
        if(*(parr+i) != 0)
        {
            for(; j<256; j++)
            {
                (psymbols+j)->freq=*(parr+i);
            }
        }
    }
}


