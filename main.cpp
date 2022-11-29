#include<iostream>
#include<algorithm>
#include"HW1_lkd.h"
using namespace std;
int main()
{
    srand((unsigned int)time(NULL));
	FILE *fin(fopen("HW1.dat","rb"));
	unsigned int Tea_n(0),Stu_n(0),Lec_n(0);
	char PASS[9],WORD[9];
	vector<Teacher>Tea;
	vector<Student>Stu,Stu_i;
	vector<Lecture>Lec;
	if(fin!=NULL)
	{
		fread(PASS,9,1,fin);
		fread(&Tea_n,4,1,fin);	
		fread(&Stu_n,4,1,fin);
		fread(&Lec_n,4,1,fin);
		char name[9],c,department[100];
		unsigned int id,S,T;
		unsigned short grade,gpa,credit,time;
		for(unsigned int j,i=0;i<Tea_n;i++)
		{
			c=1;
			fread(name,9,1,fin);
			for(j=0;c!='\0';j++)
			{
				fread(&c,1,1,fin);
				department[j]=c;
			}
			fread(&id,4,1,fin);
			Tea.push_back(Teacher(name,department,id));
		}
		for(unsigned int j,i=0;i<Stu_n;i++)
		{
			c=1;
			fread(name,9,1,fin);
			for(j=0;c!='\0';j++)
			{
				fread(&c,1,1,fin);
				department[j]=c;
			}
			fread(&grade,2,1,fin);
			fread(&id,4,1,fin);
			Stu.push_back(Student(name,department,grade,id));
		}
		for(unsigned int j,i=0;i<Lec_n;i++)
		{
			fread(&T,4,1,fin);
			fread(&S,4,1,fin);
			fread(&time,2,1,fin);
			c=1;
			for(j=0;c!='\0';j++)
			{
				fread(&c,1,1,fin);
				department[j]=c;
			}
			fread(&credit,2,1,fin);
			fread(&gpa,2,1,fin);
			fread(&grade,2,1,fin);
			Lec.push_back(Lecture(Tea[T],Stu[S],time,department,credit,gpa,grade));
		}
		for(unsigned int i=0;i<Stu.size();i++)
			Stu[i].CalGpa(Lec);
		fclose(fin);
		crypt(PASS);
	}
	else
		strcpy(PASS,"12345678");
	/*
	for(unsigned int i=0;i<Tea.size();i++)
	{
		Tea[i].Print();
		system("Pause");
	}
	for(unsigned int i=0;i<Stu.size();i++)
	{
		Stu[i].Print();
		system("Pause");
	}
	for(unsigned int i=0;i<Lec.size();i++)
	{
		Lec[i].Print();
		system("Pause");
	}
	*/
	Cursor.Background();
	switch(TeaORStu())
	{
	case 0:
		Cursor.EraseBackground_1();
		Cursor.scan(14,8,WORD,true);
		if(strcmp(PASS,WORD)!=0)
		{
			Cursor.cls();
			Cursor.Norprint(9,"对不起，您输入的密码有误",12,0);
			Cursor.Norprint(11,"请您重新登录",15,0);
			Cursor.Norprint(12,"系统自动结束",15,0);
			Cursor.sound('W');
			Sleep(2600);
			break;
		}
		Cursor.sound('R');
		unsigned char c;
		while((c=Tea_Chosen())!=5)
		{
			switch(c)
			{
			case 0:
				char Stu_name[9],Stu_department[1000];
				unsigned int Stu_id;
				unsigned short grade;
				Cursor.Stu_Create(Stu_name,Stu_department,grade,Stu_id);
				fflush(stdin);
				Stu_name[8]='\0';
				Stu_department[42]='\0';
				Despace(Stu_name,9);
				Despace(Stu_department,43);
				if(Cursor.Stu_confirm(Stu_name,Stu_department,grade,Stu_id))
				{
					bool test(true);
					for(unsigned int i=0;i<Stu.size();i++)
						if(!Stu[i].testid(Stu_id))
						{
							test=false;
							break;
						}
					if(test)
					{
						if(grade>2100||grade<1990)
						{
							Cursor.cls();
							Cursor.Norprint(7,"操作失败",12,0);
							Cursor.Norprint(9,"×",12,0);
							Cursor.Norprint(12,"请输入正确的入学年份",12,0);
							Cursor.Norprint(13,"位于1990至2100之间",12,0);
							Cursor.sound('W');
							Sleep(2500);
						}
						else
						{
							Stu.push_back(Student(Stu_name,Stu_department,grade,Stu_id));
							Save(PASS,Tea,Stu,Lec);
							Cursor.cls();
							Cursor.Norprint(7,"操作成功",10,0);
							Cursor.Norprint(9,"√",10,0);
							Cursor.sound('R');
							Sleep(1800);
						}
					}
					else
					{
						Cursor.cls();
						Cursor.Norprint(7,"操作失败",12,0);
						Cursor.Norprint(9,"×",12,0);
						Cursor.Norprint(12,"该学生已录入或学号冲突",12,0);
						Cursor.sound('W');
						Sleep(2500);
					}
				}
				break;
			case 1:
				char T_name[9],T_department[1000];
				unsigned int T_id;
				Cursor.Tea_Create(T_name,T_department,T_id);
				fflush(stdin);
				T_name[8]='\0';
				T_department[42]='\0';
				Despace(T_name,9);
				Despace(T_department,43);
				if(Cursor.Tea_confirm(T_name,T_department,T_id))
				{
					bool test(true);
					for(unsigned int i=0;i<Tea.size();i++)
						if(!Tea[i].testid(T_id))
						{
							test=false;
							break;
						}
					if(test)
					{
						Tea.push_back(Teacher(T_name,T_department,T_id));
						Save(PASS,Tea,Stu,Lec);
						Cursor.cls();
						Cursor.Norprint(7,"操作成功",10,0);
						Cursor.Norprint(9,"√",10,0);
						Cursor.sound('R');
						Sleep(1800);
					}
					else
					{
						Cursor.cls();
						Cursor.Norprint(7,"操作失败",12,0);
						Cursor.Norprint(9,"×",12,0);
						Cursor.Norprint(12,"该教师已录入或ID冲突",12,0);
						Cursor.sound('W');
						Sleep(2500);
					}
				}
				break;
			case 2:
				unsigned int T,S,TT,SS;
				char name[1000];
				unsigned short credit,gpa,test,time;
				Cursor.Lec_Create(T,S,time,name,credit,gpa,test);
				fflush(stdin);
				name[42]='\0';
				Despace(name,43);
				if(Cursor.Lec_confirm(T,S,time,name,credit,gpa,test))
				{
					bool ttest(true);
					for(unsigned int i=0;i<Tea.size();i++)
						if(!Tea[i].testid(T))
						{
							ttest=false;
							TT=i;
							break;
						}
					if(ttest)
					{
						Cursor.cls();
						Cursor.Norprint(7,"操作失败",12,0);
						Cursor.Norprint(9,"×",12,0);
						Cursor.Norprint(12,"该教师未录入",12,0);
						Cursor.Norprint(13,"请先录入教师信息",12,0);
						Cursor.sound('W');
						Sleep(2500);
						break;
					}
					ttest=true;
					for(unsigned int i=0;i<Stu.size();i++)
						if(!Stu[i].testid(S))
						{
							ttest=false;
							SS=i;
							break;
						}
					if(ttest)
					{
						Cursor.cls();
						Cursor.Norprint(7,"操作失败",12,0);
						Cursor.Norprint(9,"×",12,0);
						Cursor.Norprint(12,"该学生未录入",12,0);
						Cursor.Norprint(13,"请先录入学生信息",12,0);
						Cursor.sound('W');
						Sleep(2500);
						break;
					}
					ttest=!Stu[SS].testime(time);
					if(ttest)
					{
						Cursor.cls();
						Cursor.Norprint(7,"操作失败",12,0);
						Cursor.Norprint(9,"×",12,0);
						Cursor.Norprint(12,"该课程年份有误",12,0);
						Cursor.sound('W');
						Sleep(2500);
						break;
					}
					if(gpa>100)
					{
						Cursor.cls();
						Cursor.Norprint(7,"操作失败",12,0);
						Cursor.Norprint(9,"×",12,0);
						Cursor.Norprint(12,"请输入正确的成绩",12,0);
						Cursor.sound('W');
						Sleep(2500);
						break;
					}
					if(credit>10)
					{
						Cursor.cls();
						Cursor.Norprint(7,"操作失败",12,0);
						Cursor.Norprint(9,"×",12,0);
						Cursor.Norprint(12,"请输入正确的学分",12,0);
						Cursor.Norprint(13,"尚未承认超过10学分的课程",12,0);
						Cursor.sound('W');
						Sleep(2500);
						break;
					}
					bool had(false);
					for(unsigned int i=0;i<Lec.size();i++)
						if(Lec[i].had(name,S,T))
						{
							had=true;
							break;
						}
					if(had)
					{
						Cursor.cls();
						Cursor.Norprint(7,"操作失败",12,0);
						Cursor.Norprint(9,"×",12,0);
						Cursor.Norprint(12,"该课程已录入，不支持重名课程",12,0);
						Cursor.sound('W');
						Sleep(2500);
						break;
					}
					Lec.push_back(Lecture(Tea[TT],Stu[SS],time,name,credit,gpa,test));
					Save(PASS,Tea,Stu,Lec);
					Cursor.cls();
					Cursor.Norprint(7,"操作成功",10,0);
					Cursor.Norprint(9,"√",10,0);
					Cursor.sound('R');
					Sleep(1800);
				}
				break;
			case 3:
				char department[1000];
				for(unsigned int i=0;i<Stu.size();i++)
					Stu[i].CalGpa(Lec);
				Cursor.Inspect(department);
				fflush(stdin);
				for(unsigned int i=0;i<Stu.size();i++)
					if(Stu[i].sure(department))
						Stu_i.push_back(Stu[i]);
				if(Stu_i.size()==0)
				{
					Cursor.cls();
					Cursor.Norprint(7,"操作失败",12,0);
					Cursor.Norprint(9,"×",12,0);
					Cursor.Norprint(12,"该系学生未录入",12,0);
					Cursor.Norprint(13,"请先录入该系的学生信息",12,0);
					Cursor.sound('W');
					Sleep(2500);
					break;
				}
				else
				{
					sort(Stu_i.begin(),Stu_i.end());
					unsigned int t,*ID(new unsigned int[Stu_i.size()]);
					char **NAME=new char*[Stu_i.size()];
					unsigned short *GRADE(new unsigned short[Stu_i.size()]);
					double *GPA(new double[Stu_i.size()]);
					zhg(Stu_i,ID,NAME,GRADE,GPA);
					t=Cursor.Stu_op(Stu_i.size(),ID,NAME,GRADE,GPA);
					delete[] ID;
					delete[] NAME;
					delete[] GRADE;
					delete[] GPA;
					if(t!=2147483647)
						Stu_i[t].Show(Stu_i);
					Stu_i.clear();
					break;
				}
				break;
			case 4:
				{
					unsigned int ans;
					unsigned int ansT;
					unsigned short time;
					char name[100];
					bool flag(false);
					unsigned int del(2147483647);
					switch(Dele())
					{
					case 0:
						ans=Cursor.idinput();
						fflush(stdin);
						for(int j,i=0;i<int(Tea.size());i++)
							if(!Tea[i].testid(ans))
							{
								Tea[i].Print();
								if(Cursor.confirm(19,14,9))
								{
									Tea.erase(Tea.begin()+i);
									for(j=0;j<int(Lec.size());j++)
										if(!Lec[j].testid(ans))
											Lec.erase(Lec.begin()+j--);
									Save(PASS,Tea,Stu,Lec);
									Cursor.cls();
									Cursor.Norprint(7,"操作成功",10,0);
									Cursor.Norprint(9,"√",10,0);
									Cursor.sound('R');
									Sleep(1800);
								}
								flag=true;
								break;
							}
						if(!flag)
						{
							Cursor.cls();
							Cursor.Norprint(7,"操作失败",12,0);
							Cursor.Norprint(9,"×",12,0);
							Cursor.Norprint(12,"查无此教师",12,0);
							Cursor.sound('W');
							Sleep(2500);
						}
						break;
					case 1:
						ans=Cursor.idinput();
						fflush(stdin);
						for(int j,i=0;i<int(Stu.size());i++)
							if(!Stu[i].testid(ans))
							{
								Stu[i].Print();
								if(Cursor.confirm(19,14,9))
								{
									for(j=0;j<int(Lec.size());j++)
										if(!Lec[j].test_id(ans))
											Lec.erase(Lec.begin()+(j--));
									Stu.erase(Stu.begin()+i);
									Save(PASS,Tea,Stu,Lec);
									Cursor.cls();
									Cursor.Norprint(7,"操作成功",10,0);
									Cursor.Norprint(9,"√",10,0);
									Cursor.sound('R');
									Sleep(1800);
								}
								flag=true;
								break;
							}
						if(!flag)
						{
							Cursor.cls();
							Cursor.Norprint(7,"操作失败",12,0);
							Cursor.Norprint(9,"×",12,0);
							Cursor.Norprint(12,"查无此学生",12,0);
							Cursor.sound('W');
							Sleep(2500);
						}
						break;
					case 2:
						Cursor.idinput(ans,ansT,time,name);
						fflush(stdin);
						for(unsigned int i=0;i<Lec.size();i++)
							if(Lec[i].del(ans,ansT,time,name))
							{
								del=i;
								break;
							}
						if(del==2147483647)
						{
							Cursor.cls();
							Cursor.Norprint(7,"操作失败",12,0);
							Cursor.Norprint(9,"×",12,0);
							Cursor.Norprint(12,"查无此课",12,0);
							Cursor.sound('W');
							Sleep(2500);
						}
						else
						{
							Lec[del].Print();
							Cursor.Norprint(3,"确定删除？",13,0);
							if(Cursor.confirm(22,13,14))
							{
								Lec.erase(Lec.begin()+del);
								Cursor.cls();
								Cursor.Norprint(7,"操作成功",10,0);
								Cursor.Norprint(9,"√",10,0);
								Cursor.sound('R');
								Sleep(1800);
							}
						}
						break;
					case 3:
						Cursor.password(PASS);
						fflush(stdin);
						Save(PASS,Tea,Stu,Lec);
						break;
					}
				}
				break;
			}

		}
		break;
	case 1:
		Cursor.Backstu();
		{
			bool flag(true);
			unsigned int id,ind,n(0);
			char department[100];
			id=Cursor.inputid();
			fflush(stdin);
			for(unsigned int i=0;i<Stu.size();i++)
				if(!Stu[i].testid(id))
				{
					flag=false;
					strcpy(department,Stu[i].de());
					break;
				}
			if(flag)
			{
				Cursor.cls();
				Cursor.Norprint(7,"操作失败",12,0);
				Cursor.Norprint(9,"×",12,0);
				Cursor.Norprint(12,"学号无效",12,0);
				Cursor.Norprint(13,"请检验输入或与教师联系协助解决",12,0);
				Cursor.sound('W');
				Sleep(2500);
				break;
			}
			Cursor.cls();
			for(unsigned int i=0;i<Stu.size();i++)
				if(!Stu[i].sure(department))
					Stu.erase(Stu.begin()+i--);
			for(unsigned int i=0;i<Stu.size();i++)
				if(!Stu[i].testid(id))
				{
					ind=i;
					break;
				}
			Stu[ind].Show2(Stu);
			for(unsigned int i=0;i<Lec.size();i++)
				if(!Lec[i].test_id(id))
					n++;
			if(n==0)
			{
				Cursor.cls();
				Cursor.Norprint(7,"尚无已修课程",14,0);
				Sleep(1075);
				Cursor.Norprint(7,"尚无已修课程",6,0);
				Cursor.Norprint(10,"程序即将结束",14,0);
				Sleep(1075);
				break;
			}
			Cou *C(new Cou[n]);
			Lec[0].COU(C,Lec,id);
			sort(C,C+n);
			while(ind=Cursor.Lec_op(n,C),ind!=2147483647)
			{
				Cursor.cls();
				Cursor.Norprint(3,"课程情况",12,0);
				Cursor.Norprint(5,"名称：",7,0);
				Cursor.Norprint(7,C[ind].name,15,0);
				if(C[ind].test)
				{
					Cursor.Norprint(9,"最高：",7,0,35);
					Cursor.Norprint(9,High(C[ind],Lec),15,0,41);
					Cursor.Norprint(12,"最低：",7,0,35);
					Cursor.Norprint(12,Low(C[ind],Lec),15,0,41);
					Cursor.Norprint(15,"成绩：",7,0,35);
					Cursor.Norprint(15,C[ind].score,15,0,41);
					Cursor.Norprint(18,"排名：",7,0,35);
					Cursor.Norprint(18,Rank(C[ind],Lec),15,0,41);
					Cursor.Norprint(18,"/",15,0,44);
					Cursor.Norprint(18,Numb(C[ind],Lec),15,0,46);
				}
				else
					Cursor.Norprint(13,"此课程不计分",15,0);
				Cursor.Norprint(22,"任意键继续查询. . . ",8,0);
				getch();
			}
			delete[]C;
		}
		break;
	case 2:
		break;
	}
	

	/*for(unsigned int i=0;i<Tea.size();i++)
		Tea[i].~Teacher();
	for(unsigned int i=0;i<Stu.size();i++)
		Stu[i].~Student();
	for(unsigned int i=0;i<Lec.size();i++)
		Lec[i].~Lecture();
	system("pause");*/
	Cursor.end();
	return 0;
}
