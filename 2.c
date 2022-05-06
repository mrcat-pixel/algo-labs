#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

struct stack_entry {
    uint8_t letter;
    int is_upper_case;
    uint16_t id;
};

struct tuple {
    uint16_t big;
    uint16_t small;
};

int main( int argc, char** argv ) {
    int ch;

    struct stack_entry* stack = malloc(sizeof(struct stack_entry) * 100000);
    uint16_t i_stack = 0;

    struct tuple* res_arr = malloc(sizeof(struct tuple) * 50000);
    uint16_t i_res = 0;

    uint16_t big_temp = 0;
    uint16_t small_temp = 0;

    while (1) {
        ch = fgetc(stdin);
        if (ch == '\n' || ch == EOF) break;

        stack[i_stack].letter = toupper(ch);
        stack[i_stack].is_upper_case = isupper(ch);
        if (stack[i_stack].is_upper_case) {
            big_temp++;
            stack[i_stack].id = big_temp;
        }
        else {
            small_temp++;
            stack[i_stack].id = small_temp;
        }

        if (
            (stack[i_stack-1].is_upper_case ^ stack[i_stack].is_upper_case)
            &&
            (stack[i_stack-1].letter == stack[i_stack].letter)
        ) {
            if (stack[i_stack-1].is_upper_case) 
                res_arr[i_res] = (struct tuple) {
                    .big = stack[i_stack-1].id,
                    .small = stack[i_stack].id
                };
            else
                res_arr[i_res] = (struct tuple) {
                    .big = stack[i_stack].id,
                    .small = stack[i_stack-1].id
                };
            i_res++;
            i_stack--;
        }
        else i_stack++;
    }

    free(stack);

    uint16_t* final_array = malloc( sizeof(uint16_t) * (i_res+1) );
    for (uint16_t i = 0; i < i_res; i++) {
        //printf("big: %u, small: %u\n", res_arr[i].big, res_arr[i].small);
        final_array[res_arr[i].big] = res_arr[i].small;
    }

    if (i_stack == 0) {
        printf("Possible\n");
        for (uint16_t i = 1; i < i_res+1; i++) {
            printf("%u ", final_array[i]);
        }
    }
    else printf("Impossible\n");

}