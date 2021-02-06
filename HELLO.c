// fewefe.cpp : Defines the entry point for the console application.
//
#include<stdio.h>


struct Date
{
	int year;
	int mouth;
	int day;
} date;

struct Book
{
	char Title[120];
	char Author[20];
	float price;
	struct Date date;
	char publisher[50];
};


struct Book getinput(struct Book book);
void printBook(struct Book book);

struct Book getinput(struct Book book)
{
		printf("请输入标题：");
		scanf("%s",book.Title);
		printf("请输入作者：");
		scanf("%s",book.Author);
		printf("请输入价格:");
		scanf("%f",&book.price);
		printf("请输入出版日期:");
		scanf("%d%d%d",&book.date.year,&book.date.mouth,&book.date.day);
		printf("请输入出版社:");
		scanf("%s",&book.publisher);

		return book;
}


void printBook(struct Book book)
{

			printf("书名：%s\n",book.Title);
			printf("作者：%s\n",book.Author);
			printf("价格：%f\n",book.price);
			printf("出版日期:%d-%d-%d\n",book.date.year,book.date.mouth,book.date.day);
			printf("出版社：%s\n",book.publisher);
			
}


int main(void)
{
	
	struct Book b1,b2;
   	
	printf("请输入第一本书的信息:\n");
		b1 = getinput(b1);

	putchar('\n');

	printf("\n请输入第二本书的信息：\n");
		b2 = getinput(b2);

	printf("\n\n录入完毕开始打印第一本:");
		printBook(b1);
		putchar('\n');
	printf("\n\n录入完毕开始打印第二本：\n");
	
		printBook(b2);

		return 0;
}
