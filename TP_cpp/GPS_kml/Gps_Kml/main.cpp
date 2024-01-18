#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Fonctions de conversion
float LatGPS2KML(std::string lati) {
    float degrees = std::stof(lati.substr(0, 2));
    float minutes = std::stof(lati.substr(2));
    return degrees + minutes / 60.0;
}

float LonGPS2KML(std::string longi) {
    float degrees = std::stof(longi.substr(0, 3));
    float minutes = std::stof(longi.substr(3));
    return degrees + minutes / 60.0;
}
// Fonction pour générer un fichier KML
bool GenFicKML_Point(float longitude, float latitude, const std::string& nomFichier) {
    std::ofstream file(nomFichier);
    if (!file.is_open()) {
        return false;
    }

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n"
        << "<Placemark>\n"
        << "<Point>\n"
        << "<coordinates>" << longitude << "," << latitude << ",0</coordinates>\n"
        << "</Point>\n"
        << "</Placemark>\n"
        << "</kml>";

    file.close();
    return true;
}

bool GenFicKML_Ligne(const std::vector<float>& longitudes, const std::vector<float>& latitudes, const std::string& nomFichier) {
    if (longitudes.size() != latitudes.size()) {
        return false;
    }

    std::ofstream file(nomFichier);
    if (!file.is_open()) {
        return false;
    }

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n"
        << "<Placemark>\n"
        << "<LineString>\n"
        << "<coordinates>\n";

    for (size_t i = 0; i < longitudes.size(); ++i) {
        file << longitudes[i] << "," << latitudes[i] << ",0\n";
    }

    file << "</coordinates>\n"
        << "</LineString>\n"
        << "</Placemark>\n"
        << "</kml>";

    file.close();
    return true;
}

// Fonction pour extraire la latitude et la longitude d'une trame
std::pair<std::string, std::string> extractLatLong(const std::string& line) {
    std::stringstream ss(line);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, ',')) {
        seglist.push_back(segment);
    }

    // Pour GPGGA, la latitude est en 2ème position et la longitude en 4ème
    // Pour GPRMC, la latitude est en 3ème position et la longitude en 5ème
    std::string lat = (line.substr(1, 5) == "GPGGA") ? seglist[2] : seglist[3];
    std::string lon = (line.substr(1, 5) == "GPGGA") ? seglist[4] : seglist[5];

    return { lat, lon };
}

// Fonction principale pour traiter le fichier de capture
bool ProcessCaptureFile(const std::string& fileName, const std::string& outputKML) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return false;
    }

    std::string line;
    std::vector<float> latitudes, longitudes;
    while (getline(file, line)) {
        if (line.substr(0, 6) == "$GPGGA" || line.substr(0, 6) == "$GPRMC") {
            auto [lat, lon] = extractLatLong(line);
            latitudes.push_back(LatGPS2KML(lat));
            longitudes.push_back(LonGPS2KML(lon));
        }
    }

    file.close();

    // Générer le fichier KML
    return GenFicKML_Ligne(longitudes, latitudes, outputKML);
}

int main() {
    std::string inputFileName = "capture.txt";  // Nom du fichier de capture
    std::string outputKML = "parcours.kml";    // Nom du fichier KML généré

    if (ProcessCaptureFile(inputFileName, outputKML)) {
        std::cout << "KML file generated successfully." << std::endl;
    }
    else {
        std::cout << "Failed to generate KML file." << std::endl;
    }

    return 0;
}
