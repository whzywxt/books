# include <stdio.h>

#define MONTHS 12 

int main()
{
	const int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
	days[9] = 44;
}
