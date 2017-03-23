/*
学生成绩简单统计。
写一个程序，读入10名学生的成绩。每个学生的数据，包含一个不带空格的名字（不超过19个字符），以及三门课的成绩，每门课的成绩是1到5的整数。
程序要输出如下的一个列表，对每个学生输出他的录入时的序号、名字、三门课的成绩和平均成绩（浮点表示），最后输出每门课的平均成绩（浮点表示）和最低最高成绩。
no      name    score1  score2  score3  average
1       K.Weng  5       5       5       5
2       T.Dixon 4       3       2       3
3       V.Chu   3       4       5       4
4       L.Tson  4       3       4       3.66667
5       L.Lee   3       4       3       3.33333
6       I.Young 4       2       5       3.66667
7       K.Hiro  4       2       1       2.33333
8       G.Ping  4       4       4       4
9       H.Gu    2       3       4       3
10      J.Jon   5       4       3       4
        average 3.8     3.4     3.6
        min     2       2       1
        max     5       5       5
因为排版的缘故，你看到的表格也许不够整齐，输出时在所有的输出项之间加\t就可以了。输出格式不是评判的内容。
*/
#include <stdio.h>

typedef struct{
	char name[20];
	int score[3];
}Student;

//输入一个学生的数据
Student* student_input(Student *pStudent);
//输出一个学生的数据，包括平均成绩
void student_print(const Student *pStudent);
//计算一个学生的平均成绩
double student_average(const Student *pStudent);
//获得学生的一个成绩
int student_get_score(const Student *pStudent, int index);
//获得某一科的平均分
double subject_average(const Student *pStudent, int index);
//获得某一科的最低分
int subject_min(const Student *pStudent,int index); 
//获得某一科的最高分
int subject_max(const Student *pStudent,int index); 

const int student_number=10;//学生总人数 

int main()
{
	Student student[student_number];
	Student *pStudent;
	pStudent=&student[0];
	int i;
	printf("输入学生姓名和三科成绩：\n");
	for(i=0;i<student_number;i++)
	{
		pStudent=student_input(&student[i]);
		pStudent++;
	}
	
	printf("no\tname\tscore1\tscore2\tscore3\taverage\n");
	pStudent=&student[0];
	for(i=0;i<student_number;i++)
	{
		printf("%d\t",i+1);
		student_print(pStudent);
		pStudent++;
	}
	
	pStudent=&student[0];
	printf("\taverage");
	for(i=0;i<3;i++)
	{
		double avg=subject_average(pStudent,i);
		printf("\t%.1f",avg);
	}
	printf("\n");
	
	printf("\tmin");
	for(i=0;i<3;i++)
	{
		int min=subject_min(pStudent,i);
		printf("\t%d",min);
	} 
	printf("\n");
	
	printf("\tmax");
	for(i=0;i<3;i++)
	{
		int max=subject_max(pStudent,i);
		printf("\t%d",max);
	} 
	printf("\n");	
	return 0;
} 

Student* student_input(Student *pStudent)
{
	scanf("%s",&pStudent->name);
	scanf("%d",&pStudent->score[0]);
	scanf("%d",&pStudent->score[1]);
	scanf("%d",&pStudent->score[2]);
	return pStudent;
}

void student_print(const Student *pStudent)
{
	int i;
	double avg=student_average(pStudent);
	printf("%s\t",pStudent->name);
	for(i=0;i<3;i++)
	{
		printf("%d\t",pStudent->score[i]);
	}
	printf("%f\n",avg);
}

double student_average(const Student *pStudent)
{
	double avg,sum=0;
	int i;
	for(i=0;i<3;i++)
	{
		sum+=pStudent->score[i];
	}
	avg=sum/3;
	return avg;
}

int student_get_score(const Student *pStudent, int index)
{
	return pStudent->score[index];
}

double subject_average(const Student *pStudent,int index)
{
	double avg,sum=0;
	int i;
	for(i=0;i<student_number;i++)
	{
		sum+= student_get_score(pStudent,index);
		pStudent++;
	}
	avg=sum/student_number;
	return avg;
}

int subject_min(const Student *pStudent ,int index)
{
	int min=student_get_score(pStudent,index);
	int i,tmp;
	for(i=0;i<student_number;i++)
	{
		tmp=student_get_score(pStudent,index);
		if(min>tmp)min=tmp;
		pStudent++;
	}
	return min;
}

int subject_max(const Student *pStudent ,int index)
{
	int max=student_get_score(pStudent,index);
	int i,tmp;
	for(i=0;i<student_number;i++)
	{
		tmp=student_get_score(pStudent,index);
		if(max<tmp)max=tmp;
		pStudent++;
	}
	return max;
}
