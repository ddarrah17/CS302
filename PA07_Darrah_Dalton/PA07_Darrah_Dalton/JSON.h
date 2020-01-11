#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 

 
class overview{
	
	public: 
		void setPlayerName(string set);
		string getPlayerName();
		void setGames(double ones, double twos, double fours);
		double getGames();
		void setGamesWon(double ones, double twos, double fours);
		double getGamesWon();
		void updateWinRate(double ones, double twos, double fours);
		double getWinRate(); 
		void setGamesPlayed(double ones, double twos, double fours);
		double getGamesPlayed();
		void updateFastestWin(int ones, int twos, int fours); 
		int getFastestWin(); 
		void updateFewestMoves(int ones, int twos, int fours);
		int getFewestMoves();
		void updateTopScore(int ones, int twos, int fours);
		int getTopScore();

	private:
		string playerName;
		double games;
		double gamesWon; 
		double winRate;
		double gamesPlayed;
		int fastestWin;
		int fewestMoves;
		int topScore;  

};

class suits {
	public:
		void setType(string set);
		string getType();
		void setGamesS(double set);
		double getGamesS();
		void setGamesWonS(double set);
		double getGamesWonS();
		void updateWinRateS();
		double getWinRateS(); 
		void setGamesPlayedS(double set);
		double getGamesPlayedS();
		void setFastestWinS(int set); 
		int getFastestWinS();
		void setFewestMovesS(int set);
		int getFewestMovesS();
		void setTopScoreS(int set);
		int getTopScoreS();
	private: 
		string type; 
		double games; 
		double gamesWon; 
		double winRate; 
		double gamesPlayed; 
		int fastestWin;
		int fewestMoves; 
		int topScore; 
};

class player : public overview, public suits {
	public: 
		void test();
		void setOverview(string, double, double, int, int, int, int);
		double getOverviewGamesWon();
		double getOverviewWinRate();
		int getOverviewGamesPlayed();
		int getOverviewFastestWin();
		int getOverviewFewestWin();
		int getOverviewTopScore();
		void printOverView();
		void setOneSuit(string, double, double, int, int, int, int);
		double getOnesuitGamesWon();
		double getOnesuitWinRate();
		int getOnesuitGamesPlayed();
		int getOnesuitFastestWin();
		int getOnesuitFewestWin();
		int getOnesuitTopScore();
		void printOneSuit();
		void setTwoSuit(string, double, double, int, int, int, int);
		double getTwosuitGamesWon();
		double getTwosuitWinRate();
		int getTwosuitGamesPlayed();
		int getTwosuitFastestWin();
		int getTwosuitFewestWin();
		int getTwosuitTopScore();
		void printTwoSuit();
		void setFourSuit(string, double, double, int, int, int, int);
		double getFoursuitGamesWon();
		double getFoursuitWinRate();
		int getFoursuitGamesPlayed();
		int getFoursuitFastestWin();
		int getFoursuitFewestWin();
		int getFoursuitTopScore();
		void printFourSuit();
		void printPlayer(); 
	protected:
		overview playerO; 
		suits oneSuit; 
		suits twoSuit; 
		suits fourSuit; 
};

class json : public player {
	public:
		json();
		~json();
		void readIn();
		void updateFile();
		void writeOut();
	private:
		player *playerBase;
		string *names; 
		int playerCount; 
		ifstream fin; 
		ofstream fout;   
};







