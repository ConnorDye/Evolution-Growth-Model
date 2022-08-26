// Connor Dye

#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
unsigned seed = time(0); //generate row and column to populate


//Function Prototypes
class gameBoard //will represent an inheritance relationship as each robot HAS A map
{
	public:
		int battery = 1; //1 represents battery on map
		int wall = 2; //wall as obstacle
		int empty = 3; //nothing in map slot
		int predator = 4; //will kill robot on sight
		int row = 0;
		int column = 0;
		static const int size = 11; //array size
		int mapArray[size][size] = {{2,2,2,2,2,2,2,2,2,2,2},{2,11,12,13,14,15,16,17,18,19,2},{2,11,12,13,14,15,16,17,18,19,2},{2,11,12,13,14,15,16,17,18,19,2},{2,11,12,13,14,15,16,17,18,19,2},{2,11,12,13,14,15,16,17,18,19,2},{2,11,12,13,14,15,16,17,18,19,2},{2,11,12,13,14,15,16,17,18,19,2},{2,11,12,13,14,15,16,17,18,19,2},{2,11,12,13,14,15,16,17,18,19,2},{2,2,2,2,2,2,2,2,2,2,2}};

	

	gameBoard() //constructor will randomly populate 40% of the map with batteries and the rest with walls, empty spaces, and predators
	{
		

		bool batteryPercent = false; //steps through the array and if the battery count is 40% of map it stops populating the map with batteries...
		do
		{
			int min_value = 0;
			int max_value = 10;
			row = rand() % (max_value - min_value + 1) + min_value;	
			column = rand() % (max_value - min_value + 1) + min_value;
				if(mapArray[row][column] != battery and mapArray[row][column] != wall and mapArray[row][column] != empty and mapArray[row][column] != predator)
				{
					mapArray[row][column] = battery;
				}
			

			int batteryCount = 0; //counts batteries to upkeep 40% limit
			for (row = 0; row < size; row++) //steps through array column by column to count batteries
			{
				for(column = 0; column < size; column++)
				{
					if(mapArray[row][column] == battery)
					{
						batteryCount = batteryCount + 1;
						if(batteryCount == 40)
							batteryPercent = true;
					}
				}
			}
			//cout << "Battery count of map is ..." << batteryCount << endl;
		}
		while(batteryPercent == false);	
		

		/*bool predatorPercent = false; //5% predators on the map
		do
		{
			int min_value = 0;
			int max_value = 10;
			row = rand() % (max_value - min_value + 1) + min_value;	
			column = rand() % (max_value - min_value + 1) + min_value;
				if(mapArray[row][column] != battery and mapArray[row][column] != wall and mapArray[row][column] != empty and mapArray[row][column] != predator)
				{
					mapArray[row][column] = predator;
				}
			

			int predatorCount = 0; //counts predators to keep them at 5%
			for (row = 0; row < size; row++) //steps through array column by column to count predators
			{
				for(column = 0; column < size; column++)
				{
					if(mapArray[row][column] == predator)
					{
						predatorCount = predatorCount + 1;
						if(predatorCount == 5) 
						predatorPercent = true;
					}
				}
			}
			//cout << "Predator count on the map is " << predatorCount << endl;
		}while(predatorPercent ==false);*/


		bool wallPercent = false; //20% walls on the map
		do
		{
			int min_value = 0;
			int max_value = 10;
			row = rand() % (max_value - min_value + 1) + min_value;	
			column = rand() % (max_value - min_value + 1) + min_value;
				if(mapArray[row][column] != battery and mapArray[row][column] != wall and mapArray[row][column] != empty and mapArray[row][column] != predator)
				{
					mapArray[row][column] = wall;
				}
			
			int wallCount = 0; //counts walls to keep them at 20%
			for (row = 0; row < size; row++) //steps through array column by column to count walls
			{
				for(column = 0; column < size; column++)
				{
					if(mapArray[row][column] == wall)
					{
						wallCount = wallCount + 1;
						if(wallCount == 50) 
						wallPercent = true;
					}
				}
			}
			//cout << "Obstacle count on the map is " << wallCount << endl;
		}while(wallPercent ==false);

		
		bool emptyPercent = false; //16 emptys on the map
		do
		{
			int min_value = 0;
			int max_value = 10;
			row = rand() % (max_value - min_value + 1) + min_value;	
			column = rand() % (max_value - min_value + 1) + min_value;
				if(mapArray[row][column] != battery and mapArray[row][column] != wall and mapArray[row][column] != empty and mapArray[row][column] != predator)
				{
					mapArray[row][column] = empty;
				}
			
			int emptyCount = 0; //counts walls to keep them at 20%
			for (row = 0; row < size; row++) //steps through array column by column to count emptys
			{
				for(column = 0; column < size; column++)
				{
					if(mapArray[row][column] == empty)
					{
						emptyCount = emptyCount + 1;
						if(emptyCount == 31) 
						emptyPercent = true;
					}
				}
			}
			//cout << "Empty slots on the map is..." << emptyCount << endl;
		}while(emptyPercent ==false);

		/*cout << "Battery count of map is ..." << batteryCount << endl;
		cout << "Empty slots on the map is..." << emptyCount << endl;
		cout << "Predator count on the map is " << predatorCount << endl;
		cout << "Wall count on the map is " << obstacleCount << endl;*/
	}

	void resetBoard() //constructor will randomly populate 40% of the map with batteries and the rest with walls, empty spaces, and predators
	{
		

		for (row = 1; row < 10; row++) 
			{
				for(column = 1; column < 10; column++)
				{
					mapArray[row][column] =0;
				}
			}
		

		bool batteryPercent = false; //steps through the array and if the battery count is 40% of map it stops populating the map with batteries...
		do
		{
			int min_value = 0;
			int max_value = 10;
			row = rand() % (max_value - min_value + 1) + min_value;	
			column = rand() % (max_value - min_value + 1) + min_value;
				if(mapArray[row][column] != battery and mapArray[row][column] != wall and mapArray[row][column] != empty and mapArray[row][column] != predator)
				{
					mapArray[row][column] = battery;
				}
			

			int batteryCount = 0; //counts batteries to upkeep 40% limit
			for (row = 0; row < size; row++) //steps through array column by column to count batteries
			{
				for(column = 0; column < size; column++)
				{
					if(mapArray[row][column] == battery)
					{
						batteryCount = batteryCount + 1;
						if(batteryCount == 40)
							batteryPercent = true;
					}
				}
			}
			//cout << "Battery count of map is ..." << batteryCount << endl;
		}
		while(batteryPercent == false);	
		

		/*bool predatorPercent = false; //5% predators on the map
		do
		{
			int min_value = 0;
			int max_value = 10;
			row = rand() % (max_value - min_value + 1) + min_value;	
			column = rand() % (max_value - min_value + 1) + min_value;
				if(mapArray[row][column] != battery and mapArray[row][column] != wall and mapArray[row][column] != empty and mapArray[row][column] != predator)
				{
					mapArray[row][column] = predator;
				}
			

			int predatorCount = 0; //counts predators to keep them at 5%
			for (row = 0; row < size; row++) //steps through array column by column to count predators
			{
				for(column = 0; column < size; column++)
				{
					if(mapArray[row][column] == predator)
					{
						predatorCount = predatorCount + 1;
						if(predatorCount == 5) 
						predatorPercent = true;
					}
				}
			}
			//cout << "Predator count on the map is " << predatorCount << endl;
		}while(predatorPercent ==false);
*/

		bool wallPercent = false; //20% walls on the map
		do
		{
			int min_value = 0;
			int max_value = 10;
			row = rand() % (max_value - min_value + 1) + min_value;	
			column = rand() % (max_value - min_value + 1) + min_value;
				if(mapArray[row][column] != battery and mapArray[row][column] != wall and mapArray[row][column] != empty and mapArray[row][column] != predator)
				{
					mapArray[row][column] = wall;
				}
			
			int wallCount = 0; //counts walls to keep them at 10% of playable gameboard
			for (row = 0; row < size; row++) //steps through array column by column to count walls
			{
				for(column = 0; column < size; column++)
				{
					if(mapArray[row][column] == wall)
					{
						wallCount = wallCount + 1;
						if(wallCount == 50) 
						wallPercent = true;
					}
				}
			}
			//cout << "Obstacle count on the map is " << wallCount << endl;
		}while(wallPercent ==false);

		
		bool emptyPercent = false; //26 emptys on the map
		do
		{
			int min_value = 0;
			int max_value = 10;
			row = rand() % (max_value - min_value + 1) + min_value;	
			column = rand() % (max_value - min_value + 1) + min_value;
				if(mapArray[row][column] != battery and mapArray[row][column] != wall and mapArray[row][column] != empty and mapArray[row][column] != predator)
				{
					mapArray[row][column] = empty;
				}
			
			int emptyCount = 0; //26 empty slots
			for (row = 0; row < size; row++) //steps through array column by column to count emptys
			{
				for(column = 0; column < size; column++)
				{
					if(mapArray[row][column] == empty)
					{
						emptyCount = emptyCount + 1;
						if(emptyCount == 31) 
						emptyPercent = true;
					}
				}
			}
			//cout << "Empty slots on the map is..." << emptyCount << endl;
		}while(emptyPercent ==false);

		/*cout << "Battery count of map is ..." << batteryCount << endl;
		cout << "Empty slots on the map is..." << emptyCount << endl;
		cout << "Predator count on the map is " << predatorCount << endl;
		cout << "Wall count on the map is " << obstacleCount << endl;*/
	}

	void printMap()
	{
		for (row = 0; row < size; row++) 
		{
			for(column = 0; column < size; column++)
			{
				cout << mapArray[row][column];
				if(column != 10)
					cout << " | ";
			}
			cout << endl << endl;
		}
	}



	gameBoard(const gameBoard& original)
	{
		for (row = 0; row < size; row ++)
		{
			for(column = 0; column < size; column ++)
			{
				mapArray[row][column] = original.mapArray[row][column];
			}
		}
	}

	void componentTest()
	{
		cout << "GAMEBOARD COMPONENT TEST" << endl;
		cout <<"=================================================" << endl;
	 	cout <<"VALIDATION FOR BATTERY PERCENT, WALL PERCENT, PREDATOR PERCENT IS DONE IN A DO-WHILE LOOP. THIS COMPONENT TEST CONFIRMS THAT RANDOMIZATION WORKS PROPERLY..." << endl << endl;
	 	gameBoard test1;
	 	test1.printMap();
	 	cout << endl << endl;
	 	test1.resetBoard(); //test reset board which will run after each robots generation
	 	test1.printMap();
	 	cout << endl << endl;
	}

};










class geneSet
{
	public:
		int row =0; //ignore just for ease of loops
		int column=0;

		int senseBattery = 1; //all gene information
		int senseWall = 2; 
		int senseEmpty = 3; 
		int sensePredator = 4; 

		int moveNorth = 1;
		int moveEast = 2;
		int moveSouth = 3;
		int moveWest= 4;
		int genesArray[16][5]={{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},
							{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},
							{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14},{10,11,12,13,14}};


	geneSet() //Randomize genes
	{				
		int min_value = 1;
		int max_value = 4;
		int randomGene= rand() % (max_value - min_value + 1) + min_value;
		for (row = 0; row < 16; row++) //Steps through geneset to populate genes
		{
			for(column = 0; column < 5; column++)
			{
				randomGene= rand() % (max_value - min_value + 1) + min_value;
				genesArray[row][column] = randomGene;
			}
		}

	}


	void printGenes()
	{
	cout << "GENES" << endl;
	cout << "==================================" << endl;
	cout << "1: Sense Battery" << endl;
	cout << "2. Sense Wall" << endl;
	cout << "3: Sense Empty" << endl;
	cout << "4. Don't Care" << endl << endl;
	cout << "Movements" << endl;
	cout << "==================================" << endl;
	cout << "1. Move North" << endl;
	cout << "2. Move East" << endl;
	cout << "3. Move South" << endl;
	cout << "4. Move West" << endl << endl;

	cout << "Genes will read in the following order: | North Direction Sense, East Direction Sense, South Direction Sense, West Direction Sense | Movement Direction |" << endl << endl;
		for (row = 0; row < 16; row++) 
		{
		cout << "GENE " << (row + 1) << endl;
		cout << "=====================" << endl;
			for(column = 0; column < 5; column++)
			{
				if(column ==0 or column ==4)
					cout <<" | ";
				cout << genesArray[row][column];
				if(column != 3 and column != 4)
					cout <<", ";
				if(column == 4)
					cout << " |";
			}
			cout << endl << endl;
		}
	}

	void componentTest()
	{
		cout << "GENES COMPONENT TEST" << endl;
		cout << "============================================" << endl;
		cout << "THIS COMPONENT TEST ASSURES THAT GENE SENSORS WILL INDEED COMPARE WITH THE MAP. SEE ABOVE FOR VISUAL COMPARISON." << endl << endl;
		geneSet test2;
		test2.printGenes();
		
		bool fail = false;
		for (row = 0; row < 16; row++) 
		{
			for(column = 0; column < 5; column++)
			{
				if (test2.genesArray[row][column] != 1 and test2.genesArray[row][column] != 2 and test2.genesArray[row][column] != 3 and test2.genesArray[row][column] !=4)
				{
					fail = true;
				}
			}
		}

		if (fail == true)
		{
			cout << "Genes componentTest...FAILED!" << endl << endl << endl;
		}
		else 
		{
			cout << "Genes componentTest...PASSED!" << endl << endl << endl;
		}
	}


};









class Robot
{
	public:
		geneSet genes;     //hence the composition of the more specific robot pieces
		gameBoard board; //New Board for every 

		//fundamental robot functions
		bool dead = false; //activates if robot comes into contact with a predator
		int fitnessLevel = 0; //fitness level will track the number if batteries collected in order to track the process of evolution;
		int batteryPower = 5; //will track when the robot runs out of energy and the turn is over
		int rowStart; 	//tracks where the robot will start on the map
		int columnStart;
		
		bool operator < (const Robot& RHS) const
		{
			return (fitnessLevel < RHS.fitnessLevel);
		}

		bool operator ==(const Robot& RHS) const
		{
			int matchCount = 0;
			bool match = false;
			for (int row = 0; row < 16; row++) 
			{
				for(int column = 0; column < 5; column++)
				{
					if (genes.genesArray[row][column] == RHS.genes.genesArray[row][column])
					{
						matchCount = matchCount + 1;
					}
				}
			}
			
			if(matchCount == 80)
			{
				match = true;
			}

			return match;
		}


		Robot()
		{
			do{  //initialize start positon; in while loop to validate and assure it won't be out of bounds
			int min_value = 1;
			int max_value = 9;
			rowStart = rand() % (max_value - min_value + 1) + min_value;	
			columnStart = rand() % (max_value - min_value + 1) + min_value;
			} while(rowStart > 9 and columnStart > 9);

			/*cout << rowStart;
			cout << columnStart;*/

		}

		void Move()
		{
			//Robot Genes sense in the following order: | North Direction Sense, East Direction Sense, South Direction Sense, West Direction Sense | Movement Direction |"
			//Logic of this function is to step through all the genes and compare it with the gameboard. The gene with the exact match will activate, if not exact match, a random gene will activate. Then it will move in that direction of the gene

			//GENE comparison info:
			//1.) row + 1 looks south
			//2.) row - 1 looks north
			//3.) column + 1 looks east
			//4.) column - 1 looks west
			//genesArray[gene][sensor];

			//Compare in the following order North, East, South, West
			//**if the gene value is 4, the gene will disregard what it senses
			//cout << "Start Position row: " << rowStart + 1 << endl;
			//cout << "Start Position column: " << columnStart + 1 << endl;
			

			//1.) FIND THE GENE MATCH. IF NO MATCH IT WILL USE THE 6th GENE INFORMATION.
			bool match = false; 
			for(int row = 0; row < 16; row++)
			{
				if (( (board.mapArray[(rowStart - 1)][columnStart] == genes.genesArray[row][0] or genes.genesArray[row][0] == 4) and match ==false)
					and ((board.mapArray[rowStart][(columnStart+1)] == genes.genesArray[row][1] or genes.genesArray[row][1] == 4) and match ==false)
					and ((board.mapArray[(rowStart + 1)][columnStart] == genes.genesArray[row][2] or genes.genesArray[row][2] == 4) and match ==false)
					and ((board.mapArray[rowStart][(columnStart-1)] == genes.genesArray[row][3] or genes.genesArray[row][3] == 4) and match ==false))
				{
						/*cout << "Match found for gene: " << (row + 1)  << endl;
						cout << "Start position is (" << rowStart + 1 <<"," << columnStart + 1 << ")" << endl;
						cout << "North check board " << board.mapArray[(rowStart - 1)][columnStart] << " matches genes sensor " << genes.genesArray[row][0] << endl;
						cout << "East check board " << board.mapArray[rowStart][(columnStart+1)] << " matches genes sensor " << genes.genesArray[row][1] << endl;
						cout << "South check board " << board.mapArray[(rowStart + 1)][columnStart] << " matches genes sensor " << genes.genesArray[row][2] << endl;
						cout << "West check board " << board.mapArray[rowStart][(columnStart-1)] << " matches genes sensor " << genes.genesArray[row][3] << endl;*/
						
						match = true;
						//2.)MOVE IN THE DIRECTION OF THE GENE SENSOR
						if(genes.genesArray[row][4]== genes.moveNorth and board.mapArray[(rowStart-1)][columnStart] != board.wall) //move north if there's no wall
						{
							//cout << "Moving north..." << endl;
							rowStart = rowStart - 1;
							batteryPower = batteryPower -1;   //LOSES 1 POWER FOR EVERY MOVE
							fitnessLevel = fitnessLevel + 1;
							//cout << "Battery batteryPower is " << batteryPower << endl;
						}
						else if(genes.genesArray[row][4]== genes.moveEast and board.mapArray[rowStart][(columnStart + 1)] != board.wall) //move east if theres no wall
						{
							//cout <<"Moving east..."<<endl;
							columnStart = columnStart + 1;
							batteryPower = batteryPower -1;   //LOSES 1 POWER FOR EVERY MOVE
							fitnessLevel = fitnessLevel + 1;
							//cout << "Battery batteryPower is " << batteryPower << endl;
						}
						else if(genes.genesArray[row][4]== genes.moveSouth and board.mapArray[rowStart+1][columnStart] != board.wall) //move South if theres no wall
						{
							//cout <<"Moving South ..." << endl;
							rowStart = rowStart + 1;
							batteryPower = batteryPower -1;   //LOSES 1 POWER FOR EVERY MOVE
							fitnessLevel = fitnessLevel + 1;
							//cout << "Battery batteryPower is " << batteryPower << endl;
						}
						else if(genes.genesArray[row][4]== genes.moveWest and board.mapArray[rowStart][columnStart-1] != board.wall) // move west if there's no wall
						{
							//cout <<"Moving West..." << endl;
							columnStart = columnStart - 1;
							batteryPower = batteryPower -1;   //LOSES 1 POWER FOR EVERY MOVE
							fitnessLevel = fitnessLevel + 1;
							//cout << "Battery batteryPower is " << batteryPower << endl;
						}
						else 
						{
							batteryPower = batteryPower -1;
							fitnessLevel = fitnessLevel + 1;
						}	
				}
			}





			if(match ==false) //resort to default genes if there is no match
			{	
				int row = 15;
				//cout << "Default gene..." << endl;
				if(genes.genesArray[row][4]== genes.moveNorth and board.mapArray[(rowStart-1)][columnStart] != board.wall) //move north if there's no wall
					{
						//cout << "Moving north..." << endl;
						rowStart = rowStart - 1;
						batteryPower = batteryPower -1;   //LOSES 1 POWER FOR EVERY MOVE
						fitnessLevel = fitnessLevel + 1;
					}
					else if(genes.genesArray[row][4]== genes.moveEast and board.mapArray[rowStart][(columnStart + 1)] != board.wall) //move east if theres no wall
					{
						//cout <<"Moving east..."<<endl;
						columnStart = columnStart + 1;
						batteryPower = batteryPower -1;   //LOSES 1 POWER FOR EVERY MOVE
						fitnessLevel = fitnessLevel + 1;
					}
					else if(genes.genesArray[row][4]== genes.moveSouth and board.mapArray[rowStart+1][columnStart] != board.wall) //move South if theres no wall
					{
						//cout <<"Moving South ..." << endl;
						rowStart = rowStart + 1;
						batteryPower = batteryPower -1;   //LOSES 1 POWER FOR EVERY MOVE	
						fitnessLevel = fitnessLevel + 1;
					}
					else if(genes.genesArray[row][4]== genes.moveWest and board.mapArray[rowStart][columnStart-1] != board.wall) // move west if there's no wall
					{
						//cout <<"Moving West..." << endl;
						columnStart = columnStart - 1;
						batteryPower = batteryPower -1;   //LOSES 1 POWER FOR EVERY MOVE
						fitnessLevel = fitnessLevel + 1;
					}
					else
					{
						//cout << "Never entered nested loop..." << endl;
						batteryPower = batteryPower -1;
						fitnessLevel = fitnessLevel + 1;
					}
			}


			
			//2.) CHECK WHAT THE ROBOT CAN OBTAIN FROM ITS NEW SPOT
			if(board.mapArray[rowStart][columnStart] == board.battery)
			{	
				//cout << "Obtained battery from Row: " << rowStart + 1 << " " << "Column: " << columnStart + 1 << endl << endl;
				batteryPower = batteryPower + 5;
				//fitnessLevel = fitnessLevel + 1; //For every batter it obtains it's fitness level increases by 1
				board.mapArray[rowStart][columnStart] = board.empty; //set the board to empty after it checks the square
			}
			else if(board.mapArray[rowStart][columnStart] == board.predator)
			{
				//cout << "Killed by predator in Row: " << rowStart + 1 << " " << "Column: " << columnStart + 1 << endl << endl;
				dead = true;
				//batteryPower = 0;
				board.mapArray[rowStart][columnStart] = board.empty; //set the board to empty after it checks the square
			}
			else
			{
				//cout << "Nothing obtained in Row: " << rowStart + 1 << " " << "Column: " << columnStart + 1 << endl << endl;
				board.mapArray[rowStart][columnStart] = board.empty; //set the board to empty after it checks the square
				//no more conditions needed. If the sqaure is empty
			}			
		}//end of Move()

		
		void resetStats()
		{
			//cout << "Stats reset..." << endl;
			dead = false;
			int min_value = 1;
			int max_value = 9;
			rowStart = rand() % (max_value - min_value + 1) + min_value;	
			columnStart = rand() % (max_value - min_value + 1) + min_value;
			fitnessLevel = 0; //fitness level will track the number if batteries collected in order to track the process of evolution;
			batteryPower = 5;

			board.resetBoard();
		}


		void componentTest()
		{
			cout << "ROBOT COMPONENT TEST" << endl;
			cout <<"================================================" << endl;
			cout << "THIS TEST ASSURES THAT RANDOMLY GENERATED GENES ARE INDEED RANDOM FOR EACH INDIVIDUAL ROBOT..." << endl << endl;
			Robot robot1;
			Robot robot2;
			robot1.fitnessLevel = 0;
			robot2.fitnessLevel = 2;
			
			bool fail = false;
			if(robot1.fitnessLevel < robot2.fitnessLevel) //check the sort compare for vector sort
				fail = false;
			else
				fail = true;

			if(robot1 == robot1) //CHECK OVERLOADED == BOOL OPERATOR
			{
				fail = false;
			}
			else
			{
				fail = true;
			}

			if(robot1 == robot2) //compares the genes to assure the 
			{
				fail = true;
			}
			else
				fail = false;

			if(fail == false)
				cout << "ROBOT COMPONENT TEST...PASSED" << endl;
			else
				cout << "ROBOT COMPONENT TEST...FAILED" << endl;

	

			robot1.genes.printGenes();
			robot1.board.printMap();
			while(robot1.batteryPower > 0)
			{
				robot1.Move();
			}

			cout <<"Robot fitness level is " << robot1.fitnessLevel << endl << endl;
			robot1.board.printMap();


		}

		

};







class Population: public Robot
{
	public:
	vector<Robot> array = vector<Robot>(200);
	//Robot array[10];
	//int totalFitness;
	double averageFitness;
	double trackEvolution[30000]; //tracks evolution using the fitness levels

	double getAverage(double totalFitness)
	{
		averageFitness = totalFitness/array.size();
		//cout << "Average fitness:" << averageFitness;
		return averageFitness;
	}


	void Sort() //Sorts Vector from least fitness score to greatest...
	{
	sort(array.begin(), array.end());
	}

	
	void printVectorFitness()
	{
		for(unsigned i = 0; i < array.size(); i++) 
		{
		cout << " The fitness level is ..." << array[i].fitnessLevel << endl;
		}
	}

	
	void Breed(int child)
	{
		int min_value = 99; //GENERATE RANDOM PARENTS
		int max_value = 199; 
		//cout << "Child is " << child << endl;
		int parent = rand() % (max_value - min_value + 1) + min_value;
		for(int row = 0; row < 16; row++)
		{
			for (int column = 0; column < 5; column++)
			{
				parent = rand() % (max_value - min_value + 1) + min_value;
				//cout << "Parent is..." << parent << endl;
				array[child].genes.genesArray[row][column]=array[parent].genes.genesArray[row][column];
			}
		}


		//5% chance of mutation
		min_value = 1;
		max_value = 20;
		int mutation = rand() % (max_value - min_value + 1) + min_value;
		if(mutation ==5) 
		{
		//cout << "Mutation is true for robot..." << child + 1 << endl;
		min_value = 1;
		max_value = 4;
		int randomGene= rand() % (max_value - min_value + 1) + min_value;
			for(int column = 0; column < 5; column++)
			{
			randomGene= rand() % (max_value - min_value + 1) + min_value;
			array[child].genes.genesArray[15][column] = randomGene;
			}
		}

	}

	



	

	void componentTest() //checm sort method
	{
		cout << "POPULATION COMPONENT TEST..." << endl;
		cout << "==============================================================" << endl;
		int min_value = 1;
		int max_value = 9;
		Population test1;
		for(unsigned i = 0; i < array.size(); i++) //TEST SORT FUNCTION
		{
			test1.array[i].fitnessLevel = rand() % (max_value - min_value + 1) + min_value;
		}
		test1.Sort();
		//test1.printVectorFitness();

		bool fail = false;   //MAKE SURE SORT IS WORKING CORRECTLY
		for(unsigned i=0; i < (array.size() - 1); i++)
		{
			if(test1.array[i].fitnessLevel < test1.array[(i+1)].fitnessLevel or test1.array[i].fitnessLevel == test1.array[(i+1)].fitnessLevel )
				fail = false;
			else
				fail = true;
		}



		Population test2(test1); //TEST THE BREED FUNCTION
		int child = 0;
		for(int i = 0; i < 99; i++)
		{
			child =i;
			test1.Breed(child);
		}

		//int count = 20;
		for(unsigned i=0; i < (array.size()/2-1); i++)
		{
			if(test1.array[i] == test2.array[i])

				fail = true;
			else
				fail = false;
		}

		if (fail ==true)
			cout << "POPULATION COMPONENT TEST...FAILED!!!" << endl << endl;
		else
			cout << "POPULATION COMPONENT TEST...PASSED!!" << endl << endl;


	}	

};









//FUNCTION PROTOTYPES
void unitTest();
void programGreeting();



int main()
{
	srand(seed); // IGNORE SEED RANDOMIZES GENES AND MAP
	unitTest();
	programGreeting();

	Population population; //Population of 200 robots
	

	for(int generations = 0; generations < 200; generations++) //Loops for 2000 generations
	{
		
		//1.) Step Through and determine the average fitness level
		double totalFitness = 0;
		for(unsigned i = 0; i < population.array.size(); i++) //**********************************CHANGE TO 200 ROBOTS   //population.array.size()
		{
			while(population.array[i].batteryPower > 0)
			{
				population.array[i].Move();
			}
			totalFitness = totalFitness + population.array[i].fitnessLevel;
			//cout << "fitnessLevel for Robot " << (i+1) <<" is"  << population.array[i].fitnessLevel << endl;
		}


	//1.) GET AVERAGE FITNESS LEVEL OF GENERATION
		population.trackEvolution[generations] = population.getAverage(totalFitness); //Set Average Fitness for generation
		//cout << "Total fitness level is " << totalFitness << endl;
		cout << "Average fitness level is " << population.trackEvolution[generations] << endl;

	//2.)Sort Robots by fitness level...
		population.Sort();


	//3. Breed
		int child = 0;
		for(int i = 0; i < 99; i++)
		{
			child =i;
			population.Breed(child);
		}
		
	//4.) RESET ROBOT STATS
		for(unsigned i = 0; i < population.array.size(); i++)
		{
			population.array[i].resetStats();
		}
			
	}

	cout << endl;
	cout << "SEE COMPONENT TESTING AND PROGRAM INFORMATION AT THE TOP OF THE 200 GENERATIONS!" << endl << endl;
	cout << "Done!";

}






void unitTest()
{

	gameBoard test22; //test map randomization 
	test22.componentTest();

	geneSet test23;
	test23.componentTest();

	Robot test24;
	test24.componentTest();

	Population test25;
	test25.componentTest();


}

void programGreeting()
{
	cout << "PROGRAM GREETING" << endl;
	cout << "====================================" << endl;
	cout << "FINAL PROJECT" << endl << endl; 
	cout << "This program will follow the evolution of a species of robots. My code leveled out at approximately 200 generations so I stopped the program there." << endl;
	cout << "This program includes predators and obstacles: 10 obstacles, 40 batteries, 5 predators, and the rest is empty on the map." << endl;
	cout << "Notes: These robots are an interesting species. They like to maximize their evolution process by creating a child with more than 2 parents (yes this is possible for robots)." << endl;
	cout << "I tested multiple different breed scenarios, and the robots like to run from robot to robot to finish one breeding cycle. They want as many partners as they can get..." << endl;
	cout << "My findings were my robots tend to maximize at approximately 15-20 batteries due to the obstacles in the map. I stopped the generation process here for efficiency reasons." << endl;
	cout << "My robots on average tend to become about 6x-7x better than they were initially." << endl;
	cout << "My mutations are a random 16th gene. This may benefit or not benifit the robot as the mutation is based on luck!" << endl;
	cout << "Thanks for a great semester Mr. Fowler! I learned so much and I'll miss taking CISP with you!" << endl;
	cout << "Author of Program: Connor Dye" << endl << endl;
}
