#include "data.h"
#include <stdlib.h>
#include <stdbool.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    if(base<2 || base>16){
        return 0;
    }
    bool isNegative = false;
    if(data < 0){
        isNegative = true;
        if (data == INT32_MIN) {
        data = INT32_MAX; 
        } 
        else {
            data = -data; 
        }
    }
    uint32_t res = 0;
    unsigned char i = 1;
    uint8_t * array = malloc(sizeof(uint8_t) * i);
    *(array + (i - 1)) = '\0';

    do{
        uint8_t * temp = realloc(array, sizeof(uint8_t) * ++i);
        if(temp == 0){
            free(array);
            return 0;
        }
        array = temp;
        res = data % base;
        data /= base;
        *(array + (i - 1)) = (res < 10) ? (res + '0') : (res - 10 + 'A');
    }while(data > 0);

    if(isNegative == true){
        uint8_t * temp = realloc(array, sizeof(char) * ++i);
        if(temp == 0){
            free(array);
            return 0;
        }
        array = temp;
        *(array + (i - 1)) = '-';
    }

    uint8_t * start = array;
    uint8_t * end = array + (i - 1);

    while (start < end) {
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    ptr = array;
    return *ptr;

}
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    if(base < 2 || base > 16){
        return 0;
    }

    bool isNegative = false;
    if(*ptr == '-'){
        isNegative = true;
        ptr = ptr + 1;
        digits -= 1;
    }
    int32_t val = 0;
    int32_t temp;
    for(unsigned char i=0;i<digits-1;i++){
        if(*(ptr + i) >= 'A' && *(ptr + i) <= 'F'){
            temp = *(ptr + i) - 'A' + 10;
        }
        else{
            if(*(ptr + i) >= '0' && *(ptr + i) <= '9'){
                temp = *(ptr + i) - '0';
            }
            else{
                return 0;
            }
        }
        if(temp >= base){
            return 0;
        }
        
        val = val*base + temp;
    } 

    if(isNegative){
        val = -(val);
    }
    return val;
}