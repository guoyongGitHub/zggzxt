#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
void read(); //读取
void find();//查询
void list();//浏览
void modify();//修改
void del();//删除
void add();//添加
int grsds(float a);//计算个人所得税
void menu();//主界面
int number,oup;//职工总数
struct zggz
{  
		int gongh;
		char name[20];
		float wage1;        //岗位工资
		float wage2;        //薪级工资
		float wage3;		//职务津贴
		float wage4;        //绩效工资
        float wage5;        //应发工资
		float wage6;        //个人所得税
		float wage7;        //实发工资
};
zggz zggz0[50];
zggz *p;
void write(zggz *p,int j);//保存

void main()
	{
	    read();
		menu();
	}
void menu() 
	{
		int n,w1;
		do
		{
			printf("\n");
			printf("\n");
			printf("###\t欢迎使用广西民族大学软件与信息安全学院职工工资管理系统\t###\n");
			printf("\n");
			printf("\n");
		    printf("请选择（1-7）：\n");
			printf("================================================================\n");
			printf("|           1.查询职工工资记录                                 |\n");#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;
void read(); //读取
void find();//查询
void list();//浏览
void modify();//修改
void del();//删除
void add();//添加
int grsds(float a);//计算个人所得税
void menu();//主界面
int number,oup;//职工总数
struct zggz
{  
		int gongh;
		char name[20];
		float wage1;        //岗位工资
		float wage2;        //薪级工资
		float wage3;		//职务津贴
		float wage4;        //绩效工资
        float wage5;        //应发工资
		float wage6;        //个人所得税
		float wage7;        //实发工资
};
zggz zggz0[50]; //全局变量数组
zggz *p;  //全局变量指针
void write(zggz *p,int j);//保存

void main()
	{
	    read();
		menu();
	}
void menu() 
	{
		int n,w1;
		do
		{
			printf("\n");
			printf("\n");
			printf("###\t欢迎使用广西民族大学软件与信息安全学院职工工资管理系统\t###\n");
			printf("\n");
			printf("\n");
		    printf("请选择（1-7）：\n");
			printf("================================================================\n");
			printf("|           1.查询职工工资记录                                 |\n");
			printf("|           2.修改职工工资记录                                 |\n");
			printf("|           3.添加职工工资记录                                 |\n");
			printf("|           4.删除职工工资记录                                 |\n");
			printf("|           5.保存数据到文件                                   |\n");
			printf("|           6.浏览职工记录                                     |\n");
			printf("|           7.退出系统                                         |\n");	
			printf("================================================================\n");
			printf("\n");
			printf("你的选择是:\n");
 

		scanf("%d",&n);
		if(n<1||n>7)
		{
			w1=1;
            printf("你的选择不再范围内，请重新输入\n");
			getchar();
		}
		else w1=0;
}
		while(w1==1);
switch(n)
	{
		case 1:find();break;
    	case 2:modify(); break;
		case 3:add(); break;
		case 4:del(); break;
		case 5:write(::p,::oup); break;
		case 6:list(); break;
    	case 7:printf("谢谢，欢迎下次启动\n");
		default:exit(0);      
			
}//退出系统
        

read();
		

}

void read()
{

	ifstream in("gz.dat",ios::binary);
if(!in)
{
printf("Cannot open output file.\n");
	abort();  //退出程序
}
in.read((char *)&::zggz0,sizeof(::zggz0));
	in.close();
for(int n=0;n<50;n++)
	{ 
	if(::zggz0[n].gongh!=NULL)
		::number=n+1;
	else
		break;
	}
   menu();
	
}
	

void write(zggz *p,int j)
{
	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
		printf("Cannot open out put file");
		abort();
	}
    for(int i=0;i<j+1;i++)
	{
		out.write((char *) &*p,sizeof(*p));  
		p++;
    }
	out.close();
	printf("正在保存数据\n");
	printf("为你返回主菜单\n");
	system("pause");
	system("cls");
	read();
	menu();
	
}




void find()
{
  
	      int k,i=0,w;
          loop:printf("请输入你要查询的工号\n");//cout<<"请输入你要查询的工号："<<endl;
		  scanf("%d",&k);
		  for(int j=0;j<::number;j++)
		  {    
			  
				 if (k==::zggz0[j].gongh)
				 {
		   
			printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t效绩工资\t应发工资\t实发工资\n");
		   	printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",
				::zggz0[j].gongh,
				::zggz0[j].name,
				::zggz0[j].wage1,
				::zggz0[j].wage2,
				::zggz0[j].wage3,
				::zggz0[j].wage4,
				::zggz0[j].wage5,
				::zggz0[j].wage7);  
		    i=k;
				 printf("重新查询请按1，任意键返回菜单\n");
				 scanf("%d",&w);
			     if(w==1)
				   goto loop;
			     else 
				   menu();
				 }
		  }
		  if(i!=k)
		  {
		   printf("没有这个职员的信息，重新查询(1)，任意键返回菜单\n");
		   scanf("%d",&w);
			   if(w==1)
				   goto loop;
			   else 
				   menu();
		  }
	   

          

}

void list()
{  
	if(::number==0)
	{
    printf("现存有 %d",::number);
    printf("条员工信息\n");
    printf("\n");
    
	}
	else
	{
    printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t效绩工资\t应发工资\t实发工资\n");	
	for(int i=0;i<::number;i++)
	{ 
	printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",
		::zggz0[i].gongh,
		::zggz0[i].name,
		::zggz0[i].wage1,
		::zggz0[i].wage2,
		::zggz0[i].wage3,
		::zggz0[i].wage4,
		::zggz0[i].wage5,
		zggz0[i].wage7);  
	} 
	}
	printf("即将返回菜单\n");
	system("pause");
    menu();

}  


void modify()
{

          int k,i=0,w,a1,a2,a3,a4;
		  zggz *q;
          loop:printf("请输入你要修改的工号：\n");
		  scanf("%d",&k);
		  for(int j=0;j<::number;j++)
		  {    
			  
		 if (k==::zggz0[j].gongh)
		 {
		 printf("职员信息如下：\n");
		 printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t效绩工资\t应发工资\t实发工资\n");	
		 printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",
		 ::zggz0[j].gongh,
		 ::zggz0[j].name,
		 ::zggz0[j].wage1,
		 ::zggz0[j].wage2,
		 ::zggz0[j].wage3,
		 ::zggz0[j].wage4,
		 ::zggz0[j].wage5,
		 ::zggz0[j].wage7,"\n");  
	     printf("修改后的岗位工资：\t\n"); 
         scanf("%d",&a1);
		 printf("修改后的薪级工资：\t\n");
		 scanf("%d",&a2);
		 printf("修改后的职务津贴：\t\n");
		 scanf("%d",&a3);
		 printf("修改后的效绩工资：\t\n");
		 scanf("%d",&a4);
		  i=j;
		 ::zggz0[j].wage1=a1;
		 ::zggz0[j].wage2=a2;
		 ::zggz0[j].wage3=a3;
		 ::zggz0[j].wage4=a4;
		 ::zggz0[j].wage5=a1+a2+a3+a4;
		 ::zggz0[j].wage6=grsds(::zggz0[j].wage5);
		 ::zggz0[j].wage7=::zggz0[j].wage5-::zggz0[j].wage6;
		 q=::zggz0;
		 printf("修改成功，保存(1)，任意键返回菜单\n");
		 scanf("%d",&w);
		 if(w==1)
			 write(q,::oup);
		 else
			 menu();
		 }
		  }
			   if(i!=j)
		  {
		   printf("没有这个职员的信息，重新查询（1），任意键返回菜单\n");
		   scanf("%d",&w);
			   if(w==1)
				   goto loop;
			   else 
				   menu();
		  }
			 
}


void del()
{
	 ::p=::zggz0;
	 int gonghao;
	 printf("请输入要删除的员工工号：\n");
	 scanf("%d",&gonghao);
	 for(int i=0;i<::number;i++)
	 {
		 if(gonghao==::zggz0[i].gongh)
		 {
			 if(i!=::number)
			 {
				 for(;i<::number;i++)
				 {
					 ::zggz0[i]=::zggz0[i+1];
				 }
				 ::number=::number-1;
			 }
			 else
			 {
				 ::number=::number-1;
			 }
		 }
		 }
	 
	  printf("是否确认删除，确定删除（Y）, 任意键返回菜单");
		char g;
	    scanf("%s",&g);
		if(g=='Y')
		{
			write(::p,::number);
		}
		else
		{
			menu();
		}

}//删除


void add()
{
	int i;
	zggz zggz1[50];
	::p=zggz1;
	for(int j=0;j<::number;j++)
	{
	 zggz1[j]=zggz0[j];	
	}
	for(i=::number;i<50;i++)
	{
	int gongh1;
    char name1[20];
    float wage01,wage02,wage03,wage04;
	printf("请按顺序输入工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t效绩工资\n");
    scanf("%d",&gongh1);
	scanf("%s",name1);
	scanf("%f",&wage01);
	scanf("%f",&wage02);
	scanf("%f",&wage03);
	scanf("%f",&wage04);
	zggz1[i].gongh=gongh1;
	strcpy(zggz1[i].name,name1);
	zggz1[i].wage1=wage01;
	zggz1[i].wage2=wage02;
	zggz1[i].wage3=wage03;
	zggz1[i].wage4=wage04;
	zggz1[i].wage5=wage01+wage02+wage03+wage04;
	zggz1[i].wage6=grsds(zggz1[i].wage5);
	zggz1[i].wage7=zggz1[i].wage5-zggz1[i].wage6;
	::oup=i;
    printf("是否继续添加？(0(否)/1(是))\n");
	int k;
	scanf("%d",&k);
	if(k==0)
	{
		break;
	
	}

	}
	printf("请返回菜单保存\n");
    printf("即将返回菜单\n");
    system("pause");
	
    menu();

  

}
int grsds(float a)
{
	float i;
	if(a<500)
	{
		i=a-a*0.05; 
	}
	else if(a>500&&a<=2000)
	{
		i=(a-500)*0.1+25;
	}
	else if(a>2000&&a<=5000)
	{
		i=(a-2000)*0.15+150+25;
	}
	else if(a>5000&&a<=20000)
	{
		i=(a-5000)*0.2+450+150+25;
	}
	else if(a>20000&&a<=40000)
	{
		i=(a-20000)*0.25+3000+450+150+25;
	}
	else if(a>40000&&a<=60000)
	{
		i=(a-40000)*0.3+5000+3000+450+150+25;
	}
	else if(a>60000&&a<=80000)
	{
		i=(a-60000)*0.35+6000+5000+3000+450+150+25;
	}
	else if(a>80000&&a<=100000)
	{
		i=(a-80000)*0.4+7000+6000+5000+3000+450+150+25;
	}
	else if(a>100000)
	{
		i=(a-100000)*0.45+8000+7000+6000+5000+3000+450+150+25;
	}
	return i;
}

			printf("|           2.修改职工工资记录                                 |\n");
			printf("|           3.添加职工工资记录                                 |\n");
			printf("|           4.删除职工工资记录                                 |\n");
			printf("|           5.保存数据到文件                                   |\n");
			printf("|           6.浏览职工记录                                     |\n");
			printf("|           7.退出系统                                         |\n");	
			printf("================================================================\n");
			printf("\n");
			printf("你的选择是:\n");
 

		scanf("%d",&n);
		if(n<1||n>7)
		{
			w1=1;
            printf("你的选择不再范围内，请重新输入\n");
			getchar();
		}
		else w1=0;
}
		while(w1==1);
switch(n)
	{
		case 1:find();break;
    	case 2:modify(); break;
		case 3:add(); break;
		case 4:del(); break;
		case 5:write(::p,::oup); break;
		case 6:list(); break;
    	case 7:printf("谢谢，欢迎下次启动\n");
		default:exit(0);      
			
}//退出系统
        

read();
		

}

void read()
{

	ifstream in("gz.dat",ios::binary);
if(!in)
{
printf("Cannot open output file.\n");
	abort();  //退出程序
}
in.read((char *)&::zggz0,sizeof(::zggz0));
	in.close();
for(int n=0;n<50;n++)
	{ 
	if(::zggz0[n].gongh!=NULL)
		::number=n+1;
	else
		break;
	}
menu();
	
}
	

void write(zggz *p,int j)
{
	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
		printf("Cannot open out put file");
		abort();
	}
    for(int i=0;i<j+1;i++)
	{
		out.write((char *) &*p,sizeof(*p));  
		p++;
    }
	out.close();
	printf("正在保存数据\n");
	printf("为你返回主菜单\n");
	read();
	
}




void find()
{
  
	      int k,i=0,w;
          loop:printf("请输入你要查询的工号");//cout<<"请输入你要查询的工号："<<endl;
		  scanf("%d",&k);
		  for(int j=0;j<::number;j++)
		  {    
			  
				 if (k==::zggz0[j].gongh)
				 {
		   
			printf("工号  姓名  岗位工资  薪级工资  职务津贴  效绩工资  应发工资  实发工资\n");
		   	printf("%d     %s      %g      %g      %g      %g      %g      %g\n",::zggz0[j].gongh,::zggz0[j].name,
				::zggz0[j].wage1,::zggz0[j].wage2,::zggz0[j].wage3,::zggz0[j].wage4,::zggz0[j].wage5,zggz0[j].wage7);  
		    i=k;
				 printf("重新查询请按1，任意键返回菜单\n");
				 scanf("%d",&w);
			     if(w==1)
				   goto loop;
			     else 
				   menu();
				 }
		  }
		  if(i!=k)
		  {
		   printf("没有这个职员的信息，重新查询请按1，任意键返回菜单\n");
		   scanf("%d",&w);
			   if(w==1)
				   goto loop;
			   else 
				   menu();
		  }
	   

          

}

void list()
{
     //read();
     printf("现存有 %d",::number);
	 printf("条员工信息\n");
     printf("\n");
     printf("工号  姓名  岗位工资  薪级工资  职务津贴  效绩工资  应发工资  实发工资\n");
	
	for(int i=0;i<::number;i++)
	{ 
	printf("%d     %s      %g      %g      %g      %g      %g      %g\n",::zggz0[i].gongh,::zggz0[i].name,::zggz0[i].wage1,::zggz0[i].wage2
			,::zggz0[i].wage3,::zggz0[i].wage4,::zggz0[i].wage5,zggz0[i].wage7);  
	} 
menu();


}  


void modify()
{

          int k,i=0,w,a1,a2,a3,a4;
		  zggz *q;
          loop:printf("请输入你要修改的工号：\n");
		  scanf("%d",&k);
		  for(int j=0;j<::number;j++)
		  {    
			  
		 if (k==::zggz0[j].gongh)
		 {
		 printf("职员信息如下：\n");
		 printf("工号    姓名     岗位工资      薪级工资     职务工资     效绩工资     应发工资     实发工资\n");

		 printf("%d     %s      %g      %g      %g      %g      %g      %g\n",::zggz0[j].gongh,::zggz0[j].name,::zggz0[j].wage1,::zggz0[j].wage2
			,::zggz0[j].wage3,::zggz0[j].wage4,::zggz0[j].wage5,zggz0[j].wage7,"\n");  
	     printf("修改后的岗位工资：\t\n"); 
         scanf("%d",&a1);
		 printf("修改后的薪级工资：\t\n");
		 scanf("%d",&a2);
		 printf("修改后的职务津贴：\t\n");
		 scanf("%d",&a3);
		 printf("修改后的效绩工资：\t\n");
		 scanf("%d",&a4);
		  i=j;
		 ::zggz0[j].wage1=a1;
		 ::zggz0[j].wage2=a2;
		 ::zggz0[j].wage3=a3;
		 ::zggz0[j].wage4=a4;
		 ::zggz0[j].wage5=a1+a2+a3+a4;
		 ::zggz0[j].wage6=grsds(::zggz0[j].wage5);
		 ::zggz0[j].wage7=::zggz0[j].wage5-::zggz0[j].wage6;
		 q=::zggz0;
		 printf("修改成功，保存请按1，任意键返回菜单\n");
		 scanf("%d",&w);
		 if(w==1)
			 write(q,::oup);
		 else
			 menu();
		 }
		  }
			   if(i!=j)
		  {
		   printf("没有这个职员的信息，重新查询（1），菜单（任意键）\n");
		   scanf("%d",&w);
			   if(w==1)
				   goto loop;
			   else 
				   menu();
		  }
			 
}


void del()
{
	::p=::zggz0;
	 int gonghao;
	 cout<<"请输入要删除的员工工号："<<endl;
	 cin>>gonghao;
	 for(int i=0;i<::number;i++)
	 {
		 if(gonghao==::zggz0[i].gongh)
		 {
			 if(i!=::number-1)
			 {
				 for(;i<::number;i++)
				 {
					 ::zggz0[i]=::zggz0[i+1];
				 }
				 ::number=::number-1;
			 }
			 else
			 {
				 ::number=::number-1;
			 }
		 }
		 }
	 write(::p,::number);
}//删除*/


void add()
{
	int i;
	zggz zggz1[50];
	::p=zggz1;
	for(int j=0;j<::number;j++)
	{
	 zggz1[j]=zggz0[j];	
	}
	for(i=::number;i<50;i++)
	{
	int gongh1;
    char name1[20];
    float wage01,wage02,wage03,wage04;
	printf("请按顺序输入工号  姓名  岗位工资  薪级工资  职务津贴  效绩工资\n");
    scanf("%d",&gongh1);
	scanf("%s",name1);
	scanf("%f",&wage01);
	scanf("%f",&wage02);
	scanf("%f",&wage03);
	scanf("%f",&wage04);
	zggz1[i].gongh=gongh1;
	strcpy(zggz1[i].name,name1);
	zggz1[i].wage1=wage01;
	zggz1[i].wage2=wage02;
	zggz1[i].wage3=wage03;
	zggz1[i].wage4=wage04;
	zggz1[i].wage5=wage01+wage02+wage03+wage04;
	zggz1[i].wage6=grsds(zggz1[i].wage5);
	zggz1[i].wage7=zggz1[i].wage5-zggz1[i].wage6;
	::oup=i;
    printf("是否继续添加？(0(否)/1(是))\n");
	int k;
	scanf("%d",&k);
	if(k==0)
	{
		break;
	
	}

	}
	
	
    menu();

  

}
int grsds(float a)
{
	float i;
	if(a<500)
		i=a-a*0.05;   
	else if(a>500&&a<2000)
		i=(a-500)*0.1+25;
	else if(a>2000&&a<5000)
		i=(a-2000)*0.15+150+25;
	else if(a>5000&&a<20000)
		i=(a-5000)*0.2+450+150+25;
	else if(a>20000&&a<40000)
		i=(a-20000)*0.25+3000+450+150+25;
	else if(a>40000&&a<60000)
		i=(a-40000)*0.3+5000+3000+450+150+25;
	else if(a>60000&&a<80000)
		i=(a-60000)*0.35+6000+5000+3000+450+150+25;
	else if(a>80000&&a<100000)
		i=(a-80000)*0.4+7000+6000+5000+3000+450+150+25;
	else if(a>100000)
		i=(a-100000)*0.45+8000+7000+6000+5000+3000+450+150+25;
	return i;
}

