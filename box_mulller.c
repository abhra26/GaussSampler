/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define PI 3.14159265358979323846
#define Sigma 5.658

int box_muller(){
    
    double u1, u2, z0, z1, val;
    do {
            u1 = rand() / (RAND_MAX + 1.0);
            u2 = rand() / (RAND_MAX + 1.0);
            z0 = sqrt(-2.0 * log(u1));
            z1 = cos(2.0 * PI * u2);
            val = Sigma*z0*z1;
            
        } while (val == 0); // Prevent division by zero
    
    int rounded = floor(val);
    
    return rounded;
}

int* create_gauss_array(int size){
    int* arr = (int*)malloc(size*sizeof(int));
    for (int i=0; i<size;i++){
        arr[i] = box_muller();
    }
    
    return arr;
}

void print_binary(uint32_t num) { // Delete this function after binding GPIO
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
  printf("\n");
}

void write_BRAM(int* arr, int size){
    
    uint32_t var;
    for (int i=0;i<size;i++){
        var = (uint32_t)arr[i];
        print_binary(var); // Bind with GPIO here to write.
    }
}



int main()
{
    int size = 512; // should be multiple of 32
    int add_on = 0;
    int* result = create_gauss_array(size);
    
    for (int j=0; j<size/32;j++){
        for (int i=0;i<32;i++){
            printf("%d,",result[i+add_on]);
        }
        printf("\n");
        add_on += 32;
    }
    
    write_BRAM(result, size);
    
    
    
    return 0;
}
