#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void newFile_1(char * filename) {
	FILE *fp;

	printf("请输入文件名：");

	fgets(filename,1024,stdin);
	if(filename[strlen(filename)-1] == '\n') {	//去除回车换行符
		filename[strlen(filename)-1] = '\0';
	}

	fp = fopen(filename,"a");
	if(fp == NULL) {
		perror("创建文件时发生错误\n");
		return;
	}
	printf("文件创建成功，文件名为：%s\n",filename);
	fclose(fp);

}


void writeFile_1(char * filename) {
	
	FILE *fp;
	char *writeText = "Linux teacher is a handsome man\n";

	if(strlen(filename) == 0) {
		printf("请先创建新文件/录入已有文件，再执行操作！\n");
		return;
	}

	fp = fopen(filename,"w");
	if(fp == NULL) {
		perror("打开文件时发生错误\n");
		return;
	}
	fputs(writeText, fp);
	
/*
	printf("请输入内容：\n");
	fgets(text,1024,stdin);
*/
	printf("文件写入成功！\n");
	fclose(fp);
}

void readFile_1(char * filename) {
	
	FILE *fp;
	char buff[1024];

	if(strlen(filename) == 0) {
		printf("请先创建新文件/录入已有文件，再执行操作！\n");
		return;
	}

	fp = fopen(filename,"r");
	if(fp == NULL) {
		perror("打开文件时发生错误\n");
		return;
	}

	fgets(buff,1024,fp);
	while(!feof(fp)) {
		fputs(buff,stdout);
		fgets(buff,1024,fp);

	}
	fclose(fp);
}


void changeMode_1(char * filename) {
	int mode;
	if(strlen(filename) == 0) {
		printf("请先创建新文件/录入已有文件，再执行操作！\n");
		return;
	}
	printf("请输入文件权限的权限掩码(000～777)：");
	scanf("%o",&mode);
	chmod(filename,mode);
	printf("权限修改成功！\n");

}

void lookMode_1(char * filename) {
/*
	char str[1024] = "ls -l ";
	
	strcat(str,filename);
	system(str);
*/
	struct stat fileInfo;

	if(strlen(filename) == 0) {
		printf("请先创建新文件/录入已有文件，再执行操作！\n");
		return;
	}

	if(stat(filename, &fileInfo) < 0) {
		printf("查看失败！\n");
	}
	unsigned int mask = 0000777;
	unsigned int mode = mask & fileInfo.st_mode;
	printf("文件权限:%o\n", mode);

}































