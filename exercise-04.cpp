/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 16 April 2019
Deskripsi	: Program Menu fungsi-fungsi Multi Linked List
*/

#include<iostream>
#include<string.h>
using namespace std;

struct Contact{
	char nama[10];
	char phone[12];
	Contact *next;
};
struct Index{
	char index;
	Index *next;
	Contact *nextContact;
};
		
void createList(Index* &first){
	first=NULL;
}
void createIndex(Index* &iBaru, char index){
	iBaru=new Index;
	iBaru->index=index;
	iBaru->next=NULL;
	iBaru->nextContact=NULL;
}
void createContact(Contact* &cBaru){
	cBaru = new Contact;
	cout<<"Nama\t: ";cin.ignore();cin.getline(cBaru->nama,10);
	cout<<"Nomor\t: ";cin>>cBaru->phone;
	cBaru->next=NULL;
}

void insertLastIndex(Index* &first, Index* iBaru){
	if(first==NULL){
		first=iBaru;
	}else{
		Index *last=first;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=iBaru;
	}
}

void createListIndex(Index* &first){
	Index *iBaru;
	createList(first);
	for(char index='A'; index!='Z'+1; index++){
		createIndex(iBaru,index);
		insertLastIndex(first,iBaru);
	}
}
void insertFirstIndex(Index* &first, Index* iBaru){
	if(first==NULL){
		first=iBaru;
	}else{
		iBaru->next=first;
		first=first->next;
	}
}

void insertFirstContact(Index* &index, Contact* cBaru){
	if(index->nextContact==NULL){
		index->nextContact=cBaru;
	}else{
		cBaru->next=index->nextContact;
		index->nextContact=cBaru;
	}
}

void insertLastContact(Index* &index, Contact* cBaru){
	if(index->nextContact==NULL){
		index->nextContact=cBaru;
	}else{
		Contact *last=index->nextContact;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=cBaru;
	}
}

void insertContact(Index* &first, Contact* cBaru){
	Index *idxTrav=first;
	bool isFound=0;
	int pil;
	while(idxTrav!=NULL){
		if(idxTrav->index==toupper(cBaru->nama[0])){
			break;
		}
		idxTrav=idxTrav->next;
	}
	if(idxTrav->nextContact!=NULL){
		cout<<"1. Insert First Contact\n2. Insert Last Contact"<<endl;
		do{
			cin>>pil;
		}while(pil!=1&&pil!=2);
		switch(pil){
			case 1:
				insertFirstContact(idxTrav,cBaru);
				break;
			case 2:
				insertLastContact(idxTrav,cBaru);
				break;
		}
	}else{
		insertFirstContact(idxTrav,cBaru);
	}
}


void deleteContact(Index* &first, Contact* &cHapus){
	char nama[10];
	Index *idxSrc=first;
	bool isFound=0;
	cout<<"Nama Kontak yang ingin didelete : ";cin.ignore();cin.getline(nama,10);
	while(idxSrc!=NULL && !isFound){
		if(idxSrc->index==toupper(nama[0])){
			isFound=1;
			break;
		}
		idxSrc=idxSrc->next;
	}
	Contact *ctcSrc=idxSrc->nextContact;
	if(ctcSrc==NULL){
		cout<<"Nama tidak ditemukan!"<<endl;
	}else{
		Contact *prev=NULL;
		while(ctcSrc!=NULL){
			if(strcmp(ctcSrc->nama,nama)==0){
				isFound=1;
				if(ctcSrc==idxSrc->nextContact){
					cHapus=ctcSrc;
					idxSrc->nextContact=ctcSrc->next;
					cHapus->next=NULL;
				}else if(ctcSrc->next==NULL){
					prev->next=NULL;
				}else{
					cHapus=ctcSrc;
					prev->next=ctcSrc->next;
					cHapus->next=NULL;
				}
			}
			prev=ctcSrc;
			ctcSrc=ctcSrc->next;
		}
	}
	if(!isFound){
		cout<<"Nama tidak ditemukan!"<<endl;
	}else{
		cout<<"Delete berhasil!"<<endl;
	}
}
void updateContact(Index* &first){
	char nama[10];
	Index *idxSrc=first;
	bool isFound=0;
	cout<<"Nama Kontak yang ingin dipdate : ";cin.ignore();cin.getline(nama,10);
	while(idxSrc!=NULL && !isFound){
		if(idxSrc->index==toupper(nama[0])){
			isFound=1;
			break;
		}
		idxSrc=idxSrc->next;
	}
	Contact *ctcSrc=idxSrc->nextContact;
	if(ctcSrc==NULL){
		cout<<"Nama tidak ditemukan!"<<endl;
	}else{
		while(ctcSrc!=NULL){
			if(strcmp(ctcSrc->nama,nama)==0){
				isFound=1;
				cout<<"Nomor Baru : ";
				cin>>ctcSrc->phone;
			}
			ctcSrc=ctcSrc->next;
		}
	}
	if(!isFound){
		cout<<"Nama tidak ditemukan!"<<endl;
	}else{
		cout<<"Update berhasil!"<<endl;
	}
}
void traversal(Index* first){
	Index *idxTrav=first;
	cout<<endl;
	bool ada=0;
	while(idxTrav!=NULL){
		Contact *ctcTrav=idxTrav->nextContact;
		if(idxTrav->nextContact!=NULL){
			cout<<"|- "<<idxTrav->index<<endl;
			ada=1;
		}
		while(ctcTrav!=NULL){
			cout<<"\t|- "<<ctcTrav->nama<<" / "<<ctcTrav->phone<<endl;
			ctcTrav=ctcTrav->next;
		}
		idxTrav=idxTrav->next;
	}
	if(!ada){
		cout<<"Buku Telepon Kosong."<<endl;
	}
}

int main(){
	Index *first=NULL;
	Contact *contact;
	int pil; char jawab;
	createList(first);
	createListIndex(first);
	do{
		system("CLS");
		cout<<"1. Insert Contact"<<endl;
		cout<<"2. Delete Contact"<<endl;
		cout<<"3. Update Contact"<<endl;
		cout<<"4. Tampilkan Contact"<<endl;
		do{
			cout<<"Masukkan pilihan : ";cin>>pil;
		}while(pil<1||pil>4);
		switch(pil){
			case 1:
				createContact(contact);
				insertContact(first,contact);
				break;
			case 2:
				deleteContact(first,contact);
				break;
			case 3:
				updateContact(first);
				break;
			case 4:
				traversal(first);
				break;
		}
		cout<<endl<<"Kembali ke menu? (Y/N) ";
		do{
			cin>>jawab;
		}while(jawab!='Y'&&jawab!='y'&&jawab!='N'&&jawab!='n');
	}while(jawab=='Y'||jawab=='y');
}

