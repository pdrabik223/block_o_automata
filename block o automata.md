# Block o automata 

To minimalistyczna gra logiczna 
opierająca się na zasadach rządzących cellular automatą.

## Cel gry
Celem gry jest zdobyć punkt kontrolny (najechać na niego blokiem gracza);

## Sposób gry 
Na początku rozgrywki trwa faza przygotowawcza.

Gracz ma za zadanie ustawić swoje komórki na legalnych polach,

gdy uzna, że przygotował swoje pionki do rozgrywki, rozpoczyna się druga część rozgrywki 
tura komputera. 

W turze komputera pionki przesuwają się po planszy i wchodzą ze sobą w_ interakcje. 

Na tym etapie gracz nie ma kontroli nad pionkami.

Gracz wygrywa poprzez zdobycie celu gry. 

Za każdy poziom gracz może zdobyć trzy trofea.

## Trofea
Trofea przyznawane są za spełnienie poniższych wymagań

- ukończenie poziomu 
- ukończenie wykorzystując minimalną liczbę pionków
- ukończenie w_ ograniczonej liczbie iteracji

Twórca poziomu decyduje o trudności zdobywania trofeów.

# Edytor poziomów

Do dyspozycji gracza oddawany jest także edytor poziomów,
narzędzie pozwalające tworzyć własne łamigłówki.

# Rodzaje komórek 

Gra rozpoznaje 7 rodzajów komórek.

## Wall 
ikona:
![wall.png](images/wall.png)

- jest nieruchomym blokiem.

## Movable wall

ikona:
![Mwall.png](images/movable_wall.png)

- jest ruchomym blokiem.
- nie może zostać zabita przez Kill Cell.

## Kill 
ikona:
![enemypng](images/enemy.png)

- zabija komórki nacierające na niego. 
- może byc poruszony, ale tylko za pośrednictwem ruchomej ściany. 

## Move 
ikona:
![Move.png](images/Move.png)

- jest ruchomym blokiem.
- co iteracje (jeżeli nie jest zablokowana) przesuwa się na pole komórki przed nią samą. 
- jeżeli jakieś bloki stoją na drodze one także ulegną przesunięciu. 
- może zostać zabita. 
- porusza się jedynie wzdłuż i wszerz poziomu. 

## Curve  
ikona:
![curve.png](images/turn.png)

- jest nieruchomym blokiem.
- obraca wszystkie nacierające na niego bloki, tak by poruszały się w_ wyznaczony kierunek.

## Goal
ikona:
![goal.png](images/goal.png)

- jest ruchomym blokiem.
- może byc poruszony, ale tylko za pośrednictwem ruchomej ściany. 
- jeżeli zostanie wyeliminowana z planszy, cel gry zostaje osiągnięty.

## Spawn
ikona:
![Clone.png](images/Clone.png)

- jest ruchomym blokiem.
- może byc poruszony, ale tylko za pośrednictwem ruchomej ściany.
- co iterację gry przesuwa bloki przed sobą i w_ miejsce przesuniętego bloku 
    wstawiana jest kopia komórki stojącej za nią samą. 

## Puste pole
- pole niedostępne dla gracza, nie ma możliwości postawienia pionka na etapie przygotowania.
- nie ma symbolu 

## Legalne pole 

ikona:
![legalspot.png](images/empty_space.png)

- na etapie przygotowania gracz ma prawo w_ to pole wstawić dowolną figurę. 

## Przykładowy poziom:

![level1.png](images/demo_level.png)

Przed takim zadaniem staje gracz na początku każdej rundy

Rozwiązanie:

![level1solved.png](images/solved.png)
