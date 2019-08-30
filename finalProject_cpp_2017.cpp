/*******************************************************************
	*   CS 121 Programming Assignment 1
	*   File: Phase 1, Program 4
	*   Author: David Clark
	*   Desc: Prints instructions to screen
	*   Date: 06/12/17
	*
	*   I attest that this program is entirely my own work
	*******************************************************************/
			

	#include <iostream>
	#include <string>
	#include <stdio.h>

	//Define Doors(Nibble 0)
	#define DOOR_NORTH			0x00000001 //dec. value 1
	#define DOOR_EAST			0x00000002 //dec. value 2
	#define DOOR_SOUTH			0x00000004 //dec. value 4
	#define DOOR_WEST			0x00000008 //dec. value 8

	//Define Treasure Items(Nibble 1)
	#define  MACBOOK_PRO		0x00000010 //dec. value 16
	#define  FLASH_DRIVE		0x00000020 //dec. value 32
	#define  ETHERNET_CABLE		0x00000040 //dec. value 64
	#define  ENCRYPTION_CODE	0x00000080 //dec. value 128

	//Define Creatures(Nibble 2 and 3)
	#define  LULZSEC			0x00000100 //dec. value 256
	#define  AdrianLamo			0x00000200 //dec. value 512
	#define  MathewBevan		0x00000400 //dec. value 1024
	#define  RichardPryce		0x00000800 //dec. value 2048 
	#define  EdwardSnowden		0x00001000 //dec. value 4096
	#define  GaryMckinnon		0x00002000 //dec. value 8192
	#define  KevinMitnick		0x00004000 //dec. value 16284
	#define  Astra				0x00008000 //dec. value 32768

	//Define other items(Nibble 4)
	#define  VPN				0x00010000 //dec. value 65536
	#define  VIRUS_CD			0x00020000 //dec. value 131072
	#define  MALWARE            0x00040000 //dec. value 262144
	#define  INF_MACBOOK        0x00080000 //dec. value 524288

	//Define Dangerous creatures
	#define  DEADLY             0x00100000 //dec. value 1048576
	#define  DANGEROUS 			0x00200000 //dec. value 2097152
	#define  CAUTION            0x00400000 //dec. value 4194304
	#define  FRIENDLY 			0x00800000 //dec. value 8388608




	using namespace std;

/****** List of Functions ******/


	
	void Main_Entry();
	void N302();
	void N304();
	void N308();
	void N324();
	void N333();
	void N341();
	void N346();
	void N348();
	void N349();
	void N403();
	void N404();
	void N413();
	void N420();
	void N433();
	void N507();
	void DescribeRoomContents(int roomDesc, int row, int col);
	void BuildRooms(unsigned int rooms[][4]); //prototype to build room
	int Takeitem(unsigned int rooms[][4], int row, int col, string Object);
	





	//  Prints Game Description
	int main()
	{

		string cmdVerb;
		string cmdObj;
		int iRow; // Index of current game grid row
		int iCol; // index of current game grid column
		int iNumRows; // number of rows in the game grid 
		int iNumCols; // number of columns in the game grid
		int iPlayer = 0;//Bit to flag when player is carrying
		int endRow = 3;//Row of destination when all items have been found
		int endCol = 0;//Column of destination when all items have been found
		//int roomTest = 0xFFFFFFFF;
		unsigned int gameArray[4][4]; // 2D array of ints to define the room contents

		


	// initialize the location variables 
		iRow = 0; // numbered rows starting with 0
		iCol = 0; // numbered columns starting with 0
		iNumRows = 4; // number of rows in game grid
		iNumCols = 4; // number of columns in game grid


 			// Make sure the array is initialized to zero
		for(int row = 0; row < 4; row++)
		
			for(int col = 0; col < 4; col++)
				
					gameArray[row][col] = 0;

					BuildRooms(gameArray); //Build the room

		// print instructions to the screen 	
		
		cout << "\tWelcome to King Technology Hall!\n " << endl;
		cout << "\t\tWelcome Adventurer\n\t\t\t\t" << endl;
		cout << " \t\t\tTo the\n" << endl;
 		cout << "\t\tKing Technology Hall\n\t" << endl;


 		cout << "We need your help! A group of anonymous hackers have stolen the data of all the students at" << endl;
 		cout << "UAH. You must traverse King Technology Hall and find four hidden treasures that will allow you" << endl;
 		cout << "to retrieve the data and turn the hackers in. The four treasures are a 2017 Macbook Pro, A flash" << endl;
 		cout << "drive with Kali Linux on it, A cat6 ethernet cable, And the code to implement AES256 encryption" << endl;
 		cout << "once you retrieve the data. Once you find all of these items you must return them back into the" << endl;
 		cout << "Cyber Security Room and retrieve the data!" << endl;
 		cout << "To move from room to room use commands such as GO NORTH to go through a door on the" << endl;
 		cout << "north wall. When you find one of the treasures you must use a command such as TAKE. Be" << endl;
 		cout << "warned! The group of anonymous hackers are in the system and are minutes from taking out " << endl;
 		cout << "the entire infrastructure of UAH. You must Hurry!" << endl;  
 		
		
 		// Wait for player to read instructions then
 		// press Enter key to begin playing

 		cout << "Press the Enter key to begin\n";

 		getc(stdin); // Get a single key press

 		// Describe first room

 		Main_Entry();
 	

		//---------------------------
		//  start game loop
		//---------------------------
		bool bQuitGame = false; // init end of game flag
		while(!bQuitGame) //while not bQuitGame
		{

 			// Get the players command
 			cout << "What do you want to do?\n ";
 			cin >> cmdVerb >> cmdObj;


			//Make sure players commands are all caps

			int idx = 0; //set int idex  to 0
			while (idx < cmdVerb.length())
			{
			cmdVerb[idx] = toupper(cmdVerb[idx]);
			idx++;//increment to next index
			}

			int idx1 = 0;
			while(idx1 < cmdObj.length())
			{
				cmdObj[idx1] = toupper(cmdObj[idx1]);
				idx1++;
			}


 			//           Parse the Players command
			//
 			// Valid Commands 				Valid Objects
 			// 		GO  					NORTH, SOUTH, EAST, WEST
 			// 		TAKE					TBD
 			//		QUIT					GAME

 			// Check for GO command
 			if(cmdVerb == "GO")
 			{
 				cout << "Command verb is GO" << endl;
 				// check direction to go in

 				if(cmdObj == "NORTH")
 				{
 					// Can we move that way?
 					//if(iRow > 0)
 					if(gameArray[iRow][iCol] & DOOR_NORTH)
 				{
 						iRow--; // move up a row
 						DescribeRoomContents(gameArray[iRow][iCol], iRow, iCol);
 				}
 				else
 					cout << "There is no door to the NORTH." << endl;
 			}

 			else if(cmdObj == "SOUTH")
 			{
 				// Can we move that way?
 				//if(iRow < (iNumRows-1))
 				if(gameArray[iRow][iCol] & DOOR_SOUTH)
 				{
 					iRow++; //Move down a row
 					DescribeRoomContents(gameArray[iRow][iCol], iRow, iCol);
 				}
 				else
 					cout << "There is no door to the SOUTH." << endl;
 			}

 			else if(cmdObj == "EAST")
 			{
 				// Can we move that way?
 				//if(iCol < (iNumCols-1))
 				if(gameArray[iRow][iCol] & DOOR_EAST)
 				{
 					iCol++; // Move right a column
 					DescribeRoomContents(gameArray[iRow][iCol], iRow, iCol);
 				}
 				else
 					cout << "There is no door to the EAST." << endl;
 			}

 			else if(cmdObj == "WEST")
 			{
 				//Can we move that way?
	 			//if(iCol > 0)
	 			if(gameArray[iRow][iCol] & DOOR_WEST)
	 			{
 					iCol--; // Move left a column
 					DescribeRoomContents(gameArray[iRow][iCol], iRow, iCol);
 				}
 				else
 					cout << "There is no door to the WEST." << endl;
 			}

 			else
 				{
 				cout << "I dont understand GO " << cmdObj << endl;
 				}

 			} // End IF GO command

 			//Check to see if player is in the final destination room
 			if((iRow == endRow) && (iCol == endCol)) // are we there yet?
 			{

 				// check to see if player has all the itmes
 				if((iPlayer & MACBOOK_PRO)&&
 					(iPlayer & FLASH_DRIVE) && 
 					(iPlayer & ETHERNET_CABLE) &&
 					(iPlayer & ENCRYPTION_CODE))
 				{
 					//yes, so tell the player
 					cout << "\n\nCongratulations Player, you have successfully obtained the four" << endl;
 					cout << "treasure items; the Macbook Pro, The Flash Drive, the Ethernet Cable, The encryption code" << endl << endl;
 					cout << "The game is over now. Thank you for player. " << endl << endl;
 					bQuitGame = true; // set boolean flag to end the game
 				}
 			}

 			// Check for TAKE command
 			else if(cmdVerb == "TAKE")
 				{
 					int takeVal = Takeitem(gameArray, iRow, iCol, cmdObj);
 					//if Takeval is not zero the player successfully took the item
 					// and it was removed from the room
 					if(takeVal)
 					{
 						iPlayer |= takeVal; // Add this item to the player
 						cout << "You are now carrying the " << cmdObj << endl;
 					}
 					else
 						cout << "You cannot take the " << cmdObj << "from this location. " << endl;
 				//cout << "Command verb is TAKE" << endl;
 				//cout << "I havent learned how to take" << cmdObj << endl;
 				} // End if TAKE command

 			else if(cmdVerb == "QUIT")
 				{
 			//cout << "Command verb is QUIT" << endl;
 			bool bQuitGame = true;
 			// no need to check cmdobj
 			return 0; // end the game
 			} // End if Quit command

 			//Tell player that the command is not understood
 			else
 			{
 			cout << "I don't understand! " << cmdVerb << endl;
 			} // end if dont understand command

 			//Test lines only

 			cout << "Command is: " << cmdVerb << " " << cmdObj << endl;
 			cout << "Location is: Row " << iRow << ", COl " << iCol << endl; 

	}	
		
	





 		// Call each function


 		
 		Main_Entry();
 		cout << endl;

 		N302();
 		cout << endl;

 		N304();
 		cout << endl;

 		N308();
 		cout << endl;

 		N324();
 		cout << endl;

 		N333();
 		cout << endl;

 		N341();
 		cout << endl;

 		N346();
 		cout << endl;

 		N348();
 		cout << endl;

 		N349();
 		cout << endl;

 		N403();
 		cout << endl;

 		N404();
 		cout << endl;

 		N413();
 		cout << endl;

 		N420();
 		cout << endl;

 		N433();
 		cout << endl;

 		N507();
 		cout << endl;

 		int Takeitem(unsigned int rooms[][4], int row, int col, string Object);
 			/*{
 				//is player trying to take MACBOOK PRO
 				if((Object == "PRO") && (rooms[row][col] & MACBOOK_PRO))
 				{
 					rooms[row][col]^= MACBOOK_PRO;
 					return MACBOOK_PRO;// return appropiate flag for this item
 				}
 				//is player trying to take FLASH DRIVE
 				if((Object == "DRIVE") && (rooms[row][col] & FLASH_DRIVE))
 				{
 					rooms[row][col]^= FLASH_DRIVE;
 					return FLASH_DRIVE;//return appropiate flag for this item
 				}
 				if((Object == "CABLE") && (rooms[row][col] & ETHERNET_CABLE))
 				{
 					rooms[row][col]^= ETHERNET_CABLE;
 					return ETHERNET_CABLE;
 				}
 				if((Object == "CODE") && (rooms[row][col] & ENCRYPTION_CODE))
 				{
 					rooms[row][col]^= ENCRYPTION_CODE;
 					return ENCRYPTION_CODE;
 				}

 			 return 0
 				//Didnt find object to take so return zero
 			}	*/


return 0;
// end of main 
}


/* List of Functions */
int Takeitem(unsigned int rooms[][4], int row, int col, string Object)
 			{
 				//is player trying to take MACBOOK PRO
 				if((Object == "PRO") && (rooms[row][col] & MACBOOK_PRO))
 				{
 					rooms[row][col]^= MACBOOK_PRO;
 					return MACBOOK_PRO;// return appropiate flag for this item
 				}
 				//is player trying to take FLASH DRIVE
 				if((Object == "DRIVE") && (rooms[row][col] & FLASH_DRIVE))
 				{
 					rooms[row][col]^= FLASH_DRIVE;
 					return FLASH_DRIVE;//return appropiate flag for this item
 				}
 				if((Object == "CABLE") && (rooms[row][col] & ETHERNET_CABLE))
 				{
 					rooms[row][col]^= ETHERNET_CABLE;
 					return ETHERNET_CABLE;
 				}
 				if((Object == "CODE") && (rooms[row][col] & ENCRYPTION_CODE))
 				{
 					rooms[row][col]^= ENCRYPTION_CODE;
 					return ENCRYPTION_CODE;
 				}

 			 return 0;
 				//Didnt find object to take so return zero
 			}	


void BuildRooms(unsigned int rooms[][4])
		{
	
		//*******BUILD ROOMS IN FIRST ROW******
		//ROW0
		//Build room 1 - Entry Room
		rooms[0][0] = DOOR_EAST | DOOR_SOUTH;
		//Build Room 2(N302)
		rooms[0][1] = DOOR_EAST | DOOR_WEST | VIRUS_CD | DOOR_SOUTH;
		//Build Room 3(N304)
		rooms[0][2] = DOOR_SOUTH | DOOR_EAST | INF_MACBOOK | DOOR_WEST;
		//Build Room 4(N308)
		rooms[0][3] = DOOR_SOUTH | ENCRYPTION_CODE | DOOR_WEST;


		//ROW1
		//Build Room 1(N324)
		rooms[1][0] = DOOR_EAST | DOOR_NORTH | MACBOOK_PRO | ETHERNET_CABLE | DOOR_SOUTH;
		//Build Room 2(N333)
		rooms[1][1] = DOOR_WEST | DOOR_EAST | DOOR_SOUTH | DOOR_NORTH;
		//Build Room 3(N341)
		rooms[1][2] = DOOR_EAST | DOOR_WEST | VPN | DOOR_SOUTH | DOOR_NORTH;
		//Build Room 4(N346)
		rooms[1][3] = DOOR_WEST | FLASH_DRIVE | DOOR_SOUTH | DOOR_NORTH;

		//ROW2
		//Build Room 1(N348)
		rooms[2][0] = DOOR_EAST | DOOR_SOUTH | DOOR_NORTH;
		//Build Room 2(N349)
		rooms[2][1] = DOOR_WEST | DOOR_EAST | DOOR_SOUTH | DOOR_NORTH;
		//Build Room 3(N403)
		rooms[2][2] = DOOR_WEST | MALWARE | DOOR_EAST | DOOR_SOUTH | DOOR_NORTH;
		//Build Room 4(N404)
		rooms[2][3] = DOOR_WEST | DOOR_SOUTH | DOOR_NORTH;

		//ROW3
		//Build Room 1(N413)
		rooms[3][0] = DOOR_EAST | DOOR_NORTH;
		//Build Room 2(N420)
		rooms[3][1] = DOOR_EAST | DOOR_WEST | DOOR_NORTH;
		//Build Room 3(N433)
		rooms[3][2] = DOOR_WEST | DOOR_EAST | DOOR_NORTH;
		//Build Room 4(N507)
		rooms[3][3] = DOOR_NORTH | DOOR_WEST;

		}



//return 0;
// end of main 
//}


// Row 0 Column 0 -- Main Hall

void Main_Entry()
{
	cout << "You are entering into the Main Hall" << endl;
	cout << "on the third floor of King Technology Hall." << endl;
	
}
// Row 0 Column 1 -- N302
void N302()
{
	cout << "You have now entered room N302, the room is dark and has no power." << endl;
	
}

// Row 0 Column 2 -- N304
void N304()
{
	cout << "You have now entered room N304, This room is full of" << endl;
	cout << "computers, but none seem to be connected to the network." << endl;
	
}

// Row 0 Column 3 --N308
void N308()
{
	cout << "You have now entered room N308, this is just" << endl;
	cout << "an empty room with no power." << endl;
	
}

// Row 1 Column 0 -- N324
void N324()
{
	cout << "You have now entered room N324, the cyber room, there is" << endl;
	cout << "a picture on the wall of Led Zeplin, to your right. Servers to your left." << endl;
	
}

// Row 1 Column 1 -- N333
void N333()
{
	cout << "You have now entered room N333, the computer lab," << endl;
	cout << "all the computers are being controlled by wannaCry ransomware." << endl;
	

}

// Row 1 Column 2 --N341
void N341()
{
	cout << "You have now entered room N341, this is Dr. Coleman's office," << endl;
	cout << "his whereabouts are unknown." << endl;
	
}

// Row 1 Column 3 -- N346
void N346()
{
	cout << "You have now entered room N346, this is the server room, " << endl;
	cout << "where you can hardwire into the network." << endl;
	

}

// Row 2 Column 0 -- N348
void N348()
{
	cout << "You have now entered room N348, this is the Dean's office." << endl;
	cout << "If you look to your right there is a shrine of Steven Colbert." << endl;
	
}

// Row 2 Column 1 -- N349
void N349()
{
	cout << "You have now entered room N349, this room is the system admin room." << endl;
	cout << "There is also another server in there." << endl;
	
}

// Row 2 Column 2 -- N403
void N403()
{
	cout << "You have now entered room N403, there is a video playing in" << endl;
	cout << "the background." << endl;
	
}

// Row 2 Column 3 -- N404
void N404()
{
	cout << "You have now entered room N404, this is an empty classroom." << endl;
	
}

// Row 3 Column 0 -- N413
void N413()
{
	cout << "You have now entered room N413, this is the computer supply room." << endl;
	}

// Row 3 Column 1 -- N420
void N420()
{
	cout << "You have now entered room N420, this is Ms. Allen's office," << endl;
	cout << "whereabouts unknown." << endl;
	

}

// Row 3 Column 2 -- N433
void N433()
{
	cout << "You have now entered room N433, this is the buisness room" << endl;
	cout << "no students found." << endl;
	
}

// Row 3 Column 3 -- N507
void N507()
{
	cout << "You have now entered room N507, this room is a storage room for " << endl;
	cout << "school computers." << endl;
	
}

void DescribeRoomContents(int roomDesc, int row, int col)
{
	//Call appropriate function to describe room
	switch(row)
	{
			case 0: //Row0
				switch(col)
				{
					case 0: //col 0
					Main_Entry();
					break;
					case 1: //col 1
					N302();
					break;
					case 2: //col 2
					N304();
					break;
					case 3: //col 3
					N308();
					break;

				}
			break; //break from case 0(row)

			case 1://Row1
				switch(col)
				{
					case 0: //col0
					N324();
					break;
					case 1: //col1
					N333();
					break;
					case 2: //col2
					N341();
					break;
					case 3: //col3
					N346();
					break;
				}
			break; //break from case 1(row)

			case 2: //Row2
				switch(col)
				{
					case 0: // col0
					N348();
					break;
					case 1: //col1
					N349();
					break;
					case 2: //col2
					N403();
					break;
					case 3: //col3
					N404();
					break;

				}
			break; //break from case 2(row)

			case 3: //Row3
				switch(col)
				{
					case 0: //col0
					N413();
					break;
					case 1: //col1
					N420();
					break;
					case 2: //col2
					N433();
					break;
					case 3: //col3
					N507();
					break;
				}
			break; //break from case 3(row)


	} //end switch row
	

	


	//Describe creatures if any here
	if(roomDesc & LULZSEC)
		cout << "Beware, Dangerous hacker.\n";
	if(roomDesc & AdrianLamo)
		cout << "Beware, Adrian Lamo is dangerous.\n";
	if(roomDesc & MathewBevan)
		cout << "BEWARE: Bevan is dangerous.\n";
	if(roomDesc & RichardPryce)
		cout << "Beware..\n";
	if(roomDesc & EdwardSnowden)
		cout << "Beware, Snowden is here. Take precation.\n";
	if(roomDesc & GaryMckinnon)
		cout << "Beware, Mckinnon is here.\n";
	if(roomDesc & KevinMitnick)
		cout << "Beware, Mitnick is the world's most infamous hacker, turn off all devices.\n";
	if(roomDesc & Astra)
		cout << "Beware, Astra the cyber crime criminal is here.\n";

	//tell if they are dangerous creatures
	if(roomDesc & DEADLY)
	cout << "This creature is deadly, RUN!!!\n";
	if(roomDesc & DANGEROUS)
	cout << "This creature is dangerous. Be very careful!!\n";
	if(roomDesc & CAUTION)
	cout << "This creature could be dangerous!\n";
	if(roomDesc & FRIENDLY)
	cout << "This creature is friendly!\n";

	//check for other items that are defined
	if(roomDesc & VPN)
	cout << "You see the instructions to set up a VPN.\n";
	if(roomDesc & VIRUS_CD)
	cout << "You see a Virus infected CD.\n";
	if(roomDesc & MALWARE)
	cout << "You Have entered the wrong room, Malware activating...\n";
	if(roomDesc & INF_MACBOOK)
	cout << "You have seen an Infected Macbook.\n";

	//check for treasure items
	if(roomDesc & MACBOOK_PRO)
	cout << "You can see a Macbook Pro.\n";
	if(roomDesc & FLASH_DRIVE)
	cout << "You can see a Flash Drive with Kali Linux installed.\n";
	if(roomDesc & ETHERNET_CABLE)
	cout << "You can see a Cat6 Ethernet Cable to hardline into the network.\n";
	if(roomDesc & ENCRYPTION_CODE)
	cout << "You can see the code to encrypt all devices.\n";
}//end function for room DESCRIPTION












