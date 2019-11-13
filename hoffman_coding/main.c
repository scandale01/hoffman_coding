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

unsigned int freq[256] = {0};
just_node symbols[256] = {0}; //init array of all possible nodes
int uniq_sym_qounter = 0; //variable for count how much uniq simbols are used
int all_sym_counter = 0;

int compare(const void* a, const void* b);
void apply_freq_arr(just_node node_arr[], unsigned arr[], int size);

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
        for(int i=0; i <256; i++)       //creates table of frequency for elements
        {
            if (symbols[i].ch == ch)
            {
                freq[i]++;
                all_sym_counter++;
                break;
            }
            if (symbols[i].ch == 0)
            {
                symbols[i].ch = (unsigned char) ch;
                freq[i] = 1;
                uniq_sym_qounter++;
                all_sym_counter++;
            }
        }
    }
    apply_freq_arr(symbols, freq, 256);
    for(int i=0; i<256; i++)
    {
        printf("%d", symbols[i].freq);
    }
    qsort(symbols, 256, sizeof(unsigned), compare);
    printf("\n");
    for(int i=0; i<256; i++)
    {
        printf("%d", symbols[i].freq);
    }

    return 0;
}
int compare(const void* a, const void* b)
{
    int i1 = *(int*) a;
    int i2 = *(int*) b;
    if (i1 < i2) return -1;
    else if (i1 == i2) return 0;
    else return 1;
}



void apply_freq_arr(just_node node_arr[], unsigned arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        node_arr[i].freq= arr[i];
    }
}


