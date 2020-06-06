
// C++ program CRC and checksum calculator and error detector
// Archeticture ECCE5232
// Muslim Albalushi (114860)
#include<stdio.h>
#include<iostream>
#include<math.h>
#include <fstream>
#include <string.h>
using namespace std;
string Remainder, Codeword; char a[32], sum[32],comp[32];
/////
void checksum2(char checksum[4]){
  char carr='0';
  for(int t=3; t>=0; t--){

    if(checksum[t]=='0'&&sum[t]=='0'&&carr=='0')
    {sum[t]='0'; }
    else if(checksum[t]=='0'&&sum[t]=='1'&&carr=='0')
    {sum[t]='0'; }
    else if(checksum[t]=='1'&&sum[t]=='0'&&carr=='0')
    {sum[t]='0'; }
    else if(checksum[t]=='1'&&sum[t]=='1'&&carr=='0')
    {sum[t]='0'; carr='1';}
    else if(checksum[t]=='0'&&sum[t]=='0'&&carr=='1')
    {sum[t]='1'; }
    else if(checksum[t]=='0'&&sum[t]=='1'&&carr=='1')
    {sum[t]='0'; carr='1';}
    else if(checksum[t]=='1'&&sum[t]=='0'&&carr=='1')
    {sum[t]='0'; carr='1';}
    else if(checksum[t]=='1'&&sum[t]=='1'&&carr=='1')
    {sum[t]='1'; carr='1';}
  }
  if(carr=='1'){
    if(sum[3]=='0')
    sum[3]='1';
    else if(sum[3]=='1'&&sum[2]=='0')
    {sum[2]='1'; sum[3]='0';}
    else if(sum[3]=='1'&&sum[2]=='1'&&sum[1]=='0')
    {sum[1]='1'; sum[2]='0'; sum[3]='0';}
    else if(sum[3]=='1'&&sum[2]=='1'&&sum[1]=='1'&&sum[0]=='0')
    {sum[0]='1'; sum[1]='0'; sum[2]='0'; sum[3]='0';}
    else
    carr='0';
  }
}
////
void checksum(){
  char  carry='0';
  int i, ov=0, count=3;

  int length=strlen(a);
  // cout<<"\n"<<a<<" "<<length;
  if(strlen(a)==8||strlen(a)==16||strlen(a)==24||strlen(a)==32){


      for(i=length-1 ; i>=length-4 ; i--){
      //cout<<endl<<a[i-4]<<endl;
          if(length==8 && a[i]=='0' && a[i-4]=='0' && carry=='0')
           sum[count]='0';
           else if(length==8 && a[i]=='0' && a[i-4]=='1' && carry=='0')
           sum[count]='1';
           else if(length==8 && a[i]=='1' && a[i-4]=='0' && carry=='0')
           sum[count]='1';
           else if(length==8 && a[i]=='1' && a[i-4]=='1' && carry=='0')
           { sum[count]='0'; carry='1'; }
           //
           else if(length==8 && a[i]=='0' && a[i-4]=='0' && carry=='1')
           {sum[count]='1';    carry='0'; }
           else if(length==8 && a[i]=='0' && a[i-4]=='1' && carry=='1')
           { sum[count]='0';   carry='1'; }
           else if(length==8 && a[i]=='1' && a[i-4]=='0' && carry=='1')
           { sum[count]='0';   carry='1'; }
           else if(length==8 && a[i]=='1' && a[i-4]=='1' && carry=='1')
           {sum[count]='1'; carry='1'; }
           /////////////////////
           else if(length==16 && a[i]=='0' && a[i-4]=='0' &&a[i-8]=='0' &&a[i-12]=='0' && carry=='0')
            sum[count]='0';
            else if(length==16 && a[i]=='0' && a[i-4]=='0' &&a[i-8]=='0' &&a[i-12]=='1'&& carry=='0')
            sum[count]='1';
            else if(length==16 && a[i]=='0' && a[i-4]=='0' &&a[i-8]=='1' &&a[i-12]=='0'&& carry=='0')
            sum[count]='1';
            else if(length==16 && a[i]=='0' && a[i-4]=='0' &&a[i-8]=='1' &&a[i-12]=='1'&& carry=='0')
            { sum[count]='0'; carry='1'; }
            else if(length==16 && a[i]=='0' && a[i-4]=='1' &&a[i-8]=='0' &&a[i-12]=='0'&& carry=='0')
             sum[count]='0';
            else if(length==16 && a[i]=='0' && a[i-4]=='1' &&a[i-8]=='0' &&a[i-12]=='1'&& carry=='0')
            { sum[count]='0'; carry='1'; }
            else if(length==16 && a[i]=='0' && a[i-4]=='1' &&a[i-8]=='1' &&a[i-12]=='0'&& carry=='0')
            { sum[count]='0'; carry='1'; }
            else if(length==16 && a[i]=='0' && a[i-4]=='1' &&a[i-8]=='1' &&a[i-12]=='1'&& carry=='0')
            { sum[count]='1'; carry='1'; }
            else if(length==16 && a[i]=='1' && a[i-4]=='0' &&a[i-8]=='0' &&a[i-12]=='0'&& carry=='0')
            { sum[count]='1'; }
            else if(length==16 && a[i]=='1' && a[i-4]=='0' &&a[i-8]=='0' &&a[i-12]=='1'&& carry=='0')
            { sum[count]='0'; carry='1'; }
            else if(length==16 && a[i]=='1' && a[i-4]=='0' &&a[i-8]=='1' &&a[i-12]=='0'&& carry=='0')
            { sum[count]='0'; carry='1'; }
            else if(length==16 && a[i]=='1' && a[i-4]=='0' &&a[i-8]=='1' &&a[i-12]=='1'&& carry=='0')
            { sum[count]='1'; carry='1'; }
            else if(length==16 && a[i]=='1' && a[i-4]=='1' &&a[i-8]=='0' &&a[i-12]=='0'&& carry=='0')
            { sum[count]='0'; carry='1'; }
            else if(length==16 && a[i]=='1' && a[i-4]=='1' &&a[i-8]=='0' &&a[i-12]=='1'&& carry=='0')
            { sum[count]='1'; carry='1'; }
            else if(length==16 && a[i]=='1' && a[i-4]=='1' &&a[i-8]=='1' &&a[i-12]=='0'&& carry=='0')
            { sum[count]='1'; carry='1'; }
            else if(length==16 && a[i]=='1' && a[i-4]=='1' &&a[i-8]=='1' &&a[i-12]=='1'&& carry=='0')
            {sum[count]='0'; carry='0', ov++;}
            //
            else if(length==16 && a[i]=='0' && a[i-4]=='0' &&a[i-8]=='0' &&a[i-12]=='0' && carry=='1')
             {sum[count]='1'; carry='0';}
             else if(length==16 && a[i]=='0' && a[i-4]=='0' &&a[i-8]=='0' &&a[i-12]=='1'&& carry=='1')
             {sum[count]='0'; carry='1'; }
             else if(length==16 && a[i]=='0' && a[i-4]=='0' &&a[i-8]=='1' &&a[i-12]=='0'&& carry=='1')
             {sum[count]='0'; carry='1'; }
             else if(length==16 && a[i]=='0' && a[i-4]=='0' &&a[i-8]=='1' &&a[i-12]=='1'&& carry=='1')
             { sum[count]='1'; carry='1'; }
             else if(length==16 && a[i]=='0' && a[i-4]=='1' &&a[i-8]=='0' &&a[i-12]=='0'&& carry=='1')
             { sum[count]='0'; carry='1'; }
             else if(length==16 && a[i]=='0' && a[i-4]=='1' &&a[i-8]=='0' &&a[i-12]=='1'&& carry=='1')
             { sum[count]='1'; carry='1'; }
             else if(length==16 && a[i]=='0' && a[i-4]=='1' &&a[i-8]=='1' &&a[i-12]=='0'&& carry=='1')
             { sum[count]='1'; carry='1'; }
             else if(length==16 && a[i]=='0' && a[i-4]=='1' &&a[i-8]=='1' &&a[i-12]=='1'&& carry=='1')
             { sum[count]='0'; carry='0'; ov++;}
             else if(length==16 && a[i]=='1' && a[i-4]=='0' &&a[i-8]=='0' &&a[i-12]=='0'&& carry=='1')
             { sum[count]='0'; carry='1'; }
             else if(length==16 && a[i]=='1' && a[i-4]=='0' &&a[i-8]=='0' &&a[i-12]=='1'&& carry=='1')
             { sum[count]='1'; carry='1'; }
             else if(length==16 && a[i]=='1' && a[i-4]=='0' &&a[i-8]=='1' &&a[i-12]=='0'&& carry=='1')
             { sum[count]='1'; carry='1'; }
             else if(length==16 && a[i]=='1' && a[i-4]=='0' &&a[i-8]=='1' &&a[i-12]=='1'&& carry=='1')
             { sum[count]='0'; carry='0'; ov++;}
             else if(length==16 && a[i]=='1' && a[i-4]=='1' &&a[i-8]=='0' &&a[i-12]=='0'&& carry=='1')
             { sum[count]='1'; carry='1'; }
             else if(length==16 && a[i]=='1' && a[i-4]=='1' &&a[i-8]=='0' &&a[i-12]=='1'&& carry=='1')
             { sum[count]='0'; carry='0'; ov++;}
             else if(length==16 && a[i]=='1' && a[i-4]=='1' &&a[i-8]=='1' &&a[i-12]=='0'&& carry=='1')
             { sum[count]='0'; carry='0'; ov++;}
             else if(length==16 && a[i]=='1' && a[i-4]=='1' &&a[i-8]=='1' &&a[i-12]=='1'&& carry=='1')
             { sum[count]='1'; carry='0'; ov++;}
  else
  break;

           //
   count--;
      } //for loop end

  }
  /*
  for (int k=3 ; k>=0 ; k--){
    cout <<"\n"<<sum[k];
  } */

  if(carry=='1'){
    if(sum[3]=='0')
    sum[3]='1';
    else if(sum[3]=='1'&&sum[2]=='0')
    {sum[2]='1'; sum[3]='0';}
    else if(sum[3]=='1'&&sum[2]=='1'&&sum[1]=='0')
    {sum[1]='1'; sum[2]='0'; sum[3]='0';}
    else if(sum[3]=='1'&&sum[2]=='1'&&sum[1]=='1'&&sum[0]=='0')
    {sum[0]='1'; sum[1]='0'; sum[2]='0'; sum[3]='0';}
    else
    carry='0';
  }

  for(ov ; ov>0 ; ov--){
    if(sum[3]=='0')
    sum[3]='1';
    else if(sum[3]=='1'&&sum[2]=='0')
    {sum[2]='1'; sum[3]='0';}
    else if(sum[3]=='1'&&sum[2]=='1'&&sum[1]=='0')
    {sum[1]='1'; sum[2]='0'; sum[3]='0';}
    else if(sum[3]=='1'&&sum[2]=='1'&&sum[1]=='1'&&sum[0]=='0')
    {sum[0]='1'; sum[1]='0'; sum[2]='0'; sum[3]='0';}
    else if(sum[3]=='1'&&sum[2]=='1'&&sum[1]=='1'&&sum[0]=='1')
    {cout<<"\nOverflow\n";}
  }
  //complement checksum
  for(int t=3; t>=0; t--){
    if(sum[t]=='0')
    comp[t]='1';
    else
    comp[t]='0';
  }
}
// function to convert integer to binary string
string toBin(long long int num){
	string bin = "";
	while (num){
		if (num & 1)
			bin = "1" + bin;
		else
			bin = "0" + bin;
		num = num>>1;
	}
  if (bin=="")
    bin="0000";
	return bin;
}

// function to convert binary string to decimal
long long int toDec(string bin){
	long long int num = 0;
	for (int i=0; i<bin.length(); i++){
		if (bin.at(i)=='1')
			num += 1 << (bin.length() - i - 1);
	}
	return num;
}

// function to compute CRC and codeword
void CRC(string dataword, string generator){
	int l_gen = generator.length();
	long long int gen = toDec(generator);

	long long int dword = toDec(dataword);

	// append 0s to dividend
	long long int dividend = dword << (l_gen-1);

	// shft specifies the no. of least
	// significant bits not being XORed
	int shft = (int) ceill(log2l(dividend+1)) - l_gen;
	long long int rem;

	while ((dividend >= gen) || (shft >= 0)){

		// bitwise XOR the MSBs of dividend with generator
		// replace the operated MSBs from the dividend with
		// remainder generated
		rem = (dividend >> shft) ^ gen;
		dividend = (dividend & ((1 << shft) - 1)) | (rem << shft);

		// change shft variable
		shft = (int) ceill(log2l(dividend + 1)) - l_gen;
	}

	// finally, AND the initial dividend with the remainder (=dividend)
	long long int codeword = (dword << (l_gen - 1)) | dividend;
  Codeword=toBin(codeword);
  Remainder=toBin(dividend);
}

int main(){
  char choice;
  string dataword, generator="11101";
  START:
  cout << "=================================================\n";
  cout << "Please choose the operation you want to do:" << '\n';
  cout << "(a) store the data to the memory\n";
  cout << "(b) check the data from the memory" << '\n';
  cout << "Please Enter option here:";
  cin >> choice;
  switch (choice) {
    case 'a':
    case 'A':
  {
      int CheckType;
      cout<<"\n==============================================="<<endl;
      cout<<"1) CRC\n";
      cout<<"2) Checksum\n";
      cout<<"Choose Error Detection type(1-2):";
      cin>>CheckType;
      if (CheckType==1) {
        cout << "\nPlease Enter the data in binary (to store) in memory :";
        cin >> dataword;
      CRC(dataword, generator);
      ofstream fout("Memory.txt");
      fout<<dataword<<"   "<<Codeword<<"  "<<Remainder;
      fout.close();
      cout<<"\n==============================================="<<endl;
      cout << "Entered Data:                      " << dataword<<endl;
      cout << "Remainder:                         " << Remainder<<endl;
      cout << "Encoded Data (Data + Remainder) :  " << Codeword<<endl;
      //goto START;
      return 0;
      }
      if(CheckType==2){
        cout << "\nPlease Enter the data in binary (to store) in memory :";
        cin >> a;
        checksum();
        cout<<"\n=================================================";
        cout<<"\nData Entered :"<<a<<endl;
        cout<<"Sum          :"<<sum[0]<<sum[1]<<sum[2]<<sum[3];
        cout<<"\nChecksum:    :"<<comp[0]<<comp[1]<<comp[2]<<comp[3]<<endl;

        return 0;
      }
    }
    break;

    case 'b':
    case 'B':
    {
          int CheckType;
          cout<<"\n==============================================="<<endl;
          cout<<"1) CRC\n";
          cout<<"2) Checksum\n";
          cout<<"Choose Error Detection type used(1-2):";
          cin>>CheckType;
          if (CheckType==1) {
            cout << "\nPlease Enter the [data+Remainder] in binary (read from) memory :";
            cin >> dataword;
          CRC(dataword, generator);

          cout<<"\n==============================================="<<endl;
          cout << "Entered Data:            " << dataword<<endl;
          cout << "Remainder:               " << Remainder<<endl;
          if(Remainder=="0000")
          cout<<"Remainder is ZERO No Error in Data reading\n";
          else
          cout<<"Remainder is NOT ZERO There is an Error in Data reading\n";
          //goto START;
          return 0;
          }
          if(CheckType==2){
            char test[4];
            cout << "\nPlease Enter the data in binary (read from) memory :";
            cin >> a;
            cout<<"\nEnter the checksum used(recieved):";
            cin>>test;
            checksum();
            checksum2(test);
            cout<<"\n=================================================";
            cout<<"\nData Entered :"<<a<<endl;
            cout<<"Sum          :"<<sum[0]<<sum[1]<<sum[2]<<sum[3]<<endl;
            if(sum[0]=='0'&&sum[1]=='0'&&sum[2]=='0'&&sum[3]=='0')
            cout<<"\n** No ERROR since Sum is ZERO **\n";
            else
            cout<<"\n!! There is an ERROR since Sum is not ZERO !!\n";


            return 0;
          }
    } //
    break;
    case 'q': case 'Q':
    {
      cout <<"\nExiting . . .";
      return 0;
    }
    break;
    default :
    {
    cout<<"\nNot a valid choice try again\n";
    goto START;
  }
  }






	return 0;
}
