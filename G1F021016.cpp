#include <iostream>
using namespace std;

struct Sepatu{
	string merek, ukuran;
	int warna;

	Sepatu *next;
};

	Sepatu *head, *tail, *cur, *newNode, *del, *before;

	//create Single Linked List
	void createSingleLinkedList(string merek, string ukuran, int warna) {
		head = new Sepatu();
		head->merek=merek;
		head->ukuran=ukuran;
		head->warna=warna;
		head->next=NULL;
		tail = head;
	}

	//menghitung berapa banyak data yang ada
	int countSingleLinkedList() {
		cur = head;
		int jumlah = 0;
		while (cur != NULL) {
			jumlah++;
			cur= cur->next;
		}
		return jumlah;
	}

	//add first Single Linked List
	void addfirst(string merek, string ukuran, int warna) {
		newNode = new Sepatu();
		newNode->merek=merek;
		newNode->ukuran=ukuran;
		newNode->warna=warna;
		newNode->next=head;
		head=newNode;
	}

	//add last Single Linked List
	void addlast(string merek, string ukuran, int warna) {
		newNode = new Sepatu();
		newNode->merek=merek;
		newNode->ukuran=ukuran;
		newNode->warna=warna;
		newNode->next=NULL;
		tail->next=newNode;
		tail=newNode;
	}

	//add middle Single Linked List
	void addmiddle(string merek, string ukuran, int warna, int posisi) {
		if (posisi < 1 || posisi > countSingleLinkedList() ) {
			cout<<"Posisi diluar jangkauan"<<endl;
		} else if (posisi == 1 || posisi == countSingleLinkedList() ) {
			cout<<"Posisi bukan posisi tengah"<<endl;
		} else {
			newNode = new Sepatu();
			newNode->merek=merek;
			newNode->ukuran=ukuran;
			newNode->warna=warna;

			//tranversing
			cur = head;
			int nomor = 1;
			while (nomor < posisi -1) {
				cur = cur->next;
				nomor++;
			}
			newNode->next = cur->next;
			cur->next = newNode;
		}
	}


	//delete first
	void deletefirst() {
		del=head;
		head=head->next;
		delete del;
	}

	//delete last
	void deletelast() {
		del=tail;
		cur=head;
		while(cur->next != tail) {
			cur = cur->next;
		}
		tail=cur;
		tail->next=NULL;
		delete del;
	}

	//delete middle
	void deletemiddle(int posisi) {
		if (posisi < 1 || posisi > countSingleLinkedList() ) {
			cout<<"Posisi diluar jangkauan"<<endl;
		} else if (posisi == 1 || posisi == countSingleLinkedList() ) {
			cout<<"Posisi bukan posisi tengah"<<endl;
		} else {
			int nomor = 1;
			cur = head;
			while (nomor <= posisi) {
				if (nomor == posisi-1) {
					before = cur;
				}
				if(nomor == posisi) {
					del = cur;
				}
				cur = cur->next;
				nomor++;
			}
			before->next = cur;
			delete del;	
		}
	}



	//print Single Link List
	void printSingleLinkedList() {
		cout<<"Jumlah data ada : "<< countSingleLinkedList()<<endl;
		cur = head;
		while (cur != NULL) {
			cout << "Merek Sepatu   : "<< cur->merek<<endl;
			cout << "Ukuran         : "<< cur->ukuran<<endl;
			cout << "Warna          : "<< cur->warna<<endl;

			cur= cur->next;
		}
	}
int main() {

	createSingleLinkedList("Adidas", "Rudolf Dassler", 1920);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;

	addfirst("Nike", "Philip Knight", 1964);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;

	addlast("Asics", "Kihachiro", 1949);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;

	addmiddle("Reebok", "J.W.Foster", 1895, 2); //menambahakan data baru di posisi ke-2
	printSingleLinkedList();
	cout<<"\n\n"<<endl;

	/*deletefirst();
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deletelast();
	printSingleLinkedList();
	cout<<"\n\n"<<endl; 
	
	deletemiddle(3); //menghapus data pada posisi ke-3
	printSingleLinkedList();
	cout<<"\n\n"<<endl; */



	return 0;	
}
