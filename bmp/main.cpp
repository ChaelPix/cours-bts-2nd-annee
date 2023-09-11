#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Pixel
{
	char rouge;
	char vert;
	char bleu;
};
vector <Pixel> tabPixel;
vector < unsigned char> nouveau;

vector <unsigned char> element;
int nbImg = 0;

Pixel annulerBitsDePoidsFaible(Pixel pixel, int nbBits)
{
	unsigned char masque = 0xFF << nbBits;
	pixel.rouge &= masque;
	pixel.vert &= masque;
	pixel.bleu &= masque;
	return pixel;
}

Pixel NoirEtBlanc(Pixel pixel)
{
	float moy = (pixel.bleu + pixel.rouge + pixel.vert) / 3.0;


	pixel.rouge = moy;
	pixel.vert = moy;
	pixel.bleu = moy;
	return pixel;
}

unsigned int bytes2int(vector <unsigned char>& table, int start, int nbOfBytes)
{
	int value = 0;
	for (int i = nbOfBytes - 1; i >= 0; i--)
	{
		value *= 256;
		value += (int)table[start + i];
	}
	return value;
}

void DegraderImage(int debut, int nombreColonnes, int nombreLignes, int nbBitsDecalage)
{
	int nbPixel = nombreLignes * nombreColonnes;
	cout << dec << "Nombre de bits decales : " << nbBitsDecalage << endl;
	Pixel pixel;
	nouveau.clear();
	tabPixel.clear();
	for (int i = 0; i < nbPixel; i++)
	{
		pixel.bleu = element[debut + 3 * i];
		pixel.vert = element[debut + 1 + 3 * i];
		pixel.rouge = element[debut + 2 + 3 * i];
		tabPixel.push_back(pixel);
	}

	for (int i = 0; i < debut; i++) 
		nouveau.push_back(element[i]);

	for (int i = 0; i < nbPixel; i++)
	{
		Pixel pixelModifie = annulerBitsDePoidsFaible(tabPixel[i], nbBitsDecalage);
		nouveau.push_back(pixelModifie.bleu);
		nouveau.push_back(pixelModifie.vert);
		nouveau.push_back(pixelModifie.rouge);
	}

	std::string imgName = "img" + std::to_string(nbImg) + ".bmp";
	ofstream copie(imgName, ios::binary);
	for (int i = 0; i < nouveau.size(); i++)
		copie << nouveau[i];
	copie.close();
}

void ImageNoirEtBlanc(int debut, int nombreColonnes, int nombreLignes)
{
	int nbPixel = nombreLignes * nombreColonnes;

	Pixel pixel;
	nouveau.clear();
	tabPixel.clear();
	for (int i = 0; i < nbPixel; i++)
	{
		pixel.bleu = element[debut + 3 * i];
		pixel.vert = element[debut + 1 + 3 * i];
		pixel.rouge = element[debut + 2 + 3 * i];
		tabPixel.push_back(pixel);
	}

	for (int i = 0; i < debut; i++)
		nouveau.push_back(element[i]);

	for (int i = 0; i < nbPixel; i++)
	{
		Pixel pixelModifie = NoirEtBlanc(tabPixel[i]);
		nouveau.push_back(pixelModifie.bleu);
		nouveau.push_back(pixelModifie.vert);
		nouveau.push_back(pixelModifie.rouge);
	}

	std::string imgName = "img_bw" + std::to_string(nbImg) + ".bmp";
	ofstream copie(imgName, ios::binary);
	for (int i = 0; i < nouveau.size(); i++)
		copie << nouveau[i];
	copie.close();
}

vector<Pixel> miroirVertical(const vector<Pixel>& tabPixel, int nombreColonnes) {
	vector<Pixel> result;
	for (int i = tabPixel.size() - nombreColonnes; i >= 0; i -= nombreColonnes) {
		result.insert(result.end(), tabPixel.begin() + i, tabPixel.begin() + i + nombreColonnes);
	}
	return result;
}

vector<Pixel> miroirHorizontal(const vector<Pixel>& tabPixel, int nombreColonnes) {
	vector<Pixel> result;
	for (int i = 0; i < tabPixel.size(); i += nombreColonnes) {
		result.insert(result.end(), tabPixel.begin() + i, tabPixel.begin() + i + nombreColonnes);
		reverse(result.end() - nombreColonnes, result.end());
	}
	return result;
}

//vector<Pixel> Rotater90(const vector<Pixel>& tabPixel, int nombreColonnes) {
//	vector<Pixel> source;
//	vector<Pixel> result;
//	for (int i = 0; i < tabPixel.size(); i += nombreColonnes) {
//		source.insert(source.end(), tabPixel.begin() + i, tabPixel.begin() + i + nombreColonnes);
//		result.insert(result.end(), source.begin() + i, source.begin() + i + nombreColonnes);
//	}
//	return result;
//}

vector<Pixel> Rotater90(const vector<Pixel>& source, int nombreColonnes, int nombreLignes) {
	vector<Pixel> result(nombreLignes * nombreColonnes);

	for (int i = 0; i < nombreLignes; i++) {
		for (int j = 0; j < nombreColonnes; j++) {
			int indexSrc = i * nombreColonnes + j;
			int indexDest = (nombreColonnes - 1 - j) * nombreLignes + i;

			result[indexDest] = source[indexSrc];
		}
	}
	
	return result;
}

vector<unsigned char> intToBytes(unsigned int value) {
	return { (unsigned char)(value & 0xFF),
			 (unsigned char)((value >> 8) & 0xFF),
			 (unsigned char)((value >> 16) & 0xFF),
			 (unsigned char)((value >> 24) & 0xFF) };
}


void RotaterImage180(int debut, int nombreColonnes, int nombreLignes)
{
	int nbPixel = nombreLignes * nombreColonnes;

	Pixel pixel;
	nouveau.clear();
	tabPixel.clear();
	for (int i = 0; i < nbPixel; i++)
	{
		pixel.bleu = element[debut + 3 * i];
		pixel.vert = element[debut + 1 + 3 * i];
		pixel.rouge = element[debut + 2 + 3 * i];
		tabPixel.push_back(pixel);
	}

	for (int i = 0; i < debut; i++)
		nouveau.push_back(element[i]);

	for (int i = 0; i < nbPixel; i++)
	{
		nouveau.push_back(tabPixel[nbPixel - i - 1].bleu);
		nouveau.push_back(tabPixel[nbPixel - i - 1].vert);
		nouveau.push_back(tabPixel[nbPixel - i - 1].rouge);
	}

	std::string imgName = "img_rotate" + std::to_string(nbImg) + ".bmp";
	ofstream copie(imgName, ios::binary);
	for (int i = 0; i < nouveau.size(); i++)
		copie << nouveau[i];
	copie.close();
}

void MiroirImageVertical(int debut, int nombreColonnes, int nombreLignes)
{
	int nbPixel = nombreLignes * nombreColonnes;

	Pixel pixel;
	nouveau.clear();
	tabPixel.clear();
	for (int i = 0; i < nbPixel; i++)
	{
		pixel.bleu = element[debut + 3 * i];
		pixel.vert = element[debut + 1 + 3 * i];
		pixel.rouge = element[debut + 2 + 3 * i];
		tabPixel.push_back(pixel);
	}

	for (int i = 0; i < debut; i++)
		nouveau.push_back(element[i]);

	tabPixel = miroirVertical(tabPixel, nombreColonnes);

	for (int i = 0; i < nbPixel; i++)
	{
		nouveau.push_back(tabPixel[i].bleu);
		nouveau.push_back(tabPixel[i].vert);
		nouveau.push_back(tabPixel[i].rouge);
	}


	std::string imgName = "img_miroirvertical" + std::to_string(nbImg) + ".bmp";
	ofstream copie(imgName, ios::binary);
	for (int i = 0; i < nouveau.size(); i++)
		copie << nouveau[i];
	copie.close();
}

void MiroirImageHorizontal(int debut, int nombreColonnes, int nombreLignes)
{
	int nbPixel = nombreLignes * nombreColonnes;

	Pixel pixel;
	nouveau.clear();
	tabPixel.clear();
	for (int i = 0; i < nbPixel; i++)
	{
		pixel.bleu = element[debut + 3 * i];
		pixel.vert = element[debut + 1 + 3 * i];
		pixel.rouge = element[debut + 2 + 3 * i];
		tabPixel.push_back(pixel);
	}

	for (int i = 0; i < debut; i++)
		nouveau.push_back(element[i]);

	tabPixel = miroirHorizontal(tabPixel, nombreColonnes);

	for (int i = 0; i < nbPixel; i++)
	{
		nouveau.push_back(tabPixel[i].bleu);
		nouveau.push_back(tabPixel[i].vert);
		nouveau.push_back(tabPixel[i].rouge);
	}

	std::string imgName = "img_miroirhorizontal" + std::to_string(nbImg) + ".bmp";
	ofstream copie(imgName, ios::binary);
	for (int i = 0; i < nouveau.size(); i++)
		copie << nouveau[i];
	copie.close();
}

void RotaterImage90(int debut, int nombreColonnes, int nombreLignes)
{
	int nbPixel = nombreLignes * nombreColonnes;

	Pixel pixel;
	nouveau.clear();
	tabPixel.clear();
	for (int i = 0; i < nbPixel; i++)
	{
		pixel.bleu = element[debut + 3 * i];
		pixel.vert = element[debut + 1 + 3 * i];
		pixel.rouge = element[debut + 2 + 3 * i];
		tabPixel.push_back(pixel);
	}

	for (int i = 0; i < debut; i++)
		nouveau.push_back(element[i]);

	tabPixel = Rotater90(tabPixel, nombreColonnes, nombreLignes);
	

	for (int i = 0; i < nbPixel; i++)
	{
		nouveau.push_back(tabPixel[i].bleu);
		nouveau.push_back(tabPixel[i].vert);
		nouveau.push_back(tabPixel[i].rouge);
	}

	std::swap(nombreColonnes, nombreLignes);
	vector<unsigned char> newWidthBytes = intToBytes(nombreColonnes);
	vector<unsigned char> newHeightBytes = intToBytes(nombreLignes);

	unsigned int newSize = nouveau.size();
	vector<unsigned char> newSizeBytes = intToBytes(newSize);

	for (int i = 0; i < 4; i++) {
		nouveau[0x02 + i] = newSizeBytes[i];
		nouveau[0x12 + i] = newWidthBytes[i];
		nouveau[0x16 + i] = newHeightBytes[i];
	}

	std::string imgName = "img_rotate90_" + std::to_string(nbImg) + ".bmp";
	ofstream copie(imgName, ios::binary);
	for (int i = 0; i < nouveau.size(); i++)
		copie << nouveau[i];
	copie.close();
}
int main()
{
	ifstream fichier("img.bmp", ios::binary); // on ouvre en lecture
	if (fichier) // si l'ouverture a fonctionné
	{
		//lecture du fichier :
		char c;
		while (fichier.get(c))
		{
			element.push_back(c);
		}
		fichier.close();
		// -- Affichage des 64 premiers octets
		for (int ligne = 7; ligne < 8; ligne++)
		{
			for (int car = 0; car < 16; car++)
			{
				if (element[ligne * 16 + car] < 16) cout << "0";
				cout << hex << (int)element[ligne * 16 + car] << " ";
			}
			cout << endl;
		}
		unsigned int debut = bytes2int(element, 0x0A, 4);
		unsigned int nbCols = bytes2int(element, 0x12, 4);
		unsigned int nbLignes = bytes2int(element, 0x16, 4);
		cout << "Adresse de debut de l'image : " << debut << endl;


		for (int i = 0; i < 25; i++)
		{
			//DegraderImage(debut, nbCols, nbLignes, i);
			nbImg++;
		}
		
		//ImageNoirEtBlanc(debut, nbCols, nbLignes);
		//RotaterImage180(debut, nbCols, nbLignes);
		//MiroirImageVertical(debut, nbCols, nbLignes);
		//MiroirImageHorizontal(debut, nbCols, nbLignes);
		RotaterImage90(debut, nbCols, nbLignes);
	}

	else
	cerr << "Impossible d'ouvrir le fichier !" << endl;
	return 0;
}
