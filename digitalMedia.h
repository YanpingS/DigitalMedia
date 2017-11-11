#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H
#include <cstring>

class DigitalMedia{
	public:
	  DigitalMedia(char* newTitle, int newYear);
		~DigitalMedia();
	  char* getTitle();
	  int getYear();
	  void displayInfo();
		int getType();
	private:
	  char* title;
	  int year;
};

#endif
