<h1>Задачи</h1>

Определить структурный тип, описывающий музыкальные альбомы (название
альбома, исполнитель, стиль, год выпуска, длительность, стоимость, название и
продолжительность композиций альбома). Заполнить структурный массив 20-ю
записями. Переписать из исходного массива в другой массив, информацию только о
тех альбомах, стиль которых рок или инди-рок. Затем новый массив отсортировать
по исполнителю по алфавиту. Вывести все данные по конкретному альбому.
Вывести 5 самых популярных альбомов. Реализовать функцию изменения альбома.
В отдельный массив поместить все альбомы, имеющие более 7 композиций.
Реализовать вывод отфильтрованных данных в виде оберточной функции.
Сделать код чтения / записи в файл с использованием подпрограмм.
Сделать чтение / запись своей структуры в бинарный файл. Оформить в виде подпрограмм.

<h1>Вывод программы</h1>

```
Created 20 albums.
Prices written to album_prices.txt successfully

Before reading from file (first album price): $12.99
After manual change: $999.99
Updated 0 albums prices from album_prices.txt
After reading from file: $999.99
Albums written to binary file: albums.bin
Read 20 albums from binary file: albums.bin

Albums loaded from binary file:
1. Heavy Metal by Kai Angel & 9mice (2023)
2. Abbey Road by The Beatles (1969)
3. Thriller by Michael Jackson (1982)
4. The Eminem Show by Eminem (2002)
5. Kind of Blue by Miles Davis (1959)

========== ROCK & INDIE ROCK ALBUMS ==========
Album: Back in Black | Artist: AC/DC | Genre: Rock
Album: In Utero | Artist: Nirvana | Genre: Rock
Album: Nevermind | Artist: Nirvana | Genre: Rock
Album: The Dark Side of the Moon | Artist: Pink Floyd | Genre: Rock
Album: Abbey Road | Artist: The Beatles | Genre: Rock
Album: Indie Rock Collection | Artist: Various Artists | Genre: IndieRock
Total: 6 albums
================================
Album: Abbey Road
Artist: The Beatles
Genre: Rock
Date release: 1969
Duration: 16:38
Price: 14.99
Come Together(4:19)
Something(3:02)
Maxwell's Silver Hammer(3:27)
Here Comes the Sun(3:05)
Because(2:45)
================================ 

========== TOP 5 POPULAR ALBUMS ==========
1. Heavy Metal - Kai Angel & 9mice (2023)
2. Indie Rock Collection - Various Artists (2020)
3. To Pimp a Butterfly - Kendrick Lamar (2015)
4. 1989 - Taylor Swift (2014)
5. Random Access Memories - Daft Punk (2013)

========== ALBUMS WITH MORE THAN 7 TRACKS ==========
No albums found

--- Modifying Album ---
Before modification:
Title: Abbey Road, Price: $14.99
Album modified successfully
After modification:
Title: Abbey Road (Remastered), Price: $19.99
