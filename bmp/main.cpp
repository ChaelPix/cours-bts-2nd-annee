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



vector<Pixel> doublerTaille(const vector<Pixel>& source, int nombreColonnes) {
	vector<Pixel> result;

	for (int i = 0; i < source.size(); i += nombreColonnes) {
		// Duplique chaque ligne
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < nombreColonnes; ++k) {
				// Duplique chaque pixel
				result.push_back(source[i + k]);
				result.push_back(source[i + k]);
			}
		}
	}
	return result;
}

void mettreAJourEnTeteBMP(vector<unsigned char>& bmp, int nouveauLargeur, int nouveauHauteur) {
	// Met à jour la largeur
	bmp[0x12] = nouveauLargeur;
	bmp[0x13] = nouveauLargeur >> 8;
	bmp[0x14] = nouveauLargeur >> 16;
	bmp[0x15] = nouveauLargeur >> 24;

	// Met à jour la hauteur
	bmp[0x16] = nouveauHauteur;
	bmp[0x17] = nouveauHauteur >> 8;
	bmp[0x18] = nouveauHauteur >> 16;
	bmp[0x19] = nouveauHauteur >> 24;
}


Pixel calculerPixelMoyen(const vector<Pixel>& source, int x, int y, int largeur, int hauteur) {
	int totalPixels = 0;
	int sommeRouge = 0, sommeVert = 0, sommeBleu = 0;

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			int nx = x + i;
			int ny = y + j;

			if (nx >= 0 && nx < largeur && ny >= 0 && ny < hauteur) {
				Pixel p = source[ny * largeur + nx];
				sommeRouge += p.rouge;
				sommeVert += p.vert;
				sommeBleu += p.bleu;
				totalPixels++;
			}
		}
	}

	Pixel moyen;
	moyen.rouge = sommeRouge / totalPixels;
	moyen.vert = sommeVert / totalPixels;
	moyen.bleu = sommeBleu / totalPixels;
	return moyen;
}

vector<Pixel> doublerTailleAvecLissage(const vector<Pixel>& source, int largeur, int hauteur) {
	vector<Pixel> result;
	for (int y = 0; y < hauteur; ++y) {
		for (int x = 0; x < largeur; ++x) {
			Pixel pixelMoyen = calculerPixelMoyen(source, x, y, largeur, hauteur);
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					result.push_back(pixelMoyen);
				}
			}
		}
	}
	return result;
}

Pixel interpoler(const vector<Pixel>& source, int x, int y, int nombreColonnes) {
	// Trouver les coordonnées des quatre pixels adjacents
	int x1 = max(0, x - 1);
	int x2 = min(nombreColonnes - 1, x + 1);
	int y1 = max(0, y - 1);
	int y2 = min((int)source.size() / nombreColonnes - 1, y + 1);

	// Calculer les poids pour l'interpolation
	float dx = (x - x1) / (float)(x2 - x1);
	float dy = (y - y1) / (float)(y2 - y1);

	// Obtenir les couleurs des pixels adjacents
	Pixel p1 = source[y1 * nombreColonnes + x1];
	Pixel p2 = source[y1 * nombreColonnes + x2];
	Pixel p3 = source[y2 * nombreColonnes + x1];
	Pixel p4 = source[y2 * nombreColonnes + x2];

	// Interpoler les couleurs
	Pixel result;
	result.rouge = (1 - dx) * (1 - dy) * p1.rouge + dx * (1 - dy) * p2.rouge + (1 - dx) * dy * p3.rouge + dx * dy * p4.rouge;
	result.vert = (1 - dx) * (1 - dy) * p1.vert + dx * (1 - dy) * p2.vert + (1 - dx) * dy * p3.vert + dx * dy * p4.vert;
	result.bleu = (1 - dx) * (1 - dy) * p1.bleu + dx * (1 - dy) * p2.bleu + (1 - dx) * dy * p3.bleu + dx * dy * p4.bleu;

	return result;
}



Pixel moyennePixels(const Pixel& a, const Pixel& b) {
	Pixel result;
	result.rouge = (a.rouge + b.rouge) / 2;
	result.vert = (a.vert + b.vert) / 2;
	result.bleu = (a.bleu + b.bleu) / 2;
	return result;
}

vector<Pixel> doublerTailleInterpolation(const vector<Pixel>& source, int nombreColonnes) {
	int nombreLignes = source.size() / nombreColonnes;
	vector<Pixel> result(4 * source.size());

	for (int y = 0; y < nombreLignes; y++) {
		for (int x = 0; x < nombreColonnes; x++) {
			Pixel current = source[y * nombreColonnes + x];
			Pixel right = (x < nombreColonnes - 1) ? source[y * nombreColonnes + (x + 1)] : current;
			Pixel below = (y < nombreLignes - 1) ? source[(y + 1) * nombreColonnes + x] : current;
			Pixel diag = (x < nombreColonnes - 1 && y < nombreLignes - 1) ? source[(y + 1) * nombreColonnes + (x + 1)] : current;

			// Assignation des pixels
			result[2 * y * 2 * nombreColonnes + 2 * x] = current;
			result[2 * y * 2 * nombreColonnes + (2 * x + 1)] = moyennePixels(current, right);
			result[(2 * y + 1) * 2 * nombreColonnes + 2 * x] = moyennePixels(current, below);
			result[(2 * y + 1) * 2 * nombreColonnes + (2 * x + 1)] = moyennePixels(moyennePixels(current, right), moyennePixels(below, diag));
		}
	}

	return result;
}

int x2Taille()
{
	// Supposons que le fichier d'origine est nommé "img.bmp"
	ifstream fichier("img.bmp", ios::binary);

	if (!fichier) {
		cerr << "Impossible d'ouvrir le fichier!" << endl;
		return 1;
	}

	vector<unsigned char> bmp;
	char c;
	while (fichier.get(c)) {
		bmp.push_back(c);
	}
	fichier.close();

	int largeur = *(int*)&bmp[0x12];
	int hauteur = *(int*)&bmp[0x16];

	// Convertir le vector<unsigned char> à vector<Pixel>
	int offsetImage = *(int*)&bmp[0x0A];
	vector<Pixel> pixels;
	for (int i = offsetImage; i < bmp.size(); i += 3) {
		Pixel p;
		p.rouge = bmp[i + 2];
		p.vert = bmp[i + 1];
		p.bleu = bmp[i];
		pixels.push_back(p);
	}

	vector<Pixel> pixelsRedimensionnes = doublerTailleInterpolation(pixels, largeur);
	mettreAJourEnTeteBMP(bmp, largeur * 2, hauteur * 2);

	// Crée un nouveau fichier BMP avec les nouvelles dimensions
	ofstream sortie("img_double.bmp", ios::binary);
	for (int i = 0; i < offsetImage; ++i) {
		sortie << bmp[i];
	}
	for (const Pixel& p : pixelsRedimensionnes) {
		sortie << p.bleu << p.vert << p.rouge;
	}
	sortie.close();

	cout << "Image redimensionnée enregistrée sous 'img_double.bmp'" << endl;

	return 0;
}

//vector<Pixel> Rotater90(const vector<Pixel>& source, int nombreColonnes, int nombreLignes) {
//	vector<Pixel> result;
//	result.resize(source.size());  // redimensionner le vecteur résultat
//
//	for (int i = 0; i < nombreLignes; i++) {
//		for (int j = 0; j < nombreColonnes; j++) {
//			int newIndex = j * nombreLignes + (nombreLignes - 1 - i);
//			int oldIndex = i * nombreColonnes + j;
//			result[newIndex] = source[oldIndex];
//		}
//	}
//
//	return result;
//}

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
	
	std::swap(nombreColonnes, nombreLignes);
	vector<unsigned char> newWidthBytes = intToBytes(nombreColonnes);
	vector<unsigned char> newHeightBytes = intToBytes(nombreLignes);

	unsigned int newSize = nouveau.size();
	vector<unsigned char> newSizeBytes = intToBytes(newSize);

	for (int i = 0; i < 4; i++) {
		//nouveau[0x02 + i] = newSizeBytes[i];
		nouveau[0x12 + i] = newWidthBytes[i];
		nouveau[0x16 + i] = newHeightBytes[i];
	}

	for (int i = 0; i < nbPixel; i++)
	{
		nouveau.push_back(tabPixel[i].bleu);
		nouveau.push_back(tabPixel[i].vert);
		nouveau.push_back(tabPixel[i].rouge);
	}
	
	std::string imgName = "img_rotate90_" + std::to_string(nbImg) + ".bmp";
	ofstream copie(imgName, ios::binary);
	for (int i = 0; i < nouveau.size(); i++)
		copie << nouveau[i];
	copie.close();
}

int main()
{
	x2Taille();
	return 0;
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
		for (int ligne = 0; ligne < 4; ligne++)
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
		//RotaterImage90(debut, nbCols, nbLignes);


	}

	else
	cerr << "Impossible d'ouvrir le fichier !" << endl;
	return 0;
}
