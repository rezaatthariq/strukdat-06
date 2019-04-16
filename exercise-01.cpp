/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 15 April 2019
Deskripsi	: Program Menu fungsi-fungsi Singly Linked List
*/

#include <iostream>
using namespace std;

struct data{
    char info;
    data* next;
};
typedef data* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void traversal (List First);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast (List& First, pointer& pHapus);

main()
{
    pointer pBaru;
    List first;
    int pilihan;
    char jawab;

    createList(first);
    do{
        system("cls");
        cout<<"Pilih Menu : \n"<<endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Tampilkan Data ( traversal )"<<endl;
        cout << "\nMasukan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
            createElmt(pBaru);
            insertFirst(first, pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 3:
            deleteFirst(first, pBaru);
        break;

        case 4:
            deleteLast(first, pBaru);
        break;
		
        case 5:
            traversal(first);
        break;

        default:
        	cout<<"Exit\n";
        }

  		cout<<"Ingin Ke Menu lagi? (Y/N) ";cin>>jawab;
    	cin.ignore();
    	if (jawab=='Y'||jawab=='y'){system("cls");}
    	else 
			traversal(first);
    	}
    while(jawab=='Y'||jawab=='y');
}



void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new data;
   	cout<<"Masukkan data : ";cin>>pBaru->info;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
	if(First==NULL)
		First=pBaru;
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void traversal(List First)
{
	pointer pBantu;
	if(First==NULL) cout << "List kosong." << endl;
	else
	{	
		pBantu=First;
		cout<<"List : ";
		do 
		{
			cout << pBantu->info<<" ";
			pBantu=pBantu->next;
		} 
		while (pBantu != NULL);
	}
	cout << endl;
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus=NULL;
        cout<<"List kosong!"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast (List& First, pointer& pHapus){
    pointer Last, precLast;
    if (First==NULL){
        pHapus=NULL;
        cout<<"List kosong!"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL){
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}
