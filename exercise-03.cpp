/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 15 April 2019
Deskripsi	: Program Menu fungsi-fungsi Circular Doubly Linked List
*/

#include<iostream>
using namespace std;

struct data{
	char info;
	data* next;
	data* prev;
};

void createElmt(data* &pBaru);
void insertFirst(data* &first, data* pBaru);
void insertLast(data* &first, data* pBaru);
void deleteFirst(data* &first, data* &pHapus);
void deleteLast(data* &first, data* &pHapus);
void traversal(data* &first);

int main(){
	data *list=NULL,*p;
	int pil;char jawab;
	do{
		system("CLS");
		cout<<"1. Insert First"<<endl;
		cout<<"2. Insert Last"<<endl;
		cout<<"3. Delete First"<<endl;
		cout<<"4. Delete Last"<<endl;
		cout<<"5. Tampilkan Data"<<endl;
		do{
			cout<<"Masukkan pilihan : ";cin>>pil;
		}while(pil<1||pil>5);
		switch(pil){
			case 1:
				createElmt(p);
				insertFirst(list,p);
				break;
			case 2:
				createElmt(p);
				insertLast(list,p);
				break;
			case 3:
				deleteFirst(list,p);
				break;
			case 4:
				deleteLast(list,p);
				break;
			case 5:
				traversal(list);
				break;
		}
		cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>jawab;
		}while(jawab!='Y'&&jawab!='y'&&jawab!='N'&&jawab!='n');
	}while(jawab=='Y'||jawab=='y');
}

void createElmt(data* &pBaru){
	pBaru = new data;
	cout<<"Masukkan data : ";cin>>pBaru->info;
	pBaru->next=NULL;
	pBaru->prev=NULL;
}
void insertFirst(data* &first, data* pBaru){
	if(first==NULL){
		first=pBaru;
		first->next=first;
		first->prev=first;
	}else{
		pBaru->next=first;
		pBaru->prev=first->prev;
		first->prev->next=pBaru;
		first->prev=pBaru;
		first=pBaru;
	}
}
void insertLast(data* &first, data* pBaru){
	if(first==NULL){
		first=pBaru;
		pBaru->next=first;
		pBaru->prev=first;
	}else{
		data *last=first;
		while(last->next!=first){
			last=last->next;
		}
		last->next=pBaru;
		pBaru->prev=last;
		pBaru->next=first;
		first->prev=pBaru;
	}
}
void deleteFirst(data* &first, data* &pHapus){
	pHapus=first;
	if(first==NULL){
		pHapus=NULL;
		cout<<endl<<"Tidak ada yang didelete."<<endl;
	}else if(first->next==first){
		first->next=NULL;
		first->prev=NULL;
		first=NULL;
	}else{
		first->next->prev=first->prev;
		first->prev->next=first->next;
		first=first->next;
		pHapus->next=NULL;
		pHapus->prev=NULL;
		pHapus=NULL;
	}
}
void deleteLast(data* &first, data* &pHapus){
	pHapus=first;
	if(first==NULL){
		pHapus=NULL;
		cout<<endl<<"Tidak ada yang didelete."<<endl;
	}else if(first->next==first){
		first->next=NULL;
		first->prev=NULL;
		first=NULL;
	}else{
		data *prevLast;
		while(pHapus->next!=first){
			prevLast=pHapus;
			pHapus=pHapus->next;
		}
		prevLast->next=first;
		pHapus->prev=NULL;
		pHapus->next=NULL;
		pHapus=NULL;
	}
}
void traversal(data* &first){
	if(first!=NULL){
		data *trav=first;
		do{
			cout<<trav->info<<" ";
			trav=trav->next;
		}while(trav!=first);
	}else{
		cout<<"List Kosong!"<<endl;
	}
}
