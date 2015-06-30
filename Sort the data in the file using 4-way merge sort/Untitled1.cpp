#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#defin LENGTH 64
using namespace std;

void print (char *fileName){
		fstream file ;
		int record;
		file.open(fileName, ios::in|ios::binary );
		if(file.fail()){
			cout << "failed"<<endl;
		 
		}
		int c = 0;
	while(true){
			
		  file.read (( char*)&record , sizeof(int) );
		  c++;
		  if(file.eof())break;
		  cout<<record<<" ";
		}cout<<endl<<c-1;
		file.close();
}
void DivideInputFileIntoFourRuns(char *Inputfilename){
		fstream file , file1 , file2 , file3 , file4 ;
		int number;
		file.open(Inputfilename,  ios::out|ios::in|ios::binary );
		file1.open("file_1.txt" , ios::out|ios::binary );
		file2.open("file_2.txt" , ios::out|ios::binary );
		file3.open("file_3.txt" , ios::out|ios::binary );
		file4.open("file_4.txt" , ios::out|ios::binary );
		
		for (int i = 0 ; i < LENGTH/4 ; i++ ){
				file.read((char*)&number , sizeof(int)); 
				file1.write (( char*)&number , sizeof(int));	
		}
		for (int i = 0 ; i < LENGTH/4 ; i++ ){
				file.read((char*)&number , sizeof(int)); 
				file2.write (( char*)&number , sizeof(int));	
		}
		
		for (int i = 0 ; i < LENGTH/4 ; i++ ){
				file.read((char*)&number , sizeof(int)); 
				file3.write (( char*)&number , sizeof(int));	
		}
		
		for (int i = 0 ; i < LENGTH/4 ; i++ ){
				file.read((char*)&number , sizeof(int)); 
				file4.write (( char*)&number , sizeof(int));	
		}
		
		file.close();
		file1.close();
		file2.close();
		file3.close();
		file4.close();
}
 
void SortEachRunOnMemoryAndWriteItBack (){
	 	fstream file , file1 , file2 , file3 , file4 ;
		int number;
		int array[LENGTH/4];
		file1.open("file_1.txt" , ios::out|ios::in|ios::binary );
		file2.open("file_2.txt" , ios::out|ios::in|ios::binary );
		file3.open("file_3.txt" , ios::out|ios::in|ios::binary );
		file4.open("file_4.txt" , ios::out|ios::in|ios::binary );
		for (int i = 0 ; i < 16 ; i++ ){
				file1.read((char*)&number , sizeof(int)); 
				array[i] = number ; 
		}
		sort(array, array+LENGTH/4);
		file1.seekp( 0 , ios::beg);	
		for (int i = 0 ; i < LENGTH/4 ; i++ ){
		file1.write (( char*)&array[i] , sizeof(int));
		}
			
	for (int i = 0 ; i < LENGTH/4 ; i++ ){
				file2.read((char*)&number , sizeof(int)); 
				array[i] = number ; 
		}
		sort(array, array+LENGTH/4);
		file2.seekp( 0 , ios::beg);	
		for (int i = 0 ; i < LENGTH/4 ; i++ ){
		file2.write (( char*)&array[i] , sizeof(int));
		}

	for (int i = 0 ; i < LENGTH/4 ; i++ ){
				file3.read((char*)&number , sizeof(int)); 
				array[i] = number ; 
		}
		
		sort(array, array+LENGTH/4);
		file3.seekp( 0 , ios::beg);	
		for (int i = 0 ; i < LENGTH/4 ; i++ ){
		file3.write (( char*)&array[i] , sizeof(int));
		}
		
	for (int i = 0 ; i < LENGTH/4 ; i++ ){
				file4.read((char*)&number , sizeof(int)); 
				array[i] = number ; 
		}
		sort(array, array+LENGTH/4);
		file4.seekp( 0 , ios::beg);	
		for (int i = 0 ; i < LENGTH/4 ; i++ ){
		file4.write (( char*)&array[i] , sizeof(int));
		}	
		file1.close();
		file2.close();
		file3.close();
		file4.close();
}
void DoAFourWayMergeAndWriteASortedFile(char *Outputfilename){
		fstream  file1 , file2 , file3 , file4 , file5 , file6 , file7 ;
		int number , number1 ;
		file1.open("file_1.txt" , ios::out|ios::in|ios::binary );
		file2.open("file_2.txt" , ios::out|ios::in|ios::binary );
		file3.open("file_3.txt" , ios::out|ios::in|ios::binary );
		file4.open("file_4.txt" , ios::out|ios::in|ios::binary );
		file5.open("file_1&2.txt",ios::out|ios::binary );
		file6.open("file_3&4.txt",ios::out|ios::binary );
		file7.open(Outputfilename,ios::out|ios::binary );
	
		file1.read((char*)&number , sizeof(int)); 
		file2.read((char*)&number1 , sizeof(int)); 
		while(!file1.eof()||!file2.eof()){
				
				if (number <= number1&& !file1.eof()){
					
					file5.write (( char*)&number, sizeof(int));
					file1.read((char*)&number , sizeof(int)); 
				
				}else if(!file2.eof()) {
					
					file5.write (( char*)&number1, sizeof(int));
					file2.read((char*)&number1, sizeof(int));
					
				}else if (file1.eof() && !file2.eof()) {
					
					file5.write (( char*)&number1, sizeof(int));
					file2.read((char*)&number1, sizeof(int));
					
				}else{
					
					file5.write (( char*)&number, sizeof(int));
					file1.read((char*)&number, sizeof(int));	
				}
		}
		
		file3.read((char*)&number , sizeof(int)); 
		file4.read((char*)&number1 , sizeof(int)); 
		 	while(!file3.eof()||!file4.eof()){
		//	cout<<endl<<"  here   "<<endl;
				if (number <= number1&& !file3.eof()){
					
					file6.write (( char*)&number, sizeof(int));
					file3.read((char*)&number , sizeof(int)); 
				
				}else if(!file4.eof()) {
					
					file6.write (( char*)&number1, sizeof(int));
					file4.read((char*)&number1, sizeof(int));
					
				}else if (file1.eof() && !file2.eof()) {
					
					file6.write (( char*)&number1, sizeof(int));
					file4.read((char*)&number1, sizeof(int));
					
				}else{
					
					file6.write (( char*)&number, sizeof(int));
					file3.read((char*)&number, sizeof(int));	
				}
		}
	
		file5.close();
		file6.close();
		file5.open("file_1&2.txt",ios::in|ios::binary );
		file6.open("file_3&4.txt",ios::in|ios::binary );
		file5.read((char*)&number , sizeof(int)); 
		file6.read((char*)&number1 , sizeof(int)); 
		 
		 	while(!file5.eof()||!file6.eof()){
				if (number <= number1&& !file5.eof()){
					
					file7.write (( char*)&number, sizeof(int));
					file5.read((char*)&number , sizeof(int)); 
				
				}else if(!file6.eof()) {
					
					file7.write (( char*)&number1, sizeof(int));
					file6.read((char*)&number1, sizeof(int));
					
				}else if (file5.eof() && !file6.eof()) {
					
					file7.write (( char*)&number1, sizeof(int));
					file6.read((char*)&number1, sizeof(int));
					
				}else{
					
					file7.write (( char*)&number, sizeof(int));
					file5.read((char*)&number, sizeof(int));	
				}
		}
	
		file2.close();
		file3.close();
		file4.close();	
		file5.close();
		file6.close();
		file7.close();	 
}
int BinarySearchOnSortedFile(char *Sortedfilename, int SearchValue) {
	fstream file7 ; 
	int size = 64  , number ,  middle , left = 0 , right = 0; 
	file7.open(Sortedfilename,ios::in|ios::binary );
		
	middle = size/2;
	right = size ;
 
	while (true){
		 	if(file7.eof() || left > right )break;
	file7.seekg((middle *sizeof(int)) , ios::beg );	
	file7.read((char*)&number, sizeof(int));
	
	if ( number == SearchValue )return middle ;
		
	else if(number > SearchValue){
		right = middle - 1; 
	}else {
		left = middle+ 1 ;
	}
		middle = ( right + left)/2 ;
	 
	}
	return -1;
}

void addNumbers (char *fileName){
		ofstream file ;
		srand(time(NULL));
		int record;
		file.open(fileName , ios::out|ios::binary );
		if(file.fail()){
			cout << "failed"<<endl;
			return ;
		}
		cout << "rea" << endl;
		for (int i = 0 ; i < LENGTH ; i++ ){
		  record =  rand()%100 ; 
		  file.write (( char*)&record , sizeof(int) );
		}
		file.close();
}
int main(){
	//addNumbers("file.txt");
	DivideInputFileIntoFourRuns("file.txt");
	SortEachRunOnMemoryAndWriteItBack();
	DoAFourWayMergeAndWriteASortedFile("outputfile.txt");
	int searchValue; 
	cout<< "Enter  the value :-  "<<endl;
	cin >> searchValue ;
	int position = BinarySearchOnSortedFile("outputfile.txt" ,searchValue) ;
	cout<<endl<<"The position of "<<searchValue<<"  =  "<<position<<endl; 
	return 0;
}
