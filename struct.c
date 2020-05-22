#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int wheel;
    char* color;
    int* arr;
}Car;

void f(Car x){
    printf("%x %x %x %x \n", &x, &x.wheel, &x.color, x.arr);
}

Car* g(Car* ptr){
    ptr->wheel = 4;
    ptr->color = "blue";
    ptr->arr = malloc(1*sizeof(int));
    return ptr;
}

int main()
{
    Car a;
    a.arr = malloc(4*sizeof(int));
    
    Car b=a;
    printf("%x %x %x %x \n", &a, &a.wheel, &a.color, a.arr);
    printf("%x %x %x %x \n", &b, &b.wheel, &b.color, b.arr);
    f(a);

    Car* ptr = malloc(1*sizeof(Car));
    ptr = g(ptr);
    printf("%d %s %d", ptr->wheel, ptr->color, ptr->arr[0]);
    
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct{
int wheel; //4
char* color; //16
int* arr; //24
}Car;

void f(Car x){
printf("%x %x %x %x \n", &x, &x.wheel, x.color, x.arr);
}

int main()
{
Car a;
printf("%d \n", sizeof(a));

Car b=a;
printf("%x %x %x %x \n", &a, &a.wheel, a.color, a.arr);
printf("%x %x %x %x \n", &b, &b.wheel, b.color, b.arr);
f(a);

return 0;
}
*/
