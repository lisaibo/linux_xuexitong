#include <stdio.h>
#include <stdlib.h>
#include "myhead.h"

void menu_1() {
	int item;
	char filename[1024];		//文件名
	
	while(1) {
		item = showMenu_1();
		switch (item)
		{
			case 0:
				exit(0);
				break;
			case 1:
				newFile_1(filename);
				break;
			case 2:
				writeFile_1(filename);
				break;
			case 3:
				readFile_1(filename);
				break;
			case 4:
				changeMode_1(filename);
				break;
			case 5:
				lookMode_1(filename);
				break;
			default:
				printf("你的输入有误！\n");
				break;

		}
	}
}



int showMenu_1() {
	int item;
	printf("\n********************\n");
	printf("0.退出\n");
	printf("1.创建新文件\n");
	printf("2.写文件\n");
	printf("3.读文件\n");
	printf("4.修改文件权限\n");
	printf("5.查看当前文件的权限\n");
	printf("********************\n");
	printf("请输入选项(填入0~5):");
	
	scanf("%d",&item);
	getchar();	//吃掉一个回车符
	return item;
}

