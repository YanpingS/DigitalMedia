#include "digitalMedia.h"
#include "digitalMedia.cpp"
#include "videogame.h"
#include "videogame.cpp"
#include "movie.h"
#include "movie.cpp"
#include "music.h"
#include "music.cpp"
#include <cstring>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<DigitalMedia*> medias;
	cout << "Enter 'ADD' to Add Media" << endl;
	cout << "Enter 'DELETE' to Delete an item" << endl;
	cout << "Enter 'SEARCH' to Search for Objects in the Database" << endl;
	cout << "Enter 'QUIT' to exit the program" << endl;
	while(true) {
		char input[7];

		cout << "List all digital medias title and year " << endl;
		int i;
		for(i=0; i<medias.size(); i++){
			  cout << "NUMBER " << i << " :" <<endl;
				cout << "Title: " << medias[i]->getTitle() << endl;
				cout << "Year: " << medias[i]->getYear() << endl;
		}
    cout << endl << endl;

		cout << "Please Enter a command: "<<endl;
		cin.getline(input, 7);

		if (strcmp(input, "ADD") == 0){
			char mediaType[10];
			char *title = new char[150];
			char yearStr[5];
			int year;
		  //enter a new digital media information if they input ADD
		  cout << "Please enter the Type of Media (VIDEOGAME, MOVIE, MUSIC):"<<endl;
		  cin.getline (mediaType, 10);

		  cout << "Please Enter the Title:" << endl;
		  cin.getline (title, 150);
		  cout << "Enter the Year:"<< endl;
		  cin.getline (yearStr, 5);
			year = atoi(yearStr);
			if (strcmp(mediaType, "VIDEOGAME") == 0){
				char *publisher = new char[50];
				char ratingStr[4];
				float rating;
				cout << "Enter the Name of the Publisher:" << endl;
				//cin.ignore();
				cin.getline (publisher, 50);
				cout << "Enter the Rating: " << endl;
				cin.getline (ratingStr, 4);
				rating = atof(ratingStr);
			  VideoGame* temp = new VideoGame(title, year, publisher, rating);
				medias.push_back(temp);
			} else if (strcmp(mediaType, "MOVIE") == 0){
				char *director = new char[50];
				int duration;
				char durationStr[4];
				float rating;
				char ratingStr[4];
				cout << "Enter the Name of the Director of the Movie:"<< endl;
				cin.getline(director, 50);
				cout << "Enter the Duration of the Movie in Minutes: "<< endl;
				cin.getline (durationStr, 4);
				duration = atoi(durationStr);
				cout << "Enter the Rating of the Movie (1-5 Stars): " <<endl;
				cin.getline (ratingStr, 4);
				rating = atof(ratingStr);
			  Movie* temp = new Movie(title, year, director, duration, rating);
			  medias.push_back(temp);
      } else if (strcmp(mediaType, "MUSIC") == 0){
				char *artist = new char[50];
				int duration;
				char durationStr[4];
				char *publisher = new char[50];

				cout << "Enter the name of the Artist: " <<endl;
				cin.getline(artist, 50);
				cout << "Enter the Duration of the Song (in seconds): " <<endl;
				cin.getline (durationStr, 4);
				duration = atoi(durationStr);
				cout << "Enter the Publisher: " << endl;
				cin.getline(publisher, 50);
			  Music* temp = new Music(title, year, artist, publisher, duration);
	      medias.push_back(temp);
			} else {
				cout << "Invalid media type.." <<endl;
				break;
			}
    } else if(strcmp(input, "SEARCH") == 0){
   		cout << "Search by Title or Year? (TITLE, YEAR): " << endl;
			char *searchField = new char[6];
			cin.getline(searchField, 6);
			vector<DigitalMedia*>::iterator it;
			int count = 0;
			if (strcmp(searchField, "TITLE")==0) {
				char *searchTitle = new char[150];
				cout << "Please Enter the title you want to search: " << endl;
				cin.getline(searchTitle, 150);

				for(it = medias.begin(); it != medias.end(); it++) {
					if (strcmp((*it)->getTitle(), searchTitle)==0) {
						switch((*it)->getType()) {
					  case 1  : //movie
					  	((Movie*)(*it))->displayInfo();
					    break;
						case 2  : //music
						  ((Music*)(*it))->displayInfo();
							break;
					  default : //VideoGame
					    ((VideoGame*)(*it))->displayInfo();
					}

					count++;
					}
				}

				printf("Found total %d Digital Medias with TITLE %s. \n", count, searchTitle);
			}
			else if (strcmp(searchField, "YEAR")==0){
				char *searchYear = new char[5];
				cout << "Please enter the year you want to search: " << endl;
				cin.getline(searchYear, 5);
				for(it = medias.begin(); it != medias.end(); it++) {
					if ((*it)->getYear()==atoi(searchYear)) {
						(*it)->displayInfo();
						count++;
					}
				}
				printf("Found total %d Digital Medias with YEAR %s. \n", count, searchYear);
			}
			else {
				cout << "Invalid Search Field" << endl;
				break;
			}

    } else if(strcmp(input, "DELETE")==0){
			cout << "Delete by Title or Year? (TITLE, YEAR): " << endl;
			char *deleteField = new char[6];
			cin.getline(deleteField, 6);
			vector<DigitalMedia*>::iterator it;
			int count = 0;
			if (strcmp(deleteField, "TITLE")==0) {
				char *deleteTitle = new char[150];
				cout << "Please enter the title you want to delete: " << endl;
				cin.getline(deleteTitle, 150);
				for ( it = medias.begin(); it != medias.end(); ){
   				if (strcmp((*it)->getTitle(),deleteTitle)==0) {
      			delete * it;
      			it = medias.erase(it);
						count++;
   				}
   				else {
      			++it;
   				}
				}
				printf("Deleted total %d Digital Medias with TITLE %s. \n", count, deleteTitle);
			}
			else if (strcmp(deleteField, "YEAR")==0){
				char *deleteYear = new char[5];
				cout << "Please enter the year you want to delete: " << endl;
				//cin.ignore();
				cin.getline(deleteYear, 5);
				int index = 0;
				for ( it = medias.begin(); it != medias.end(); ){
   				if ((*it)->getYear()==atoi(deleteYear)) {
      			delete * it;
      			it = medias.erase(it);
						count++;
   				}
   				else {
      			++it;
   				}
				}
				printf("Deleted total %d Digital Medias with YEAR %s. \n", count, deleteYear);
			}
			else {
				cout << "Invalid Delete Field" << endl;
				break;
			}
    } else if(strcmp(input, "QUIT") ==0){
      //end on quit
      break;
    } else{
      cout << "Not a valid option. ";
    }
  }
}
