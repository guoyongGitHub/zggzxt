/*************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
File name: Staff information management system // �ļ���
Author: ��Ӿ Version: 1.0 Date: 2018.6.29 // ���ߡ��汾���������
Description: 
���ж�ְ����Ϣ��1.��ѯ 2.�޸� 3.��� 4.ɾ�� 5.���� 6.����Ȳ�����
//������ϸ˵���˳����ļ���ɵ���Ҫ���ܣ�������ģ������Ľӿڣ�
//���ֵ��ȡֵ��Χ�����弰������Ŀ��ơ�˳�򡢶����������ȹ�ϵ
read()��ȡ���ݡ�find()��ѯ��modify()�޸ġ�add()��ӡ�del()ɾ����write()���桢list()���
Others: �ó�����Ҫ�����ڱ����Ͻ���gz.dat�ļ�// �������ݵ�˵��
Function List: // ��Ҫ�����б�ÿ����¼Ӧ���������������ܼ�Ҫ˵��
1. read() //��ȡ���� 
2. find() //��ѯ 
3. modify() //�޸� 
4. add() //��� 
5. del() //ɾ�� 
6. write() //���� 
7. list() //���
9.grsds() //�����������˰
10.menu() //������
11.main() //���˵�
History: // �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ���
1. Date:2018.6.29
Author:��Ӿ
Modification:���г����Ű�
*************************************************/



#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;
void read(); //��ȡ
void find();//��ѯ
void list();//���
void modify();//�޸�
void del();//ɾ��
void add();//���
int grsds(float a);//�����������˰
void menu();//������
int number,oup;//ְ������
struct zggz
{  
		int gongh;
		char name[20];
		float wage1;        //��λ����
		float wage2;        //н������
		float wage3;		//ְ�����
		float wage4;        //��Ч����
        float wage5;        //Ӧ������
		float wage6;        //��������˰
		float wage7;        //ʵ������
};
zggz zggz0[50]; //ȫ�ֱ�������
zggz *p;  //ȫ�ֱ���ָ��
void write(zggz *p,int j);//����

void main()
	{
	    read();  //�������е��ö�ȡ����
		menu();  //�������е��������溯��
	}
void menu()  //������
	{
		int n,w1;
		do
		{
			printf("\n");
			printf("\n");
			printf("###\t��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ\t###\n");
			printf("\n");
			printf("\n");
		    printf("��ѡ��1-7����\n");
			printf("================================================================\n");
			printf("|           1.��ѯְ�����ʼ�¼                                 |\n");
			printf("|           2.�޸�ְ�����ʼ�¼                                 |\n");
			printf("|           3.���ְ�����ʼ�¼                                 |\n");
			printf("|           4.ɾ��ְ�����ʼ�¼                                 |\n");
			printf("|           5.�������ݵ��ļ�                                   |\n");
			printf("|           6.���ְ����¼                                     |\n");
			printf("|           7.�˳�ϵͳ                                         |\n");	
			printf("================================================================\n");
			printf("\n");
			printf("���ѡ����:\n");
 

		scanf("%d",&n);
		if(n<1||n>7)
		{
			w1=1;
            printf("���ѡ���ٷ�Χ�ڣ�����������\n");
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
    	case 7:printf("лл����ӭ�´�����\n");
		default:exit(0);      
			
}//�˳�ϵͳ
        

read();
		

}

/*************************************************
Function: // read
Description: // ��ȡְ���������ݺ���,������ִ��ʱҪ���úͱ�����õĵ�һ������
Called By: // main()
Input: // �����ļ��Ķ�ȡ
Output: // �������ļ����ݴ���zggz0[]
Return: // ��������ֵ��˵��
*************************************************/

void read()  //��ȡְ����Ϣ����
{

	ifstream in("gz.dat",ios::binary);
    if(!in)
	{
    printf("Cannot open output file.\n");
	abort();  //�˳�����
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
	
/*************************************************
Function: // write
Description: // ����ְ���������ݺ���
Called By: // main()
Output: // ��zggz0[]���ݴ��뱾���ļ�
*************************************************/

void write(zggz *p,int j)  //���溯��
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
	printf("���ڱ�������\n");
	printf("Ϊ�㷵�����˵�\n");
	system("pause");
	system("cls");
	read();
	menu();
	
}

/*************************************************
Function: // find
Description: // ��ѯְ���������ݺ���
Called By: // main()
Input: // ���̼��빤��
Output: // ����ض�ְ������
*************************************************/

void find()  //���Һ���
{
	int k,i=0,w;
    loop:printf("��������Ҫ��ѯ�Ĺ���\n");//cout<<"��������Ҫ��ѯ�Ĺ��ţ�"<<endl;
    scanf("%d",&k);
	for(int j=0;j<::number;j++)
	{
		if (k==::zggz0[j].gongh)
		{
		   printf("����\t����\t��λ����\tн������\tְ�����\tЧ������\tӦ������\tʵ������\n");
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
		   printf("���²�ѯ�밴1����������ز˵�\n");
		   scanf("%d",&w);
		   if(w==1)
			   goto loop;
		   else 
			   menu();
		}
	}
		   if(i!=k)
		   {
		   printf("û�����ְԱ����Ϣ�����²�ѯ(1)����������ز˵�\n");
		   scanf("%d",&w);
		   if(w==1)
			   goto loop;
		   else 
			   menu();
		   }
}

/*************************************************
Function: // list
Description: //���ְ���������ݺ���
Called By: // main()
Output: // ���ȫ��ְ������
*************************************************/

void list()  //�������
{  
	if(::number==0)
	{
		printf("�ִ��� %d",::number);
        printf("��Ա����Ϣ\n");
        printf("\n");
   	}
	else
	{
        printf("����\t����\t��λ����\tн������\tְ�����\tЧ������\tӦ������\tʵ������\n");	
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
	printf("�������ز˵�\n");
	system("pause");
    menu();

}  

/*************************************************
Function: // read
Description: 	// �޸�ְ���������ݺ���
Called By: // main()
Input: // ���̼��빤��
*************************************************/

void modify()
{
	int k,i=0,w,a1,a2,a3,a4;
    zggz *q;
    loop:printf("��������Ҫ�޸ĵĹ��ţ�\n");
    scanf("%d",&k);
	for(int j=0;j<::number;j++)
	{
		if (k==::zggz0[j].gongh)
		 {
			printf("ְԱ��Ϣ���£�\n");
		    printf("����\t����\t��λ����\tн������\tְ�����\tЧ������\tӦ������\tʵ������\n");	
		    printf("%d\t%s\t%g\t\t%g\t\t%g\t\t%g\t\t%g\t\t%g\n",
		    ::zggz0[j].gongh,
		    ::zggz0[j].name,
		    ::zggz0[j].wage1,
		    ::zggz0[j].wage2,
		    ::zggz0[j].wage3,
		    ::zggz0[j].wage4,
		    ::zggz0[j].wage5,
		    ::zggz0[j].wage7,"\n");  
	        printf("�޸ĺ�ĸ�λ���ʣ�\t\n"); 
            scanf("%d",&a1);
		    printf("�޸ĺ��н�����ʣ�\t\n");
		    scanf("%d",&a2);
		    printf("�޸ĺ��ְ�������\t\n");
		    scanf("%d",&a3);
		    printf("�޸ĺ��Ч�����ʣ�\t\n");
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
		    printf("�޸ĳɹ�������(1)����������ز˵�\n");
		    scanf("%d",&w);
		    if(w==1)
				write(q,::oup);
		    else
			    menu();
		 }
	}
	if(i!=j)
	{
		printf("û�����ְԱ����Ϣ�����²�ѯ��1������������ز˵�\n");
		scanf("%d",&w);
		if(w==1)
			goto loop;
	    else 
			menu();
	}
}

/*************************************************
Function: // del
Description: //ɾ��ְ���������ݺ���
Called By: // main()
Input: // ���̼��빤��
Output: // �޸�zggz0[]����
*************************************************/

void del() //ɾ������
{
	 ::p=::zggz0;
	 int gonghao;
	 printf("������Ҫɾ����Ա�����ţ�\n");
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
	 
	  printf("�Ƿ�ȷ��ɾ����ȷ��ɾ����Y��, ��������ز˵�");
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

}//ɾ��

/*************************************************
Function: // add
Description: // ���ְ������
Called By: // main()
Input: // ���̼���ְ������
Output: // �����ݴ���zggz0[]
*************************************************/

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
	printf("�밴˳�����빤��\t����\t��λ����\tн������\tְ�����\tЧ������\n");
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
    printf("�Ƿ������ӣ�(0(��)/1(��))\n");
	int k;
	scanf("%d",&k);
	if(k==0)
	{
		break;
	
	}

	}
	printf("�뷵�ز˵�����\n");
    printf("�������ز˵�\n");
    system("pause");
	
    menu();

  

}


/*************************************************
Function: // grsds
Description: // ��������˰����
Calls: // ��
Called By: // modify(), add()
Output: // ��zggz0[i].wage6��ֵ
*************************************************/

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
