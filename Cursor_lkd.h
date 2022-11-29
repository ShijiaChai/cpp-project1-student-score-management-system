#include<Windows.h>
#include<conio.h>
#include<ctime>
struct Cou
{
	bool test;
	unsigned short time;
	unsigned short score;
	unsigned short credit;
	char *name;
	char *tea;
	unsigned int Tid;
	bool operator<(const Cou &a)
	{
		if(time!=a.time)
			return time<a.time;
		if((!test)&&(!a.test))
			return credit>a.credit;
		if(test&&a.test)
			return score==a.score?credit>a.credit:score>a.score;
		if(test)
			return true;
		else
			return false;
	}
};
class CURSOR
{
public:
	CURSOR()
	{
		welldone();
		return;
	}
	~CURSOR()
	{
		return;
	}
	void cls()
	{
		X=Y=0;
		gotoxy();
		setcolor();
		printf("%s","                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                ");
		X=Y=0;
		gotoxy();
		return;
	}
	void end()
	{
		cls();
		Norprint(9,"chaishijia设计",15,0);
		Norprint(10,"感谢使用，谢谢",15,0);
		Sleep(1600);
		for(unsigned i=0;i<2000;i++)
		{
			setcolor(0,rand()%16);
			printf("%c",' ');
		}
		welldone();
		for(unsigned j,i=0;i<320;i++)
		{
			for(j=0;j<i*i/700;j++)
			{
				X=rand()%80;
				Y=rand()%25;
				gotoxy();
				if(X!=79||Y!=24)
					printf("%c",' ');
			}
			Sleep(4);
		}
		cls();
		clock_t cl(clock());
		char str[16]="将在5.2秒后退出";
		while(clock()-cl<=5200)
		{
			str[4]=(5200+cl-clock())/1000%10+48;
			str[6]=(5200+cl-clock())/100%10+48;
			Norprint(10,str,15,0);
		}
		return;
	}
	void setcolor(unsigned char foreground=7,unsigned char background=0)
	{
		HANDLE hOut(GetStdHandle(STD_OUTPUT_HANDLE));
		SetConsoleTextAttribute(hOut,foreground+background*16);
		return;
	}
	void sound(char c)
	{
		switch(c)
		{
		case 'R':
			Beep(323,250);
			Beep(384,350);
			break;
		case 'W':
			Beep(575,280);
			Beep(512,250);
			break;
		case ' ':
			Beep(323,350);
			break;
		}
		return;
	}
	bool confirm(unsigned char y,unsigned char foreground,unsigned char background)
	{
		char c(0);
		bool ans(true);
		while(c!=13&&c!=32)
		{
			if(ans)
			{
				X=23;Y=y;
				gotoxy();
				setcolor(background,0);
				printf("%c",'<');
				setcolor(0,background);
				printf("%s","确认");
				setcolor(background,0);
				printf("%c",'>');
				X=50;Y=y;
				gotoxy();
				setcolor(foreground,0);
				printf("%s"," 取消 ");
			}
			else
			{
				X=23;Y=y;
				gotoxy();
				setcolor(foreground,0);
				printf("%s"," 确认 ");
				X=50;Y=y;
				gotoxy();
				setcolor(background,0);
				printf("%c",'<');
				setcolor(0,background);
				printf("%s","取消");
				setcolor(background,0);
				printf("%c",'>');
			}
			c=getch();
			if(c=='a'||c=='A')
				ans=true;
			if(c=='d'||c=='D')
				ans=false;
			if(c==8)
				ans=!ans;
		}
		return ans;
	}
	void Norprint(unsigned char y,char *s,unsigned char foreground,unsigned char background,unsigned char x=0)
	{
		Y=y;
		if(x==0)
			X=(80-strlen(s))/2;
		else
			X=x;
		gotoxy();
		setcolor(foreground,background);
		printf("%s",s);
		welldone();
		return;
	}
	void Norprint(unsigned char y,unsigned short s,unsigned char foreground,unsigned char background,unsigned char x=0)
	{
		Y=y;
		if(x==0)
			X=(80-6)/2;
		else
			X=x;
		gotoxy();
		setcolor(foreground,background);
		printf("%hu",s);
		welldone();
		return;
	}
	void Norprint(unsigned char y,unsigned int s,unsigned char foreground,unsigned char background,unsigned char x=0)
	{
		Y=y;
		if(x==0)
			X=(80-6)/2;
		else
			X=x;
		gotoxy();
		setcolor(foreground,background);
		printf("%u",s);
		welldone();
		return;
	}
	void Norprint(unsigned char y,double s,unsigned char foreground,unsigned char background,unsigned char x=0)
	{
		Y=y;
		if(x==0)
			X=(80-6)/2;
		else
			X=x;
		gotoxy();
		setcolor(foreground,background);
		printf("%.3lf",s);
		welldone();
		return;
	}
	void Chosenprint(unsigned char y,char L,char *s,char R,unsigned char foreground,unsigned char background)
	{
		Y=y;
		X=(80-strlen(s))/2-1;
		gotoxy();
		setcolor(background,0);
		printf("%c",L);
		setcolor(foreground,background);
		printf("%s",s);
		setcolor(background,0);
		printf("%c",R);
		welldone();
		return;
	}
	unsigned char Chose(unsigned char n,char L,char *s[],char R,unsigned char pos[],unsigned char foreground,unsigned char background,bool Esc=false)
	{
		char c(0);
		unsigned char ans(0);
		while(c!=13&&c!=8&&c!=32)
		{
			for(unsigned char i=0;i<n;i++)
				if(i==ans)
					if(background>8)
						Chosenprint(pos[i],L,s[i],R,0,background);
					else
						Chosenprint(pos[i],L,s[i],R,15,background);
				else
					Chosenprint(pos[i],' ',s[i],' ',foreground,0);
			c=getch();
			if(c=='w'||c=='W')
				if(ans)
					ans--;
				else if(Esc)
					return 99;
			if(c=='s'||c=='S')
				if(ans!=n-1)
					ans++;
				else if(Esc)
					return 100;
			if(c==27&&Esc)
			{
				ans=127;
				break;
			}
		}
		sound(' ');
		return ans;
	}
	char Waitscanchar()
	{
		return getch();
	}
	void scan(unsigned char y,unsigned char len,char *s,bool secrecy=false)
	{//8_Backspace 13_Enter 32_space
		X=(80-len)/2;
		Y=y;
		gotoxy();
		setcolor();
		char c(0),i(0);
		while(c!=13)
		{
			if(i==len)
				cursor_reveal(false);
			else
				cursor_reveal(true);
			c=Waitscanchar();
			if(c==8)
			{
				if(i)
				{
					X=(80-len)/2+i-1;
					Y=y;
					gotoxy();
					printf("%c",' ');
					X=(80-len)/2+i-1;
					Y=y;
					gotoxy();
					i--;
				}
				continue;
			}
			if(c==13)
			{
				s[i++]='\0';
				break;
			}
			if(i!=len)
			{
				s[i++]=c;
				if(secrecy)
					printf("%c",'*');
				else
					printf("%c",c);
			}
		}
		/*for(char i=0;i<len;i++)
		{
			
			s[i]=Waitscanchar();
			if(s[i]==8)
			{
				if(i==0)
				{
					i--;
					continue;
				}
				X=(80-len)/2+i-1;
				Y=y;
				gotoxy();
				printf("%c",' ');
				X=(80-len)/2+i-1;
				Y=y;
				gotoxy();
				i-=2;
				continue;
			}
			if(s[i]==13)
			{
				s[i]='\0';
				break;
			}
			if(secrecy)
				printf("%c",'*');
			else
				printf("%c",s[i]);
		}*/
		s[len]='\0';
		welldone();
		return;
	}
	void Background()
	{
		setcolor(11,0);
		for(unsigned char i=0;i<80;i++)
		{
			X=i;Y=0;
			gotoxy();
			printf("%c",4);
			X=i;Y=24;
			gotoxy();
			printf("%c",4);
		}
		for(unsigned char i=0;i<25;i++)
		{
			X=0;Y=i;
			gotoxy();
			printf("%c",4);
			X=79;Y=i;
			gotoxy();
			printf("%c",4);
		}
		welldone();
		return;
	}
	void TeaBackground()
	{
		setcolor(0,13);
		for(X=1;X!=80;X++)
		{
			Y=0;
			gotoxy();
			printf("%c",' ');
			Y=24;
			gotoxy();
			printf("%c",' ');
		}
		for(Y=0;Y!=25;Y++)
		{
			X=0;
			gotoxy();
			printf("%c",' ');
			X=79;
			gotoxy();
			printf("%c",' ');
		}
		welldone();
		return;
	}
	void EraseBackground_1()
	{
		for(unsigned char i=0;i<80;i+=2)
		{
			X=i;Y=0;
			gotoxy();
			printf("%c",' ');
			Sleep(1);
		}
		for(unsigned char i=0;i<25;i+=2)
		{
			X=79;Y=24-i;
			gotoxy();
			printf("%c",' ');
			if(Y==24)
				welldone();
			Sleep(4);
		}
		for(unsigned char i=0;i<80;i+=2)
		{
			X=79-i;Y=24;
			gotoxy();
			printf("%c",' ');
			if(X==79)
				welldone();
			Sleep(1);
		}
		for(unsigned char i=0;i<25;i+=2)
		{
			X=0;Y=24-i;
			gotoxy();
			printf("%c",' ');
			Sleep(4);
		}
		for(unsigned char i=1;i<80;i+=2)
		{
			X=i;Y=0;
			gotoxy();
			printf("%c",' ');
			Sleep(1);
		}
		for(unsigned char i=1;i<25;i+=2)
		{
			X=79;Y=24-i;
			gotoxy();
			printf("%c",' ');
			Sleep(4);
		}
		for(unsigned char i=1;i<80;i+=2)
		{
			X=79-i;Y=24;
			gotoxy();
			printf("%c",' ');
			Sleep(1);
		}
		for(unsigned char i=1;i<25;i+=2)
		{
			X=0;Y=24-i;
			gotoxy();
			printf("%c",' ');
			Sleep(4);
		}
		cls();
		Cursor.Norprint(5,"请输入密码：",15,0);
		Cursor.Norprint(13,"            ",0,14);
		X=34;Y=14;
		gotoxy();
		setcolor(0,14);
		printf("%s","  ");
		X=44;Y=14;
		gotoxy();
		printf("%s","  ");
		Cursor.Norprint(15,"            ",0,14);
		return;
	}
	void Tea_Create(char T_name[],char *T_department,unsigned int &T_id)
	{
		cls();
		Norprint(5,"请您输入：",13,0);
		Norprint(9,"姓名：",15,0,30);
		Norprint(12,"系别：",15,0,30);
		Norprint(15,"ID号：",15,0,30);
		scan(9,8,T_name,false);
		cursor_reveal(true);
		X=36;Y=12;gotoxy();
		scanf("%s",T_department);
		X=36;Y=15;gotoxy();
		scanf("%u",&T_id);
		cursor_reveal(false);
		return;
	}
	bool Tea_confirm(char T_name[],char *T_department,unsigned int T_id)
	{
		cls();
		Norprint(5,"请您输入：",13,0);
		Norprint(9,"姓名：",15,0,30);
		Norprint(9,T_name,7,0,36);
		Norprint(12,"系别：",15,0,30);
		Norprint(12,T_department,7,0,36);
		Norprint(15,"ID号：",15,0,30);
		X=36;Y=15;gotoxy();
		printf("%u",T_id);
		return confirm(19,10,14);
	}
	void Stu_Create(char Stu_name[],char *Stu_department,unsigned short &grade,unsigned int &Stu_id)
	{
		cls();
		Norprint(3,"请输入：",14,0);
		Norprint(7,"姓名：",15,0,30);
		Norprint(10,"系别：",15,0,30);
		Norprint(13,"入学：",15,0,30);
		Norprint(16,"学号：",15,0,30);
		scan(7,8,Stu_name,false);
		cursor_reveal(true);
		X=36;Y=10;gotoxy();
		scanf("%s",Stu_department);
		X=36;Y=13;gotoxy();
		scanf("%hu",&grade);
		X=36;Y=16;gotoxy();
		scanf("%u",&Stu_id);
		cursor_reveal(false);
		return;
	}
	bool Stu_confirm(char Stu_name[],char *Stu_department,unsigned short grade,unsigned int Stu_id)
	{
		cls();
		Norprint(3,"请输入：",14,0);
		Norprint(7,"姓名：",15,0,30);
		Norprint(7,Stu_name,7,0,36);
		Norprint(10,"系别：",15,0,30);
		Norprint(10,Stu_department,7,0,36);
		Norprint(13,"入学：",15,0,30);
		X=36;Y=13;gotoxy();
		printf("%hu",grade);
		Norprint(16,"学号：",15,0,30);
		X=36;Y=16;gotoxy();
		printf("%u",Stu_id);
		return confirm(20,11,10);
	}
	void Lec_Create(unsigned int &T,unsigned int &S,unsigned short &time,char name[],unsigned short &credit,unsigned short &gpa,unsigned short &test)
	{
		char c;
		cls();
		Norprint(2,"请您输入：",10,0);
		Norprint(6,"教师ID号：",15,0,26);
		Norprint(8,"学生学号：",15,0,26);
		Norprint(10,"课程年份：",15,0,26);
		Norprint(12,"课程名称：",15,0,26);
		Norprint(14,"课程学分：",15,0,26);
		Norprint(16,"(0为不计分，否则计分) 是否计分：",15,0,4);
		cursor_reveal(true);
		X=36;Y=6;gotoxy();
		scanf("%u",&T);
		X=36;Y=8;gotoxy();
		scanf("%u",&S);
		X=36;Y=10;gotoxy();
		scanf("%hu",&time);
		X=36;Y=12;gotoxy();
		scanf("%s",name);
		X=36;Y=14;gotoxy();
		scanf("%hu",&credit);
		X=36;Y=16;gotoxy();
		c=getch();
		X=36;Y=16;gotoxy();
		if(c=='0'||c==')')
		{
			test=0;
			printf("%s","是");
		}
		else
		{
			test=1;
			printf("%s","是");
		}
		if(test)
		{
			Norprint(18,"课程成绩：",15,0,26);
			X=36;Y=18;gotoxy();
			scanf("%hu",&gpa);
		}
		else
			gpa=0;
		cursor_reveal(false);
		return;
	}
	bool Lec_confirm(unsigned int T,unsigned int S,unsigned short id,char name[],unsigned short credit,unsigned short gpa,unsigned short test)
	{
		cls();
		Norprint(2,"请您输入：",10,0);
		Norprint(6,"教师ID号：",15,0,26);
		Norprint(8,"学生学号：",15,0,26);
		Norprint(10,"课程年份：",15,0,26);
		Norprint(12,"课程名称：",15,0,26);
		Norprint(14,"课程学分：",15,0,26);
		Norprint(16,"(0为不计分，否则计分) 是否计分：",15,0,4);
		X=36;Y=6;gotoxy();
		printf("%u",T);
		X=36;Y=8;gotoxy();
		printf("%u",S);
		X=36;Y=10;gotoxy();
		printf("%hu",id);
		X=36;Y=12;gotoxy();
		printf("%s",name);
		X=36;Y=14;gotoxy();
		printf("%hu",credit);
		X=36;Y=16;gotoxy();
		if(test)
		{
			printf("%s","是");
			Norprint(18,"课程成绩：",15,0,26);
			X=36;Y=18;gotoxy();
			printf("%hu",gpa);
		}
		else
			printf("%s","否");
		return confirm(21,13,10);
	}
	void Inspect(char department[])
	{
		cls();
		Norprint(5,"请您输入其系别",14,0);
		Norprint(7,"请务必与录入时一致",14,0);
		Norprint(11,"系别：",15,0,28);
		X=34;Y=11;
		gotoxy();
		cursor_reveal(true);
		scanf("%s",department);
		cursor_reveal(false);
		fflush(stdin);
		return;
	}
	unsigned int Stu_op(unsigned int x,unsigned int *ID,char **NAME,unsigned short *GRADE,double *GPA)
	{
		char c(0);
		unsigned char n[7]={9,11,13,15,17,19,21},t;
		unsigned int ans(0),page(1),Page(x%7?x/7+1:x/7);
		cls();
		Norprint(3,"请您选择：",12,0);
		Norprint(4,"页数：   /",12,0,33);
		Norprint(4,page,12,0,39);
		Norprint(4,Page,12,0,45);
		setcolor(15,0);
		X=18;Y=7;
		gotoxy();
		printf("%s","学号          姓名       入学年份      成绩");
		while(c!=13&&c!=8&&c!=32)
		{
			if(page==Page)
				t=x%7;
			else
				t=7;
			if(t==0)
				t=7;
			for(unsigned char i=0;i<t;i++)
				if(i==ans)
				{
					Y=n[i];
					X=13;
					gotoxy();
					setcolor(15,0);
					printf("%s","→");;
					setcolor(11,0);
					Y=n[i];
					X=18;
					gotoxy();
					printf("%u            ",ID[i+page*7-7]);
					X=32;
					gotoxy();
					printf("%s            ",NAME[i+page*7-7]);
					X=45;
					gotoxy();
					printf("%hu            ",GRADE[i+page*7-7]);
					X=57;
					gotoxy();
					printf("%.2lf            ",GPA[i+page*7-7]);
				}
				else
				{
					Y=n[i];
					X=13;
					gotoxy();
					setcolor();
					printf("%s","  ");
					setcolor();
					Y=n[i];
					X=18;
					gotoxy();
					printf("%u            ",ID[i+page*7-7]);
					X=32;
					gotoxy();
					printf("%s            ",NAME[i+page*7-7]);
					X=45;
					gotoxy();
					printf("%hu            ",GRADE[i+page*7-7]);
					X=57;
					gotoxy();
					printf("%.2lf            ",GPA[i+page*7-7]);
				}
				welldone();
			c=getch();
			if(c=='w'||c=='W')
				if(ans)
					ans--;
				else if(page!=1)
				{
					ans=6;
					page--;
					cls();
					Norprint(3,"请您选择：",12,0);
					Norprint(4,"页数：   /",12,0,33);
					Norprint(4,page,12,0,39);
					Norprint(4,Page,12,0,45);
					setcolor(15,0);
					X=18;Y=7;
					gotoxy();
					printf("%s","学号          姓名       入学年份      成绩");
				}
			if(c=='s'||c=='S')
				if(ans!=t-1)
					ans++;
				else if(page!=Page)
				{
					ans=0;
					page++;
					cls();
					Norprint(3,"请您选择：",12,0);
					Norprint(4,"页数：   /",12,0,33);
					Norprint(4,page,12,0,39);
					Norprint(4,Page,12,0,45);
					setcolor(15,0);
					X=18;Y=7;
					gotoxy();
					printf("%s","学号          姓名       入学年份      成绩");
				}
			if(c==27)
			{
				ans=2147483647;
				break;
			}
		}
		sound(' ');
		return ans+page*7-7;
	}
	unsigned int idinput()
	{
		cls();
		Norprint(5,"请输入其ID编号：",13,0);
		cursor_reveal(true);
		Y=12;
		X=35;
		gotoxy();
		unsigned int ans;
		scanf("%u",&ans);
		cursor_reveal(false);
		cls();
		return ans;
	}
	void idinput(unsigned int &ans,unsigned int &ansT,unsigned short &time,char *name)
	{
		cls();
		Norprint(3,"请您输入：",13,0);
		Norprint(7,"学生学号：",15,0,32);
		Norprint(10,"教师ID号：",15,0,32);
		Norprint(13,"上课年份：",15,0,32);
		Norprint(16,"课程名称：",15,0,32);
		cursor_reveal(true);
		Y=7;
		X=42;
		gotoxy();
		scanf("%u",&ans);
		Y=10;
		X=42;
		gotoxy();
		scanf("%u",&ansT);
		Y=13;
		X=42;
		gotoxy();
		scanf("%hu",&time);
		Y=16;
		X=42;
		gotoxy();
		scanf("%s",name);
		cursor_reveal(false);
		cls();
		return;
	}
	void password(char PASS[])
	{
		char name[9],WORD[9],xin[9];
		cls();
		Cursor.Norprint(2,"  请输入原密码：",15,0);
		Cursor.Norprint(4,"            ",0,14);
		X=34;Y=5;
		gotoxy();
		setcolor(0,14);
		printf("%s","  ");
		X=44;Y=5;
		gotoxy();
		printf("%s","  ");
		Cursor.Norprint(6,"            ",0,14);
		Cursor.Norprint(9,"  请输入新密码：",15,0);
		Cursor.Norprint(11,"            ",0,11);
		X=34;Y=12;
		gotoxy();
		setcolor(0,11);
		printf("%s","  ");
		X=44;Y=12;
		gotoxy();
		printf("%s","  ");
		Cursor.Norprint(13,"            ",0,11);
		Cursor.Norprint(16,"确定新密码：",15,0);
		Cursor.Norprint(18,"            ",0,11);
		X=34;Y=19;
		gotoxy();
		setcolor(0,11);
		printf("%s","  ");
		X=44;Y=19;
		gotoxy();
		printf("%s","  ");
		Cursor.Norprint(20,"            ",0,11);
		Cursor.scan(5,8,WORD,true);
		Cursor.scan(12,8,name,true);
		Cursor.scan(19,8,xin,true);
		if(strcmp(PASS,WORD)!=0)
		{
			Cursor.cls();
			Cursor.Norprint(7,"操作失败",12,0);
			Cursor.Norprint(9,"×",12,0);
			Cursor.Norprint(12,"原密码输入不正确",12,0);
			Cursor.sound('W');
			Sleep(2500);
			return;
		}
		else if(strcmp(name,xin)!=0)
		{
			Cursor.cls();
			Cursor.Norprint(7,"操作失败",12,0);
			Cursor.Norprint(9,"×",12,0);
			Cursor.Norprint(12,"两次密码输入不一致",12,0);
			Cursor.sound('W');
			Sleep(2500);
			return;
		}
		else if(strcmp(name,"")==0)
		{
			Cursor.cls();
			Cursor.Norprint(7,"操作失败",12,0);
			Cursor.Norprint(9,"×",12,0);
			Cursor.Norprint(12,"密码不能为空",12,0);
			Cursor.sound('W');
			Sleep(2500);
			return;
		}
		strcpy(PASS,xin);
		Cursor.cls();
		Cursor.Norprint(7,"操作成功",10,0);
		Cursor.Norprint(9,"√",10,0);
		Cursor.sound('R');
		Sleep(1800);
		return;
	}
	void Backstu()
	{
		for(unsigned char i=0;i<80;i++)
		{
			X=i;
			Y=24;
			gotoxy();
			printf("%c",' ');
			if(X==79)
				welldone();
			X=79-i;
			Y=0;
			gotoxy();
			printf("%c",' ');
			Sleep(1);
		}
		for(unsigned char i=1;i<24;i++)
		{
			X=0;
			Y=i;
			gotoxy();
			printf("%c",' ');
			Sleep(2);
			X=79;
			Y=24-i;
			gotoxy();
			printf("%c",' ');
		}
		cls();
		return;
	}
	unsigned int inputid()
	{
		Norprint(5,"请输入你的学号",13,0);
		unsigned int ans;
		X=36;Y=10;
		gotoxy();
		cursor_reveal(true);
		scanf("%u",&ans);
		cursor_reveal(false);
		return ans;
	}
	unsigned int Lec_op(unsigned int x,Cou *C)
	{
		char c(0);
		unsigned char n[7]={9,11,13,15,17,19,21},t;
		unsigned int ans(0),page(1),Page(x%7?x/7+1:x/7);
		cls();
		Norprint(3,"请选择要查询的课程（按Esc键退出）：",10,0);
		Norprint(4,"页数：   /",10,0,33);
		Norprint(4,page,10,0,39);
		Norprint(4,Page,10,0,45);
		setcolor(15,0);
		X=12;Y=7;
		gotoxy();
		printf("%s","时间       名称                任课教师     学分      成绩");
		while(c!=13&&c!=8&&c!=32)
		{
			if(page==Page)
				t=x%7;
			else
				t=7;
			if(t==0)
				t=7;
			for(unsigned char i=0;i<t;i++)
				if(i==ans)
				{
					Y=n[i];
					X=7;
					gotoxy();
					setcolor(15,0);
					printf("%s","→");;
					setcolor(11,0);
					Y=n[i];
					X=12;
					gotoxy();
					printf("%hu            ",C[i+page*7-7].time);
					X=22;
					gotoxy();
					printf("%s                                                  ",C[i+page*7-7].name);
					X=44;
					gotoxy();
					printf("%s            ",C[i+page*7-7].tea);
					X=57;
					gotoxy();
					printf("%hu            ",C[i+page*7-7].credit);
					X=67;
					gotoxy();
					if(C[i+page*7-7].test)
						printf("%hu            ",C[i+page*7-7].score);
					else
						printf("%c               ",'-');
				}
				else
				{
					Y=n[i];
					X=7;
					gotoxy();
					setcolor();
					printf("%s","  ");
					setcolor();
					Y=n[i];
					X=12;
					gotoxy();
					printf("%hu            ",C[i+page*7-7].time);
					X=22;
					gotoxy();
					printf("%s                                                  ",C[i+page*7-7].name);
					X=44;
					gotoxy();
					printf("%s            ",C[i+page*7-7].tea);
					X=57;
					gotoxy();
					printf("%hu            ",C[i+page*7-7].credit);
					X=67;
					gotoxy();
					if(C[i+page*7-7].test)
						printf("%hu            ",C[i+page*7-7].score);
					else
						printf("%c               ",'-');
				}
				welldone();
			c=getch();
			if(c=='w'||c=='W')
				if(ans)
					ans--;
				else if(page!=1)
				{
					ans=6;
					page--;
					cls();
					Norprint(3,"请选择要查询的课程（按Esc键退出）：",10,0);
					Norprint(4,"页数：   /",10,0,33);
					Norprint(4,page,10,0,39);
					Norprint(4,Page,10,0,45);
					setcolor(15,0);
					X=12;Y=7;
					gotoxy();
					printf("%s","时间       名称                任课教师     学分      成绩");
				}
			if(c=='s'||c=='S')
				if(ans!=t-1)
					ans++;
				else if(page!=Page)
				{
					ans=0;
					page++;
					cls();
					Norprint(3,"请选择要查询的课程（按Esc键退出）：",10,0);
					Norprint(4,"页数：   /",10,0,33);
					Norprint(4,page,10,0,39);
					Norprint(4,Page,10,0,45);
					setcolor(15,0);
					X=12;Y=7;
					gotoxy();
					printf("%s","时间       名称                任课教师     学分      成绩");
				}
			if(c==27)
			{
				ans=2147483647;
				break;
			}
		}
		sound(' ');
		return ans+page*7-7;
	}
private:
	unsigned char X,Y,Color; //(X,Y):(0,0)~(79,24)
	void welldone()
	{
		X=Y=0;
		setcolor(7,0);
		gotoxy();
		cursor_reveal(false);
		return;
	}
	void getxy() 
	{
		HANDLE hOut(GetStdHandle(STD_OUTPUT_HANDLE));
		CONSOLE_SCREEN_BUFFER_INFO cci;
		GetConsoleScreenBufferInfo(hOut,&cci); 
		X=(unsigned char)cci.dwCursorPosition.X;
		Y=(unsigned char)cci.dwCursorPosition.Y;
		return;
	}
	void cursor_reveal(bool flag)
	{
		HANDLE hOut(GetStdHandle(STD_OUTPUT_HANDLE));
		CONSOLE_CURSOR_INFO cci;
		GetConsoleCursorInfo(hOut,&cci);
		cci.bVisible=flag;
		SetConsoleCursorInfo(hOut,&cci);
		return;
	}
	void gotoxy()
	{
		HANDLE hOut(GetStdHandle(STD_OUTPUT_HANDLE));
		COORD pos;
		pos.X=X;
		pos.Y=Y;
		SetConsoleCursorPosition(hOut,pos);
		return;
	}
}Cursor;
