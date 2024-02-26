/* 

	PURPOSE:		this program serves to calculate ingredients for the creation of 
					the beard oils and to calculate costs for the ingredients

	INPUT:			ask if bottling or calculating costs
					bottling: ask how many bottles being produced
					costs: ask for price of goods and number of bottles

	PROCESSING:		bottling: calculate how much of each ingredient needed for number of specified bottles
					costs: calculate cost per bottle using specified prices,
					total production cost of bottles specified,
					retail and wholesale prices of total bottles,
					profit per bottle and total for wholesale and retail prices

	OUTPUT:			bottling: print amount of each ingredient needed to produce specified number of bottles
					with ingredients being printed in grams, ounces, and drops as needed
					costs: print cost per bottle, cost for total bottles, total wholesale, total retail,
					bottle profit wholesale, bottle profit retail, total profit wholesale, total profit retail


*/

// includes
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>

// libaries
using namespace std;

// structures
struct ModernRecipe {
	double avocado;
	double castor;
	double jojoba;
	double lemongrass;
	double eucalyptus;
	double peppermint;
	double frankincense;
	double sandalwood;
};

struct  ClassicRecipe {
	double avocado;
	double castor;
	double jojoba;
	double patchouli;
	double teatree;
	double eucalyptus;
	double bergamot;
	double cedarwood;
	double sandalwood;
};

struct ModernUnitCost {
	double avocado;
	double castor;
	double jojoba;
	double patchouli;
	double teatree;
	double eucalyptus;
	double bergamot;
	double cedarwood;
	double sandalwood;
	double bottle;
	double label;
	double printing;
	double box;
};

struct ClassicUnitCost {
	double avocado;
	double castor;
	double jojoba;
	double patchouli;
	double teatree;
	double eucalyptus;
	double bergamot;
	double cedarwood;
	double sandalwood;
	double bottle;
	double label;
	double printing;
	double box;
};

struct ModernTotalCost {
	double avocado;
	double castor;
	double jojoba;
	double patchouli;
	double teatree;
	double eucalyptus;
	double bergamot;
	double cedarwood;
	double sandalwood;
	double bottle;
	double label;
	double printing;
	double box;
};

struct ClassicTotalCost {
	double avocado;
	double castor;
	double jojoba;
	double patchouli;
	double teatree;
	double eucalyptus;
	double bergamot;
	double cedarwood;
	double sandalwood;
	double bottle;
	double label;
	double printing;
	double box;
};

struct IngredientsCost {
	double avocado;
	double castor;
	double jojoba;
	double patchouli;
	double teatree;
	double eucalyptus;
	double bergamot;
	double cedarwood;
	double sandalwood;
	double bottle;
	double label;
	double printing;
	double box;
};

// functions
void displayMenu();
int getSelection();
void mainMenu(vector<ModernRecipe>&,
	vector<ClassicRecipe>&,
	vector<ModernUnitCost>&,
	vector<ClassicUnitCost>&,
	vector<ModernTotalCost>&,
	vector<ClassicTotalCost>&,
	vector<IngredientsCost>&);
void calculateRecipe(vector<ModernRecipe>&, vector<ClassicRecipe>&);
void calculateCosts(vector<ModernRecipe>&,
	vector<ClassicRecipe>&,
	vector<ModernUnitCost>&,
	vector<ClassicUnitCost>&,
	vector<ModernTotalCost>&,
	vector<ClassicTotalCost>&,
	vector<IngredientsCost>&);


// constants for ratios
const double RETAIL_BOTTLE_PRICE = 20.00;
const double WHOLESALE_BOTTLE_PRICE = 12.50;
const int MILLILITERS_PER_OUNCE = 30;
const double MILLILITERS_PER_DROP = 0.05;
// in milliliters
const double AVOCADO_PER_BOTTLE = 4.8;
const double CASTOR_PER_BOTTLE = 10.2;
const double JOJOBA_PER_BOTTLE = 15;
const double LEMONGRASS_PER_MODERN_BOTTLE = 0.15;
const double EUCALYPTUS_PER_MODERN_BOTTLE = 0.30;
const double PEPPERMINT_PER_MODERN_BOTTLE = 0.15;
const double FRANKINCENSE_PER_MODERN_BOTTLE = 0.15;
const double SANDALWOOD_PER_MODERN_BOTTLE = 0.30;
const double PATCHOULI_PER_CLASSIC_BOTTLE = 0.10;
const double TEATREE_PER_CLASSIC_BOTTLE = 0.10;
const double EUCALYPTUS_PER_CLASSIC_BOTTLE = 0.20;
const double BERGAMOT_PER_CLASSIC_BOTTLE = 0.20;
const double CEDARWOOD_PER_CLASSIC_BOTTLE = 0.20;
const double SANDALWOOD_PER_CLASSIC_BOTTLE = 0.20;
// in ounces
const int BOTTLE_SIZE = 1;

// main 
int main()
{
	// declare variables needed
	vector<ModernRecipe> modernRecipe;
	vector<ClassicRecipe> classicRecipe;
	vector<ModernUnitCost> modernUnitCost;
	vector<ClassicUnitCost> classicUnitCost;
	vector<ModernTotalCost> modernTotalCost;
	vector<ClassicTotalCost> classicTotalCost;
	vector<IngredientsCost> ingredientsCost;
	
	// declare price variables
	
	// call main menu
	mainMenu(modernRecipe, classicRecipe, modernUnitCost, classicUnitCost, modernTotalCost, classicTotalCost, ingredientsCost);

	cout << "program is working";

	return 0;
}

// main menu function
void displayMenu()
{
	// title
	cout << "THIS PROGRAM CALCULATES INGREDIENTS NEEDED AND COSTS FOR BEARD OIL PRODUCTION." << endl << endl;

	// main menu
	cout << "What would you like to do?" << endl;
	cout << "Press 1 to calculate recipe ingredients." << endl;
	cout << "Press 2 to calculate costs and profits." << endl;
	cout << "Press X to exit." << endl;
} // displayMenu

// main menu function
void mainMenu(vector<ModernRecipe>& modernRecipe, vector<ClassicRecipe>& classicRecipe, vector<ModernUnitCost>& modernUnitCost, vector<ClassicUnitCost>& classicUnitCost, vector<ModernTotalCost>& modernTotalCost, vector<ClassicTotalCost>& classicTotalCost, vector<IngredientsCost>& ingredientsCost)
{
	// declare variables
	char selection = ' ';
	bool processMenuSelection = false;

	cout << fixed << setprecision(2);

	// show main menu
	do {
		// display the main menu
		cout << "THIS PROGRAM CALCULATES INGREDIENTS NEEDED AND COSTS FOR BEARD OIL PRODUCTION." << endl << endl;

		// main menu
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to calculate recipe ingredients." << endl;
		cout << "Press 2 to calculate costs and profits." << endl;
		cout << "Press X to exit." << endl;

		selection = getSelection();
		cout << "You have selected " << selection << "." << endl << endl;
		processMenuSelection = true;

		// process main menu selection
		switch (selection)
		{
		case '1':
			// recipe function
			calculateRecipe(modernRecipe, classicRecipe);
			break;
		case '2':
			calculateCosts(modernRecipe, classicRecipe, modernUnitCost, classicUnitCost, modernTotalCost, classicTotalCost, ingredientsCost);
			break;
		case 'X':
			processMenuSelection = false;
			cout << "Exiting the program.";
			break;
		default:
			cout << "Please make a valid selection." << endl;
		} // switch
	} while (processMenuSelection);
} // mainMenu

// get user selection
int getSelection()
{
	char userInput = ' ';

	cout << "Please make a selection: ";
	cin >> userInput;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return userInput;
} // getSelection

// recipe function
void calculateRecipe(vector<ModernRecipe>& modernRecipe, vector<ClassicRecipe>& classicRecipe)
{
	char selection = ' ';
	bool processMenuSelection = false;
	int numberOfBottles = 0;

	do {
		// display menu
		cout << "RECIPE CALCULATION FUNCTION" << endl << endl;
		cout << "Which formula would you like to calculate?" << endl;
		cout << "Press 1 for Modern formula." << endl;
		cout << "Press 2 for Classic formula." << endl;
		cout << "Press X to go back." << endl;

		selection = getSelection();
		cout << "You have selected " << selection << "." << endl << endl;
		processMenuSelection = true;

		// process menu selection
		switch (selection)
		{
		case '1':
			// if vector is empty, add default values
			if (modernRecipe.empty())
			{
				modernRecipe.push_back(ModernRecipe());
			} // if

			// modern calculation
			cout << "How many bottles are required?" << endl;
			cin >> numberOfBottles;
			cout << "You have selected " << numberOfBottles << " bottles." << endl;

			// calculate ingredient quantities
			modernRecipe[0].avocado = (numberOfBottles * AVOCADO_PER_BOTTLE);
			modernRecipe[0].castor = (numberOfBottles * CASTOR_PER_BOTTLE);
			modernRecipe[0].jojoba = (numberOfBottles * JOJOBA_PER_BOTTLE);
			modernRecipe[0].lemongrass = (numberOfBottles * LEMONGRASS_PER_MODERN_BOTTLE);
			modernRecipe[0].eucalyptus = (numberOfBottles * EUCALYPTUS_PER_MODERN_BOTTLE);
			modernRecipe[0].peppermint = (numberOfBottles * PEPPERMINT_PER_MODERN_BOTTLE);
			modernRecipe[0].frankincense = (numberOfBottles * FRANKINCENSE_PER_MODERN_BOTTLE);
			modernRecipe[0].sandalwood = (numberOfBottles * SANDALWOOD_PER_MODERN_BOTTLE);

			// print quantities to console
			cout << "Avocado oil: " << modernRecipe[0].avocado << "ml." << endl;
			cout << "Castor oil: " << modernRecipe[0].castor << "ml." << endl;
			cout << "Jojoba oil: " << modernRecipe[0].jojoba << "ml." << endl;
			cout << "Lemongrass oil: " << modernRecipe[0].lemongrass << "ml." << endl;
			cout << "Eucalyptus oil: " << modernRecipe[0].eucalyptus << "ml." << endl;
			cout << "Peppermint oil: " << modernRecipe[0].peppermint << "ml." << endl;
			cout << "Frankincense oil: " << modernRecipe[0].frankincense << "ml." << endl;
			cout << "Sandalwood oil: " << modernRecipe[0].sandalwood << "ml." << endl;

			break;
		case '2':
			// if vector is empty, add default values
			if (classicRecipe.empty())
			{
				classicRecipe.push_back(ClassicRecipe());
			} // if

			// modern calculation
			cout << "How many bottles are required?" << endl;
			cin >> numberOfBottles;
			cout << "You have selected " << numberOfBottles << " bottles." << endl;

			// calculate ingredient quantities
			classicRecipe[0].avocado = (numberOfBottles * AVOCADO_PER_BOTTLE);
			classicRecipe[0].castor = (numberOfBottles * CASTOR_PER_BOTTLE);
			classicRecipe[0].jojoba = (numberOfBottles * JOJOBA_PER_BOTTLE);
			classicRecipe[0].patchouli = (numberOfBottles * PATCHOULI_PER_CLASSIC_BOTTLE);
			classicRecipe[0].teatree = (numberOfBottles * TEATREE_PER_CLASSIC_BOTTLE);
			classicRecipe[0].eucalyptus = (numberOfBottles * EUCALYPTUS_PER_CLASSIC_BOTTLE);
			classicRecipe[0].bergamot = (numberOfBottles * BERGAMOT_PER_CLASSIC_BOTTLE);
			classicRecipe[0].cedarwood = (numberOfBottles * CEDARWOOD_PER_CLASSIC_BOTTLE);
			classicRecipe[0].sandalwood = (numberOfBottles * SANDALWOOD_PER_CLASSIC_BOTTLE);

			// print quantities to console
			cout << "Avocado oil: " << classicRecipe[0].avocado << "ml." << endl;
			cout << "Castor oil: " << classicRecipe[0].castor << "ml." << endl;
			cout << "Jojoba oil: " << classicRecipe[0].jojoba << "ml." << endl;
			cout << "Patchouli oil: " << classicRecipe[0].patchouli << "ml." << endl;
			cout << "Tea Tree oil: " << classicRecipe[0].teatree << "ml." << endl;
			cout << "Eucalyptus oil: " << classicRecipe[0].eucalyptus << "ml." << endl;
			cout << "Bergamot oil: " << classicRecipe[0].bergamot << "ml." << endl;
			cout << "Cedarwood oil: " << classicRecipe[0].cedarwood << "ml." << endl;
			cout << "Sandalwood oil: " << classicRecipe[0].sandalwood << "ml." << endl;

			break;
		case 'X':
			processMenuSelection = false;
			cout << "Going back.";
			break;
		default:
			cout << "Please make a valid selection." << endl;
		} // switch
	} while (processMenuSelection);
} // calculateRecipe

// costs function
void calculateCosts(vector<ModernRecipe>&, vector<ClassicRecipe>&, vector<ModernUnitCost>&, vector<ClassicUnitCost>&, vector<ModernTotalCost>&, vector<ClassicTotalCost>&, vector<IngredientsCost>&)
{
	// declare variables
	double purchasePrice = 0;		// price for ingredient
	double unitsPurchased = 0;		// size of item purchased (ex: 64oz)
	char unitOfMeasure = ' ';		// ounces or milliliters
	double unitPrice = 0;			// price per milliliter
	char selection = ' ';
	bool processMenuSelection = false;
	int numberOfBottles = 0;

	// MENU:
	// enter ingredient prices
	// calculate unit prices
	// calculate total prices
	// calculate profits for wholesale and retail

	do
	{
		// display menu
		cout << "PRICES CALCULATION FUNCTION" << endl << endl;
		cout << "Please select an option." << endl;
		cout << "Press 1 to enter ingredient prices." << endl;
		cout << "Press 2 for unit prices." << endl;
		cout << "Press 3 for total prices." << endl;
		cout << "Press X to go back." << endl;

		selection = getSelection();
		cout << "You have selected " << selection << "." << endl << endl;
		processMenuSelection = true;

		switch (selection)
		{
		case '1':
			//// if vector is empty, add default values
			//if (ingredientsCost.empty())
			//{
			//	ingredientsCost.push_back(IngredientsCost());
			//} // if

			// display menu
			cout << "ENTER INGREDIENT PRICES." << endl;
			cout << "What is the price of avocado oil?" << endl;
			cin >> purchasePrice;
			cout << "What is the quantity of units purchased (in ounces or milliliters)?" << endl;
			cin >> unitsPurchased;
			cout << "What unit of measurement is used? Press 1 for ounces and 2 for milliliters." << endl;
			cin >> unitOfMeasure;
			if (unitOfMeasure == 1)
			{
				cout << "Converting ounces to milliliters." << endl;
				unitsPurchased *= MILLILITERS_PER_OUNCE;
			} // if



			break;
		case '2':
			cout << "option 2 works." << endl;
			break;
		case '3':
			cout << "option 3 works." << endl;
			break;
		case 'X':
			processMenuSelection = false;
			cout << "Going back.";
			break;
		default:
			cout << "Please make a valid selection." << endl;
		} // switch

	} while (processMenuSelection);
} // calculateCosts


// recipe calculations function

// costs calculations function

// print recipe function

// print costs function