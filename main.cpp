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
using namespace std;

int main(){
	vector<DigitalMedia*> medias;
	cout << "Enter 'ADD' to Add Media" << endl;
	cout << "Enter 'DELETE' to Delete an item" << endl;
	cout << "Enter 'SEARCH' to Search for Objects in the Database" << endl;
	cout << "Enter 'QUIT' to exit the program" << endl;
	while(true) {
		char input[7];
		char mediaType[10];
		char title[150];
		int year;
		//get input for commands
		cout << "Please Enter a command: "<<endl;
		cin >> input;
		if (strcmp(input, "ADD") == 0){
		  //enter a new digital media information if they input ADD
		  cout << "Please enter the Type of Media (VIDEOGAME, MOVIE, MUSIC):"<<endl;
			cin.ignore();
		  cin.getline (mediaType, 10);
		  cout << "Enter the Title: " << endl;
			cin.ignore();
		  cin.getline (title, 150);
		  cout << "Enter the Year: "<< endl;
		  cin >> year;
			if (strcmp(mediaType, "VIDEOGAME") == 0){
				char publisher[50];
				float rating;
				cout << "Enter the Name of the Publisher: " << endl;
				cin.ignore();
				cin.getline (publisher, 50);
				cout << "Enter the Rating: " << endl;
				cin >> rating;
			  VideoGame* temp = new VideoGame(title, year, publisher, rating);
				medias.push_back(temp);
			} else if (strcmp(mediaType, "MOVIE") == 0){
				char director[50];
				int duration;
				float rating;
				cout << "Enter the Name of the Director of the Movie:"<< endl;
				cin.ignore();
				cin.getline(director, 50);
				cout << "Enter the Duration of the Movie in Minutes: "<< endl;
				cin >> duration;
				cout << "Enter the Rating of the Movie (1-5 Stars): " <<endl;
				cin >> rating;
			  Movie* temp = new Movie(title, year, director, duration, rating);
			  medias.push_back(temp);
      } else if (strcmp(mediaType, "MUSIC") == 0){
				char artist[50];
				int duration;
				char publisher[50];
				cout << "Enter the name of the Artist: " <<endl;
				cin.ignore();
				cin.getline(artist, 50);
				cout << "Enter the Duration of the Song (in seconds): " <<endl;
				cin >> duration;
				cout << "Enter the Publisher: " << endl;
				cin.ignore();
				cin.getline(publisher, 50);
			  Music* temp = new Music(title, year, artist, publisher, duration);
	      medias.push_back(temp);
			} else {
				cout << "Invalid media type.." <<endl;
				break;
			}
    } else if(strcmp(input, "SEARCH") == 0){
   		cout << "Search by Title or Year? (TITLE, YEAR): " << endl;
			char searchField[6];
			cin >> searchField;
			vector<DigitalMedia*>::iterator it;
			int count = 0;
			if (strcmp(searchField, "TITLE")==0) {
				char searchTitle[150];
				cout << "Please enter the title you want to search: " << endl;
				cin.ignore();
				cin.getline(searchTitle, 150);
				for(it = medias.begin(); it != medias.end(); it++) {
					if (strcmp((*it)->getTitle(), searchTitle)==0) {
						count++;
					}
				}
				printf("Found total %d Digital Medias with TITLE %s. \n", count, searchTitle);
			}
			else if (strcmp(searchField, "YEAR")==0){
				char searchYear[5];
				cout << "Please enter the year you want to search: " << endl;
				cin.ignore();
				cin.getline(searchYear, 5);
				for(it = medias.begin(); it != medias.end(); it++) {
					if ((*it)->getYear()==atoi(searchYear)) {
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
			char deleteField[6];
			cin >> deleteField;
			vector<DigitalMedia*>::iterator it;
			int count = 0;
			if (strcmp(deleteField, "TITLE")==0) {
				char deleteTitle[150];
				cout << "Please enter the title you want to delete: " << endl;
				cin.ignore();
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
				char deleteYear[5];
				cout << "Please enter the year you want to delete: " << endl;
				cin.ignore();
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
