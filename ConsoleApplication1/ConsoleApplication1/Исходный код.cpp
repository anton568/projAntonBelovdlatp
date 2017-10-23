
#include <iostream>
using namespace std;
struct chel  //ñòðóêòóðà îäíîãî ýëåìåíòà ãðóïïû -÷åëîâåêà
{
	int numb;//íîìåð ÷åëîâåêà
	chel *next;//óêàçàòåë íà ñëåä ÷åëîâåêà
};
class Krug
{
private:
	chel *nach, *res;

public:
	Krug(){
		nach = new(chel); res = NULL;
	};
	~Krug(){
		delete nach;
	};
	void POSTROENIE(int);
	void VYVOD();
	chel *POISK(int,int,int,int,int);
	void Delete();
	void OCHISTKA();


};

void main()
{
	Krug A;
	int el,n,m,k,d,l,h;
	//chel *Res_Zn;//
	cout << "Vvedi kolichestvo chelovek" << endl;
	cin >> n;
	k = n;
	d = 1;
	l = 0;
	h = 0;
	cout << "Vvedi nomer udalaemogo cheloveka" << endl;
	cin >> m;
	el = m;
	A.POSTROENIE(n);


	//A.VYVOD();
	
		//cout << "\nÂâåäèòå ýëåìåíò óäàëÿåìîãî çâåíà: ";
		//cin >> el;
	//A.POISK(el, m, d, h, k);
	while (k != 1)
	{
	if (A.POISK(el, m, d, h, k) != NULL)
		{
			A.Delete(); //A.VYVOD();
		}
		else  cout << "Zvena s el v kolce net!";
			k--;
	d++;
	}
	A.OCHISTKA();
}

/*void Krug::POSTROENIE()
//Ïîñòðîåíèå êîëüöåâîãî ñïèñêà ñ óäàëåííûì çàãëàâíûì çâåíîì.
//phead - óêàçàòåëü íà çàãëàâíîå çâåíî.
{
	chel *t;
	int  el;

	t = nach; (*t).next = NULL;
	cout << "Ââîäèòå ýëåìåíòû êîëüöà: ";
	cin >> el;
	while (el != 0)
	{
		(*t).next = new (chel);
		t = (*t).next; (*t).numb = el;
		cin >> el;
	}
	(*t).next = (*nach).next;
}*/
void Krug::POSTROENIE(int n)
//Ïîñòðîåíèå êîëüöåâîãî ñïèñêà ñ óäàëåííûì çàãëàâíûì çâåíîì.
//phead - óêàçàòåëü íà çàãëàâíîå çâåíî.
{
	
	int el;//êîëëè÷åñòâî, íîìåð óäàëåìîãî
	 chel *t;
	 
	nach = new (chel);//âûäåëÿåì  ïàìÿòü äëÿ îáüåêòà
	t = nach;
	for (int i = 0; i < n; i++)//çàïèñûâàåì ëþäåé â ñïèñîê
	{
		if (i != n - 1)		{
			(*t).numb = i + 1; //íîìåð ÷åëîâåêà
			(*t).next = new (chel); //âûäåëÿåì ïàìÿòü äëÿ àäðåñà ñëåä îáüåêòà
			t = (*t).next;
		}
		else	{               //ïîñëåäíèé ÷åëîâåê
			(*t).numb = i + 1;
			//(*t).next = new (chel);
			//t = nach;
			//(*t).next = (*nach).next;
			(*t).next = nach;
			

		}
	}
	int i;                                            //
	i = 0;                                            //
	for (t = nach; i < n; t = (*t).next)              //âûâîä
	{                                                 //
		                                              //
		//(*t).next2 = (*t).next;                     //
		cout << (*t).numb << " ";				      //
		cout << (*t).next << " ";
		i++;                                          //
	}
}


/*void Krug::VYVOD()
//Âûâîä ñîäåðæèìîãî êîëüöåâîãî ñïèñêà ñ óäàëåííûì çàãëàâíûì çâåíîì.
//phead - óêàçàòåëü íà çàãëàâíîå çâåíî.
{
	chel *t;
	/*t = (*nach).next;
	cout << "Kolco: ";
	if (t != NULL)
	{
		cout << (*t).numb << " ";
		t = (*t).next;
		while (t != (*nach).next)
		{
			cout << (*t).numb << " ";
			t = (*t).next;
		}
	}
	else  cout << "ïóñòî!\n";
	
}*/

	chel *Krug::POISK(int el,int m, int d, int h,int k)
//Ïîèñê ýëåìåíòà el â êîëüöåâîì ñïèñêå phead.  
//Åñëè ýëåìåíò íàéäåí, òî Res ñîäåðæèò óêàçàòåëü íà çâåíî,
//ñîäåðæàùåå ýëåìåíò el. Â ïðîòèâíîì ñëó÷àå - NULL. 
{
	//int el;
	chel *t;
	int e,a,j;
		a = 0;
		if (h = 0)
		{
			(*t).next = (*nach).next;
			h++;
		}
		res = NULL;
		e = 1;
		//t =(*nach).next;
		cout << (*nach).numb<<" ";
	for (e = 1; e < m; e++)
	{
		t = (*t).next;
		
	}
	if (e == m)
	{
		res = t;
		t = (*t).next;
		
	}
	cout << res<< " ";
		//if ((*t).numb == el) res = t;
		//else  t = (*t).next;
		//if (res == NULL && (*t).numb == el)
			//res = t;
	
	
	return res;
}


void Krug::Delete()
//Óäàëåíèå çâåíà, íà êîòîðîå óêàçûâàåò ññûëêà Res, 
//èç êîëüöåâîãî ñïèñêà ñ óäàëåííûì çàãëàâíûì çâåíîì,
//çàäàííîãî óêàçàòåëåì phead. 
{
	chel *z, *q;
	if ((*res).next != nach)
	{
		q = (*res).next;
		(*res).numb = (*((*res).next)).numb;
		(*res).next = (*((*res).next)).next;
		delete q;
	}
	  else  if ((*res).next == res)
	{
	//Â êîëüöå åäèíñòâåííîå çâåíî.
	q = (*nach).next; (*nach).next = NULL;
	cout<<q;
	delete q;
	cout << "kolco pusto!";
	}
	else
	{
		//Óäàëÿåòñÿ "ïîñëåäíåå" çâåíî êîëüöà.
		z = nach; q = (*nach).next;
		while (q != res)
		{
			z = q; q = (*q).next;
		}
		(*z).next = (*((*z).next)).next;
		delete q;
	}
	
}


void Krug::OCHISTKA()
{
	chel *q, *q1;// Ðàáî÷èå óêàçàòåëè.
	q = nach;
	q1 = (*q).next; // Óêàçàòåëü q1 "îïåðåæàåò" óêàçàòåëü q.
	do {
		q = q1;
		q1 = (*q1).next;
		delete q;
	} while (q1 != (*nach).next);
}

/*void main()
{
chel  *a, *b;//óêàçàòåëü íà íà÷àëüíîãî è êîíå÷íîãî ëþäåé
int n, m, k, c;//êîëëè÷åñòâî, íîìåð óäàëåìîãî
cout << "Vvedi kolichestvo chelovek" << endl;
cin >> n;
k = n;
c = 0;
cout << "Vvedi nomer udalaemogo cheloveka" << endl;
cin >> m;
nach = new (chel);//âûäåëÿåì  ïàìÿòü äëÿ îáüåêòà
t = nach;
cout << "Spisok nomerov ludey: ";
for (int i = 0; i < n; i++)//çàïèñûâàåì ëþäåé â ñïèñîê
{
if (i != n - 1)		{
(*t).numb = i + 1; //íîìåð ÷åëîâåêà
(*t).next = new (chel); //âûäåëÿåì ïàìÿòü äëÿ àäðåñà ñëåä îáüåêòà
t = (*t).next;
}
else	{               //ïîñëåäíèé ÷åëîâåê
(*t).numb = i + 1;
//(*t).next = new (chel);
//t = nach;
(*t).next = nach;

}

}
int i;
i = 0;
for (t = nach; i < n; t = (*t).next)
{

//(*t).next2 = (*t).next;
cout << (*t).numb << " ";
i++;
}
i = 0;
while (k > 1)
{
/*i = 0;
for (t = nach; i < m; t = (*t).next)
{
i++;
}
cout << t << " ";
b = t;
cout << b << " ";

i = 0;
for (t = nach; i < m - 1; t = (*t).next)
{
(*t).next = (*(*t).next).next;
cout << (*(*t).next).next << " ";
i++;
}
//cout << (*t).next << " ";
//(*(*t).next).next=(*t).next;
//(*t).next = (*(*t).next).next;
*t->next = *t->next->next;
/*cout << t << " ";
t = b;
cout << a << " ";
i = 0;

k--;
c++;
}
i = 0;
for (t = nach; i < n; t = (*t).next)
{

cout << (*t).numb << " ";
i++;
}
}*/
