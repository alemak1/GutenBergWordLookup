
#include <iostream>
#include <cassert>
#include <string>

#include "Definitions.h"

int main(){

	Definitions definitionsGroup1;
	Definitions definitionsGroup2(20);

	Definitions defGroupA;
	Definitions defGroupB;
	Definitions defGroupC;
	Definitions defGroupD;

	defGroupA.appendDefinition("a small, furry animal");
	defGroupA.appendDefinition("a man who lives a lascivious lifestyle, a playboy");
	defGroupA.appendDefinition("man's best friend");
	defGroupA.appendDefinition("a despicable, contemptible person");
	defGroupA.showDefinitions(cout);

	cout << string(defGroupA) << endl;

	return 0;

	defGroupB = "a small canine animal loyal to men and able to perform many important functions";
	defGroupB += "a cute and cuddly little creature";
	defGroupB += "the softer, cuddlier version of a werewolf";
	defGroupB.showDefinitions(cout);

	defGroupC = defGroupA;
	defGroupC.showDefinitions(cout);

	if(defGroupC == defGroupA){
		cout << "The two definitions (Definiions A and Definitons C) are equal!" << endl;
	};

	if(defGroupB != defGroupA){
		cout << "The two definitions (Definitions B and Definitions A) are not equal!" << endl;
	}

	defGroupD = defGroupB + defGroupA;
	defGroupD.showDefinitions(cout);

	return 0;

	cout << "Current Capacity for DefinitionsGroup1 is: " << definitionsGroup1.getCurrentCapacity() << endl;
	cout << "Current Capacity for DefinitionsGroup2 is: " << definitionsGroup2.getCurrentCapacity() << endl;

	assert(definitionsGroup1.isEmpty());
	assert(definitionsGroup2.isEmpty());
	assert(!definitionsGroup2.hasDefinitions());
	assert(!definitionsGroup1.hasDefinitions());

	cout << "Adding definitions for hypothetical word 'clash'... " << endl;

	definitionsGroup1.appendDefinition("To engage in military conflict");
	definitionsGroup1.appendDefinition("To have a difference of opinions, values, personalities, or attitudes");
	definitionsGroup1.appendDefinition("To physically strike or hit against another solid object");
	definitionsGroup1.appendDefinition("A conflict, battle, or mutual struggle due to mutually incompatible end goals");
	definitionsGroup1.appendDefinition("A difference of attitudes,values,or beliefs that leads to friction or the inability to maintain harmonious relations");
	definitionsGroup1.appendDefinition("To have a fight");
	definitionsGroup1.appendDefinition("To have an altercation or argument");
	definitionsGroup1.appendDefinition("To engage in warfrace");
	definitionsGroup1.appendDefinition("To have a swordfight");
	definitionsGroup1.appendDefinition("To have minor, localized battle, not quite worthy of being called a war");
	definitionsGroup1.appendDefinition("To spar over commonly-needed or commonly-desired goals or resources");
	definitionsGroup1.appendDefinition("To have a jousting match");

	cout << "After appending definitions in excess of original capacity, Current Capcity of DefinitionsGroup1 is (20): " << definitionsGroup1.getCurrentCapacity() << endl;

	definitionsGroup1.popDefinition();
	definitionsGroup1.popDefinition();
	definitionsGroup1.popDefinition();
	definitionsGroup1.popDefinition();
	definitionsGroup1.popDefinition();
	definitionsGroup1.popDefinition();

	cout << "After popping definitions, Current Capacity of DefinitionsGroup1 is (10): " << definitionsGroup1.getCurrentCapacity() << endl;

	definitionsGroup1.showDefinitions(cout);


	return 0;

	cout << "Displaying definitions using the subscript operator..." << endl;;

	cout << "Definition 0 is: " << definitionsGroup1[0] << endl;
	cout << "Definition 1 is: " << definitionsGroup1[1] << endl;
	cout << "Definition 2 is: " << definitionsGroup1[2] << endl;
	cout << "Definition 3 is: " << definitionsGroup1[3] << endl;
	cout << "Definition 4 is: " << definitionsGroup1[4] << endl;

	cout << "Now attempting to display all definitions..." << endl;
	definitionsGroup1.showDefinitions(cout);

	cout << "Replacing definitions 0 and 1...." << endl;
	definitionsGroup1[0] = "To engage in a conflict, military, verbal or otherwise";
	definitionsGroup1[1] = "To be in a state of conflict or friction as a result of a difference of opinions, values, personalities, or the like";

	cout << "Displaying updated dictionary definitions.." << endl;
	definitionsGroup1.showDefinitions(cout);





	return 0;
}