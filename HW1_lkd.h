#include"Cursor_lkd.h"
#include<vector>
using namespace std;
class Figure
{
	virtual void Print()=0;
	virtual bool testid(unsigned int)=0;
	virtual void Ran()=0;
};
class Student;
class Lecture;
class Teacher:public Figure
{
	friend void Save(char[],vector<Teacher>&,vector<Student>&,vector<Lecture>&);
public:
	Teacher(char name[],char department[],unsigned int T_id):T_department(new char[strlen(department)+1]),T_id(T_id)
	{
		strcpy(T_name,name);
		strcpy(T_department,department);
		T_name[8]='\0';
		Ran();
		return;
	}
	Teacher(const Teacher &p):T_department(new char[strlen(p.T_department)+1]),T_id(p.T_id)
	{
		strcpy(T_name,p.T_name);
		strcpy(T_department,p.T_department);
		Ran();
		return;
	}
	virtual ~Teacher()
	{
		delete[] T_department;
		return;
	}
	bool testid(unsigned int id)
	{
		return T_id!=id;
	}
	void Ran()
	{
		for(unsigned char j,i=0;i<9;i++)
		if(T_name[i]=='\0')
		{
			for(j=i+1;j<9;j++)
				T_name[j]=rand();
			break;
		}
		return;
	}
	void Print()
	{
		Cursor.Norprint(5,"姓名：",15,0,34);
		Cursor.Norprint(5,T_name,7,0,40);
		Cursor.Norprint(7,"系别：",15,0,34);
		Cursor.Norprint(7,T_department,7,0,40);
		Cursor.Norprint(9,"ID号：",15,0,34);
		Cursor.Norprint(9,T_id,7,0,40);
		return;
	}
protected:
	char T_name[9];
	char *T_department;
	unsigned int T_id;
};
class Student:public Figure
{
	friend void Save(char[],vector<Teacher>&,vector<Student>&,vector<Lecture>&);
	friend void zhg(vector<Student>&,unsigned int*,char**,unsigned short*,double*);
public:
	Student(char name[],char department[],unsigned short grade,unsigned int Stu_id,unsigned short gpa=0,unsigned short Stu_credit=0):Stu_department(new char[strlen(department)+1]),grade(grade),Stu_id(Stu_id),gpa(gpa),Stu_credit(Stu_credit)
	{
		strcpy(Stu_name,name);
		strcpy(Stu_department,department);
		Stu_name[8]='\0';
		Ran();
		return;
	}
	Student(const Student &p):Stu_department(new char[strlen(p.Stu_department)+1]),grade(p.grade),Stu_id(p.Stu_id),gpa(p.gpa),Stu_credit(p.Stu_credit)
	{
		strcpy(Stu_name,p.Stu_name);
		strcpy(Stu_department,p.Stu_department);
		Ran();
		return;
	}
	virtual ~Student()
	{
		delete[] Stu_department;
		return;
	}
	bool operator<(const Student &p)
	{
		return grade!=p.grade?grade<p.grade:(gpa==p.gpa?Stu_id<p.Stu_id:gpa>p.gpa);
	}
	const Student& operator=(const Student &p)
	{
		char *str(new char[strlen(p.Stu_department)+1]);
		strcpy(str,p.Stu_department);
		delete[] Stu_department;
		Stu_department=str;
		strcpy(Stu_name,p.Stu_name);
		grade=p.grade;
		Stu_id=p.Stu_id;
		Stu_credit=p.Stu_credit;
		gpa=p.gpa;
		return *this;
	}
	void Show(vector<Student> &Stu)
	{
		Cursor.cls();
		Cursor.Norprint(4,"学生姓名：",15,0,30);
		Cursor.Norprint(4,Stu_name,7,0,40);
		Cursor.Norprint(6,"学生系别：",15,0,30);
		Cursor.Norprint(6,Stu_department,7,0,40);
		Cursor.Norprint(8,"系内排名：    /",15,0,30);
		Cursor.Norprint(8,rank(Stu),7,0,41);
		Cursor.Norprint(8,number(Stu),7,0,46);
		Cursor.Norprint(10,"学生学号：",15,0,30);
		Cursor.Norprint(10,Stu_id,7,0,40);
		Cursor.Norprint(12,"入学年份：",15,0,30);
		Cursor.Norprint(12,grade,7,0,40);
		Cursor.Norprint(14,"已修学分：",15,0,30);
		Cursor.Norprint(14,Stu_credit,7,0,40);
		Cursor.Norprint(16,"平均成绩：",15,0,30);
		Cursor.Norprint(16,gpa,7,0,40);
		Cursor.Norprint(21,"按任意键继续",8,0);
		char c;
		c=getch();
		return;
	}
	void Show2(vector<Student> &Stu)
	{
		Cursor.cls();
		Cursor.Norprint(4,"学生姓名：",15,0,30);
		Cursor.Norprint(4,Stu_name,7,0,40);
		Cursor.Norprint(6,"学生系别：",15,0,30);
		Cursor.Norprint(6,Stu_department,7,0,40);
		Cursor.Norprint(8,"系内排名：    /",15,0,30);
		Cursor.Norprint(8,rank(Stu),7,0,41);
		Cursor.Norprint(8,number(Stu),7,0,46);
		Cursor.Norprint(10,"学生学号：",15,0,30);
		Cursor.Norprint(10,Stu_id,7,0,40);
		Cursor.Norprint(12,"入学年份：",15,0,30);
		Cursor.Norprint(12,grade,7,0,40);
		Cursor.Norprint(14,"已修学分：",15,0,30);
		Cursor.Norprint(14,Stu_credit,7,0,40);
		Cursor.Norprint(16,"平均成绩：",15,0,30);
		Cursor.Norprint(16,gpa,7,0,40);
		Cursor.Norprint(21,"按任意键进入课程查分. . . ",8,0);
		char c;
		c=getch();
		return;
	}
	void Ran()
	{
		for(unsigned char j,i=0;i<7;i++)
		if(Stu_name[i]=='\0')
		{
			for(j=i+1;j<8;j++)
				Stu_name[j]=rand();
			break;
		}
		return;
	}
	unsigned int rank(vector<Student> &Stu)
	{
		unsigned int ans(1);
		for(unsigned int i=0;i<Stu.size();i++)
			if(Stu[i].grade==grade&&Stu[i].gpa>gpa)
				ans++;
		return ans;
	}
	unsigned int number(vector<Student> &Stu)
	{
		unsigned int ans(0);
		for(unsigned int i=0;i<Stu.size();i++)
			if(Stu[i].grade==grade)
				ans++;
		return ans;
	}
	bool testid(unsigned int id)
	{
		return Stu_id!=id;
	}
	bool testime(unsigned short time)
	{
		return time>=grade&&time<=2106;
	}
	void Print()
	{
		Cursor.Norprint(5,"姓名：",15,0,34);
		Cursor.Norprint(5,Stu_name,7,0,40);
		Cursor.Norprint(7,"系别：",15,0,34);
		Cursor.Norprint(7,Stu_department,7,0,40);
		Cursor.Norprint(9,"学号：",15,0,34);
		Cursor.Norprint(9,Stu_id,7,0,40);
		Cursor.Norprint(11,"入学：",15,0,34);
		Cursor.Norprint(11,grade,7,0,40);
		return;
	}
	bool sure(char department[])
	{
		if(strcmp(department,Stu_department)==0)
			return true;
		bool b(false);
		char *de2(new char[strlen(department)+3]);
		for(unsigned char i=0;i<strlen(department);i++)
			de2[i]=department[i];
		de2[strlen(department)]=-49;
		de2[strlen(department)+1]=-75;
		de2[strlen(department)+2]='\0';
		if(strcmp(de2,Stu_department)==0)
			b=true;
		delete[] de2;
		de2=new char[strlen(Stu_department)+3];
		for(unsigned char i=0;i<strlen(Stu_department);i++)
			de2[i]=Stu_department[i];
		de2[strlen(Stu_department)]=-49;
		de2[strlen(Stu_department)+1]=-75;
		de2[strlen(Stu_department)+2]='\0';
		if(strcmp(de2,department)==0)
			b=true;
		delete[] de2;
		return b;
	}
	char* de()
	{
		return Stu_department;
	}
	inline void CalGpa(vector<Lecture>&);
protected:
	char Stu_name[9];
	char *Stu_department;
	unsigned short grade;
	unsigned int Stu_id;
	unsigned short Stu_credit;
	double gpa;
};
class Lecture:virtual public Teacher,virtual public Student
{
	friend inline void Student::CalGpa(vector<Lecture>&);
	friend void Save(char[],vector<Teacher>&,vector<Student>&,vector<Lecture>&);
	friend unsigned int High(Cou,vector<Lecture>&);
	friend unsigned int  Low(Cou,vector<Lecture>&);
	friend unsigned int Rank(Cou,vector<Lecture>&);
	friend unsigned int Numb(Cou,vector<Lecture>&);
public:
	Lecture(Teacher T,Student S,unsigned short time,char name[],unsigned short credit,unsigned short score,unsigned short t):Teacher(T),Student(S),Lec_name(new char[strlen(name)+1]),score(score),credit(credit),time(time)
	{
		test=(t!=0);
		strcpy(Lec_name,name);
		Ran();
		return;
	}
	Lecture(const Lecture &p):Teacher(p),Student(p),time(p.time),Lec_name(new char[strlen(p.Lec_name)+1]),credit(p.credit),score(p.score),test(p.test)
	{
		strcpy(Lec_name,p.Lec_name);
		Ran();
		return;
	}
	bool operator<(const Lecture &p)
	{
		return time!=p.time?time<p.time:(credit==p.credit?score>p.score:credit>p.credit);
	}
	const Lecture& operator=(const Lecture &p)
	{
		time=p.time;
		credit=p.credit;
		score=p.score;
		test=p.test;
		grade=p.grade;
		Stu_id=p.Stu_id;
		Stu_credit=p.Stu_credit;
		gpa=p.gpa;
		T_id=p.T_id;
		char *strStu(new char[strlen(p.Stu_department)+1]),
			*strT(new char[strlen(p.T_department)+1]),
			*strLec(new char[strlen(p.Lec_name)+1]);
		strcpy(strStu,p.Stu_department);
		strcpy(strT,p.T_department);
		strcpy(strLec,p.Lec_name);
		delete[] Stu_department;
		delete[] T_department;
		delete[] Lec_name;
		Stu_department=strStu;
		T_department=strT;
		Lec_name=strLec;
		strcpy(Stu_name,p.Stu_name);
		strcpy(T_name,p.T_name);
		Ran();
		return *this;
	}
	virtual ~Lecture()
	{
		delete[] Lec_name;
		return;
	}
	bool had(char *de,unsigned int Stu,unsigned int Tea)
	{
		return (strcmp(Lec_name,de)==0)&&Stu==Stu_id&&Tea==T_id;
	}
	void Ran()
	{
		for(unsigned char j,i=0;i<9;i++)
		if(T_name[i]=='\0')
		{
			for(j=i+1;j<9;j++)
				T_name[j]=rand();
			break;
		}
		return;
		for(unsigned char j,i=0;i<9;i++)
		if(Stu_name[i]=='\0')
		{
			for(j=i+1;j<9;j++)
				Stu_name[j]=rand();
			break;
		}
		return;
	}
	void Print()
	{
		Cursor.Norprint(7,"学生学号：",15,0,32);
		Cursor.Norprint(7,Stu_id,7,0,42);
		Cursor.Norprint(10,"教师ID号：",15,0,32);
		Cursor.Norprint(10,T_id,7,0,42);
		Cursor.Norprint(13,"上课年份：",15,0,32);
		Cursor.Norprint(13,time,7,0,42);
		Cursor.Norprint(16,"课程名称：",15,0,32);
		Cursor.Norprint(16,Lec_name,7,0,42);
		Cursor.Norprint(19,"课程成绩：",15,0,32);
		Cursor.Norprint(19,score,7,0,42);
		return;
	}
	bool testid(unsigned int id)
	{
		return T_id!=id;
	}
	bool test_id(unsigned int id)
	{
		return Stu_id!=id;
	}
	bool del(unsigned int ans,unsigned int ansT,unsigned short anstime,char *ansname)
	{
		return ans==Stu_id&&ansT==T_id&&anstime==time&&strcmp(ansname,Lec_name)==0;
	}
	void COU(Cou *C,vector<Lecture> &Lec,unsigned int id)
	{
		for(unsigned int top=0,i=0;i<Lec.size();i++)
			if(!Lec[i].test_id(id))
			{
				C[top].time=Lec[i].time;
				C[top].score=Lec[i].score;
				C[top].credit=Lec[i].credit;
				C[top].test=Lec[i].test;
				C[top].tea=Lec[i].T_name;
				C[top].Tid=Lec[i].T_id;
				C[top++].name=Lec[i].Lec_name;
			}
		return;
	}
private:
	char *Lec_name;
	unsigned short time,credit,score;
	bool test;
};
inline void Student::CalGpa(vector<Lecture> &Lec)
{
	unsigned int sum(0),credit(0);
	Stu_credit=0;
	for(unsigned int i=0;i<Lec.size();i++)
		if(Stu_id==Lec[i].Stu_id)
		{
			Stu_credit+=Lec[i].credit;
			if(Lec[i].test==true)
			{
				sum+=Lec[i].score*Lec[i].credit;
				credit+=Lec[i].credit;
			}
		}
	if(credit==0)
		gpa=0.0;
	else
		gpa=sum/double(credit);
	return;
}
unsigned char TeaORStu()
{
	Cursor.Norprint(4,"学生成绩管理系统",10,0);
	Cursor.Norprint(20,"  Designed. by.",14,0);
	Cursor.Norprint(21,"柴士佳",14,0);
	char *a[3]={"      教 师 登 录      ","      学 生 登 录      ","        退   出        "};
	unsigned char n[3]={9,12,15};
	return Cursor.Chose(3,'>',a,'<',n,13,11);
}
unsigned char Tea_Chosen()
{
	Cursor.cls();
	Cursor.TeaBackground();
	Cursor.Norprint(5,"请您选择：",9,0);
	char *a[6]={"      创 建 学 生      ","      创 建 教 师      ","      创 建 课 程      ","      查 看 学 生      ","      删 改 项 目      ","      退 出 程 序      "};
	unsigned char n[6]={9,11,13,15,17,19};
	return Cursor.Chose(6,4,a,4,n,10,14);
}
unsigned char Dele()
{
	Cursor.cls();
	Cursor.TeaBackground();
	Cursor.Norprint(5,"请您选择：",9,0);
	char *a[5]={"      删 除 教 师      ","      删 除 学 生      ","      删 除 课 程      ","      修 改 密 码      ","        返   回        "};
	unsigned char n[5]={8,11,14,17,20};
	return Cursor.Chose(5,4,a,4,n,10,14);
}
void crypt(char PASS[])
{
	char pass[9]={119,-92,-3,-31,99,12,-49,40,68};
	for(char i=0;i<9;i++)
		PASS[i]^=pass[i];
	return;
}
void Save(char PASS[],vector<Teacher> &Tea,vector<Student> &Stu,vector<Lecture> &Lec) 
{
	FILE *fout(fopen("HW1.dat","wb"));
	unsigned int Tea_n(Tea.size()),Stu_n(Stu.size()),Lec_n(Lec.size());
	for(char j,i=0;i<8;i++)
		if(PASS[i]=='\0')
		{
			for(j=i+1;j<9;j++)
				PASS[j]=rand();
			break;
		}
	crypt(PASS);
	fwrite(PASS,9,1,fout);
	crypt(PASS);
	fwrite(&Tea_n,4,1,fout);	
	fwrite(&Stu_n,4,1,fout);
	fwrite(&Lec_n,4,1,fout);
	for(unsigned int i=0;i<Tea_n;i++)
	{
		fwrite(Tea[i].T_name,9,1,fout);
		fwrite(Tea[i].T_department,strlen(Tea[i].T_department)+1,1,fout);
		fwrite(&Tea[i].T_id,4,1,fout);
	}
	for(unsigned int i=0;i<Stu_n;i++)
	{
		fwrite(Stu[i].Stu_name,9,1,fout);
		fwrite(Stu[i].Stu_department,strlen(Stu[i].Stu_department)+1,1,fout);
		fwrite(&Stu[i].grade,2,1,fout);
		fwrite(&Stu[i].Stu_id,4,1,fout);
	}
	for(unsigned int j,i=0;i<Lec_n;i++)
	{
		j=0;
		while(Lec[i].T_id!=Tea[j].T_id)
			j++;
		fwrite(&j,4,1,fout);
		j=0;
		while(Lec[i].Stu_id!=Stu[j].Stu_id)
			j++;
		fwrite(&j,4,1,fout);
		fwrite(&Lec[i].time,2,1,fout);
		fwrite(Lec[i].Lec_name,strlen(Lec[i].Lec_name)+1,1,fout);
		fwrite(&Lec[i].credit,2,1,fout);
		fwrite(&Lec[i].score,2,1,fout);
		fwrite(&Lec[i].test,2,1,fout);
	}
	fclose(fout);
	return;
}
void Despace(char *s,unsigned char n)
{
	for(unsigned char j,i=0;i<n;i++)
		if(s[i]==' ')
			for(j=i--;j<n-1;j++)
				s[j]=s[j+1];
	return;
}
void zhg(vector<Student> &Stu_i,unsigned int *ID,char **NAME,unsigned short *GRADE,double *GPA)
{
	for(unsigned int i=0;i<Stu_i.size();i++)
	{
		ID[i]=Stu_i[i].Stu_id;
		NAME[i]=Stu_i[i].Stu_name;
		GPA[i]=Stu_i[i].gpa;
		GRADE[i]=Stu_i[i].grade;
	}
	return;
}
unsigned int High(Cou C,vector<Lecture> &Lec)
{
	unsigned int ans(0);
	for(unsigned int i=0;i<Lec.size();i++)
		if(C.credit==Lec[i].credit&&strcmp(C.name,Lec[i].Lec_name)==0&&strcmp(C.tea,Lec[i].T_name)==0&&C.test==Lec[i].test&&C.Tid==Lec[i].T_id&&C.time==Lec[i].time)
			ans=Lec[i].score>ans?Lec[i].score:ans;
	return ans;
}
unsigned int Low(Cou C,vector<Lecture> &Lec)
{
	unsigned int ans(101);
	for(unsigned int i=0;i<Lec.size();i++)
		if(C.credit==Lec[i].credit&&strcmp(C.name,Lec[i].Lec_name)==0&&strcmp(C.tea,Lec[i].T_name)==0&&C.test==Lec[i].test&&C.Tid==Lec[i].T_id&&C.time==Lec[i].time)
			ans=Lec[i].score<ans?Lec[i].score:ans;
	return ans;
}
unsigned int Numb(Cou C,vector<Lecture> &Lec)
{
	unsigned int ans(0);
	for(unsigned int i=0;i<Lec.size();i++)
		if(C.credit==Lec[i].credit&&strcmp(C.name,Lec[i].Lec_name)==0&&strcmp(C.tea,Lec[i].T_name)==0&&C.test==Lec[i].test&&C.Tid==Lec[i].T_id&&C.time==Lec[i].time)
			ans++;
	return ans;
}
unsigned int Rank(Cou C,vector<Lecture> &Lec)
{
	unsigned int ans(1);
	for(unsigned int i=0;i<Lec.size();i++)
		if(C.credit==Lec[i].credit&&strcmp(C.name,Lec[i].Lec_name)==0&&strcmp(C.tea,Lec[i].T_name)==0&&C.test==Lec[i].test&&C.Tid==Lec[i].T_id&&C.time==Lec[i].time&&C.score<Lec[i].score)
			ans++;
	return ans;
}