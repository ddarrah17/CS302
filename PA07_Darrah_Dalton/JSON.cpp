#include "JSON.h"

json::json()
{
	playerBase = new player[10];
	playerCount = 0; 
	names = new string[10]; 
}

json::~json()
{
	delete [] playerBase; 
	delete [] names; 
}

void json::readIn()
{
	string dataInput; 
	string nameInput;
	string type; 
	double gameWon = -1, winRate = -1;
	int gamePlay = -1, fastWin = -1, fewWin = -1, topWin = -1;  
	char temp; 
	int tempInt = -1;
	double tempdouble = -1;  
	int count = 0; 

	cout << "==================================" << endl << endl; 	
	fin.clear();
	fin.open("PlayerStatistics.json");
	if(fin.good()){
		//*************************** PLAYER OVERVIEW HERE ****//
	fin >> temp; 
	playerCount++; 
	while(!fin.eof() || playerCount <= 10){
		getline(fin, dataInput, ':');
		getline(fin, dataInput, '"'); 
		getline(fin, dataInput, '"');
		//Player Name available here 
		nameInput = dataInput; 
		names[playerCount - 1] = nameInput;

		getline(fin, dataInput, '{');
		getline(fin, dataInput, ':');
		fin >> tempdouble;
		//Games won available here
		gameWon = tempdouble; 

		getline(fin, dataInput, ':');
		fin >> tempdouble; 
		//Win Rate available here
		winRate = tempdouble; 

		getline(fin, dataInput, ':'); 
		fin >> tempdouble; 
		//Games played available here
		gamePlay = tempdouble; 

		getline(fin, dataInput, ':');
		fin >> tempInt;
		//Fastest Win available here
		fastWin = tempInt; 

		getline(fin, dataInput, ':'); 
		fin >> tempInt; 
		//Fewest Moves available here
		fewWin = tempInt; 

		getline(fin, dataInput, ':'); 
		fin >> tempInt; 
		//Top Score available here
		topWin = tempInt; 

		playerBase[playerCount - 1].setOverview(nameInput, gameWon, winRate, gamePlay, fastWin, fewWin, topWin); 

		//*************************** SUITS HERE ****//

		//*************************** ONE SUIT HERE ****//
			
			getline(fin, dataInput, '{');
			getline(fin, dataInput, ':');
			getline(fin, dataInput, '"'); 
			getline(fin, dataInput, '"'); 
			//Type is available here
			type = dataInput; 

			getline(fin, dataInput, ':');
			fin >> tempdouble; 
			//Games won available here
			gameWon = tempdouble; 

			getline(fin, dataInput, ':'); 
			fin >> tempdouble; 
			//Win Rate available here
			winRate = tempdouble; 

			getline(fin, dataInput, ':'); 
			fin >> tempdouble; 
			//Games won available here
			gamePlay = tempdouble; 

			getline(fin, dataInput, ':');
			fin >> tempInt;
			//Fastest Win available here
			fastWin = tempInt; 

			getline(fin, dataInput, ':'); 
			fin >> tempInt; 
			//Fewest Moves available here
			fewWin = tempInt; 

			getline(fin, dataInput, ':'); 
			fin >> tempInt; 
			//Top Score available here
			topWin = tempInt; 
			
			playerBase[playerCount - 1].setOneSuit(type, gameWon, winRate, gamePlay, fastWin, fewWin, topWin);

			getline(fin, dataInput, '{');  

		//*************************** TWO SUITS HERE ****//

			getline(fin, dataInput, ':');
			getline(fin, dataInput, '"'); 
			getline(fin, dataInput, '"'); 
			//Type is available here
			type = dataInput; 

			getline(fin, dataInput, ':');
			fin >> tempdouble; 
			//Games won available here
			gameWon = tempdouble; 

			getline(fin, dataInput, ':'); 
			fin >> tempdouble; 
			//Win Rate available here
			winRate = tempdouble; 

			getline(fin, dataInput, ':'); 
			fin >> tempdouble; 
			//Games won available here
			gamePlay = tempdouble; 

			getline(fin, dataInput, ':');
			fin >> tempInt;
			//Fastest Win available here
			fastWin = tempInt; 

			getline(fin, dataInput, ':'); 
			fin >> tempInt; 
			//Fewest Moves available here
			fewWin = tempInt; 

			getline(fin, dataInput, ':'); 
			fin >> tempInt; 
			//Top Score available here
			topWin = tempInt; 
			
			playerBase[playerCount - 1].setTwoSuit(type, gameWon, winRate, gamePlay, fastWin, fewWin, topWin);

			getline(fin, dataInput, '{');  

			//*************************** FOUR SUITS HERE ****//

			getline(fin, dataInput, ':');
			getline(fin, dataInput, '"'); 
			getline(fin, dataInput, '"'); 
			//Type is available here
			type = dataInput; 

			getline(fin, dataInput, ':');
			fin >> tempdouble; 
			//Games won available here
			gameWon = tempdouble; 

			getline(fin, dataInput, ':'); 
			fin >> tempdouble; 
			//Win Rate available here
			winRate = tempdouble; 

			getline(fin, dataInput, ':'); 
			fin >> tempdouble; 
			//Games won available here
			gamePlay = tempdouble; 

			getline(fin, dataInput, ':');
			fin >> tempInt;
			//Fastest Win available here
			fastWin = tempInt; 

			getline(fin, dataInput, ':'); 
			fin >> tempInt; 
			//Fewest Moves available here
			fewWin = tempInt; 

			getline(fin, dataInput, ':'); 
			fin >> tempInt; 
			//Top Score available here
			topWin = tempInt; 

			playerBase[playerCount - 1].setFourSuit(type, gameWon, winRate, gamePlay, fastWin, fewWin, topWin);

			fin >> temp; 
			fin >> temp; 
			fin >> temp;
			fin >> temp;  

			playerBase[playerCount - 1].printPlayer();

			if(temp == ']'){
				break; 
			}
			playerCount++; 	
			cout << endl; 		
		}
	}
	fin.close(); 
}

void json::updateFile()
{
	double winRate = 0; 
	double temp1 = -1.1; 
	int temp = -1; 
	//Modified Player 1 Data
	if(playerCount >= 1){
	playerBase[0].setOneSuit("One Suit", 4, winRate, 10, 124, 107, 12467);
	playerBase[0].setTwoSuit("Two Suit", 3, winRate, 12, 673, 208, 123904);
	playerBase[0].setFourSuit("Four Suit", 5, winRate, 15, 982, 416, 342393);
	playerBase[0].setOverview(names[0], temp1, temp1, temp1, temp, temp, temp);
	playerBase[0].printPlayer();
	} 
	if(playerCount >= 2){
	playerBase[1].setOneSuit("One Suit", 19, winRate, 32, 100, 76, 87672);
	playerBase[1].setTwoSuit("Two Suit", 34, winRate, 82, 503, 125, 234024);
	playerBase[1].setFourSuit("Four Suit", 234, winRate, 281, 783, 316, 622393);
	playerBase[1].setOverview(names[1], temp1, temp1, temp1, temp, temp, temp);
	playerBase[1].printPlayer();
	}
	if(playerCount >= 3){
	playerBase[2].setOneSuit("One Suit", 9, winRate, 41, 203, 73, 124672);
	playerBase[2].setTwoSuit("Two Suit", 12, winRate, 88, 803, 189, 1239024);
	playerBase[2].setFourSuit("Four Suit", 2, winRate, 12, 1783, 872, 3422393);
	playerBase[2].setOverview(names[2], temp1, temp1, temp1, temp, temp, temp);
	playerBase[2].printPlayer();
	}
	if(playerCount >= 4){
	playerBase[3].setOneSuit("One Suit", 12, winRate, 58, 241, 114, 97172);
	playerBase[3].setTwoSuit("Two Suit", 8, winRate, 50, 586, 221, 182024);
	playerBase[3].setFourSuit("Four Suit", 2, winRate, 3, 794, 380, 452393);
	playerBase[3].setOverview(names[3], temp1, temp1, temp1, temp, temp, temp);
	playerBase[3].printPlayer();
	}
	if(playerCount >= 5){
	playerBase[4].setOneSuit("One Suit", 61, winRate, 87, 256, 149, 162023);
	playerBase[4].setTwoSuit("Two Suit", 12, winRate, 19, 388, 220, 379399);
	playerBase[4].setFourSuit("Four Suit", 28, winRate, 33, 754, 329, 739992);
	playerBase[4].setOverview(names[4], temp1, temp1, temp1, temp, temp, temp);
	playerBase[4].printPlayer();
	}
	if(playerCount >= 6){
	playerBase[5].setOneSuit("One Suit", 81, winRate, 95, 314, 147, 136552);
	playerBase[5].setTwoSuit("Two Suit", 3, winRate, 6, 783, 251, 336599);
	playerBase[5].setFourSuit("Four Suit", 71, winRate, 80, 996, 452, 761859);
	playerBase[5].setOverview(names[5], temp1, temp1, temp1, temp, temp, temp);
	playerBase[5].printPlayer();
	}
	if(playerCount >= 7){
	playerBase[6].setOneSuit("One Suit", 42, winRate, 55, 530, 192, 237112);
	playerBase[6].setTwoSuit("Two Suit", 19, winRate, 31, 615, 254, 313590);
	playerBase[6].setFourSuit("Four Suit", 19, winRate, 67, 881, 348, 803191);
	playerBase[6].setOverview(names[6], temp1, temp1, temp1, temp, temp, temp);
	playerBase[6].printPlayer();
	}
	if(playerCount >= 8){
	playerBase[7].setOneSuit("One Suit", 21, winRate, 28, 149, 213, 102675);
	playerBase[7].setTwoSuit("Two Suit", 28, winRate, 53, 515, 385, 453703);
	playerBase[7].setFourSuit("Four Suit", 17, winRate, 50, 652, 442, 991244);
	playerBase[7].setOverview(names[7], temp1, temp1, temp1, temp, temp, temp);
	playerBase[7].printPlayer();
	}
	if(playerCount >= 9){
	playerBase[8].setOneSuit("One Suit", 34, winRate, 43, 231, 169, 103193);
	playerBase[8].setTwoSuit("Two Suit", 71, winRate, 97, 685, 236, 211271);
	playerBase[8].setFourSuit("Four Suit", 10, winRate, 88, 912, 442, 868598);
	playerBase[8].setOverview(names[8], temp1, temp1, temp1, temp, temp, temp);
	playerBase[8].printPlayer();
	}
	if(playerCount >= 10){
	playerBase[9].setOneSuit("One Suit", 12, winRate, 22, 234, 160, 167976);
	playerBase[9].setTwoSuit("Two Suit", 35, winRate, 85, 624, 201, 247305);
	playerBase[9].setFourSuit("Four Suit", 49, winRate, 75, 818, 488, 884659);
	playerBase[9].setOverview(names[9], temp1, temp1, temp1, temp, temp, temp);
	playerBase[9].printPlayer();
	}
}

void json::writeOut()
{
	int index = 0; 
	char quote = 34; 
	fout.open("PlayerStatisticsNew.json");
	if(fout.good()){
		fout << '[' << endl;
		while(playerCount != 0){
			fout << ' ' << ' ' << '{' << endl; 
			fout << '\t' << quote << "Player Name" << quote << ':' << ' ' << quote << names[index] << quote << ',' << endl; 
			fout << '\t' << quote << "Overview" << quote << ':' << ' ' << '{' << endl;
			fout << '\t' << ' ' << ' ' << quote << "Games Won" << quote << ':' << ' ' << playerBase[index].getOverviewGamesWon() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << quote << "Win Rate" << quote << ':' << ' ' << playerBase[index].getOverviewWinRate() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << quote << "Games Played" << quote << ':' << ' ' << playerBase[index].getOverviewGamesPlayed() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << quote << "Fastest Win" << quote << ':' << ' ' << playerBase[index].getOverviewFastestWin() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << quote << "Fewest Moves" << quote << ':' << ' ' << playerBase[index].getOverviewFewestWin() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << quote << "Top Score" << quote << ':' << ' ' << playerBase[index].getOverviewTopScore() << endl;  
			fout << '\t' << '}' << ',' << endl; 
			fout << '\t' << quote << "Suits" << quote << ':' << endl; 
			fout << '\t' << '[' << endl; 
			fout << '\t' << ' ' << ' ' << '{' << endl; 
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Type" << quote << ':' << ' ' << quote << "One Suit" << quote << ',' << endl; 
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Games Won" << quote << ':' << ' ' << playerBase[index].getOnesuitGamesWon() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Win Rate" << quote << ':' << ' ' << playerBase[index].getOnesuitWinRate() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Games Played" << quote << ':' << ' ' << playerBase[index].getOnesuitGamesPlayed() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Fastest Win" << quote << ':' << ' ' << playerBase[index].getOnesuitFastestWin() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Fewest Moves" << quote << ':' << ' ' << playerBase[index].getOnesuitFewestWin() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Top Score" << quote << ':' << ' ' << playerBase[index].getOnesuitTopScore() << endl;  
 			fout << '\t' << ' ' << ' ' << '}' << ',' << endl; 
 			fout << '\t' << ' ' << ' ' << '{' << endl; 
 			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Type" << quote << ':' << ' ' << quote << "Two Suits" << quote << ',' << endl; 
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Games Won" << quote << ':' << ' ' << playerBase[index].getTwosuitGamesWon() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Win Rate" << quote << ':' << ' ' << playerBase[index].getTwosuitWinRate() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Games Played" << quote << ':' << ' ' << playerBase[index].getTwosuitGamesPlayed() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Fastest Win" << quote << ':' << ' ' << playerBase[index].getTwosuitFastestWin() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Fewest Moves" << quote << ':' << ' ' << playerBase[index].getTwosuitFewestWin() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Top Score" << quote << ':' << ' ' << playerBase[index].getTwosuitFewestWin() << endl;  
			fout << '\t' << ' ' << ' ' << '}' << ',' << endl; 
 			fout << '\t' << ' ' << ' ' << '{' << endl; 
 			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Type" << quote << ':' << ' ' << quote << "Four Suits" << quote << ',' << endl; 
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Games Won" << quote << ':' << ' ' << playerBase[index].getFoursuitGamesWon() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Win Rate" << quote << ':' << ' ' << playerBase[index].getFoursuitWinRate() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Games Played" << quote << ':' << ' ' << playerBase[index].getFoursuitGamesPlayed() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Fastest Win" << quote << ':' << ' ' << playerBase[index].getFoursuitFastestWin() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Fewest Moves" << quote << ':' << ' ' << playerBase[index].getFoursuitFewestWin() << ',' << endl;  
			fout << '\t' << ' ' << ' ' << ' ' << ' ' << quote << "Top Score" << quote << ':' << ' ' << playerBase[index].getFoursuitFewestWin() << endl;  
			fout << '\t' << ' ' << ' ' << '}' << endl; 
			fout << '\t' << ']' << endl; 
			if((playerCount - 1) == 0){
				fout << '}' << ']';
			}
			else 
				fout << ' ' << ' ' << '}' << ',' << endl; 
			index++; 
			playerCount--; 
		}
	}
}

void player::setOverview(string name, double gamesWon, double winRate, int gamesPlayed, int fastestWin, int fewestMoves, int topScore)
{
	playerO.setPlayerName(name);
	playerO.setGamesPlayed(oneSuit.getGamesPlayedS(), twoSuit.getGamesPlayedS(), fourSuit.getGamesPlayedS());
	playerO.setGamesWon(oneSuit.getGamesWonS(), twoSuit.getGamesWonS(), fourSuit.getGamesWonS()); 
	playerO.updateWinRate(oneSuit.getGamesWonS(), twoSuit.getGamesWonS(), fourSuit.getGamesWonS());
	playerO.updateFastestWin(oneSuit.getFastestWinS(), twoSuit.getFastestWinS(), fourSuit.getFastestWinS()); 
	playerO.updateFewestMoves(oneSuit.getFewestMovesS(), twoSuit.getFewestMovesS(), fourSuit.getFewestMovesS()); 
	playerO.updateTopScore(oneSuit.getTopScoreS(), twoSuit.getTopScoreS(), fourSuit.getTopScoreS());
}

double player::getOverviewGamesWon()
{
	return playerO.getGamesWon(); 
}

double player::getOverviewWinRate()
{
	return playerO.getWinRate();
}

int player::getOverviewGamesPlayed()
{
	return playerO.getGamesPlayed();
}

int player::getOverviewFastestWin()
{	
	return playerO.getFastestWin();
}

int player::getOverviewFewestWin()
{
	return playerO.getFewestMoves();
}

int player::getOverviewTopScore()
{
	return playerO.getTopScore();
}

double player::getOnesuitGamesWon()
{
	return oneSuit.getGamesWonS();
}

double player::getOnesuitWinRate()
{
	return oneSuit.getWinRateS();
}

int player::getOnesuitGamesPlayed()
{
	return oneSuit.getGamesPlayedS();
}

int player::getOnesuitFastestWin()
{
	return oneSuit.getFastestWinS();
}

int player::getOnesuitFewestWin()
{
	return oneSuit.getFewestMovesS();
}

int player::getOnesuitTopScore()
{
	return oneSuit.getTopScoreS();
}

double player::getTwosuitGamesWon()
{
	return twoSuit.getGamesWonS();
}

double player::getTwosuitWinRate()
{
	return twoSuit.getWinRateS();
}

int player::getTwosuitGamesPlayed()
{
	return twoSuit.getGamesPlayedS();
}

int player::getTwosuitFastestWin()
{
	return twoSuit.getFastestWinS();
}

int player::getTwosuitFewestWin()
{
	return twoSuit.getFewestMovesS();
}

int player::getTwosuitTopScore()
{
	return twoSuit.getTopScoreS();
}

double player::getFoursuitGamesWon()
{
	return fourSuit.getGamesWonS();
}

double player::getFoursuitWinRate()
{
	return fourSuit.getWinRateS();
}

int player::getFoursuitGamesPlayed()
{
	return fourSuit.getGamesPlayedS();
}

int player::getFoursuitFastestWin()
{
	return fourSuit.getFastestWinS();
}

int player::getFoursuitFewestWin()
{
	return fourSuit.getFewestMovesS();
}

int player::getFoursuitTopScore()
{
	return twoSuit.getTopScoreS();
}

void player::setOneSuit(string type, double gamesWon, double winRate, int gamesPlayed, int fastestWin, int fewestMoves, int topScore)
{
	oneSuit.setType(type); 
	oneSuit.setGamesPlayedS(gamesPlayed);
	oneSuit.setGamesWonS(gamesWon); 
	oneSuit.updateWinRateS();
	oneSuit.setFastestWinS(fastestWin); 
	oneSuit.setFewestMovesS(fewestMoves); 
	oneSuit.setTopScoreS(topScore);
}

void player::setTwoSuit(string type, double gamesWon, double winRate, int gamesPlayed, int fastestWin, int fewestMoves, int topScore)
{
	twoSuit.setType(type); 
	twoSuit.setGamesPlayedS(gamesPlayed);
	twoSuit.setGamesWonS(gamesWon); 
	twoSuit.updateWinRateS();
	twoSuit.setFastestWinS(fastestWin); 
	twoSuit.setFewestMovesS(fewestMoves); 
	twoSuit.setTopScoreS(topScore);
}

void player::setFourSuit(string type, double gamesWon, double winRate, int gamesPlayed, int fastestWin, int fewestMoves, int topScore)
{
	fourSuit.setType(type); 
	fourSuit.setGamesPlayedS(gamesPlayed);
	fourSuit.setGamesWonS(gamesWon); 
	fourSuit.updateWinRateS();
	fourSuit.setFastestWinS(fastestWin); 
	fourSuit.setFewestMovesS(fewestMoves); 
	fourSuit.setTopScoreS(topScore);
}

void player::printOverView()
{
	cout << "Games Won: " << playerO.getGamesWon() << endl; 
	cout << "Win Rate: " << playerO.getWinRate() << endl; 
	cout << "Games Played: " << playerO.getGamesPlayed() << endl; 
	cout << "Fastest Win: " << playerO.getFastestWin() << endl; 
	cout << "Fewest Moves: " << playerO.getFewestMoves() << endl; 
	cout << "Top Score: " << playerO.getTopScore() << endl << endl;
}

void player::printOneSuit()
{
	cout << "Type: " << oneSuit.getType() << endl; 
	cout << "Games Won: " << oneSuit.getGamesWonS() << endl; 
	cout << "Win Rate: " << oneSuit.getWinRateS() << endl; 
	cout << "Games Played: " << oneSuit.getGamesPlayedS() << endl; 
	cout << "Fastest Win: " << oneSuit.getFastestWinS() << endl; 
	cout << "Fewest Moves: " << oneSuit.getFewestMovesS() << endl; 
	cout << "Top Score: " << oneSuit.getTopScoreS() << endl << endl; 
}

void player::printTwoSuit()
{	
	cout << "Type: " << twoSuit.getType() << endl; 
	cout << "Games Won: " << twoSuit.getGamesWonS() << endl; 
	cout << "Win Rate: " << twoSuit.getWinRateS() << endl; 
	cout << "Games Played: " << twoSuit.getGamesPlayedS() << endl; 
	cout << "Fastest Win: " << twoSuit.getFastestWinS() << endl; 
	cout << "Fewest Moves: " << twoSuit.getFewestMovesS() << endl; 
	cout << "Top Score: " << twoSuit.getTopScoreS() << endl << endl;
}

void player::printFourSuit()
{
	cout << "Type: " << fourSuit.getType() << endl; 
	cout << "Games Won: " << fourSuit.getGamesWonS() << endl; 
	cout << "Win Rate: " << fourSuit.getWinRateS() << endl; 
	cout << "Games Played: " << fourSuit.getGamesPlayedS() << endl; 
	cout << "Fastest Win: " << fourSuit.getFastestWinS() << endl; 
	cout << "Fewest Moves: " << fourSuit.getFewestMovesS() << endl; 
	cout << "Top Score: " << fourSuit.getTopScoreS() << endl << endl;
}

void player::printPlayer()
{
	cout << "Player Name: " << playerO.getPlayerName() << endl << endl; 
	cout << "OVERVIEW" << endl << endl;
	printOverView();
	cout << "SUITS" << endl << endl;  
	printOneSuit();
	printTwoSuit();
	printFourSuit();
	cout << "==================================" << endl; 
}

void overview::setPlayerName(string set)
{
	playerName = set; 
}

string overview::getPlayerName()
{
	return playerName; 
}

void overview::setGames(double ones, double twos, double fours)
{
	games = ones + twos + fours; 
}

double overview::getGames()
{
	return games; 
}

void overview::setGamesWon(double ones, double twos, double fours)
{
	int wins = ones + twos + fours; 

	if(wins > gamesPlayed){
		cout << "You can't have more games won than played." << endl << "ERROR" << endl; 
		gamesWon = -1; 
		return; 
	}
	else 
		gamesWon = wins; 
		 
}

double overview::getGamesWon()
{
	return gamesWon; 
}

void overview::updateWinRate(double ones, double twos, double fours)
{
	if(gamesPlayed == 0){
		winRate = 0;
		return; 
	}
	winRate = ((ones + twos + fours) / gamesPlayed)*100; 
}

double overview::getWinRate()
{
	return winRate; 
}

void overview::setGamesPlayed(double ones, double twos, double fours)
{
	gamesPlayed =  ones + twos + fours; 
}

double overview::getGamesPlayed()
{
	return gamesPlayed;
}

void overview::updateFastestWin(int ones, int twos, int fours)
{
	int fastest; 

	fastest = ones; 

	if(fastest > twos){
		fastest = twos; 
	}
	if(fastest > fours){
		fastest = fours; 
	}

	fastestWin = fastest; 
}

int overview::getFastestWin()
{
	return fastestWin; 
}

void overview::updateFewestMoves(int ones, int twos, int fours)
{
	int fewest; 

	fewest = ones; 

	if(fewest > twos){
		fewest = twos; 
	}
	if(fewest > fours){
		fewest = fours; 
	}

	fewestMoves = fewest; 
}

int overview::getFewestMoves()
{
	return fewestMoves; 
}

void overview::updateTopScore(int ones, int twos, int fours)
{
	int top; 

	top = ones; 

	if(top < twos){
		top = twos; 
	}
	if(top < fours){
		top = fours; 
	}

	topScore = top; 
}

int overview::getTopScore()
{
	return topScore; 
}

void suits::setType(string set)
{
	type = set; 
}

string suits::getType()
{
	return type; 
}

void suits::setGamesS(double set)
{
	games = set; 
}

double suits::getGamesS()
{
	return games; 
}

void suits::setGamesWonS(double set)
{
	if(set > gamesPlayed){
		cout << "You can't have more games won than played." << endl << "ERROR" << endl; 
		gamesWon = -1; 
		return; 
	}
	else 
	gamesWon = set; 
}

double suits::getGamesWonS()
{
	return gamesWon; 
}

void suits::updateWinRateS()
{
	if(gamesPlayed == 0){
		winRate = 0; 
		return; 
	}
	winRate = (gamesWon / gamesPlayed) * 100; 
}

double suits::getWinRateS()
{
	return winRate; 
}

void suits::setGamesPlayedS(double set)
{
	gamesPlayed = set; 
}

double suits::getGamesPlayedS()
{
	return gamesPlayed; 
}

void suits::setFastestWinS(int set)
{
	fastestWin = set; 
}

int suits::getFastestWinS()
{
	return fastestWin; 
}

void suits::setFewestMovesS(int set)
{
	fewestMoves = set; 
}

int suits::getFewestMovesS()
{
	return fewestMoves; 
}

void suits::setTopScoreS(int set)
{
	topScore = set; 
}

int suits::getTopScoreS()
{
	return topScore; 
}


