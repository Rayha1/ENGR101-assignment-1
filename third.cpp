#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
#include <fstream>
 
using namespace std; 
 
int main(){
	int sample_rate = 4410; // samples per second, select value which provides good quality sound  
   //double duration= 2; // how long [seconds] it will sound 
   double dt = 1.0/500; // time between samples 
   int n_samples = 25000; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
                        // - how many samples are there altogether? What type should this variable be? 
   int* waveform = new int[n_samples]; // creates the array 
   int i_sample = 0;
   int volume = 6000; //vol value used for equation
   int frequency;
   int n = 0;
   int NOTE = 2500;
   string line;
   ifstream myfile;
   myfile.open("odetojoy.txt");
   while(getline(myfile, line)){
	   cout<<"Read:"<<line<<endl;
	   double number = stod(line) - 500;
	   while (n < NOTE) {
	   waveform[i_sample] = number;
	   i_sample++;
	   n++;
	   }
	   n = 0;
   }
	   myfile.close();
       
   for ( int i_sample = 0; i_sample < n_samples ; i_sample++){  
       frequency = waveform[i_sample];
       waveform[i_sample] = volume*sin(dt * i_sample * frequency * 2 * M_PI);// 
       
   }
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   MakeWavFromInt("tone1.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav 
  
   delete[] (waveform); //if using array  
   return 0; 
} 

