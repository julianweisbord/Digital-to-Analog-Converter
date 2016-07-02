#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

void introduction();
int* get_num(int, int*, float);
bool err_check(int*, int);
int binDec(int*, int);
float get_voltage_high(float);

int main(int argc, char** argv){
  int *d_signal;

  // const int length = sizeof(d_signal)/sizeof(int);
  const int length = 8;
  int bin_num[length]={1,0,0,1,0,0,0,1}; // default 8 bit binary number
  float voltage_high = 5;// volts
  bool bit8;
  int dec_num;
  float voltage;


  //intro
    introduction();

  //Take in an 8 bit binary number
    d_signal =get_num(length, bin_num, voltage_high);
    cout << "Enter the max voltage of the digital wave: " <<endl;
    cin >> voltage_high;
    // add error checking
    get_voltage_high(voltage_high);
  //error check based on number of bits, each number
    bit8 = err_check(d_signal, length);

    if(bit8 == 0){
      do{

        d_signal =get_num(length, bin_num, voltage_high);
      }while(bit8==false);
    }

  //convert it to decimal
    dec_num = binDec(d_signal, length);
  //divide the number by 2^8 and this is the DC Current
    voltage = voltage_high*dec_num/255.0;
    cout<< "Your Analog Voltage Output Is " << voltage << " V"<< endl;
  return 0;
}

int binDec(int* binaryNumber, int length){
  int decimal = 0;
  int n=0;
  for(int i = length; i >0; --i){
    decimal+= binaryNumber[i-1]*exp2(n);//2^n * bit
    // cout << "Decimal: " << decimal<< ", " << i << endl;
    n+=1;
  }
  cout << "Decimal is: " << decimal << endl;
  return decimal;
}

bool err_check(int* checkArr, int length){
  short check = 0;
  for(int i=0; i<length; ++i){
    if(checkArr[i]== 0){
      ++check;
      if(check == length)
        return 0;

    }
  }
  return 1;
}


void introduction(){

  cout << "This program takes an 8 bit binary signal from a waveform and converts it to a  voltage. This is called a Digital to Analog Converter." << endl;
}

int* get_num(int length, int *bin_num, float voltage_high){

  char def_char;
  cout<<"Should we enter a default binary string? (y or n)"<< endl;
  cin >> def_char;
  if(def_char !='y'){
    cout << "Enter an 8 bit number: "<< endl;
    for(int i =0; i < length; ++i){ //allow overwrite
      bin_num[i] = 0;
      cout << "Enter bit " << i << ": "<<endl;
      cin >> bin_num[i];
    }

  }

  for(int i = 0; i<length; ++i)//print array
    cout << bin_num[i] << " ";
  cout <<endl;

  return bin_num;

}
float get_voltage_high(float voltage_high){
  return voltage_high;
}
