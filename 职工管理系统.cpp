#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define NUM 1000
    void read(); //��ȡ
	void write();//����
	void find();//��ѯ
	void list();//���
	void modify();//�޸�
	void del();//ɾ��
	void add();//���
	int grsds(float a);//�����������˰
	void menu();//������
	int n;//ְ������
	
struct zggz
{  
		int gongh;
		char name[8];
		float wage1;        //��λ����
		float wage2;        //н������
		float wage3;		//ְ�����
		float wage4;        //��Ч����
        float wage5;        //Ӧ������
		float wage6;        //��������˰
		float wage7;        //ʵ������
};


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
		
			cout<<"<------------ְ�����ʹ���ϵͳ------------>"<<endl;
			cout<<"|                 1.��ȡ                 |"<<endl;
			cout<<"|                 2.����                 |"<<endl;
			cout<<"|                 3.��ѯ                 |"<<endl;
			cout<<"|                 4.���                 |"<<endl;
			cout<<"|                 5.�޸�                 |"<<endl;
			cout<<"|                 6.ɾ��                 |"<<endl;
			cout<<"|                 7.���                 |"<<endl;
			cout<<"|                 8.�˳�                 |"<<endl;
			cout<<"<---------------------------------------->"<<endl;
			cout<<"              ���������ѡ��            "<<endl;
 

		cin>>n;
		if(n<1||n>9)
		{
			w1=1;
            cout<<"���ѡ���ٷ�Χ�ڣ�����������"<<endl;
			getchar();
		}
		else w1=0;
}
		while(w1==1);
switch(n)
	{
		case 1:read(); break;
	
	//	case 2:find(); break;
	//	case 3:list(); break;
	//	case 4:modify(); break;
		//case 5:del(); break;
		case 6:add(); break;
    	case 7:cout<<"лл����ӭ�´�����"<<endl;
		default:exit(0);       }//�˳�ϵͳ

}

void read()
{
	zggz zggz0[50];
	ifstream in("gz.dat",ios::binary);
	if(!in)
	{
		cout<<"���ļ�ʧ��"<<endl;
		abort();//�˳�����
	}
	for(int i=0;i<50;i++)
	{
		in.read((char *) &zggz0[i],sizeof(zggz0[i]));
		cout<<zggz0[i].gongh <<"  "<<zggz0[i].name<<"  "<<zggz0[i].wage1<<"  "<<zggz0[i].wage2<<"  "
			<<zggz0[i].wage3<<"  "<<zggz0[i].wage4<<"  "<<zggz0[i].wage5<<"  "<<zggz0[i].wage6<<"  "<<zggz0[i].wage7<<endl;
	}
	in.close();
}
void write(zggz zggz0)
{
	ofstream out("gz.dat",ios::binary);
	if(!out)
	{
		cout<<"���ļ�ʧ��"<<endl;
		abort();
	}

		out.write((char *) &zggz0,sizeof(zggz0));

	out.close();
}
void find()
{
}
void add()
{
	zggz zggz1[50];
	int gongh1;
    char name1[8];
    float wage01,wage02,wage03,wage04;
	for(int i=0;i<50;i++)
	{
	cout<<"�밴˳�����빤��  ����  ��λ����  н������  ְ�����  Ч������"<<endl;
    cin>>gongh1>>" ">>name1>>" ">>wage01>>" ">>wage02>>" ">>wage03>>" ">>wage04;
	zggz1[i].gongh=gongh1;
	strcpy(zggz1[i].name,name1);
	zggz1[i].wage1=wage01;
	zggz1[i].wage2=wage02;
	zggz1[i].wage3=wage03;
	zggz1[i].wage4=wage04;
	zggz1[i].wage5=wage01+wage02+wage03+wage04;
	zggz1[i].wage6=grsds(zggz1[i].wage5);
	zggz1[i].wage7=zggz1[i].wage5-zggz1[i].wage6;
	write(zggz1[i]);

	}
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
