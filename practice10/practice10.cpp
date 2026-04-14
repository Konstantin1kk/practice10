#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

enum Genre { Rock, IndieRock, Pop, Rap, Jazz, Classical };

string genreToString(Genre g) {
    switch (g) {
    case Rock: return "Rock";
    case IndieRock: return "IndieRock";
    case Pop: return "Pop";
    case Rap: return "Rap";
    case Jazz: return "Jazz";
    case Classical: return "Classical";
    default: return "Unknown";
    }
}

struct Track {
    string name;
    int duration;

    void getInfo() {
        cout << name << "(" << duration / 60 << ":";
        if (duration % 60 < 10) {
            cout << "0";
        }
        cout << duration % 60 << ")" << endl;
    }
};

struct Album {
    string title;
    string artist;
    Genre genre;
    int releaseYear;
    int totalDuration;
    double price;
    vector<Track> tracksVector;

    void getInfo() {
        cout << "================================" << endl;
        cout << "Album: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Genre: " << genreToString(genre) << endl;
        cout << "Date release: " << releaseYear << endl;
        cout << "Duration: " << totalDuration / 60 << ":";
        if (totalDuration % 60 < 10) {
            cout << "0";
        }
        cout << totalDuration % 60 << endl;
        cout << "Price: " << price << endl;
        for (Track& track : tracksVector) {
            track.getInfo();
        };

        cout << "================================" << endl;
    }

    void setInfo(string title, string artist, Genre genre, int releaseYear, int duration, double price, vector<Track> tracksVector) {

    }
};

Album createAlbum(string title, string artist, Genre genre, int releaseYear, int totalDuration, double price, vector<Track> tracksVector = {}) {
    Album album;
    album.title = title;
    album.artist = artist;
    album.genre = genre;
    album.releaseYear = releaseYear;
    album.totalDuration = totalDuration;
    album.price = price;
    album.tracksVector = tracksVector;
    return album;
}

Track createTrack(string name, int duration) {
    Track track;
    track.name = name;
    track.duration = duration;
    return track;
}

vector<Album> createAlbums() {
    vector<Album> albumsVector;

    // Альбом 1: Heavy Metal - Kai Angel & 9mice (Rap, 2023)
    vector<Track> tracks1;
    tracks1.push_back(createTrack("Cyber Is Dead Interlude", 85));
    tracks1.push_back(createTrack("Metal Heart", 210));
    tracks1.push_back(createTrack("Rage Mode", 195));
    tracks1.push_back(createTrack("Dark Paradise", 228));
    tracks1.push_back(createTrack("Final Strike", 185));
    Album album1 = createAlbum("Heavy Metal", "Kai Angel & 9mice", Rap, 2023, 903, 12.99, tracks1);
    albumsVector.push_back(album1);

    // Альбом 2: Abbey Road - The Beatles (Rock, 1969)
    vector<Track> tracks2;
    tracks2.push_back(createTrack("Come Together", 259));
    tracks2.push_back(createTrack("Something", 182));
    tracks2.push_back(createTrack("Maxwell's Silver Hammer", 207));
    tracks2.push_back(createTrack("Here Comes the Sun", 185));
    tracks2.push_back(createTrack("Because", 165));
    Album album2 = createAlbum("Abbey Road", "The Beatles", Rock, 1969, 998, 14.99, tracks2);
    albumsVector.push_back(album2);

    // Альбом 3: Thriller - Michael Jackson (Pop, 1982)
    vector<Track> tracks3;
    tracks3.push_back(createTrack("Wanna Be Startin' Somethin'", 363));
    tracks3.push_back(createTrack("Thriller", 357));
    tracks3.push_back(createTrack("Beat It", 258));
    tracks3.push_back(createTrack("Billie Jean", 294));
    tracks3.push_back(createTrack("Human Nature", 245));
    tracks3.push_back(createTrack("PYT", 238));
    Album album3 = createAlbum("Thriller", "Michael Jackson", Pop, 1982, 1755, 16.99, tracks3);
    albumsVector.push_back(album3);

    // Альбом 4: The Eminem Show - Eminem (Rap, 2002)
    vector<Track> tracks4;
    tracks4.push_back(createTrack("White America", 324));
    tracks4.push_back(createTrack("Business", 251));
    tracks4.push_back(createTrack("Cleanin' Out My Closet", 297));
    tracks4.push_back(createTrack("Without Me", 290));
    tracks4.push_back(createTrack("Sing for the Moment", 339));
    tracks4.push_back(createTrack("Superman", 350));
    Album album4 = createAlbum("The Eminem Show", "Eminem", Rap, 2002, 1851, 13.99, tracks4);
    albumsVector.push_back(album4);

    // Альбом 5: Kind of Blue - Miles Davis (Jazz, 1959)
    vector<Track> tracks5;
    tracks5.push_back(createTrack("So What", 564));
    tracks5.push_back(createTrack("Freddie Freeloader", 586));
    tracks5.push_back(createTrack("Blue in Green", 337));
    tracks5.push_back(createTrack("All Blues", 695));
    tracks5.push_back(createTrack("Flamenco Sketches", 558));
    Album album5 = createAlbum("Kind of Blue", "Miles Davis", Jazz, 1959, 2740, 11.99, tracks5);
    albumsVector.push_back(album5);

    // Альбом 6: In Utero - Nirvana (Rock, 1993)
    vector<Track> tracks6;
    tracks6.push_back(createTrack("Serve the Servants", 216));
    tracks6.push_back(createTrack("Scentless Apprentice", 228));
    tracks6.push_back(createTrack("Heart-Shaped Box", 281));
    tracks6.push_back(createTrack("Rape Me", 169));
    tracks6.push_back(createTrack("All Apologies", 231));
    Album album6 = createAlbum("In Utero", "Nirvana", Rock, 1993, 1125, 12.49, tracks6);
    albumsVector.push_back(album6);

    // Альбом 7: 1989 - Taylor Swift (Pop, 2014)
    vector<Track> tracks7;
    tracks7.push_back(createTrack("Welcome to New York", 212));
    tracks7.push_back(createTrack("Blank Space", 231));
    tracks7.push_back(createTrack("Style", 231));
    tracks7.push_back(createTrack("Shake It Off", 219));
    tracks7.push_back(createTrack("Bad Blood", 211));
    tracks7.push_back(createTrack("Wildest Dreams", 220));
    Album album7 = createAlbum("1989", "Taylor Swift", Pop, 2014, 1324, 15.99, tracks7);
    albumsVector.push_back(album7);

    // Альбом 8: The Dark Side of the Moon - Pink Floyd (Rock, 1973)
    vector<Track> tracks8;
    tracks8.push_back(createTrack("Speak to Me", 90));
    tracks8.push_back(createTrack("Breathe", 163));
    tracks8.push_back(createTrack("Time", 421));
    tracks8.push_back(createTrack("Money", 382));
    tracks8.push_back(createTrack("Us and Them", 463));
    tracks8.push_back(createTrack("Eclipse", 122));
    Album album8 = createAlbum("The Dark Side of the Moon", "Pink Floyd", Rock, 1973, 1641, 17.99, tracks8);
    albumsVector.push_back(album8);

    // Альбом 9: good kid, m.A.A.d city - Kendrick Lamar (Rap, 2012)
    vector<Track> tracks9;
    tracks9.push_back(createTrack("Sherane a.k.a Master Splinter's Daughter", 273));
    tracks9.push_back(createTrack("Bitch, Don't Kill My Vibe", 298));
    tracks9.push_back(createTrack("Backseat Freestyle", 212));
    tracks9.push_back(createTrack("The Art of Peer Pressure", 324));
    tracks9.push_back(createTrack("Swimming Pools", 316));
    tracks9.push_back(createTrack("Sing About Me", 732));
    Album album9 = createAlbum("good kid, m.A.A.d city", "Kendrick Lamar", Rap, 2012, 2155, 14.49, tracks9);
    albumsVector.push_back(album9);

    // Альбом 10: Back in Black - AC/DC (Rock, 1980)
    vector<Track> tracks10;
    tracks10.push_back(createTrack("Hells Bells", 312));
    tracks10.push_back(createTrack("Shoot to Thrill", 317));
    tracks10.push_back(createTrack("What Do You Do for Money Honey", 215));
    tracks10.push_back(createTrack("Back in Black", 255));
    tracks10.push_back(createTrack("You Shook Me All Night Long", 210));
    tracks10.push_back(createTrack("Rock and Roll Ain't Noise Pollution", 256));
    Album album10 = createAlbum("Back in Black", "AC/DC", Rock, 1980, 1565, 13.99, tracks10);
    albumsVector.push_back(album10);

    // Альбом 11: The Four Seasons - Antonio Vivaldi (Classical, 1723)
    vector<Track> tracks11;
    tracks11.push_back(createTrack("Spring: Allegro", 205));
    tracks11.push_back(createTrack("Summer: Presto", 165));
    tracks11.push_back(createTrack("Autumn: Allegro", 210));
    tracks11.push_back(createTrack("Winter: Allegro non molto", 185));
    Album album11 = createAlbum("The Four Seasons", "Antonio Vivaldi", Classical, 1723, 765, 9.99, tracks11);
    albumsVector.push_back(album11);

    // Альбом 12: Random Access Memories - Daft Punk (Pop, 2013)
    vector<Track> tracks12;
    tracks12.push_back(createTrack("Give Life Back to Music", 274));
    tracks12.push_back(createTrack("Giorgio by Moroder", 544));
    tracks12.push_back(createTrack("Get Lucky", 368));
    tracks12.push_back(createTrack("Lose Yourself to Dance", 353));
    tracks12.push_back(createTrack("Contact", 383));
    Album album12 = createAlbum("Random Access Memories", "Daft Punk", Pop, 2013, 1922, 15.49, tracks12);
    albumsVector.push_back(album12);

    // Альбом 13: To Pimp a Butterfly - Kendrick Lamar (Rap, 2015)
    vector<Track> tracks13;
    tracks13.push_back(createTrack("Wesley's Theory", 287));
    tracks13.push_back(createTrack("King Kunta", 234));
    tracks13.push_back(createTrack("Alright", 219));
    tracks13.push_back(createTrack("The Blacker the Berry", 328));
    tracks13.push_back(createTrack("i", 351));
    tracks13.push_back(createTrack("Mortal Man", 727));
    Album album13 = createAlbum("To Pimp a Butterfly", "Kendrick Lamar", Rap, 2015, 2146, 16.99, tracks13);
    albumsVector.push_back(album13);

    // Альбом 14: A Love Supreme - John Coltrane (Jazz, 1965)
    vector<Track> tracks14;
    tracks14.push_back(createTrack("Part I: Acknowledgement", 465));
    tracks14.push_back(createTrack("Part II: Resolution", 440));
    tracks14.push_back(createTrack("Part III: Pursuance", 650));
    tracks14.push_back(createTrack("Part IV: Psalm", 448));
    Album album14 = createAlbum("A Love Supreme", "John Coltrane", Jazz, 1965, 2003, 12.99, tracks14);
    albumsVector.push_back(album14);

    // Альбом 15: Nevermind - Nirvana (Rock, 1991)
    vector<Track> tracks15;
    tracks15.push_back(createTrack("Smells Like Teen Spirit", 301));
    tracks15.push_back(createTrack("In Bloom", 254));
    tracks15.push_back(createTrack("Come as You Are", 218));
    tracks15.push_back(createTrack("Lithium", 256));
    tracks15.push_back(createTrack("Something in the Way", 230));
    Album album15 = createAlbum("Nevermind", "Nirvana", Rock, 1991, 1259, 14.99, tracks15);
    albumsVector.push_back(album15);

    // Альбом 16: 21 - Adele (Pop, 2011)
    vector<Track> tracks16;
    tracks16.push_back(createTrack("Rolling in the Deep", 228));
    tracks16.push_back(createTrack("Rumour Has It", 223));
    tracks16.push_back(createTrack("Someone Like You", 285));
    tracks16.push_back(createTrack("Set Fire to the Rain", 242));
    tracks16.push_back(createTrack("Don't You Remember", 243));
    Album album16 = createAlbum("21", "Adele", Pop, 2011, 1221, 13.99, tracks16);
    albumsVector.push_back(album16);

    // Альбом 17: The Blueprint - Jay-Z (Rap, 2001)
    vector<Track> tracks17;
    tracks17.push_back(createTrack("The Ruler's Back", 190));
    tracks17.push_back(createTrack("Takeover", 313));
    tracks17.push_back(createTrack("Izzo", 240));
    tracks17.push_back(createTrack("Girls, Girls, Girls", 275));
    tracks17.push_back(createTrack("Song Cry", 330));
    Album album17 = createAlbum("The Blueprint", "Jay-Z", Rap, 2001, 1348, 12.49, tracks17);
    albumsVector.push_back(album17);

    // Альбом 18: Moonlight Sonata - Beethoven (Classical, 1801)
    vector<Track> tracks18;
    tracks18.push_back(createTrack("I. Adagio sostenuto", 360));
    tracks18.push_back(createTrack("II. Allegretto", 135));
    tracks18.push_back(createTrack("III. Presto agitato", 420));
    Album album18 = createAlbum("Moonlight Sonata", "Ludwig van Beethoven", Classical, 1801, 915, 8.99, tracks18);
    albumsVector.push_back(album18);

    // Альбом 19: Indie Rock Collection - Various Artists (IndieRock, 2020)
    vector<Track> tracks19;
    tracks19.push_back(createTrack("Electric Feel", 229));
    tracks19.push_back(createTrack("Little Talks", 266));
    tracks19.push_back(createTrack("Dog Days Are Over", 251));
    tracks19.push_back(createTrack("Float On", 208));
    tracks19.push_back(createTrack("The Cave", 218));
    Album album19 = createAlbum("Indie Rock Collection", "Various Artists", IndieRock, 2020, 1172, 11.99, tracks19);
    albumsVector.push_back(album19);

    // Альбом 20: The Marshall Mathers LP - Eminem (Rap, 2000)
    vector<Track> tracks20;
    tracks20.push_back(createTrack("Kill You", 264));
    tracks20.push_back(createTrack("Stan", 404));
    tracks20.push_back(createTrack("The Way I Am", 290));
    tracks20.push_back(createTrack("The Real Slim Shady", 284));
    tracks20.push_back(createTrack("I'm Back", 330));
    tracks20.push_back(createTrack("Criminal", 319));
    Album album20 = createAlbum("The Marshall Mathers LP", "Eminem", Rap, 2000, 1891, 15.99, tracks20);
    albumsVector.push_back(album20);

    return albumsVector;
}

// фильтрация по жанру
vector<Album> albumsFilterGenre(vector<Album>& albums) {
    vector<Album> resultAlbums;
    for (Album& album : albums) {
        if (album.genre == Genre::Rock || album.genre == Genre::IndieRock) {
            resultAlbums.push_back(album);
        }
    }
    return resultAlbums;
}

// сортировка пузырьком по исполнителю
void sortAlbumsByAlphabet(vector<Album>& albums) {
    for (size_t i = 0; i < albums.size() - 1; i++) {
        for (size_t j = 0; j < albums.size() - i - 1; j++) {
            if (albums[j].artist > albums[j + 1].artist) {
                swap(albums[j], albums[j + 1]);
            }
        }
    }
}

// вывод определенного альбома
void printSpecificAlbum(vector<Album>& albums, const string& title) {
    for (Album& album : albums) {
        if (album.title == title) {
            album.getInfo();
            return;
        }
    }
    cout << "Album \"" << title << "\" not found" << endl;
}

// топ 5 альбомов
void printTop5Albums(const vector<Album>& albums) {
    vector<Album> sortedAlbums = albums;

    for (size_t i = 0; i < sortedAlbums.size() - 1; i++) {
        for (size_t j = 0; j < sortedAlbums.size() - i - 1; j++) {
            if (sortedAlbums[j].releaseYear < sortedAlbums[j + 1].releaseYear) {
                swap(sortedAlbums[j], sortedAlbums[j + 1]);
            }
        }
    }

    cout << "\n========== TOP 5 POPULAR ALBUMS ==========" << endl;
    for (int i = 0; i < 5 && i < sortedAlbums.size(); i++) {
        cout << i + 1 << ". " << sortedAlbums[i].title << " - "
            << sortedAlbums[i].artist << " (" << sortedAlbums[i].releaseYear << ")" << endl;
    }
}

// изменение альбома
void modifyAlbum(Album& album, const string& newTitle, const string& newArtist,
    Genre newGenre, int newYear, double newPrice) {
    album.title = newTitle;
    album.artist = newArtist;
    album.genre = newGenre;
    album.releaseYear = newYear;
    album.price = newPrice;
    cout << "Album modified successfully" << endl;
}

// вывод альбомов с треками > 7
vector<Album> filterAlbumsWithMoreThan7Tracks(const vector<Album>& albums) {
    vector<Album> result;
    for (const Album& album : albums) {
        if (album.tracksVector.size() > 7) {
            result.push_back(album);
        }
    }
    return result;
}

// оберточная функция с выводом оберточных данных
void printFilteredAlbums(const vector<Album>& albums, const string& filterName) {
    cout << "\n========== " << filterName << " ==========" << endl;
    if (albums.empty()) {
        cout << "No albums found" << endl;
        return;
    }

    for (const Album& album : albums) {
        cout << "Album: " << album.title << " | Artist: " << album.artist
            << " | Genre: " << genreToString(album.genre) << endl;
    }
    cout << "Total: " << albums.size() << " albums" << endl;
}

//                             ПРАКТИКА 10
// Запись числового поля (цены) в текстовый файл
void writePricesToTextFile(const vector<Album>& albums, const string& filename) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cout << "Error opening file for writing" << endl;
        return;
    }

    for (const Album& album : albums) {
        fout << album.title << " " << album.price << endl;
    }

    fout.close();
    cout << "Prices written to " << filename << " successfully" << endl;
}

// Чтение числового поля (цены) из текстового файла и обновление альбомов
void readPricesFromTextFile(vector<Album>& albums, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error opening file for reading" << endl;
        return;
    }

    string title;
    double price;
    int updated = 0;

    while (fin >> title >> price) {
        for (Album& album : albums) {
            if (album.title == title) {
                album.price = price;
                updated++;
                break;
            }
        }
    }

    fin.close();
    cout << "Updated " << updated << " albums prices from " << filename << endl;
}

// Задание 2
struct BinaryAlbum {
    char title[100];
    char artist[100];
    int genre;
    int releaseYear;
    int totalDuration;
    double price;
    int trackCount;
};

// Запись альбомов в бинарный файл
void writeAlbumsToBinaryFile(const vector<Album>& albums, const string& filename) {
    ofstream fout(filename, ios::binary | ios::out);
    if (!fout.is_open()) {
        cout << "Error opening binary file for writing" << endl;
        return;
    }

    for (const Album& album : albums) {
        BinaryAlbum binAlbum;

        strcpy_s(binAlbum.title, album.title.c_str());
        strcpy_s(binAlbum.artist, album.artist.c_str());
        binAlbum.genre = album.genre;
        binAlbum.releaseYear = album.releaseYear;
        binAlbum.totalDuration = album.totalDuration;
        binAlbum.price = album.price;
        binAlbum.trackCount = album.tracksVector.size();

        fout.write((char*)&binAlbum, sizeof(BinaryAlbum));
    }

    fout.close();
    cout << "Albums written to binary file: " << filename << endl;
}

// Чтение альбомов из бинарного файла
vector<Album> readAlbumsFromBinaryFile(const string& filename) {
    vector<Album> albums;
    ifstream fin(filename, ios::binary | ios::in);

    if (!fin.is_open()) {
        cout << "Error opening binary file for reading" << endl;
        return albums;
    }

    BinaryAlbum binAlbum;
    while (fin.read((char*)&binAlbum, sizeof(BinaryAlbum))) {
        Album album;
        album.title = binAlbum.title;
        album.artist = binAlbum.artist;
        album.genre = static_cast<Genre>(binAlbum.genre);
        album.releaseYear = binAlbum.releaseYear;
        album.totalDuration = binAlbum.totalDuration;
        album.price = binAlbum.price;

        albums.push_back(album);
    }

    fin.close();
    cout << "Read " << albums.size() << " albums from binary file: " << filename << endl;
    return albums;
}

int main() {

    // создание альбомов
    vector<Album> allAlbums = createAlbums();
    cout << "\nCreated " << allAlbums.size() << " albums." << endl;

    // Запись цены в текстовый файл
    writePricesToTextFile(allAlbums, "album_prices.txt");

    // Изменение цены для демонстрации
    cout << "\nBefore reading from file (first album price): $" << allAlbums[0].price << endl;
    allAlbums[0].price = 999.99;
    cout << "After manual change: $" << allAlbums[0].price << endl;

    // Чтение цены из файла обратно
    readPricesFromTextFile(allAlbums, "album_prices.txt");
    cout << "After reading from file: $" << allAlbums[0].price << endl;

    // Запись альбомов в бинарный файл
    writeAlbumsToBinaryFile(allAlbums, "albums.bin");

    // Чтение альбомов из бинарного файла
    vector<Album> loadedAlbums = readAlbumsFromBinaryFile("albums.bin");
    cout << "\nAlbums loaded from binary file:" << endl;
    for (size_t i = 0; i < loadedAlbums.size() && i < 5; i++) {
        cout << i + 1 << ". " << loadedAlbums[i].title << " by "
            << loadedAlbums[i].artist << " (" << loadedAlbums[i].releaseYear << ")" << endl;
    }

    // занятие 9

    // Фильтрация по жанру
    vector<Album> rockAlbums = albumsFilterGenre(allAlbums);
    sortAlbumsByAlphabet(rockAlbums);
    printFilteredAlbums(rockAlbums, "ROCK & INDIE ROCK ALBUMS");

    // Вывод конкретного альбома
    printSpecificAlbum(allAlbums, "Abbey Road");

    // Топ 5 альбомов
    printTop5Albums(allAlbums);

    // Альбомы с более чем 7 треками
    vector<Album> manyTracks = filterAlbumsWithMoreThan7Tracks(allAlbums);
    printFilteredAlbums(manyTracks, "ALBUMS WITH MORE THAN 7 TRACKS");

    // Изменение альбома
    cout << "\n--- Modifying Album ---" << endl;
    cout << "Before modification:" << endl;
    cout << "Title: " << allAlbums[1].title << ", Price: $" << allAlbums[1].price << endl;
    modifyAlbum(allAlbums[1], "Abbey Road (Remastered)", "The Beatles", Rock, 2024, 19.99);
    cout << "After modification:" << endl;
    cout << "Title: " << allAlbums[1].title << ", Price: $" << allAlbums[1].price << endl;

    return 0;
}
