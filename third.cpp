#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
#include <fstream>
 
using namespace std; 
 
int main(){
	int sample_rate = 4410; // samples per second, select value which provides good quality sound  
   double dt = 1.0/500; // time between samples 
   int n_samples = 100000; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
                        // - how many samples are there altogether? What type should this variable be? 
   int* waveform = new int[n_samples]; // creates the array 
   int i_sample = 0;
   int volume = 0; //max vol value used for equation
   int frequency = 0;
   int n = 0; //number of notes of same freq added in one go
   int NOTE = 2000; //note duration
   int REL = 569; //max no# of flat note
   int release = REL; //release note
   bool decay = false;
   string line;
   ifstream myfile;
   myfile.open("odetojoy.txt");
   while(getline(myfile, line)){
	   cout<<"Read:"<<line<<endl;
	   double number = stod(line) / 4;
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
       //xylophone noise
       if (volume < 20000 && decay == false) {
		   volume = volume + 200;
		   } else if (volume == 20000 && release > 0){
			   decay = true;
			   volume = 20000; //sustain
			   release--;
			   }else {
				   if (volume > 0 && decay == true) {
					   volume = volume - 20;
					   } else {
						   decay = false;
						   release = REL;
								   }
						   }
						  
				   
				   
       waveform[i_sample] = volume*sin(dt * i_sample * frequency * 2 * M_PI);// 
       
   }
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   MakeWavFromInt("tone3.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav 
  
   delete[] (waveform); //if using array  
   return 0; 
} 
