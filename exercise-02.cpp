/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 15 April 2019
Deskripsi	: Program Menu fungsi-fungsi Doubly Linked List
*/

#include <iostream>
using namespace std;

struct ElemtList { 
	char info; 
	ElemtList* next; 
	ElemtList* prev; 
};
typedef ElemtList* pointer; 
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirstDoubly (List& First, pointer pBaru);
void insertLastDoubly (List& First, pointer pBaru);
void insertAfterDoubly (List& First, pointer pCari, pointer pBaru);
void insertBeforeDoubly (List& First, pointer pCari, pointer pBaru);
void traversal (List First);
void linearSearch (List First, char key, int& found, pointer& pCari);
void deleteFirstDoubly(List& First, pointer& pHapus);
void deleteLastDoubly (List& First, pointer& pHapus);
void deleteAfterDoubly (List& First, pointer pCari, pointer& pHapus);
void deleteBeforeDoubly (List& First, pointer pCari, pointer& pHapus);

main()
{
    pointer pBaru,pCari,pHapus;
    List first;
    int pilihan,ketemu;
    char jawab,kunci;

    createList(first);
    do{
        system("cls");
        cout<<"Pilih Menu : \n"<<endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Insert After"<<endl;
        cout<<"4. Insert Before"<<endl;
        cout<<"5. Delete First"<<endl;
        cout<<"6. Delete Last"<<endl;
        cout<<"7. Delete After"<<endl;
        cout<<"8. Delete Before"<<endl;
        cout<<"9. Tampilkan Data ( traversal )"<<endl;
        cout << "\nMasukan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
            createElmt(pBaru);
            insertFirstDoubly(first,pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLastDoubly(first,pBaru);
        break;
		
		case 3:
			cout<<"Insert setelah data : ";cin>>kunci;
			linearSearch(first,kunci,ketemu,pCari);
			if(ketemu){
				createElmt(pBaru);
				insertAfterDoubly(first,pCari,pBaru);}
			else cout<<"Data tidak ditemukan"<<endl;
		break;
		
		case 4:
			cout<<"Insert sebelum data : ";cin>>kunci;
			linearSearch(first,kunci,ketemu,pCari);
			if(ketemu){
				createElmt(pBaru);
				insertBeforeDoubly(first,pCari,pBaru);
			}
			else cout<<"Data tidak ditemukan"<<endl;
		break;
		
        case 5:
            deleteFirstDoubly(first, pBaru);
        break;

        case 6:
            deleteLastDoubly(first, pBaru);
        break;
		
		case 7:
			cout<<"Hapus setelah data : ";cin>>kunci;
			linearSearch(first,kunci,ketemu,pCari);
			if(ketemu){
				deleteAfterDoubly(first,pCari,pHapus);
			}
			else cout<<"Data tidak ditemukan"<<endl;
		break;
		
		case 8:
			cout<<"Hapus sebelum data : ";cin>>kunci;
			linearSearch(first,kunci,ketemu,pCari);
			if(ketemu){
				deleteBeforeDoubly(first,pCari,pHapus);
			}
			else cout<<"Data tidak ditemukan"<<endl;
		break;
		
        case 9:
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



void createList (List& First){
	First = NULL;
}

void createElmt(pointer& pBaru) { 
	pBaru = new ElemtList; 
	cout<<"Masukkan data : ";cin >> pBaru->info; 
	pBaru->next = NULL; 
	pBaru->prev = NULL; 
}

void insertFirstDoubly(List& First, pointer pBaru){ 
	if (First==NULL)           
		First=pBaru; 
	else { 						
		pBaru->next=First; 		
		First->prev = pBaru; 
		First=pBaru; 			
	}
}

void insertLastDoubly(List& First, pointer pBaru){ 
	pointer last;  
	if (First==NULL){         
		First=pBaru; 
	} 
	else {              
		last=First;                    
		while (last->next!=NULL){       
			last=last->next; 
		} 
		last->next=pBaru; 
		pBaru->prev = last; 
	} 
}

void deleteFirstDoubly (List& First, pointer& pHapus){
	if (First == NULL){               
		pHapus = NULL; 
		cout << "List kosong, tidak ada yang dihapus" << endl; 
	}
	else if (First->next == NULL){   
		pHapus = First; 
		First = NULL;                  
	}
	else {								
		pHapus = First;					
		First = First->next;
		pHapus->next = NULL;
		First->prev = NULL;
	}
}

void deleteLastDoubly (List& First, pointer& pHapus){
	pointer last;
	if (First == NULL){               
		pHapus = NULL; 
		cout << "List kosong, tidak ada yang dihapus" << endl; 
	}
	else if (First->next == NULL){   
		pHapus = First; 
		First = NULL;                  
	}
	else {								
		last = First;
		while (last->next != NULL){
			last = last->next;
		}
		pHapus = last;
		last->prev->next = NULL;
		pHapus->prev = NULL;
	}
}

void traversal (List First){
	pointer pBantu;
	if (First == NULL){
		cout << "List Kosong"<<endl;
	}
	else {
		pBantu = First;				
		do {
			cout << pBantu->info;		
			pBantu = pBantu->next;		
		} while (pBantu != NULL);	
		cout << endl;
	}
}

void linearSearch (List First, char key, int& found, pointer& pCari){
	found = 0;			
	pCari = First;		
	while (found == 0 && pCari != NULL){
		if (pCari->info == key){
			found = 1;
		}
		else {
			pCari = pCari->next;
		}
	}
}

void insertAfterDoubly(List& First, pointer pCari, pointer pBaru){
 	if(pCari->next == NULL){
  		insertLastDoubly(First,pBaru);
 	}
 	else{
  		pBaru->next = pCari->next;
  		pBaru->prev = pCari;
  		pBaru->next->prev = pBaru;
  		pCari->next = pBaru;
	}
}

void insertBeforeDoubly(List& First, pointer pCari, pointer pBaru){
	if(pCari->prev == NULL){
  		insertFirstDoubly(First,pBaru);
 	}
 	else {
 		pCari->next = pCari;
 		pBaru->prev = pCari->prev;
 		pCari->prev->next = pBaru;
 		pCari->prev = pBaru;
	 }
}

void deleteAfterDoubly(List& First, pointer pCari, pointer& pHapus){
	if (pCari->next == NULL){
		cout << "Tidak ada data setelah data yang dicari!" << endl;
	}
	else if (pCari->next->next == NULL){
		deleteLastDoubly (First, pHapus);
	}
	else{
		pHapus = pCari->next;
		pCari->next = pHapus->next;
		pHapus->next->prev = pCari;
		pHapus->next = NULL;
		pHapus->prev = NULL;
	}
}

void deleteBeforeDoubly(List& First, pointer pCari, pointer& pHapus){
	if (pCari->prev == NULL){
		cout << "Tidak ada data sebelum data yang dicari!" << endl;
	}
	else if (pCari->prev->prev == NULL){
		deleteFirstDoubly(First, pHapus);
	}
	else{
		pHapus = pCari->prev;
		pHapus->prev->next = pCari;
		pCari->prev = pHapus->prev;
		pHapus->next = NULL;
		pHapus->prev = NULL;
	}
}

void deletePCari (List& First, pointer pCari, pointer& pHapus){
	if (pCari == First){   
		if (First->next==NULL){   
			pHapus = First; 
			First = NULL;                  
		}
		else {								
			pHapus = First;					
			First = First->next;
			pHapus->next = NULL;
			First->prev = NULL;
		}                
	}
	else if (pCari->next == NULL){
		pointer last;
		
		last = First;
		while (last->next != NULL){
			last = last->next;
		}
		pHapus = last;
		last->prev->next = NULL;
		pHapus->prev = NULL;
	}
	else {								
		pHapus = pCari;					
		pCari->prev->next = pCari->next;
		pCari->next->prev = pCari->prev;
		pCari->next = NULL;
		pCari->prev = NULL;
	}
}
