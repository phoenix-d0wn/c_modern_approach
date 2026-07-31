//12-1.c

#include <stdio.h>

int main(void) 
{

    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];

    //QUESTIONS
    // Suppose that the declarations above are in effect:
    // (a) What is the value of *(p+3)?
    // (b) What is the value of *(q-3)?
    // (c) What is the value of q-p?
    // (d) Is the condition p < q true or false?
    // (e) Is the condition *p < *q true or false?

    //ANSWERS
    // (a) 14       -- CORRECT
    // (b) 34       -- CORRECT
    // (c) 4        -- CORRECT
    // (d) true     -- CORRECT
    // (e) false    -- CORRECT

    //ANSWER CHECK
    printf("(a) *(p+3) = %d", *(p+3));
    printf("\n(b) *(q-3) = %d", *(q-3));
    printf("\n(c) q-p = %ld", (q-p));
    printf("\n(d) p < q ? %d", p < q);
    printf("\n(e) *p < *q ? = %d", *p < *q);
    
}   //end main