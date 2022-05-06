#include <stdio.h>
#include <stdint.h>

int main( int argc, char** argv ) {
    uint32_t len = 0;
    scanf("%u", &len);
    
    uint32_t tmp = 0, past1 = 0, past2 = 0, length = 0, length_res = 0;
    uint32_t section_i = 0, section_i_res = 0;

    for (uint32_t i = 0; i < len; i++) {
        past2 = past1;
        past1 = tmp;
        scanf("%u", &tmp);
        length++;

        if (past2 == past1 && past1 == tmp && i > 1) {
            section_i = i - 1;
            length = 2;
        }
        
        if (length > length_res) {
            length_res = length;
            section_i_res = section_i;
        }
    }
    
    section_i_res++;
    printf("%u %u", section_i_res, section_i_res + --length_res);
}
