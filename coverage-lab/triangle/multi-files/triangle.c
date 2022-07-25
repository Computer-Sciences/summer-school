#include <stdio.h>
#include <stdlib.h>

int is_negative (int, int, int) ;

int 
main ()
{
	int a, b, c ;
	int match ;

	scanf("%d %d %d", &a, &b, &c) ;

	if (is_negative(a, b, c)) 
		return 1 ;

	match = 0 ;
	if (a == b)
		match = match + 1 ;
	if (a == c)
		match = match + 2 ;
	if (b == c)
		match = match + 3 ;

	if (match == 0) {
		if ((a + b) <= c)
			printf("Not a triangle\n") ;
		else if ((b + c) <= a)
			printf("Not a triangle\n") ;
		else if ((a + c) <= b)
			printf("Not a triangle\n") ;
		else
			printf("Scalene\n") ;
	}
	else if (match == 1) {
		if ((a + c) <= b)
			printf("Not a triangle\n") ;
		else 
			printf("Isosceles\n") ;
	}
	else if (match == 2) {
		if ((a + c) <= b)
			printf("Not a triangle\n") ;
		else 
			printf("Isosceles\n") ;
	}
	else if (match == 3) {
		if ((b + c) <= a)
			printf("Not a triangle\n") ;
		else
			printf("Isosceles\n") ;
	}
	else if (match < 0) {
		printf("unreachable\n") ;	
	}
	else {
		printf("Equilateral\n") ;
	}

	exit(0) ;

	return 0 ;
}
