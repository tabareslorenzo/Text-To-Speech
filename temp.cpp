#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <unordered_map>
#include <fstream>
#include <Carbon/Carbon.h>
#include<ApplicationServices/ApplicationServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include<CoreAudio/CoreAudio.h>
#include <AudioToolbox/AudioToolbox.h>
// #include "podofo1/podofo/podofo.h"


// using namespace PoDoFo;
using namespace std;
bool fin = false;

SpeechDoneProcPtr MySpeechDoneProc (SpeechChannel chan, long refCon)
 {
       fin = true;
       SpeechDoneProcPtr x;
       return x;
 }




int main()
{
      cout << "Enter filename" << endl;
      string file;
      string test =" ";
      string type;

      //PoDoFo::PdfMemDocument pdf("mydoc.pdf");

      cin >> file;
      for(int i = 0; i < file.length(); i++)
      {
            if(i>0)
            {
                  if(   (file.at(i-1) == '.') && (i<file.length()-2)    )
                  {
                        type = file.substr (i,i+2);
                  }
            }

      }

      ifstream inFile(file.c_str());
      string contents;
      CFStringRef phonemes;
      // void MySpeechDoneProc (
      //       SpeechChannel chan,
      //       long refCon
      //       );
      // SpeechDoneUPP = SpeechDoneProcPtr;
      if(! inFile)
      {
            cerr << "unable to open:" << file << "exiting \n";
            return -1;
      }
      SpeechChannel speechchannel;
      OSErr val = NewSpeechChannel(NULL, &speechchannel);
      SpeechDoneProcPtr MySpeechDoneProc (
         SpeechChannel speechchannel,
         long refCon
      );



      while (inFile)
      {
            getline(inFile, contents);
            CFStringRef Cfile = CFStringCreateWithCString(NULL, contents.c_str(), kCFStringEncodingUTF8);
            SpeakCFString(speechchannel, Cfile, NULL);

            // SpeechDoneProcPtr = (speechchannel, NULL);
            // for(int i = 0; i < 100000; i++)
            // {
            //       for(int j = 0; j < 10000; j++);
            // }
            while(fin != true);


      }

      // CFstring CFStringCreateWithBytes(file.c_str(), file.size()); kCFAllocatorDefault
      //CFStringRef Cfile = CFStringCreateWithCString(NULL, contents.c_str(), kCFStringEncodingUTF8);
      //CFStringRef Ctest = CFStringCreateWithCString(NULL, test.c_str(), kCFStringEncodingUTF8);

      string * fileptr=nullptr;
      //CopyPhonemesFromText(speechchannel, Cfile, &phonemes);






      return 0;
}
