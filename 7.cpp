#include<stdio.h>
#define Pri_Arti 2.05
#define Pri_Beet 1.15
#define Pri_Carr 1.09
#define Discount 0.95
#define divide 100
#define divide_1 5
#define divide_2 20
#define Ex_Fee_1 6.5
#define Ex_Fee_2 14
#define Ex_Fee_3_Per_Pound_Above_20_Basic_On_14 0.5
void menu(int index);
int main(void)
{
	int index = 0;
	char vegi_type;
	float arti, beet, carr;
	float total_weight;
	float total_arti = 0, total_beet = 0, total_carr = 0;
	float Total_fee_of_arti, Total_fee_of_beet, Total_fee_of_carr;
	float Total_fee, Discounted_total_fee;
	float Transportation_and_package;
	while (1)
	{
		menu(index);
		while (scanf("%c", &vegi_type) == 1)
		{
			switch (vegi_type)
			{
			case'a': printf("You want to buy some artichokes.Please enter the amount of artichoke by pound:");
				scanf("%f", &arti);
				total_arti += arti; menu(index); break;
			case'b': printf("You want to buy some Beets.Please enter the amount of beet by pound:");
				scanf("%f", &beet);
				total_beet += beet; menu(index); break;
			case'c': printf("You want to buy some Carrots.Please enter the amount of carrot by pound:");
				scanf("%f", &carr);
				total_carr += carr; menu(index); break;
			case'q':printf("Quitting...\n"); break;
			}
			if (vegi_type == 'q')
				break;
		}
		printf("You would buy %.1f pounds of artichoke,%.1f pounds of beets and %.1f pounds of carrots.\n", total_arti, total_beet, total_carr);
		total_weight = total_arti + total_beet + total_carr;
		Total_fee_of_arti = Pri_Arti * total_arti;
		Total_fee_of_beet = Pri_Beet * total_beet;
		Total_fee_of_carr = Pri_Carr * total_carr;
		Total_fee = Total_fee_of_arti + Total_fee_of_beet + Total_fee_of_carr;
		if (Total_fee >= divide)
			Discounted_total_fee = Discount * Total_fee;
		else
			Discounted_total_fee = 0;
		if (total_weight <= divide_1)
			Transportation_and_package = Ex_Fee_1;
		else if (total_weight > divide_1 && total_weight <= divide_2)
			Transportation_and_package = Ex_Fee_2;
		else
			Transportation_and_package = Ex_Fee_2 + (total_weight - divide_2) * Ex_Fee_3_Per_Pound_Above_20_Basic_On_14;
		printf("the fee of all kinds of vegetables is:\n");
		printf("Artichoke    $%3.2f per pound;\nBeet         $3.2f per pound;\nCarrot       $3.2f per pound.\n", Pri_Arti, Pri_Beet, Pri_Carr);
		printf("Now you would buy:\n");
		printf("%.1f pounds of artichoke,with the price of %.2f dollars;\n%.1f pounds of beet,with the price of %.2f dollars;\n%.1f pounds of carrot,with the price of %.2f dollars;\n", total_arti, Total_fee_of_arti, total_beet, Total_fee_of_beet, total_carr, Total_fee_of_carr);
		printf("with the total price of the vegetables is %.2f dollars.\n", Total_fee);
		printf("After the discount,the discounted price is %.2f dollars.\n", Discounted_total_fee);
		printf("The extra fee including transportation and packaging is %.2f dollars.\n", Transportation_and_package);
		printf("So,the total fee in the buying is %.2f.\n", Total_fee + Transportation_and_package);
		printf("Done of it.\n");
		printf("\n\n\n");
	}
	return 0;
}
void menu(int index)
{
	for (index = 0; index <= 100; index++)
		printf("*");
	printf("\n");
	printf("Enter a letter below to enter an option to choose what kind of vegetable you want to buy\n");
	printf("a.Artichoke;      b.Beet;      c.Carrot\n");
	for (index = 0; index <= 100; index++)
		printf("*");
	printf("\n");
	printf("Press a,b or c to choose.Press q to quit:");
}
