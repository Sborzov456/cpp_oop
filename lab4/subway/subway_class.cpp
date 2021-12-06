#include "subway_class.h"
ostream& operator << (ostream& out, const Subway& SUBWAY)
{
	if (SUBWAY.Lines.empty()) throw exception("Error! Subway is empty\n");
	for (unsigned int i = 0; i < SUBWAY.Lines.size(); i++)
		out << SUBWAY.Lines[i];
	return out;
}
const int Subway::findLine(const string& lineName) const
{
	for (unsigned i = 0; i < Lines.size(); i++)
		if (Lines[i].getName() == lineName) return i;
	return -1;
}
bool Subway::findStation(const string& stationName) const
{
	for (unsigned i = 0; i < Lines.size(); i++)
		for (unsigned j = 0; j < Lines[i].getSize(); j++)
			if (Lines[i][j]->getName() == stationName) return true;
	return false;
}
const int Subway::findStation(const string& stationName, const string& lineName) const
{
	Line stationLine = Lines[findLine(lineName)];
	for (unsigned i = 0; i < stationLine.getSize(); i++)
		if (stationLine[i]->getName() == stationName) return i;
	return -1;

}
/*void Subway::drawSubwayGFVZ()
{
	ofstream fout;
	fout.open("C:\\Users\\boroz\\Desktop\\graphviz\\subway.txt");
	fout << "graph G {\n";
	fout << "Dmitrovskaya--Timiryazevckaya;\n";
	fout << "Timiryazevckaya--Petrasha;\n";
	fout << "}";
	fout.close();
	//system("C:\\Users\\boroz\\Graphviz\\bin\\dot.exe -Tpng -o C:\\Users\\boroz\\Desktop\\graphviz\\subway.png C:\\Users\\boroz\\Desktop\\graphviz\\subway.txt");
	system("C:\\Users\\boroz\\Graphviz\\bin\\dot.exe -Tpng -Gsize=9,15\! -Gdpi=100 -o C:\\Users\\boroz\\Desktop\\graphviz\\subway.png C:\\Users\\boroz\\Desktop\\graphviz\\subway.txt");
	system("C:\\Users\\boroz\\Desktop\\graphviz\\subway.png");
}*/