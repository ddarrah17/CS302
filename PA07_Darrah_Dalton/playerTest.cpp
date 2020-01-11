void player::test()
{
	//////////////////////////////////////////////////////////
	////////////////////SUITS TESTING/////////////////////////
	//////////////////////////////////////////////////////////

	/*		*		*		*		ONES 	*/

	///////////////////		TYPE TEST
	string type, type1; 
	type = "One Suit";
	oneSuit.setType(type);
	type1 = oneSuit.getType();
	cout << "Type: " << type << endl; 

	///////////////////		GAMES TEST
	double games1 = 10, games2; 
	oneSuit.setGames(games1);
	games2 = oneSuit.getGames();
	cout << "Games: " << games2 << endl; 

	///////////////////		GAMES WON TEST
	double gamesWon2 = 8, gamesWon3; 
	oneSuit.setGamesWon(gamesWon2);
	gamesWon3 = oneSuit.getGamesWon();
	cout << "Games Won: " << gamesWon3 << endl; 

	///////////////////		WIN RATE TEST
	double winRate2; 
	oneSuit.updateWinRate();
	winRate2 = oneSuit.getWinRate();
	cout << "Win Rate: " << winRate2 << "%" << endl; 

	///////////////////		GAMES PLAYED TEST
	double gamesPlayed2 = 10, gamesPlayed3; 
	oneSuit.setGamesPlayed(gamesPlayed2);
	gamesPlayed3 = oneSuit.getGames();
	cout << "Games Played: " << gamesPlayed3 << endl; 

	///////////////////		FASTEST WIN TEST
	int fastestWin2 = 234, fastestWin3; 
	oneSuit.setFastestWin(fastestWin2); 
	fastestWin3 = oneSuit.getFastestWin();
	cout << "Fastest Win: " << fastestWin3 << "(s)" << endl; 

	///////////////////		FEWEST MOVES TEST
	int fewestMoves2 = 67, fewestMoves3;
	oneSuit.setFewestMoves(fewestMoves2);
	fewestMoves3 = oneSuit.getFewestMoves();
	cout << "Fewest Moves: " << fewestMoves3 << endl; 

	///////////////////		TOP SCORE TEST
	int topScore2 = 4410, topScore3;
	oneSuit.setTopScore(topScore2);
	topScore3 = oneSuit.getTopScore(); 
	cout << "Top Score: " << topScore3 << endl;  



	/*		*		*		*		TWOS 	*/
	
	///////////////////		TYPE TEST
	string type2, type3; 
	type2 = "Two Suit";
	twoSuit.setType(type2);
	type3 = twoSuit.getType();
	cout << endl << "Type: " << type3 << endl; 

	///////////////////		GAMES TEST
	double games3 = 1, games4; 
	twoSuit.setGames(games3);
	games4 = twoSuit.getGames();
	cout << "Games: " << games4 << endl;

	///////////////////		GAMES WON TEST
	double gamesWon4 = 0, gamesWon5; 
	twoSuit.setGamesWon(gamesWon4);
	gamesWon5 = twoSuit.getGamesWon();
	cout << "Games Won: " << gamesWon5 << endl; 

	///////////////////		WIN RATE TEST 
	double winRate3; 
	twoSuit.updateWinRate();
	winRate3 = twoSuit.getWinRate();
	cout << "Win Rate: " << winRate3 << "%" << endl; 

	///////////////////		GAMES PLAYED TEST
	double gamesPlayed4 = 1, gamesPlayed5; 
	twoSuit.setGamesPlayed(gamesPlayed4);
	gamesPlayed5 = twoSuit.getGames();
	cout << "Games Played: " << gamesPlayed5 << endl; 

	///////////////////		FASTEST WIN TEST
	int fastestWin4 = 631, fastestWin5; 
	twoSuit.setFastestWin(fastestWin4); 
	fastestWin5 = twoSuit.getFastestWin();
	cout << "Fastest Win: " << fastestWin5 << "(s)" << endl; 

	///////////////////		FEWEST MOVES TEST
	int fewestMoves4 = 182, fewestMoves5;
	twoSuit.setFewestMoves(fewestMoves4);
	fewestMoves5 = twoSuit.getFewestMoves();
	cout << "Fewest Moves: " << fewestMoves5 << endl; 

	///////////////////		TOP SCORE TEST
	int topScore4 = 12410, topScore5;
	twoSuit.setTopScore(topScore4);
	topScore5 = twoSuit.getTopScore(); 
	cout << "Top Score: " << topScore5 << endl;  

	/*		*		*		*		FOURS 	*/
	
	///////////////////		TYPE TEST
	string type4, type5; 
	type4 = "Four Suit";
	fourSuit.setType(type4);
	type5 = fourSuit.getType();
	cout << endl << "Type: " << type5 << endl; 

	///////////////////		GAMES TEST
	double games5 = 3, games6; 
	fourSuit.setGames(games5);
	games6 = fourSuit.getGames();
	cout << "Games: " << games6 << endl; 

	///////////////////		GAMES WON TEST
	double gamesWon6 = 2, gamesWon7; 
	fourSuit.setGamesWon(gamesWon6);
	gamesWon7 = fourSuit.getGamesWon();
	cout << "Games Won: " << gamesWon7 << endl;  

	///////////////////		WIN RATE TEST
	double winRate4; 
	fourSuit.updateWinRate();
	winRate4 = fourSuit.getWinRate();
	cout << "Win Rate: " << winRate4 << "%" << endl; 

	///////////////////		GAMES PLAYED TEST
	double gamesPlayed6 = 3, gamesPlayed7; 
	fourSuit.setGamesPlayed(gamesPlayed6);
	gamesPlayed7 = fourSuit.getGames();
	cout << "Games Played: " << gamesPlayed7 << endl;

	///////////////////		FASTEST WIN TEST
	int fastestWin6 = 1267, fastestWin7; 
	fourSuit.setFastestWin(fastestWin6); 
	fastestWin7 = fourSuit.getFastestWin();
	cout << "Fastest Win: " << fastestWin7 << "(s)" << endl;  

	///////////////////		FEWEST MOVES TEST
	int fewestMoves6 = 245, fewestMoves7;
	fourSuit.setFewestMoves(fewestMoves6);
	fewestMoves7 = fourSuit.getFewestMoves();
	cout << "Fewest Moves: " << fewestMoves7 << endl; 

	///////////////////		TOP SCORE TEST
	int topScore6 = 32410, topScore7;
	fourSuit.setTopScore(topScore6);
	topScore7 = fourSuit.getTopScore(); 
	cout << "Top Score: " << topScore7 << endl;  

	//////////////////////////////////////////////////////////
	/////////////////OVERVIEW TESTING/////////////////////////
	//////////////////////////////////////////////////////////

	cout << endl << "OVERVIEW" << endl; 
	///////////////////		PLAYERNAME TEST 
	string test, test1; 
	test = "Dalton"; 
	playerO.setPlayerName(test); 
	test1 = playerO.getPlayerName(); 
	cout << "Player Name: " << test1 << endl; 

	///////////////////		GAMES TEST 
	double games; 
	playerO.setGames(oneSuit.getGames(), twoSuit.getGames(), fourSuit.getGames());
	games = playerO.getGames();
	cout << "Games: " << games << endl; 

	///////////////////		GAMES WON TEST 
	double gamesWon = 5, gamesWon1; 
	playerO.setGamesWon(oneSuit.getGamesWon(), twoSuit.getGamesWon(), fourSuit.getGamesWon()); 
	gamesWon1 = playerO.getGamesWon();
	cout << "Games Won: " << gamesWon1 << endl; 

	///////////////////		WIN RATE TEST 
	double winRate; 
	playerO.updateWinRate(oneSuit.getGamesWon(), twoSuit.getGamesWon(), fourSuit.getGamesWon());
	winRate = playerO.getWinRate();
	cout << "Win Rate: " << winRate << "%" << endl; 

	///////////////////		GAMES PLAYED TEST 
	int gamesPlayed; 
	playerO.setGamesPlayed(oneSuit.getGamesPlayed(), twoSuit.getGamesPlayed(), fourSuit.getGamesPlayed());
	gamesPlayed = playerO.getGamesPlayed();
	cout << "Games Played: " << gamesPlayed << endl; 

	///////////////////		FASTEST WIN TEST 
	int fastestWin; 
	playerO.updateFastestWin(oneSuit.getFastestWin(), twoSuit.getFastestWin(), fourSuit.getFastestWin()); 
	fastestWin = playerO.getFastestWin(); 
	cout << "Fastest Win: " << fastestWin << "(s)" << endl;

	///////////////////		FEWEST MOVES TEST
	int fewestMoves; 
	playerO.updateFewestMoves(oneSuit.getFewestMoves(), twoSuit.getFewestMoves(), fourSuit.getFewestMoves()); 
	fewestMoves = playerO.getFewestMoves();
	cout << "Fewest Moves: " << fewestMoves << endl; 

	///////////////////		TOP SCORE TEST
	int topScore; 
	playerO.updateTopScore(oneSuit.getTopScore(), twoSuit.getTopScore(), fourSuit.getTopScore());
	topScore = playerO.getTopScore();
	cout << "Top Score: " << topScore << endl; 

}