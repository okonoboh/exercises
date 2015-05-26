#include <stdio.h>
#include <stdlib.h>

typedef struct gcd_struct {
   int gcd;
   int x;
   int y;
} gcd_struct;

void print_menu(int n);
int get_option();
int process_option(int option, int* n);
int get_n();
int get_representative();
int add(int a, int b, int n);
int multiply(int a, int b, int n);
gcd_struct gcd(int a, int n);
gcd_struct gcd_helpher(int a, int n, int x1, int y1, int x2, int y2);

int main() {
   int n = 0;

   do {
      print_menu(n);;
   } while(process_option(get_option(), &n) != 0);

   return EXIT_SUCCESS;
}

void print_menu(int n) {
   printf("\n1. Set the value of n.");
   printf("(Current n = %d)\n", n);
   printf("2. Add and multiply two residue classes mod n.\n");
   printf("3. Find the inverse of a residue class.\n");
   printf("4. Exit.\n");
}

int get_option() {
   int n;

   printf("Please choose an option: ");
   scanf("%d", &n);
   return n;
}

int process_option(int option, int* n) {
   int a;
   int b;
   int c;
   gcd_struct g;
   switch(option) {
      case 1:
         *n = get_n();
         break;
      case 2:
         if(*n > 1) {
         printf("Please enter the first integer representative: ");
         a = get_representative();

         printf("Please enter the second integer representative: ");
         b = get_representative();
         
         printf("%d + %d (mod %d) = %d.\n", a, b, *n, add(a, b, *n));
         printf("%d x %d (mod %d) = %d.\n", a, b, *n, multiply(a, b, *n));

         } else {
            fprintf(stderr, "\nError: You must first set the value of n.\n\n");
         }
         break;
      case 3:
         if(*n > 1) {
            printf("Please enter the representative: ");
            c = get_representative();

            g = gcd(c, *n);

            if(g.gcd != 1) {
               fprintf(stderr, "\nError: %d does not have an inverse.\n\n", c);
            } else {
               while(g.y >= *n) {
                  g.y -= *n;
               }

               while(g.y < 0) {
                  g.y += *n;
               }

               printf("The inverse of %d is %d.\n", c, g.y);
            }
         } else {
            fprintf(stderr, "\nError: You must first set the value of n.\n\n");
         }
         break;
      case 4:
         return 0;         
   }

   return 1;
}

int get_n() {
   int n = 0;

   while(n <= 1) {
      printf("Please choose an n greater than 1: ");
      scanf("%d", &n);
   }

   return n;
}

int get_representative() {
   int n = 0;
   scanf("%d", &n);
   
   return n;
}

int add(int a, int b, int n) {
   int sum = a + b;

   while(sum >= n) {
      sum -= n;
   }

   while(sum < 0) {
      sum += n;
   }

   return sum;
}

int multiply(int a, int b, int n) {
   int product = a * b;

   while(product >= n) {
      product -= n;
   }

   while(product < 0) {
      product += n;
   }

   return product;
}

gcd_struct gcd(int a, int n) {
   return gcd_helpher(a, n, 1, 0, 0, 1);
}

gcd_struct gcd_helpher(int a, int n, int x1, int y1, int x2, int y2) {
   int q = n / a;
   int r = n % a;
   gcd_struct g;

   if(r == 0) {
      g.gcd = a;
      g.x = 0;
      g.y = 1;

      return g;
   }

   x1 = x1 - q * x2;
   y1 = y1 - q * y2;

   if(a % r == 0) {
      g.gcd = r;
      g.x = x1;
      g.y = y1;

      return g;
   }

   return gcd_helpher(r, a, x2, y2, x1, y1);
}
