# Exercice 00 - CPP06
```c++
int	main(void)
{
	// int		-> 32 bits
	// double	-> 64 bits

	int		a = 42;			/* Reference value */

	double	b = a;			/* Implicit conversion cast */
	double	c = (double) a;	/* Explicit conversion cast */

	double	d = a;			/* Implicit promotion -> OK */
	int		e = d;			/* Implicit demotion -> Hazardous ! */
	int		f = (int) a;	/* Explicit demotion -> OK, you're in charge */
	
	return (0);
}
```