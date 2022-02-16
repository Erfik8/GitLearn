# Główny plik operacyjny
- [Główny plik operacyjny](#główny-plik-operacyjny)
  - [Plany i pomysły](#plany-i-pomysły)
  - [Komendy do gita](#komendy-do-gita)
    - [1. Podstawowy setup](#1-podstawowy-setup)
    - [2. Komendy do monitorowania](#2-komendy-do-monitorowania)
    - [3. Tworzenie zmian w plikach](#3-tworzenie-zmian-w-plikach)
    - [4. Wysyłanie zmian na github](#4-wysyłanie-zmian-na-github)
    - [5. aktualizowanie lokalnego repozytorium](#5-aktualizowanie-lokalnego-repozytorium)
    - [6. Klonowanie całego repozytorium (gdy chcemy mieć na czysto cały setup)](#6-klonowanie-całego-repozytorium-gdy-chcemy-mieć-na-czysto-cały-setup)

Plik jak narazie będzie podzielony na 2 sekcje:
1. Plany i pomysły do realizacji 
2. ściąga z komendami do gita

## Plany i pomysły

1. Z racji początkowej fazy projektu, narazie skupiamy się na nauce gita. W ramach tego zajmujemy się edycją programów z labów.
    1a. Wszystkie programy można wspólnie tak napisać i poprawić (jeśli będzie trzeba), żeby faktycznie działały tak jak powinny
    1b. Do każdego z programów będzie można dodać nowe funkcje rozszerzające
    1c. Na bazie jakiegoś programu można stworzyć zupełnie coś nowego, jeśli będzie pomysł 
    1d. W miarę rozwoju można dodawać funkcjonalności z c++11, tak żeby wyglądało to wszystki bardziej profesjonalnie xd
2. W ramach nauki gita 
    2a. Można stworzyć jeden plik z przydatnymi komendami objaśniającymi, wraz z jakimś zastosowaniem
    2b. Może docelowo jakiś mini poradnik, jak sami będziemy mieć wszystko obcykane
3. Pojawił się pomysł stworzenia w przyszłości dużej apki okienkowej, w której mogłyby się znaleźć wszystkie przeedtytowane programy. Dlatego oprócz wcześniejszego, w ramach punktu 1 można też się przyjrzeć lepszemu wykorzystaniu obiektówki, żeby faktycznie wszystkie programy później łatwo połączyć w jeden

## Komendy do gita

### 1. Podstawowy setup

**`git init`** - zainicjowanie lokalnego repozytorium

**`git config user.name "nazwa użytkownika na Githubie"`**

**`git config user.email "email taki jak na githubie"`**

**`git remote add dowolna_nazwa "link"`** - ustawienie zdalnego repo. W miejsce *dowolna_nazwa* najczęściej wpisuje się **origin**

Na tym etapie mamy gotowe czyste repozytorium

### 2. Komendy do monitorowania

**`git status`** - wyświetla aktualny stan plików, które są zmodyfikowane, czy są dodane do następnego commita itp.

**`git log`** - w najbardziej podstawowej wersji wyświetla aktualne drzewko commitów na danym branchu. Ta komenda ma wiele bardziej rozbudowanych opcji 

- **`git log --all --graph`**
- **`git log --all --graph --oneline`**

**`git branch`** - pokazuje wszystkie **lokalne** branche
**`git branch -a`** - pokazuje lokalne oraz zdalne branche
 
### 3. Tworzenie zmian w plikach

Gdy rozpoczynamy zmiany, przede wszystkim trzeba zacząć od stworzenia nowego brancha, na którym te zmiany będą zachodzić. Lepiej unikać sytuacji modyfikowania plików na branchu **master**

**`git branch nazwa_brancha`** - stworzenie nowego brancha na zmiany

**`git checkout nazwa_brancha`** - przełączenie się na tego brancha

W tym momencie można robić zmiany. Po ich skończeniu robimy następujące rzeczy:

**`git add .`** - dodanie wszystkich zmian do następnego commita

**`git add /lokalizacja/`** - dodanie specyficznego pliku lub lokalizacji do następnego commita

**`git status`** - sprawdzenie co zostało dodane do commita

Pliki w tym momencie możemy dalej modyfikować, zanim wszystko zostanie ostatecznie dodane do commita

**`git commit -m "opis zmian"`** - dodanie nowego commita ze wszystkimi zmianami. `-m` Pozwala na dodanie wiadomości od razu w poleceniu

**`git commit`** - wersja standardowa. Wiadomość zostanie wygenerowana w pliku do ręcznego zatwierdzenia.

### 4. Wysyłanie zmian na github

Gdy wszystkie commity są przygotowane, pozostaje tylko spushować na repo 

**`git push /lokalizacja/ nazwa_branch`** - wysłanie z danego brancha commitów na zdalny branch o nazwie *nazwa_brancha*. Dla zachowania jednolitości, najlepiej w *nazwa_brancha* używać tej samej nazwy, jaką mamy nazwany lokalny branch.

### 5. aktualizowanie lokalnego repozytorium

Gdy zmiany zostały wysłane oraz zdalnie zostały zatwierdzone, trzeba zaktualizować to co mamy lokalnie i pobrać wszystkie zmiany. 
1. W pierwszej kolejności trzeba sprawdzić na githubie, czy zdalne branche nadal się znajdują. 

2. Komenda: 

**`git fetch --all`** - pobranie wszystkich zmian, wraz z informacjami o innych branchach

**`git branch -a`** - sprawdzenie listy zdalnych branchy

3. Jeśli są jakieś branche zdalne, które nie mają odpowiednika lokalnego, dobrze będzie stworzyć lokalne odpowiedniki.

**`git branch nazwa_brancha_zdalnego`** - stworzenie lokalnego brancha odpowiadającego temu zdalnemu. Do nazwy lokalnego brancha bierz tylko końcową nazwę, bez przedrosta wskazującego na źródło

**Przykład**
```
C:\Users\admin\main> git branch -a
 *  master
    feature
    remotes/origin/master
    remotes/origin/other
    remotes/origin/feature
```
*remotes/origin/other* jest zdalnym branchem, który nie ma odpowiednika lokalnego. Jego nazwą będzie **other**.

```
C:\Users\admin\main> git branch other
```

4. Na każdego brancha osobno trzeba się przełączyć i zaktualizować stan plików poleceniem 

**`git pull`**

### 6. Klonowanie całego repozytorium (gdy chcemy mieć na czysto cały setup)

Wystarczy wejść na pulpit i w terminalu wykonać polecenie

**`git clone "link z repo"`**

oprócz tego trzeba ustawić configurację użytkownika (parametry user.name i user.email). Domyślnie lokalizacja będzie nazwana **origin**. Wszystkie branche zdalne, oprócz głównego **master**, trzeba będzie utworzyć lokalnie.
