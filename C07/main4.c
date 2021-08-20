#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main(void)
{

	//https://www.dcode.fr/conversion-base-n

	printf("\033[1;31m");
	printf("Expected results :\n");
	printf("\033[0m");

	printf("-4250\n");
	printf("-64\n");
	printf("0\n");
	printf("-4d58\n");
	printf("10000010\n");
	printf("fcc\n");
	printf("-ok\n");
	printf("uiyh\n");
	printf("aFrcaF\n");
	printf("45608123\n");
	printf("]abs]'\n");
	printf("(null)\n");	
	printf("(null)\n");	
	printf("(null)\n");			

	printf("\033[1;31m");
	printf("Your results :\n");
	printf("\033[0m");

	char *nbr = "   +---4250";
	char *base_from = "0123456789";
	char *base_to = "0123456789";

	ft_convert_base(nbr, base_from, base_to);
	printf("%s\n", ft_convert_base(nbr, base_from, base_to));

	char *nbr2 = "   -----100";
	char *base_from2 = "0123456789";
	char *base_to2 = "0123456789abcdef";

	ft_convert_base(nbr2, base_from2, base_to2);
	printf("%s\n", ft_convert_base(nbr2, base_from2, base_to2));

	char *nbr3 = "   ----0";
	char *base_from3 = "0123456789abcdef";
	char *base_to3 = "01";

	ft_convert_base(nbr3, base_from3, base_to3);
	printf("%s\n", ft_convert_base(nbr3, base_from3, base_to3));

		char *nb4 = "   ---19800";
	char *base_from4 = "0123456789";
	char *base_to4 = "0123456789abcdef";

	ft_convert_base(nb4, base_from4, base_to4);
	printf("%s\n", ft_convert_base(nb4, base_from4, base_to4));

		char *nbr5 = "   ----42";
	char *base_from5 = "0123456789abcdef";
	char *base_to_5 = "01";

	ft_convert_base(nbr5, base_from5, base_to_5);
	printf("%s\n", ft_convert_base(nbr5, base_from5, base_to_5));

	char *nbr6 = "   ----poney";
	char *base_from6 = "poney";
	char *base_to_6 = "abcdef";

	ft_convert_base(nbr6, base_from6, base_to_6);
	printf("%s\n", ft_convert_base(nbr6, base_from6, base_to_6));

	char *nbr8 = "   ---nvm42wert";
	char *base_from8 = "nvmwert";
	char *base_to_8 = "pokemin";

	ft_convert_base(nbr8, base_from8, base_to_8);
	printf("%s\n", ft_convert_base(nbr8, base_from8, base_to_8));

	char *nbr9 = "   ----489wwyzz";
	char *base_from9 = "024869xyzabc";
	char *base_to_9 = "yugioh";

	ft_convert_base(nbr9, base_from9, base_to_9);
	printf("%s\n", ft_convert_base(nbr9, base_from9, base_to_9));

	char *nbr10 = "   ----iehSN45";
	char *base_from10 = "PiScNeBrUh";
	char *base_to_10 = "FrancE";

	ft_convert_base(nbr10, base_from10, base_to_10);
	printf("%s\n", ft_convert_base(nbr10, base_from10, base_to_10));

	char *nbr11 = "   ----baud8oin";
	char *base_from11 = "doinbau789";
	char *base_to_11 = "0123456789";

	ft_convert_base(nbr11, base_from11, base_to_11);
	printf("%s\n", ft_convert_base(nbr11, base_from11, base_to_11));

		char *nbr12 = "   ----SHHHHEKR";
	char *base_from12 = "SHREK";
	char *base_to_12 = "b']ase";

	ft_convert_base(nbr12, base_from12, base_to_12);
	printf("%s\n", ft_convert_base(nbr12, base_from12, base_to_12));

	char *nbr13 = "   ----0";
	char *base_from13 = "0123456789abcdef";
	char *base_to13 = "?121";

	ft_convert_base(nbr13, base_from13, base_to13);
	printf("%s\n", ft_convert_base(nbr13, base_from13, base_to13));

	char *nbr14 = "   ---0";
	char *base_from14 = "0123456789abcdef";
	char *base_to14 = "/121";

	ft_convert_base(nbr14, base_from14, base_to14);
	printf("%s\n", ft_convert_base(nbr14, base_from14, base_to14));

	char *nbr15 = "   ---45";
	char *base_from15 = "01234456789abcdef";
	char *base_to15 = "/121";

	ft_convert_base(nbr15, base_from15, base_to15);
	printf("%s\n", ft_convert_base(nbr15, base_from15, base_to15));

	return (0);
}
