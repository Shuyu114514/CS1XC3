#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int simpleParse(const char *exp){
    int flag_plus = 0;
    int flag_mult = 0;
    int flag_minus = 0;
    int flag_div = 0;
    int flag_mod = 0;
    int sign_1_empty = 0;
    int sign_2_empty = 0;
    int flag_plus_2 = 0;
    int flag_mult_2 = 0;
    int flag_minus_2 = 0;
    int flag_div_2 = 0;
    int flag_mod_2 = 0;
    char s_a[21];
    char s_b[21];
    char s_c[21];
    int a = 0;
    int b = 0;
    int c = 0;
    int temp = 0;
    int position = 0;
    int a_empty = 0;
    int b_empty = 0;
    int c_empty = 0;
    int i = 0;
    int j = 0;

    while(exp[i] != '\0'){
        if(isdigit(exp[i]) && a_empty == 0){
            while(isdigit(exp[i])){
                s_a[position] = exp[i];
                position+=1;
                i+=1;
            }
            s_a[position] = '\0';
            a = atoi(s_a);
            a_empty = 1;
            position = 0;
            //printf("a: %d\n", a);
        }
        
        if(isdigit(exp[i]) && a_empty == 1 && b_empty == 0){
            while(isdigit(exp[i])){
                s_b[position] = exp[i];
                position+=1;
                i+=1;
            }
            s_b[position] = '\0';
            b = atoi(s_b);
            b_empty = 1;
            position = 0;
            //printf("b: %d\n", b);
        }
        
        if(isdigit(exp[i]) && b_empty == 1){
            while(isdigit(exp[i])){
                s_c[position] = exp[i];
                position+=1;
                i+=1;
            }
            s_c[position] = '\0';
            c = atoi(s_c);
            c_empty = 1;
            position = 0;
            //printf("c: %d\n", c);
        }

        //printf("a: %d b: %d c: %c\n", a, b, c);
        
        if(c_empty == 1 && b_empty == 1 && a_empty == 1){
            if(sign_1_empty == 2 || (sign_1_empty == 1 && sign_2_empty == 1)){
                if(flag_plus == 1){
                    temp = a + b;
                    a = temp;
                    b = c;
                    c_empty = 0;
                    flag_plus = 0;
                }else if( flag_minus == 1){
                    temp = a - b;
                    a = temp;
                    b = c;
                    c_empty = 0;
                    flag_minus = 0;
                }else if( flag_mult == 1){
                    temp = a * b;
                    a = temp;
                    b = c;
                    c_empty = 0;
                    flag_mult = 0;
                }else if( flag_div == 1){
                    temp = a / b;
                    a = temp;
                    b = c;
                    c_empty = 0;
                    flag_div = 0;
                }else if( flag_mod == 1){
                    temp = a % b;
                    a = temp;
                    b = c;
                    c_empty = 0;
                    flag_mod = 0;
                }
                flag_plus = flag_plus_2;
                flag_minus = flag_minus_2;
                flag_mult = flag_mult_2;
                flag_div = flag_div_2;
                flag_mod = flag_mod_2;
                flag_plus_2 = 0;
                flag_minus_2 = 0;
                flag_mult_2 = 0;
                flag_div_2 = 0;
                flag_mod_2 = 0;
                sign_1_empty = sign_2_empty;
                sign_2_empty = 0;
            }else{
                if( flag_mult_2 == 1){
                    temp = b * c;
                    b = temp;
                    c_empty = 0;
                    flag_mult_2 = 0;
                }else if( flag_div_2 == 1){
                    temp = b / c;
                    b = temp;
                    c_empty = 0;
                    flag_div_2 = 0;
                }else if( flag_mod_2 == 1){
                    temp = b % c;
                    b = temp;
                    c_empty = 0;
                    flag_mod_2 = 0;
                }
                sign_2_empty = 0;
            }
            //printf("result: %d\n", a);
        }
        //printf("flag 1: %d %d %d %d %d\nflag 2: %d %d %d %d %d\n", flag_plus, flag_minus, flag_mult, flag_div, flag_mod, flag_plus_2, flag_minus_2, flag_mult_2, flag_div_2, flag_mod_2);
        
        if(sign_1_empty == 0){
            if(exp[i] == '+'){
                flag_plus = 1;
                sign_1_empty = 1;
            }else if(exp[i] == '-'){
                flag_minus = 1;
                sign_1_empty = 1;
            }else if(exp[i] == '*'){
                flag_mult = 1;
                sign_1_empty = 2;
            }else if(exp[i] == '/'){
                flag_div = 1;
                sign_1_empty = 2;
            }else if(exp[i] == '\%'){
                flag_mod = 1;
                sign_1_empty = 2;
            }
        }else{
            if(exp[i] == '+'){
                flag_plus_2 = 1;
                sign_2_empty = 1;
            }else if(exp[i] == '-'){
                flag_minus_2 = 1;
                sign_2_empty = 1;
            }else if(exp[i] == '*'){
                flag_mult_2 = 1;
                sign_2_empty = 2;
            }else if(exp[i] == '/'){
                flag_div_2 = 1;
                sign_2_empty = 2;
            }else if(exp[i] == '\%'){
                flag_mod_2 = 1;
                sign_2_empty = 2;
            }
        }

        i+=1;
        
        if(exp[i] == '\0'){
            if(b_empty == 1){
                if(flag_plus == 1){
                    temp = a + b;
                    a = temp;
                    flag_plus = 0;
                }else if( flag_minus == 1){
                    temp = a - b;
                    a = temp;
                    flag_minus = 0;
                }else if( flag_mult == 1){
                    temp = a * b;
                    a = temp;
                    flag_mult = 0;
                }else if( flag_div == 1){
                    temp = a / b;
                    a = temp;
                    flag_div = 0;
                }else if( flag_mod == 1){
                    temp = a % b;
                    a = temp;
                    flag_mod = 0;
                }
            }else{
                return a;
            }
            return a;
        }
        
    }
    return a;
}

int main() {
    char exp1[] = "2 + 2";
    printf("%s = %d\n", exp1, simpleParse(exp1));
	// Expected Value = 4
    char exp2[] = "3 + 7 - 4 * 1";
	printf("%s = %d\n", exp2, simpleParse(exp2));
	// Expected Value = 6
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 \% 97 + 3";
   	printf("%s = %d\n", exp3, simpleParse(exp3));
	// Expected Value = 2005
    
}

