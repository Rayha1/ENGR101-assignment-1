#include <iostream> // input-output library 
#include <math.h>  // library for sin function 
#include <vector>  // if using vectors 
#include "wav.hpp" // make sure to include this helper library 
// " " instead of <> means that library is in the same folder as your program 
 
using namespace std; 
 
int main(){ 
   int sample_rate = 1500; // samples per second, select value which provides good quality sound  
   //double duration= 2; // how long [seconds] it will sound 
   double dt = 1.0/500; // time between samples 
   int n_samples = 100000; // if sound is "duration" seconds long and there are "sample_rate" samples per second 
                        // - how many samples are there altogether? What type should this variable be? 
   int* waveform = new int[n_samples]; // creates the array 
   int frequency1= 1200; // pitch of the sound 1
   int frequency2= 600; // pitch of the sound 2
   int volume1 = 6000; // 6000 is loud enough 
   int volume2 = 12000; // 6000 is loud enough
   int frequency; // freq value used for equation
   int volume; //vol value used for equation
   
   for ( int i_sample = 0; i_sample < n_samples ; i_sample++){  
       // if using array
       
       if (i_sample %1337 == 0) { //large number of samples to seperate the wee from the woo
		   if (frequency == frequency1){ //wee
			   frequency = frequency2;
			   volume = volume2;
			   } else { //woo
				   frequency = frequency1;
				   volume = volume1;
				   } 
				   }
				   
			   
       waveform[i_sample] = volume*sin(dt * i_sample * frequency * 2 * M_PI);// formula 
   } 
   // generates sound file from waveform array, writes n_samples numbers  
   // into sound wav file 
   // should know sample_rate for sound timing 
   MakeWavFromInt("tone1.wav",sample_rate, waveform, n_samples); //file name can be changed but keep extension .wav 
  
   delete[] (waveform); //if using array  
   return 0; 
} 

