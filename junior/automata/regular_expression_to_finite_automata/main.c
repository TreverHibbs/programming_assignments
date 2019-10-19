#include "parser.h"

void main(int argc, char *argv[]){

    struct nfa nfa1; //= (struct nfa*)malloc(sizeof(struct nfa));
    struct nfa nfa2; //= *
    struct node tmp;
    struct node *pointer = &tmp;
    struct node **top = &pointer;

    int length = 100;
    char regex[length];
    char c;
    int var = 1;
    
    FILE *fp; 
    fp = fopen(argv[1], "r");

    while(fgets(regex, length, (FILE*)fp)){
        int i = 0;
        while(regex[i] != '\n'){ 
            c = regex[i];
            //test code
            //printf("this is regex %s", regex);
            //printf("this is c %c\n", c);
            if (c == '&'){ 
                struct nfa newNfa = nfa_concat(top);
                push(newNfa, top);

            } else if (c == '|') { 
                //nfa2= pop();
                //nfa1= pop();
                //push(NFAthat accepts L(nFA1) |L(nFA2));
                
            } else if (c == '*') { 
                //nfa1 = pop();
                //push(NFAthat accepts L(nFA)star);
            } else{
                //create nfa that accepts c
                create_nfa_that_accepts_c(top, c);
            }
            i++;    
        }

    }

    print_nfa(top);
}
