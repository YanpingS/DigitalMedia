#include <cstring>
#include "videogame.h"

VideoGame::VideoGame(char* newTitle, int newYear, char* newPublisher, float newRating) : DigitalMedia(newTitle, newYear){
  publisher = newPublisher;
  rating = newRating;
}

char* VideoGame::getPublisher(){
  return publisher;
}

float VideoGame::getRating(){
  return rating;
}
