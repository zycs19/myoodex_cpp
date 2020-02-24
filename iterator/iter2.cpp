#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>

using namespace std;

class songIterator;
//class SongOfThe90s: public songIterator;
//class SongOfThe80s: public songIterator;
//class SongOfThe70s: public songIterator;

class SongOfThe90s;
class SongOfThe80s;
class SongOfThe70s;

class SongInfo{
private:
	string songName;
	string bandName;
	int yearReleased;
public:
	SongInfo(string inputName, string inputBand, int inputYear):
		songName(inputName), bandName(inputBand), yearReleased(inputYear){};
	string getSongName(){
		return songName;
	}
	string getBandName(){
		return bandName;
	}
	int getYearReleased(){
		return yearReleased;
	}
};

class songIterator{
public:
	bool hasNext();
	songIterator* createIterator(){
		return this;
	};
	virtual void print(){};
//	songIterator(){};
};

class SongOfThe70s : public songIterator{
//vector
public:
	vector<SongInfo> bestSongs;
	SongOfThe70s(){
		//bestSongs.push(new SongInfo("Imagine", "John Lennon", 1971));
		//bestSongs.push(new SongInfo("American Pie", "Don McLean", 1971));
		//bestSongs.push(new SongInfo("I Will Survive", "Gloria Gaynor", 1979));
		Add("Imagine", "John Lennon", 1971);
		Add("American Pie", "Don McLean", 1971);
		Add("I Will Survive", "Gloria Gaynor", 1979);
	}
	void Add(string newName, string newBand, int newYear){
		SongInfo *newSong = new SongInfo(newName, newBand, newYear);
		bestSongs.push_back(*newSong);
	}
	void print(){
		for(auto it = bestSongs.begin(); it < bestSongs.end(); it ++){
			cout<<"Song:" << it->getSongName() 
				<<"Band: " << it->getBandName()
				<<"Year: " << it->getYearReleased() << endl;
		}
	}
};
class SongOfThe80s : public songIterator{
//queue
public:
	vector<SongInfo> bestSongs;
	SongOfThe80s(){
		//bestSongs.push(new SongInfo("Imagine", "John Lennon", 1971));
		//bestSongs.push(new SongInfo("American Pie", "Don McLean", 1971));
		//bestSongs.push(new SongInfo("I Will Survive", "Gloria Gaynor", 1979));
		Add("Imagine", "John Lennon", 1971);
		Add("American Pie", "Don McLean", 1971);
		Add("I Will Survive", "Gloria Gaynor", 1979);
	}
	void Add(string newName, string newBand, int newYear){
		SongInfo *newSong = new SongInfo(newName, newBand, newYear);
		bestSongs.push_back(*newSong);
	}
	void print(){
		for(auto it = bestSongs.begin(); it < bestSongs.end(); it ++){
			cout<<"Song:" << it->getSongName() 
				<<"Band: " << it->getBandName()
				<<"Year: " << it->getYearReleased() << endl;
		}
	}

};
class SongOfThe90s : public songIterator{
//map
public:
	vector<SongInfo> bestSongs;
	SongOfThe90s(){
		//bestSongs.push(new SongInfo("Imagine", "John Lennon", 1971));
		//bestSongs.push(new SongInfo("American Pie", "Don McLean", 1971));
		//bestSongs.push(new SongInfo("I Will Survive", "Gloria Gaynor", 1979));
		Add("Imagine", "John Lennon", 1971);
		Add("American Pie", "Don McLean", 1971);
		Add("I Will Survive", "Gloria Gaynor", 1979);
	}
	void Add(string newName, string newBand, int newYear){
		SongInfo *newSong = new SongInfo(newName, newBand, newYear);
		bestSongs.push_back(*newSong);
	}
	void print(){
		for(auto it = bestSongs.begin(); it < bestSongs.end(); it ++){
			cout<<"Song:" << it->getSongName() 
				<<"Band: " << it->getBandName()
				<<"Year: " << it->getYearReleased() << endl;
		}
	}

};

class DiscJockey{
	public:
	SongOfThe70s s70s;
	SongOfThe80s s80s;
	SongOfThe90s s90s;

	
	void showTheSongs(){
	songIterator* iter70s = s70s.createIterator();
	songIterator* iter80s = s80s.createIterator();
	songIterator* iter90s = s90s.createIterator();
	
	iter70s->print();
	iter80s->print();
	iter90s->print();
	}
};
int main(){
	DiscJockey songs;
	songs.showTheSongs();
}
