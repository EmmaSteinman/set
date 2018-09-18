//============================================================
//Emma Steinman
//September 4, 2017
//presidents.cpp
//This file contains a program to 
//============================================================

#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
using namespace std;
Set<string> Whig (void)
{
	Set<string> w;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		getline(linestream, name, '\t');
		linestream >> party;	
		
		if (party == "(W)")
			w.insert(name);	
	}
	
	return w;
}

Set<string> Democrat (void)
{
	Set<string> d;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		getline(linestream, name, '\t');
		linestream >> party;	
		
		if (party == "(D)")
			d.insert(name);	
	}
	
	return d;
}

Set<string> Republican (void)
{
	Set<string> r;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		getline(linestream, name, '\t');
		linestream >> party;	
		
		if (party == "(R)")
			r.insert(name);	
	}
	
	return r;
}

Set<string> OtherParty (void)
{
	Set<string> op;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		getline(linestream, name, '\t');
		linestream >> party;	
		
		if (party != "(W)" && party != "(D)" && party != "(R)")
			op.insert(name);	
	}
	
	return op;
}

Set<string> VA (void)
{
	Set<string> VA;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		getline(linestream, name, '\t');
		linestream >> party >> state;	
		
		if (state == "VA")
			VA.insert(name);	
	}
	
	return VA;
}

Set<string> NY (void)
{
	Set<string> NY;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		getline(linestream, name, '\t');
		linestream >> party >> state;	
		if (state == "NY")
			NY.insert(name);
	}
	
	return NY;
}

Set<string> MA (void)
{
	Set<string> MA;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		getline(linestream, name, '\t');
		linestream >> party >> state;	
		if (state == "MA")
			MA.insert(name);
	}
	
	return MA;
}

Set<string> OH (void)
{
	Set<string> OH;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		getline(linestream, name, '\t');
		linestream >> party >> state;	
		if (state == "OH")
			OH.insert(name);
	}
	
	return OH;
}

Set<string> OtherStates (void)
{
	Set<string> O;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		getline(linestream, name, '\t');
		linestream >> party >> state;	
		
		if (state != "VA" && state != "NY" && state != "MA" && state != "OH")
			O.insert(name);	
	}
	
	return O;
}

Set<string> Episcopalian (void)
{
	Set<string> Ep;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		string religion;
		getline(linestream, name, '\t');
		linestream >> party >> state >> religion;	
		
		if (religion == "Episcopalian")
			Ep.insert(name);	
	}
	
	return Ep;
}

Set<string> Presbyterian (void)
{
	Set<string> P;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		string religion;
		getline(linestream, name, '\t');
		linestream >> party >> state >> religion;	
		
		if (religion == "Presbyterian")
			P.insert(name);	
	}
	
	return P;
}

Set<string> Methodist (void)
{
	Set<string> M;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		string religion;
		getline(linestream, name, '\t');
		linestream >> party >> state >> religion;	
		
		if (religion == "Methodist")
			M.insert(name);	
	}
	
	return M;
}

Set<string> OtherReligion (void)
{
	Set<string> OR;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		string religion;
		getline(linestream, name, '\t');
		linestream >> party >> state >> religion;	
		
		if (religion != "Episcopalian" && religion != "Presbyterian" && religion != "Methodist")
			OR.insert(name);	
	}
	
	return OR;
}

Set<string> Forties(void)
{
	Set<string> A40;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		string religion;
		int age;
		getline(linestream, name, '\t');
		linestream >> party >> state >> religion >> age;	
		
		if (age >= 40 && age <=49)
			A40.insert(name);	
	}
	
	return A40;
}

Set<string> Fifties(void)
{
	Set<string> A50;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		string religion;
		int age;
		getline(linestream, name, '\t');
		linestream >> party >> state >> religion >> age;	
		
		if (age >= 50 && age <=59)
			A50.insert(name);	
	}
	
	return A50;
}

Set<string> Sixties(void)
{
	Set<string> A60;
	ifstream inFile;
	string line;
	inFile.open("pres.txt");
	if (!inFile)
	{
		cout << "Unable to open file pres.txt" << endl;
		exit(1);
	}
	while (getline(inFile, line))
	{
		stringstream linestream(line);
		string name;
		string party;
		string state;
		string religion;
		int age;
		getline(linestream, name, '\t');
		linestream >> party >> state >> religion >> age;	
		
		if (age >= 60 && age <=69)
			A60.insert(name);	
	}
	
	return A60;
}

int main (void)
{
	Set<string> va = VA();
	Set<string> ny = NY();
	Set<string> ma = MA();
	Set<string> oh = OH();
	Set<string> otherstate = OtherStates();
	Set<string> episcopalian = Episcopalian();
	Set<string> presbyterian = Presbyterian();
	Set<string> methodist = Methodist();
	Set<string> otherreligion = OtherReligion();
	Set<string> forties = Forties();
	Set<string> fifties = Fifties();
	Set<string> sixties = Sixties();
	Set<string> whig = Whig();
	Set<string> democrat = Democrat();
	Set<string> republican = Republican();
	Set<string> otherparty = OtherParty();
	

	cout << (episcopalian & va & whig) << endl;
	cout << (methodist & oh) << endl;
	cout << (whig + democrat) << endl;
	cout << forties << endl;
	return 0;
}





































