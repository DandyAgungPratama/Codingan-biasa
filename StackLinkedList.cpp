#include <iostream>
#define MAX_STACK_SIZE 10
using namespace std;
struct Element{
	int d;
	int t;
	Element *n;
};
Element tumpuk;
Element *head = NULL;
class MyStack{
	public:
		void awal(){
			tumpuk.t = -1;
		}
		bool isFull(){
			if(tumpuk.t == 9){
				return 1;
			}else{
				return 0;
			}
		}
		bool isEmpty(){
			if(tumpuk.t == -1){
				return 1;
			}else{
				return 0;
			}
		}
	void push(int a){
		if (isFull()){
			cout<<"Stack Full"<<endl;
		}else{
			Element *tmp = new Element;
			tmp->d = a;
			tmp->n = NULL;
			if(isEmpty()){
				head = tmp;
				head->n = NULL;
			}else{
				tmp->n = head;
				head = tmp;
			}
			cout<<"Push Angka berhasil, tekan ENTER untuk kembali ke MENU"<<endl;
			tumpuk.t++;
		}
	}
	void getTop(){
		if(isEmpty()){
			cout<<"Stack Kosong"<<endl;
		}else{
			cout<<head->d;
		}
	}
	void pop(){
		if(isEmpty()){
			cout<<"Stack Kosong"<<endl;
		}else{
			Element *tmp = new Element;
			tmp = head;
			head = head->n;
			delete tmp;
			cout<<"Pop Angka berhasil, tekan ENTER untuk kembali ke MENU"<<endl;
			tumpuk.t--;
		}
	}
	void print(){
		if(isEmpty()){
			cout<<"Tumpukan Kosong"<<endl;
		}else{
			cout<<"Isi Tumpukan : "<<endl;
			Element *tmp = new Element;
			tmp = head;
			while(tmp!=NULL){
				cout<<tmp->d<<"   ";
				tmp=tmp->n;
				cout<<endl;
				cout<<"tekan ENTER untuk kembali ke MENU"<<endl;
			}
		}
	}
};


int nama_menu(){
	int menu;
	cout<<"PILIH STACK MENU : "<<endl<<endl;
	cout<<"1) Push Angka "<<endl;
	cout<<"2) Pop Angka "<<endl;
	cout<<"3) Get Top "<<endl;
	cout<<"4) Print Stack List "<<endl;
	cout<<"5) Exit "<<endl<<endl;
	cout<<" Pilihan : ";
	cin>>menu;
	cin.ignore();
	return menu;
}
int main(){
	MyStack obj;
	int menu,angka;
	obj.awal();
	do{
		menu = nama_menu();
		switch(menu){
			case 1:
				cout<<"Masukan Angka = ";
				cin>>angka;
				obj.push(angka);
				cin.ignore();
				cin.get();
				break;
			case 2:
				if(obj.isEmpty()){
					cout<<"Stack Kosong"<<endl;
				}else{
					cout<<"Angka ";
					obj.getTop();
					cout<<" telah dihapus, tekan ENTER untuk kembali ke MENU";
					cin.get();
					obj.pop();
					
				}break;
			case 3:
				if(obj.isEmpty()){
					cout<<"Stack Kosong"<<endl;
				}else{
					cout<<"Element Paling Atas adalah ";
					obj.getTop();
					cin.get();
					cout<<endl;
					cout<<"tekan ENTER untuk kembali ke MENU"<<endl;
				}
				break;
			case 4:
				obj.print();
				cin.get();
				break;
			case 5:
				exit(0);
				default:
					cout<<endl;
					cout<<"Pilihan tidak ada, tekan ENTER untuk kembali ke MENU";
					cin.get();
					break;
		}
		system("cls");
	}while (menu!=5);
	cin.get();
	return 0;
}
