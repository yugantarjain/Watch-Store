#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
fstream sf,tf;
int y=5;			//watch size
int p=-1;			//wnnp class (pointer recog)
int x=(80-((2*y+1)*3))/4;      	//free space between watches
int z=2;			//alignment variable
int shift=(80-(16)-(2*x)-3*(2*y+1))/2+(16)-x;	//x2=16 , vert line column
//using namespace std;
//void ta3(char x[],int spe);
//void wipe(int wc1,int wr1,int wc2,int wr2,int spe);
//void watch(int c,int r,int m);
void order();
void menu();
//void create();
//void home(int a);
//void ctrdisp(int a);
void pointer();
//void log(char file[20]);
//void pchange(int a,int b);
//void search(char se[20]);

class wnnp
{
	char brand[10],price[10];
	char infor[4][30];
	public:
		int pno;
		void assign();	//asign brand and price to six strd watches
		void custom()	//enter nnp for custom watch in create()
		{
			brand[0]='\0';
			price[0]='\0';
		}
		void showid(int x1,int x2,int y)
		{
			gotoxy(x1,y);
			cout<<infor[0];
			gotoxy(x2,y);
			cout<<infor[2];
		}
		void showb()	//show brand
		{
			cout<<brand;
		}
		void showp()	//show price
		{
			cout<<price;
		}
		void showbi()
		{
			cout<<char(toupper(brand[0]));
		}
		void enterb()
		{
			cin>>brand;
		}
		void enterp()
		{
			cin>>price;
		}
		void transin(char in[30],int a)
		{
			strcpy(infor[a],in);
		}
		void display(int c,int r)
		{
			gotoxy(c,r);
			cout<<"NAME      - "<<infor[0]<<"\n";
			gotoxy(c,r+1);
			cout<<"ADDRESS   - "<<infor[1]<<"\n";
			gotoxy(c,r+2);
			cout<<"PHONE NO. - "<<infor[2]<<"\n";
			gotoxy(c,r+3);
			cout<<"E-MAIL    - "<<infor[3]<<"\n\n";
		}
		int find(char f[20]);
};
wnnp w[7],s;
void wnnp::assign()
{
	char brand2[3][10]={"Titan","Casio","Timex"};
	for(int a=0;a<=5;a++)
	{
		int x=p/2;                         //set brand name
		strcpy(brand,brand2[x]);

		if(p%2==0)			  //set price
		strcpy(price,"8000");
		else
		strcpy(price,"5000");
	}
}
int wnnp::find(char f[20])
{
	clrscr();
	int a,b,c,d,e;
	int g=0;
	char td[3][30],tw[30];
	a=strlen(f);		//word to search for
	strcpy(td[0],infor[0]); //temp info to be used
	strcpy(td[1],brand);
	strcpy(td[2],price);
	for(c=0;c<=2;c++)
	{
		b=strlen(td[c]);
		for(d=0;d<=b-a;d++)		//no of words to be formed
		{
			for(e=0;e<=a-1;e++)	//word formation
			{
				tw[e]=td[c][e+d];
			}
			tw[e]='\0';
			if(strcmpi(tw,f)==0)
			{
				cout<<tw<<endl;
				g=1;
				break;
			}
		}
	}
	return g;
}

void ta3(char x[],int spe=15)			//simple wipe
{
	int a=strlen(x);
	for(int b=0;b<=a-1;b++)
	{
		cout<<x[b];
		delay(spe);
	}
}
void wipe(int wc1,int wr1,int wc2,int wr2,int spe=6)		//wipe screen l-r
{
	for(int wc=wc1;wc<=wc2;wc++)
	{
		for(int wr=wr1;wr<=wr2;wr++)
		{
			gotoxy(wc,wr);
			cout<<" ";
		}
		delay(spe);
	}
}
void watch(int c,int r,int m=0)
{
	for(int b=r;b<=r+y;b=b+y)            //top and bottom resp 2y+1*
	{
		gotoxy(c,b);
		for(int a=1;a<=(y*2+1);a++)
		{
			cout<<"_";
		}

	}
	int e=220;                                //emosym variable
	for(b=c;b<=c+(2*y);b=b+(2*y))             //left and right resp y*
	{
		e++;
		for(int a=1;a<=y;a++)
		{

			gotoxy(b,r+a);
			cout<<char(e);
		}
	}
	gotoxy((c+y),r+(y/2));                 //hands
	cout<<"³";
	gotoxy((c+y),r+y/2+1);
	cout<<"ùÄÄ";
	p++;					//wnnp iden
	gotoxy((c+y),r+(y/2)+2);		//brand initial
	w[p].showbi();
	gotoxy(c+1,r+y+1);                     //brand and price disp
	{
		w[p].showb();
	}
	gotoxy(c+1,r+y+2);
	{
		if(m==0)
		cout<<"Rs.";
		w[p].showp();
	}
}
void create()
{
	w[6].custom();                  //assign custom watch its nnp
	clrscr();
	p=5;                            //watch() will inc it and make it 6
	int c,r;
	c=x;
	r=(25-y)/2-1;
	gotoxy(c+20,r+y/2+1);
	ta3("Enter BRAND and PRICE");
	watch(c,r,1);			//display watch and take brand and price
	gotoxy(c+1,r+y+1);		//enter brand
	w[p].enterb();
	gotoxy((c+y),r+(y/2)+2);	//brand initial
	w[p].showbi();
	gotoxy(c+1,r+y+2);		//enter price
	cout<<"Rs.";
	w[p].enterp();
	wipe(c+20,r+y/2,c+50,r+y/2+1,10);
	order();
}
void home(int c)
{
	p=-1;
	int r=x+2*y+1;                  //add to x for next column of watches
	int z2=z+2;			//adj z for 1st row

	watch(c,z2);			//1st column of watches
	watch(c,z2+4+y);

	watch(c+r,z2);                   //2nd
	watch(c+r,z2+4+y);

	watch(c+2*r,z2);                 //3rd
	watch(c+2*r,z2+4+y);
	//cont=0;
}

void ctrdisp(int a=0)
{
	int b=23;
	gotoxy(76,z);                      //control guide
	cout<<"W";
	gotoxy(74,z+1);
	cout<<"A-|-D";
	gotoxy(76,z+2);
	cout<<"S";
	gotoxy(65,b);
	cout<<"ENTER - Select";
	if(a==1)
	{
		gotoxy(65,b);
		cout<<"SPACE - Search   ";
	}
	gotoxy(65,24);
	cout<<"ESC - Menu";
}
void pchange(int c, int r)                //change pointer location
{
	cout<<char(8)<<" ";
	gotoxy(c+(2*y)+2,r+y/2+1);
	cout<<"*";
}
int search()
{
	int nosr=0;
	tf.open("tfwatch",ios::in|ios::binary);
	sf.open("sfwatch",ios::out|ios::binary);
	char se[20];
	cin>>se;
	int a,b,c;
	while(tf)
	{
		tf.read((char*)&s,sizeof(s));
		if(tf.eof())
		break;
		if(s.find(se)==1)
		{
			sf.write((char*)&s,sizeof(s));
			nosr++;
		}
	}
	sf.close();
	tf.close();
	return nosr;
}
void sbr(int no)
{
	sf.seekg((no-1)*sizeof(s));
	gotoxy(1,4);
	for(int a=no;a<=no+19;a++)
	{
		sf.read((char*)&s,sizeof(s));
		if(sf.eof())
		break;
		cout<<a<<".";
		s.showid(5,25,wherey());
		cout<<"\n";
	}
}
void log(char file[20])
{
	clrscr();
	gotoxy(33,z);
	ta3("L O G");
	cout<<"\n\n";
	sf.open(file,ios::in|ios::binary);
	int nor;
	sf.seekg(0,ios::end);
	nor=sf.tellg()/sizeof(s);
	if(nor==0)
	{
		cout<<"No records found";
		sf.close();
		getch();
		clrscr();
		gotoxy(38,12);
		ta3("No records found",7);
		menu();
	}
	sbr(1);			//displaying records in brief
	sf.close();
	char cc;
	int no=1;
	int c=65-(2*y)-2;
	int r=6;
	ctrdisp(1);
	gotoxy(c,4);
	cout<<"COMPLETE DETAILS";
	sf.open(file,ios::in|ios::binary);
	int pos=4;
	for(int a=0;a==0;a=a+0)
	{
		sf.seekg((no-1)*sizeof(s));		//get data
		sf.read((char*)&s,sizeof(s));
		p=5;
		s.display(c,r);
		wipe(c+12,r,80,r+7,0);                  //wipe old data
		s.display(c,r);                         //show new data
		watch(c+2,r+5,1);
		wipe(c+3,r+y+1+5,75,r+y+7+2,0);         //wipe b and p detail
		gotoxy(c+3,r+y+1+5);
		s.showb();          			//show brand
		gotoxy(c+3,r+y+2+5);
		cout<<"Rs.";				//show price
		s.showp();
		gotoxy(45,pos);
		cout<<"*";
		cc=getch();
		if(cc=='s' && no<nor)
		{
			no++;
			if(wherey()<(3+20))
			{
				pos++;
				cout<<char(8)<<" ";
			}
			else
			{
				wipe(1,3,45,24,0);
				sbr(no-19);
			}
		}
		else if(cc=='w' && no>1)
		{
			no--;
			if(wherey()>3+1)
			{
				pos--;
				cout<<char(8)<<" ";
			}
			else
			{
				wipe(1,3,45,24,0);
				sbr(no);
			}
		}
		else if(cc==27)
		{
			sf.close();
			clrscr();
			gotoxy(45,12);
			ta3("L  O  G",20);
			menu();
		}
		else if(cc==8)
		{
			fstream df;
			int notbc=s.pno;
			df.open("dfwatch",ios::out|ios::binary);
			tf.open("tfwatch",ios::in|ios::binary);
			while(tf)
			{
				tf.read((char*)&s,sizeof(s));
				if(tf.eof())
					break;
				if(notbc!=s.pno)
				df.write((char*)&s,sizeof(s));
			}
			tf.close();
			df.close();
			sf.close();
			remove("tfwatch");
			rename("dfwatch","tfwatch");
			log("tfwatch");
		}
		else if(cc==32)
		{
			sf.close();
			tf.close();
			wipe(72,1,80,4,0);
			gotoxy(c,2);			//bottom left
			cout<<char(192);
			gotoxy(c,1);			//left vertical line
			cout<<char(179);
			for(int a=c+1;a<=80;a++)	//top and bottom
			{
				gotoxy(a,2);
				cout<<char(196);
				delay(10);
			}
			gotoxy(c+2,1);
			int nosr;
			nosr=search();
			if(nosr==0)
			{
				gotoxy(33,z);
				cout<<"L O G";
				cout<<"\n\nNo record relevant to the searched word found";
				getch();
				log("tfwatch");
			}
			log("sfwatch");
		}
	}
}
void menu()
{
	int x2=16;
	for(int l=1;l<=25;l++)			//draw vertical line
	{
		gotoxy(x2,l);
		cout<<char(179);
		delay(13);
	}
	//cont=0;
	char title[5]="MENU";			//fill the menu bar
	int slen=strlen(title);
	int atitle=(x2-slen)/2+1;                    //align menu pos.
	gotoxy(atitle-3,z);                      	//same as above
	cout<<title;                             //display title
	char obj[4][10]={"HOME","CUSTOM","LOG","EXIT"};
	char head[30]="WELCOME TO THE WATCH STORE";
	for(slen=0;slen<=3;slen++)              //display options
	{
		gotoxy(1,z+2+slen);
		cout<<slen+1<<"."<<obj[slen];
	}

	gotoxy(x2-4,z+2);		//pointer settings , initial pointer
	cout<<"*";
	char cc;
	for(int i=0;i==0;i=i+0)
	{
		cc=getch();
		if(cc=='s' && wherey()<z+2+3)
		{
			cout<<char(8)<<" ";
			gotoxy(x2-4,wherey()+1);
			cout<<"*";
		}
		else if(cc=='w' && wherey()>z+2)
		{
			cout<<char(8)<<" ";
			gotoxy(x2-4,wherey()-1);
			cout<<"*";
		}
		if(cc==13)
		{
			int opt=wherey()-z-1;
			if(opt==1)
			{
				for(l=25;l>=1;l--)	//remove vert line
				{
					gotoxy(x2,l);
					cout<<" ";
					delay(13);
				}
				for(int b=x+shift+3;b>=x;b--)//shift home back
				{
					clrscr();
					home(b);
					delay(10);
				}
				gotoxy(25,z);
				ta3(head);
				ctrdisp();
				pointer();
			}
			else if(opt==2)
			{
				create();
			}
			else if(opt==3)
			{
				log("tfwatch");
			}
			else
			{
				clrscr();
				gotoxy(30,12);
				ta3("Made by Yugantar Jain",13);
				for(int a=wherex();a<=80;a++)
				{
					cout<<"_";
					if(a!=80)
					delay(10);
				}
				gotoxy(80,12);
				getch();
				wipe(30,12,80,12,10);
				exit(0);
			}
		}
	}
}
void order()
{
	int p2=p;
	//cont++;
	int or=(25-y)/2-1;
	if(p!=6)
	{
		wipe(1,2,80,24,7);			//clear screen
		for(int oc=1;oc<=x;oc++)
		{
			clrscr();
			p=p2-1;
			watch(oc,or);
			delay(20);
		}
	}
	gotoxy(35,z);
	ta3("ORDER PAGE");
	gotoxy(70,24);
	cout<<"ESC->Menu";
	char info[4][30]={"Full Name","Address","Phone No.","E-Mail"};
	for(int ino=0;ino<=3;ino++)
	{
		gotoxy(30,z+5+3*ino);
		cout<<info[ino];
		gotoxy(40,z+5+3*ino);
		cout<<" :";
	}
	gotoxy(43,z+5);		//initial intake at name
	char in;
	int loc=0;
	for(ino=0;ino<=3;loc=loc+0)
	{
		in=getch();
		if(in==27)
		{
			for(int sp=x;sp<=x+shift+5;sp++)
			{
				clrscr();
				p=p2-1;
				watch(sp,or);
				delay(15);
			}
			gotoxy(sp+2*y+1+10,or+y/2+1);
			ta3("ORDER PAGE");
			sp--;
			menu();
		}
		else if(in==13)
		{
			info[ino][loc]='\0';
			gotoxy(43,z+5+(ino+1)*3);
			ino++;
			loc=0;
		}
		else if(in==8)
		{
			if(loc>=1)
			{
				cout<<char(8)<<" "<<char(8);
				info[ino][loc-1]=' ';
				loc=loc-1;
			}
		}
		else
		{
			info[ino][loc]=in;
			cout<<info[ino][loc];
			loc++;
		}
	}
	tf.open("tfwatch",ios::app|ios::in|ios::binary);
	for(int a=0;a<=3;a++)
	{
		w[p].transin(info[a],a);
	}
	int count;
	tf.seekp(0,ios::end);
	count=tf.tellp()/sizeof(s);
	if(count==0)
	{
		w[p].pno=1;
	}
	else
	{
		tf.seekg((count-1)*sizeof(s));
		tf.read((char*)&s,sizeof(s));
		w[p].pno=s.pno+1;
	}
	tf.write((char*)&w[p],sizeof(w[p]));
	tf.close();
	log("tfwatch");
}
void pointer()
{
	p=0;                         //watch wnnp[0]
	int c,r;                     //initial r & c
	c=x;
	r=4;

	gotoxy(c+(2*y)+2,r+y/2+1);          //initial pointer
	cout<<"*";

	for(int a=0;a==0;a=a+0)                       //024
	{                                             //135
		char cc=getch();                     //cc=control command

		if(cc=='w')
		{
			if(p%2==1)
			{
				r=r-4-y;
				p--;
				pchange(c,r);
			}
		}
		else if(cc=='s')
		{
			if(p%2==0)
			{
				r=r+4+y;
				p++;
				pchange(c,r);
			}
		}
		else if(cc=='a')
		{
			if(p/2!=0)
			{
				c=c-x-2*y-1;
				p=p-2;
				pchange(c,r);
			}
		}
		else if(cc=='d')
		{
			if(p/4!=1)
			{
				c=c+x+2*y+1;
				p=p+2;
				pchange(c,r);
			}
		}
		else if(cc==27)
		{
			for(int sp=x;sp<=x+shift+3;sp++)
			{
				clrscr();
				home(sp);
				delay(15);
			}
			menu();
		}
		else if(cc==13)// && cont==0)
		order();
	}
}
void main()
{
	clrscr();
	for(p=0;p<=5;p++)
	{
		w[p].assign();
	}
	gotoxy(25,z);
	ta3("WELCOME TO THE WATCH STORE");
	home(x);
	ctrdisp();
	pointer();
	getch();
}

