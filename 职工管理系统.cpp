#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
void read(); //读取
void write();//保存
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
			
		
			cout<<"<------------职工工资管理系统------------>"<<endl;
			cout<<"|                 1.读取                 |"<<endl;
			cout<<"|                 2.保存                 |"<<endl;
			cout<<"|                 3.查询                 |"<<endl;
			cout<<"|                 4.浏览                 |"<<endl;
			cout<<"|                 5.修改                 |"<<endl;
			cout<<"|                 6.删除                 |"<<endl;
			cout<<"|                 7.添加                 |"<<endl;
			cout<<"|                 8.退出                 |"<<endl;
			cout<<"<---------------------------------------->"<<endl;
			cout<<"              请输入你的选择：            "<<endl;
 

		cin>>n;
		if(n<1||n>9)
		{
			w1=1;
            cout<<"你的选择不再范围内，请重新输入"<<endl;
			getchar();
		}
		else w1=0;
}
		while(w1==1);
switch(n)
	{
		case 1:read(); break;
	
    	case 2:find(); break;
		case 3:list(); break;
		case 4:modify(); break;
		//case 5:del(); break;
		case 6:add(); break;
    	case 7:cout<<"谢谢，欢迎下次启动"<<endl;
		default:exit(0);       }//退出系统

}

void read()
{

	ifstream in("gz.dat",ios::binary);
if(!in)
{
cout<<"Cannot open output file.\n";
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
	
}
	/*	cout<<zggz0[i].gongh<<"  "<<zggz0[i].name<<"  "<<zggz0[i].wage1<<"  "<<zggz0[i].wage2<<"  "
			<<zggz0[i].wage3<<"  "<<zggz0[i].wage4<<"  "<<zggz0[i].wage5<<"  "<<zggz0[i].wage6<<"  "<<zggz0[i].wage7<<endl;*/

void write(zggz *p,int j)
{
	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
		cout<<"Cannot open out put file"<<endl;
		abort();
	}
    for(int i=0;i<j+1;i++)
	{
		out.write((char *) &*p,sizeof(*p));  
		p++;
    }
	out.close();
}





void find()
{
  read();
	 
	      int j;
		  cout<<"请输入你要查询的工号："<<endl;
		  cin>>j;
		  if(1<=j&&j<=::number)
		  { cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  效绩工资  应发工资  实发工资"<<endl;
		   	cout<<::zggz0[j-1].gongh<<" "<<::zggz0[j-1].name<<" "<<::zggz0[j-1].wage1<<" "<<::zggz0[j-1].wage2
			<<" "<<::zggz0[j-1].wage3<<" "<<::zggz0[j-1].wage4<<" "<<::zggz0[j-1].wage5<<" "<<zggz0[j-1].wage6<<endl;  
		  }
	   else
		   cout<<"没有这一项数据"<<endl;
	   


}

void list()
{
     //read();
     cout<<"工号  姓名  岗位工资  薪级工资  职务津贴  效绩工资  应发工资  实发工资"<<endl;
	 cout<<::number<<endl;
	for(int i=0;i<::number;i++)
	{ 
		cout<<::zggz0[i].gongh<<" "<<::zggz0[i].name<<" "<<::zggz0[i].wage1<<" "<<::zggz0[i].wage2<<" "
			<<::zggz0[i].wage3<<" "<<::zggz0[i].wage4<<" "<<::zggz0[i].wage5<<" "<<zggz0[i].wage6<<endl;	
	} 
menu();


}  


void modify()
{

          int k,i=0,w,a1,a2,a3,a4;
		  zggz *q;
          cout<<"请输入你要修改的工号："<<endl;
		  cin>>k;
		  for(int j=0;j<::number;j++)
		  {    
			  
		 if (k==::zggz0[j].gongh)
		 {
		 cout<<"职员信息如下："<<endl;
		 cout<<"工号"<<"\t"<<"姓名"<<"\t"<<"岗位工资"<<"\t"<<"薪级工资"<<"\t"<<"职务工资"<<"\t"<<"效绩工资"<<"\t"<<"应发工资"<<"\t"<<"实发工资"<<endl;
		 cout<<::zggz0[j].gongh<<"\t"<<::zggz0[j].name<<"\t"<<::zggz0[j].wage1<<
			 "\t\t"<<::zggz0[j].wage2<<"\t\t"<<::zggz0[j].wage3<<"\t\t"<<::zggz0[j].wage4<<"\t\t"<<::zggz0[j].wage5<<"\t\t"<<zggz0[j].wage6<<endl;
	     cout<<"修改后的岗位工资："<<"  "; 
         cin>>a1;
		 cout<<"修改后的薪级工资："<<"  ";
		 cin>>a2;
		 cout<<"修改后的职务津贴："<<"  ";
		 cin>>a3;
		 cout<<"修改后的效绩工资："<<"  ";
		 cin>>a4;
		 ::zggz0[j].wage1=a1;
		 ::zggz0[j].wage2=a1;
		 ::zggz0[j].wage3=a1;
		 ::zggz0[j].wage4=a1;
		 }    
		 }
		  q=::zggz0;
		 cout<<"修改成功，保存（1），菜单（任意键）"<<endl;
		 cin>>w;
		 if(w==1)
			 write(q,::oup);
		 else
		 menu();
}


void add()
{
	int i;
	zggz zggz1[50],*p;
	p=zggz1;
	//read();
	for(int j=0;j<::number;j++)
	{
	 zggz1[j]=zggz0[j];
	
	}
	for(i=::number;i<50;i++)
	{
	int gongh1;
    char name1[20];
    float wage01,wage02,wage03,wage04;
	cout<<"请按顺序输入工号  姓名  岗位工资  薪级工资  职务津贴  效绩工资"<<endl;
    cin>>gongh1>>name1>>wage01>>wage02>>wage03>>wage04;
	zggz1[i].gongh=gongh1;
	strcpy(zggz1[i].name,name1);
	zggz1[i].wage1=wage01;
	zggz1[i].wage2=wage02;
	zggz1[i].wage3=wage03;
	zggz1[i].wage4=wage04;
	zggz1[i].wage5=wage01+wage02+wage03+wage04;
	zggz1[i].wage6=grsds(zggz1[i].wage5);
	zggz1[i].wage7=zggz1[i].wage5-zggz1[i].wage6;
    cout<<"是否继续添加？(0(否)/1(是))"<<endl;
	int k;
	cin>>k;
	if(k==0)
	{
		break;
	}

	}
	write(p,i);
     menu();

}
void grsds(int i)//求职工应发工资，个人所得税，实发工资
{
		zggz0[i].wage5=zggz0[i].wage1+zggz0[i].wage2+zggz0[i].wage3+zggz0[i].wage4;//计算应得工资
		if(zggz0[i].wage5>100000)//计算不同工资的对应个人所得税
		{
			zggz0[i].wage6=(zggz0[i].wage5-100000)*0.45+8000+7000+6000+5000+3000+450+150+25;
		}
		else if(zggz0[i].wage5>80000)
		{
			zggz0[i].wage6=(zggz0[i].wage5-80000)*0.4+7000+6000+5000+3000+450+150+25;
		}
		else if(zggz0[i].wage5>60000)
		{
			zggz0[i].wage6=(zggz0[i].wage5-60000)*0.35+6000+5000+3000+450+150+25;
		}
		else if(zggz0[i].wage5>40000)
		{
			zggz0[i].wage6=(zggz0[i].wage5-40000)*0.3+5000+3000+450+150+25;
		}
		else if(zggz0[i].wage5>20000)
		{
			zggz0[i].wage6=(zggz0[i].wage5-20000)*0.25+3000+450+150+25;
		}
		else if(zggz0[i].wage5>5000)
		{
			zggz0[i].wage6=(zggz0[i].wage5-5000)*0.2+450+150+25;
		}
		else if(zggz0[i].wage5>2000)
		{
			zggz0[i].wage6=(zggz0[i].wage5-2000)*0.15+150+25;
		}
		else if(zggz0[i].wage5>500)
		{
			zggz0[i].wage6=(zggz0[i].wage5-500)*0.1+150+25;
		}
		else if(zggz0[i].wage5<500)
		{
			zggz0[i].wage6=zggz0[i].wage5*0.05;
		}
		zggz0[i].wage7=zggz0[i].wage5-zggz0[i].wage6;//计算实得工资
	
}
