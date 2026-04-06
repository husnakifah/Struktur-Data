#include<iostream>
using namespace std;

struct mahasiswa{
	string nim, nama, prodi;
	float ipk;
};

int main(){
	
	mahasiswa mhs1, mhs2;
	
	mhs1.nim =  "11223344";
	cin>>mhs1.nama;
	mhs2.nim = "11335577";
	cin>>mhs2.ipk;
	
	cout<<"NIM mhs1: "<<mhs1.nim<<endl;
	cout<<"IPK mhs2: "<<mhs2.ipk;
}
