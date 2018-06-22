#include<iostream>
#include<fstream>
#include<string>
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
int n;//职工总数
	
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
		menu();
	}
void menu() 
	{
		int n,w1;
		do
		{
			system("cls");
		
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
	//	case 4:modify(); break;
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
		cout<<"打开文件失败"<<endl;
		abort();//退出程序
	}

	in.read((char *) &::zggz0,sizeof(::zggz0));
	in.close;
	for(int n=0;n<50;n++)
	{ 
	if(::zggz0[n].gongh!=NULL)
		::n=::zggz0[n].gongh;
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
		  if(1<=j&&j<=::n)
		  {
		   	cout<<::zggz0[j-1].gongh<<" "<<::zggz0[j-1].name<<" "<<::zggz0[j-1].wage1<<" "<<::zggz0[j-1].wage2
			<<" "<<::zggz0[j-1].wage3<<" "<<::zggz0[j-1].wage4<<" "<<::zggz0[j-1].wage5<<" "<<zggz0[j-1].wage6<<endl;  
		  }
	   else
		   cout<<"没有这一项数据"<<endl;
	   


}

void list()
{
 read();
	for(int i=0;i<::n;i++)
	{

		cout<<::zggz0[i].gongh<<" "<<::zggz0[i].name<<" "<<::zggz0[i].wage1<<" "<<::zggz0[i].wage2<<" "
			<<::zggz0[i].wage3<<" "<<::zggz0[i].wage4<<" "<<::zggz0[i].wage5<<" "<<zggz0[i].wage6<<endl;
	}
menu();


}  







void add()
{
	int i;
	zggz zggz1[50],*p;
	p=zggz1;
	read();
	cout<<::n<<endl;
	for(int j=0;j<::n;j++)
	{
	 zggz1[j]=zggz0[j];
	
	}
	for(i=::n;i<100;i++)
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


	}
	write(p,i);
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
