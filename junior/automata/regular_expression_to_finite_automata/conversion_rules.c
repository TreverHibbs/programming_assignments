#include"parser.h"

struct nfa nfa_concat(struct node **top){
    struct transition *newTransition = (struct transition*)malloc(sizeof(struct transition));

    struct nfa nfa2 = pop(top);
    struct nfa nfa1 = pop(top);

    newTransition->state1 = nfa1.finalState;
    newTransition->state2 = nfa1.finalState+1;
    newTransition->symbol = 0;

    nfa1.finalState = adjust_transitionPointer(nfa2.transitionPointer, newTransition->state2);

    printf("nfa1.finalState = %i\n", nfa1.finalState);
    add_to_end(nfa1.transitionPointer, newTransition);

    newTransition->nextTransitionPointer = nfa2.transitionPointer;

    return(nfa1);
}

void create_nfa_that_accepts_c(struct node **top, char c){
    struct nfa newNfa;
    struct transition *transition1 = (struct transition*)malloc(sizeof(struct transition));
    
    transition1->state1 = 1;
    transition1->state2 = 2;

    if(c == 'a'){
        transition1->symbol = 1;
    }else if (c == 'b'){
        transition1->symbol = 2; 
    }else if (c == 'c'){
        transition1->symbol = 3; 
    }else if (c == 'd'){
        transition1->symbol = 4; 
    }else if (c == 'e'){
        transition1->symbol = 5; 
    }


    newNfa.startState = transition1->state1;
    newNfa.finalState = transition1->state2;
    newNfa.transitionPointer = transition1;
    newNfa.transitionPointer->nextTransitionPointer = NULL;
    push(newNfa, top);
}