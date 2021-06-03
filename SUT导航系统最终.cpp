#include<iostream>  
#include<string>  
#include<fstream>  
#include<Windows.h>  
#include"stdio.h"  
#include<ctype.h>  
#include<conio.h>  
#include<sstream> 
#include<graphics.h>

using namespace std;   
#define INFINITY 32767//���ֵ        
int have [15];//�Ͻ���˹���㷨�ĸ�������   
string info [15];//��ž�����Ϣ   
#define MAX_V 30//��󶥵����

typedef struct  
{  
    char* vexs[MAX_V]; 
	int vexx[MAX_V];
	int vexy[MAX_V];
	int arcs[MAX_V][MAX_V];   
	int vexnum,arcnum;
} MGraph;


//��½����  
void menu_main()  
{   
    cout<<"          ����������������������������������������������������������"<<endl;
	cout<<"          ��������                                          ��������"<<endl;
    cout<<"          ��������          ��ӭʹ��SUT����ϵͳ!            ��������"<<endl;
	cout<<"          ��������          --����յ�ͼʹ��                ��������" << endl;
    cout<<"          ��������          --��ѡ���½����                ��������"<<endl;
	cout<<"          ��������                                          ��������"<<endl;
    cout<<"          ��������           1   ����ϵͳ                   ��������"<<endl;
    cout<<"          ��������           0   �˳�ϵͳ                   ��������"<<endl;
	cout<<"          ��������                                          ��������"<<endl;
    cout<<"          ����������������������������������������������������������"<<endl;  
	cout<< "         ���������ѡ��1/0����";
}  


//�û����� 
void Y_menu()  
{  
    cout<<endl<<endl;  
	cout<<"          \3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"<<endl;
    cout<<"          \3\3\3\3\3\3\3                     \3\3\3\3\3\3\3"<<endl;
	cout<<"          \3\3\3\3\3\3\3  1   ��ѯ���·��   \3\3\3\3\3\3\3"<<endl;
    cout<<"          \3\3\3\3\3\3\3  0   �� �� ϵ  ͳ   \3\3\3\3\3\3\3"<<endl;
	cout<<"          \3\3\3\3\3\3\3                     \3\3\3\3\3\3\3"<<endl;
    cout<<"          \3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"<<endl;
    cout<<"          ���������ѡ��1/0����";  
}  


//��������ͼ  
void createUDN(MGraph &G)  
{  
    int i = 0,j=0;  
    G.vexnum = 26;  
    G.arcnum = 33;  
    G.vexs[0] = "����"; 
	G.vexx[0] = 304;
	G.vexy[0] = 165;
    G.vexs[1] = "����ѧԺ";  
	G.vexx[1] = 228;
	G.vexy[1] = 80;
    G.vexs[2] = "��ϢѧԺ"; 
	G.vexx[2] = 275;
	G.vexy[2] = 176;
    G.vexs[3] = "˼Դ·��";  
	G.vexx[3] = 332;
	G.vexy[3] = 298;
    G.vexs[4] = "���´�ҵѧԺ";  
	G.vexx[4] = 150;
	G.vexy[4] = 67;
    G.vexs[5] = "��ѧԺ";  
	G.vexx[5] = 177;
	G.vexy[5] = 100;
    G.vexs[6] = "��ѧ¥A��"; 
	G.vexx[6] = 234;
	G.vexy[6] = 201;
    G.vexs[7] = "��ѧ¥";  
	G.vexx[7] = 277;
	G.vexy[7] = 279;
    G.vexs[8] = "�Ŀ�¥��";  
	G.vexx[8] = 284;
	G.vexy[8] = 360;
    G.vexs[9] = "�Ŀ�¥��";  
	G.vexx[9] = 344;
	G.vexy[9] = 360;
    G.vexs[10] = "��ת��";
	G.vexx[10] = 336;
	G.vexy[10] = 408;
    G.vexs[11] = "C7��Ԣ";
	G.vexx[11] = 428;
	G.vexy[11] = 445;
	G.vexs[12] = "C6��Ԣ";
	G.vexx[12] = 351;
	G.vexy[12] = 450;
	G.vexs[13] = "C1��Ԣ";
	G.vexx[13] = 264;
	G.vexy[13] = 452;
	G.vexs[14] = "УҽԺ"; 
	G.vexx[14] = 260;
	G.vexy[14] = 408;
	G.vexs[15] = "���";
	G.vexx[15] = 215;
	G.vexy[15] = 408;
	G.vexs[16] = "��������";
	G.vexx[16] = 158;
	G.vexy[16] = 423;
	G.vexs[17] = "��ʳ��";
	G.vexx[17] = 158;
	G.vexy[17] = 366;
	G.vexs[18] = "B1��Ԣ";
	G.vexx[18] = 92;
	G.vexy[18] = 376;
	G.vexs[19] = "A2��Ԣ";
	G.vexx[19] = 59;
	G.vexy[19] = 254;
	G.vexs[20] = "˼Դ·��";
	G.vexx[20] = 137;
	G.vexy[20] = 293;
	G.vexs[21] = "��ʳ��";
	G.vexx[21] = 107;
	G.vexy[21] = 224;
	G.vexs[22] = "��ѧ����";
	G.vexx[22] = 127;
	G.vexy[22] = 254;
	G.vexs[23] = "ͼ���";
	G.vexx[23] = 180;
	G.vexy[23] = 226;
	G.vexs[24] = "��еѧԺ";
	G.vexx[24] = 125;
	G.vexy[24] = 121;
	G.vexs[25] = "����";
	G.vexx[25] = 108;
	G.vexy[25] = 88;

   for(i=0; i<G.vexnum; i++) //��ʼ��·������  
        for(j=0; j<G.vexnum; j++)  
       {  
           if(i==j)  
               G.arcs[i][j]=0;  
           else  
               G.arcs[i][j]=INFINITY;  
       } 

   //Ϊÿһ���߸�Ȩ  
   G.arcs[0][1]=G.arcs[1][0]=3.9;  
   G.arcs[0][2]=G.arcs[2][0]=0.8;  
   G.arcs[0][3]=G.arcs[3][0]=5;
   G.arcs[1][2]=G.arcs[2][1]=2.8;
   G.arcs[1][5]=G.arcs[5][1] =1.3;
   G.arcs[1][4]=G.arcs[4][1]=2.2;
   G.arcs[2][3] = G.arcs[3][2] = 3.4;
   G.arcs[2][6] = G.arcs[6][2] = 1.1;
   G.arcs[3][7] = G.arcs[7][3] = 1.4;
   G.arcs[3][9] = G.arcs[9][3] = 1;
   G.arcs[4][5] = G.arcs[5][4] = 1.3;
   G.arcs[4][25] = G.arcs[25][4] = 1.5;
   G.arcs[5][6] = G.arcs[6][5] = 3.2;
   G.arcs[5][24] = G.arcs[24][5] = 1.4;
   G.arcs[6][7] = G.arcs[7][6] = 2.4;
   G.arcs[6][23] = G.arcs[23][6] = 1.4;
   G.arcs[6][24] = G.arcs[24][6] = 3.7;
   G.arcs[7][8] = G.arcs[8][7] = 1.2;
   G.arcs[7][20] = G.arcs[20][7] = 3.4;
   G.arcs[8][9] = G.arcs[9][8] = 1.3;
   G.arcs[8][15] = G.arcs[15][8] = 2.4;
   G.arcs[9][10] = G.arcs[10][9] = 1.7;
   G.arcs[10][12] = G.arcs[12][10] = 1.2;
   G.arcs[10][14] = G.arcs[14][10] = 1.5;
   G.arcs[11][12]=G.arcs[12][11]=2;  
   G.arcs[12][13]=G.arcs[13][12]=2.3;  
   G.arcs[13][14]=G.arcs[14][13]=1.1;  
   G.arcs[13][16]=G.arcs[16][13]=2.6;  
   G.arcs[14][15]=G.arcs[15][14]=1.5;  
   G.arcs[15][16]=G.arcs[16][15]=1.5;  
   G.arcs[15][17] = G.arcs[17][15] = 2.1;
   G.arcs[16][17]=G.arcs[17][16]=1.5;  
   G.arcs[17][18]=G.arcs[18][17]=1.6;  
   G.arcs[17][20]=G.arcs[20][17]=2;
   G.arcs[18][19]=G.arcs[19][18]=2.7;
   G.arcs[19][22]=G.arcs[22][19]=1.7;
   G.arcs[19][21] = G.arcs[21][19] = 1.5;
   G.arcs[20][22] = G.arcs[22][20] = 1;
   G.arcs[21][22] = G.arcs[22][21] = 1.1;
   G.arcs[21][23] = G.arcs[23][21] = 2.2;
   G.arcs[21][25] = G.arcs[25][21] = 4.1;
   G.arcs[22][23] = G.arcs[23][22] = 1.6;
   G.arcs[24][25] = G.arcs[25][24] = 2.2;
}


//�Ͻ���˹���㷨  
void Djtsl(MGraph &G,int v0,int p[MAX_V][MAX_V],int d[])  
{  
    int v,w,i,j,min;  
    int final[MAX_V];  
    int k=1;  
    for(v=0; v<G.vexnum; ++v)  
    {  
       //��ʼ��  
       final[v]=0;  
       d[v]=G.arcs[v0-1][v];  
       for(w=0; w<G.vexnum; ++w)  
       p[v][w]=0;  
      if(d[v]<INFINITY)  
        {  
           p[v][v0-1]=1;  
           p[v][v]=1;  
        }  
    }  
    d[v0-1]=0;  
    final[v0-1]=1;  
    have[0]=v0-1;  
    for(i=1; i<G.vexnum; ++i)  
    {  
        //�����vexnum-1������  
        min=INFINITY;  
        for(w=0; w<G.vexnum; ++w)  
           if(!final[w])  
           if(d[w]<min) //����о�������ĵ�  
               {  
                    v=w;  
                    min=d[w];  
                }  
       final[v]=1;  
       have[k]=v;  
       k++;  
        for(w=0; w<G.vexnum; ++w) //���µ�ǰ���·��������  
            if(!final[w]&&(min+G.arcs[v][w]<d[w]))  
            {  
                d[w]=min+G.arcs[v][w];  
                for(j=0; j<G.vexnum; j++)  
                p[w][j]=p[v][j];  
                p[w][w]=1;  
            }  
    }  
}  


//�������������·��  
int shortPath()
{
	stringstream ss;
	string num_v0;
	string num_end;
	bool trail_v0;
	bool trail_end;
	MGraph G;
	createUDN(G);
	int v0, i, end;
	int P[MAX_V][MAX_V];
	int D[MAX_V];

	int R[MAX_V];
	int j = 0;

	cout << "���������(1-26):";
	cin >> num_v0;

	cout << "�������յ�(1-26):";
	cin >> num_end;

	v0 = atoi(num_v0.c_str());
	end = atoi(num_end.c_str());

	Djtsl(G, v0, P, D);

	initgraph(500, 500);      //����500*500����	
	IMAGE img;  //ͼ�����
	loadimage(&img, _T("1.jpg"), 500, 500, false);
	putimage(0, 0, &img);   //��ʾͼƬ
	BeginBatchDraw(); //��ʼ������ͼ
	setlinestyle(PS_SOLID, 3);   //���Ʊ��� �߿�Ϊ7
	setlinecolor(0x08BAFF);

	//cout << "���·���ǣ�"<<endl;  

	for (i = 0; i < G.vexnum; i++)
	{
		if (P[end - 1][have[i]] == 1)
		{	//cout << "-->"<<G.vexs[have[i]];
			R[j] = i;
			j++;
		}

	}
	for (i = 0; i < j-1; i++)
		line(G.vexx[have[R[i]]], G.vexy[have[R[i]]], G.vexx[have[R[i + 1]]], G.vexy[have[R[i + 1]]]);
   
	//cout << "   ·�����ȴ�Լ�ǣ�"<<D[end-1]*100 << "��" <<endl;
	wchar_t s[] = L"��Ϊ���滮�����·��";
	settextcolor(WHITE);   //���������ʽ
	settextstyle(0);
	outtextxy(100,100,s);
   

	FlushBatchDraw();   //�����ͼ

	EndBatchDraw();   //������ͼ
   
	return 0;
	system("pause");
}

void main()  
{  
    system("color B0");
    string choice_main;  
    string Y_choice;  
    string G_choice;  
    bool sign;   
    do  
    {  
		menu_main();
       cin>>choice_main;  
       if(choice_main=="0")  
       {  
          cout<<"�����˳�ϵͳ�����Ժ�..."<<endl;  
          Sleep(500);  
          return ;  
      }
        
        else if(choice_main == "1")  
        { 
           system("cls");
            do  
            {  
              Y_menu();  
              cin>>Y_choice; 
               if(Y_choice == "0")  
                {  
					cout<<"�����˳�ϵͳ..."<<endl;  
                    Sleep(500);  
               }             
                else if(Y_choice =="1")  
               {   
                   shortPath();  
               }  
               
             else  
              {  
                    cout<<"������ȷѡ����"<<endl;       
                }
               system("pause");  
               system("cls");  
            }  
           while(Y_choice!="0");  
        }  
        else  
        {  
            cout <<"����ȷѡ��"<<endl;  
            Sleep(500);  
            system("cls");  
       }  
    }  
    while(choice_main !="2" && choice_main !="1");  
}  
