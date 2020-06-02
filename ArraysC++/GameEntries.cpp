#include<iostream>
#include<string>

/**********************Defining Exceptions*******************/
class RuntimeException{
	private:
		std::string errMsg;
	public:
		RuntimeException(const std::string& str ):errMsg(str){}
};

class IndexOutOfBounds:public RuntimeException{
	public:
		IndexOutOfBounds(const std::string& str):RuntimeException(str){}
};


/******************Game Entry class****************/
class GameEntry{
	public:
		GameEntry(const std::string&,int s); //The string passed to the constructor cannot be modified
		GameEntry(){};
		std::string getName() const;         //The implicit this pointer is a constant
	    int getScore() const;	
	private:
		std::string name;
		int score;
};


GameEntry::GameEntry(const std::string& n,int s):name(n),score(s){}

std::string GameEntry::getName() const {
	return name; 
}

int GameEntry::getScore()const { 
	return score; 
}


/********************Class Scores******************/

class Scores{
	public:
		Scores(int maxEntries = 10){			//Constructor
			this->maxEntries = maxEntries;
			entries = new GameEntry[maxEntries];
			numEntries = 0;
		}
		~Scores(){				       //Destructor
			delete[] entries;
		}

		void addScore(GameEntry& g);
		GameEntry removeScore(int i) throw(IndexOutOfBounds);
	private:
		int maxEntries;
		int numEntries;
		GameEntry* entries;
};

/********************Insertion to the array************/

void Scores::addScore(GameEntry& g){
    int i,count=0;
    
	if(numEntries==maxEntries){
		if (g.getScore()<=entries[maxEntries-1].getScore())
			return;
	}
	else{
        /****************Modification*****************/
        /*For max number of a name to be maxentries/2*/

		for(i=0;i<maxEntries;++i){
            if(g.getName()==entries[i].getName())
                count++;
            if (count==maxEntries/2){
                return;
                }
            }
        /*************End Modification****************/
        numEntries++;

	i = numEntries-2;
	while(i>=0&&g.getScore()>entries[i].getScore()){
		entries[i+1] = entries[i];
		i--;
	}
	entries[i+1]=g;
    }
}

/*******************Deletion*************************/

GameEntry Scores::remove(int i) throw(IndexOutOfBounds){  //i is the position of the object we want to remove
	if(i<0||i>=maxEntries) throw IndexOutOfBounds("Invalid Index");
	GameEntry e = entries[i];
        for(int j = i;j<numEntries-1;j++){
		entries[j] = entries[j+1];
	}	
	--numEntries;
	return e;
}


int main(){
	return 0;
}
