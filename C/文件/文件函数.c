#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{

	// FILE * fopen (const char *filename, const char *mode)
	// filename 表示被打开的文件的名字，这个名字可以是绝对路径，也可以是相对路径
	// mode 表示对打开的文件的操作方式
	// 若文件成功打开，该函数将返回一个指向 FILE 对象的指针，该指针可以用于后续操做中标识对应的流
	// 若打开失败，则返回 NULL 指针，所以一定要对 fopen 的返回值进行判断，来验证文件是否打开成功
	// "r" 只读，为了输入数据，打开一个已经存在的文本文件，文件不存在：出错
	// "w" 只写，为了输出数据，打开一个文本文件，文件不存在：建立一个新的文件
	// "a" 追加，向文本文件尾添加数据，文件不存在：建立一个新的文件

	//FILE* pf = fopen("date.txt", "w");
	//相对路径的写法
	//  . 表示当前路径
	//  ..表示上一级路径
	//  ./../表示当前路径的上一级路径

	//绝对路经
	//属性

	//if (pf == NULL)
	//{
	//	perror("fopen");
	//}

	

	// int fputc( int character, FILE * stream )
	// 向输出流中写入一个字符
	// 成功返回写入的字符（以int形式）
	// 失败返回 EOF （通常是-1）

	//写字符到文件
	/*fputc('a', pf);
	fputc('b', pf);*/

	//写字符到标准输出流
	/*fputc('a', stdout);
	
	fputc('b', stdout);

	putchar('a');
	putchar('b');*/

	// int fclose( FILE * stream ); //关闭文件
	/*fclose(pf);
	pf = NULL;*/

	//int fgetc(FILE * stream);

	//从输入流中读取一个字符
	//int fgetc(FILE * stream);

	//从键盘中读取字符
	/*for (int i = 0; i < 10; i++)
	{
		char ch = fgetc(stdin);
		fputc(ch, stdout);
	}*/


	//int feof(FILE * stream);
	//检测 stream 指针指向的流是否遇到文件末尾
	//如果 feof 检测到文件结束指示符已经被设置，返回非0，如果没有返回0

	//int ferror(FILE * stream);
	//检测 stream 指针指向的流是否发生读写错误
	//如果 ferror 检测到文件错误指数符，返回非0，如果没有返回0

    // int fputs( const char * str, FILE * stream );
    // 将 str 指向的字符串写入到参数 stream 指定的流中（不包含末尾的\0)
    //成功返回非负整数，失败返回 EOF （-1）

    // char * fgets(char * str, int num, FILE * stream);
    // 从stream指定输入流中读取字符串
    // str 是指向字符数组的指针，str指向的空间用于储存读取到的字符串
    // num 最大读取字符数，包含结尾的 \0, 实际最多读取 num - 1个字符
    // stream 输入流的文件指针，（如文件流或stdin）
    // 成功返回 str 指针
    // 读取时遇到文件末尾，返回NULL
    // 发生读取错误，返回NULL

    fprintf(stdout, "%d", 20);

	return 0;
}