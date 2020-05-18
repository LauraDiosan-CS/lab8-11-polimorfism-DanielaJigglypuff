#include "RepositoryFileTXT.h"
#include "Marfar.h"
#include "Calatori.h"
#include <fstream>

RepositoryFileTXT::RepositoryFileTXT() : RepositoryFileTransport()
{
}

RepositoryFileTXT::RepositoryFileTXT(string fileNameIn, string fileNameOut, ValidationTransport* validation) : RepositoryFileTransport(fileNameIn, fileNameOut, validation)
{
	this->loadFromFile();
}

RepositoryFileTXT::~RepositoryFileTXT()
{
}

void RepositoryFileTXT::loadFromFile()
{
	ifstream fin(this->fileNameIn);
	if (fin.is_open())
	{
		this->emptyRepository();
		string line;
		string delimiter = " ";
		int position;
		while (getline(fin, line))
		{
			if (line.substr(0, 5) == "Marfar")
			{
				line = line.erase(0, 6);

				position = line.find(delimiter);
				int model = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string producator = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int numar_vagoane = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string marfa = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int garnituri_disponibile = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int garnituri_rezervate = stod(line.substr(0, position));
				line = line.erase(0, position + 1);



				Marfar* marfar = new Marfar(model, producator, numar_vagoane, marfa, garnituri_disponibile, garnituri_rezervate);
				this->items.push_back(marfar);
			}
			else if (line.substr(0, 7) == "Calatori")
			{
				line = line.erase(0, 8);

				position = line.find(delimiter);
				int model = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string producator = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int numar_vagoane = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int locuri = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int garnituri_disponibile = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int garnituri_rezervate = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

	

				Calatori* calatori = new Calatori(model, producator, numar_vagoane, locuri, garnituri_disponibile, garnituri_rezervate);
				this->items.push_back(calatori);
			}
		}
		fin.close();
	}
}

void RepositoryFileTXT::saveToFile()
{
	ofstream fout(this->fileNameOut);
	if (fout.is_open())
	{
		for (Transport* items : this->items)
		{
			fout << items->toString(" ") << endl;
		}
	}
}