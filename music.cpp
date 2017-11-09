#include <cstring>
#include "music.h"

Music::Music(char* newTitle, int newYear, char* newArtist, char* newPublisher, int newDuration ) : DigitalMedia(newTitle, newYear){
  artist = newArtist;
  publisher = newPublisher;
  duration = newDuration;
}

char* Music::getArtist(){
  return artist;
}

char* Music::getPublisher(){
  return publisher;
}

int Music::getDuration(){
  return duration;
}
