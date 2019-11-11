#include <stdio.h>

struct heap_node    //struct for min. node for hoffmann tree(with all information)
{
    char ch;
    unsigned freq;
    struct heap_node* left, *right;
};

struct min_heap     //minimalnaja ku4a vseh listjev dereva, nuzna dlj9 organizacii priority queue
{
    unsigned size; // actual size of ku4a
    unsigned capacity;
    struct heap_node** array;   //heap_node pointers
};

unsigned int freq[256] = {0};
struct heap_node symbols[256] = {0}; //init array of all possible nodes
int uniq_sym_qounter = 0; //variable for count how much uniq simbols are used
int all_sym_counter = 0;

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
    return 0;
}


