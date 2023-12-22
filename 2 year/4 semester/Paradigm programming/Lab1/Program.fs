open System
open System.Threading
open System.Text
// zadanie 1

//let poleKola (r : float) : float = 3.14159*(r*r) // deklaracja funkcji 


//printfn "Podaj dlugosc promienia:"
//let (r:float) = float (Console.ReadLine()) // wczytanie zmiennej r - dlugosc promienia

//if r > 0.00 then // warunek sprawdzający poprawnosc danych
//    let (pole:float) = poleKola r // wywolanie funkcji i przypisanie wartosci do zmiennej
//    printfn "Wynik pola kola z wartoscia r=%f wynosi: %f" r pole
//else 
//    printfn "Dlugosc promienia powinna byc wieksza niz 0"








// zadanie 2

 
//let funkcjaKwadratowa (a:float) (b:float) (c:float) =  // deklaracja funkcji
//    let (delta:float) = (b*b)-4.0*a*c // obliczenie delty  
//    if delta > 0.00 then
//        (2.00,(-b-sqrt(delta))/2.0*a,(-b+sqrt(delta))/2.0*a) //wyznaczenie ilosci i samych miejsc zerowych
//    elif delta = 0 then
//        (1.00,-b/(a*a),-b/(a*a)) //wyznaczenie ilosci i samych miejsc zerowych
//    else
//        (0.00,0.00,0.00) //wyznaczenie ilosci i samych miejsc zerowych


//printfn "Podaj wartosc a funkcji liniowej:"
//let (a:float) = float(Console.ReadLine()) // pobranie zmiennej a
//printfn "Podaj wartosc b funkcji liniowej:"
//let (b:float) = float(Console.ReadLine()) // pobranie zmiennej b
//printfn "Podaj wartosc c funkcji liniowej:"
//let (c:float) = float(Console.ReadLine()) // pobranie zmiennej c

//let (ilosc_miejsc,x1,x2) = funkcjaKwadratowa a b c  // wywolanie funkcji kwadratowej
//if ilosc_miejsc=0.00 then // gdy 0 miejsc 
//    printfn "Brak miejsc zerowych"
//elif ilosc_miejsc=1.00 then // gdy 1 miejsce
//    printfn "Z funkcji kwadratowej f(x)=%fx^2+%fx+%f otrzymujemy jedno miejsce zerowe -> x0 = %f" a b c x1
//else  // gdy 2 miejsca
//    printfn "Z funkcji kwadratowej f(x)=%fx^2+%fx+%f otrzymujemy dwa miejsca zerowe -> x1 = %f , x2 = %f " a b c x1 x2



// zadanie 3

//let czyMoznaZbudowacTrojkat (a:float) (b:float) (c:float) = // deklaracja funkcji
//    if a>0.00 || b>0.00 || c>0.00 then
//        if a+b>c && a+c>b && b+c>a then
//            printfn "Mozna zbudowac trojkat!"
//        else
//            printfn "Nie mozna zbudowac trojkata z podanych wartosci."
//    else
//        printfn "Dlugosci bokow muszą być większe niż 0!"
        
        

//printfn "Podaj dlugosc pierwszego boku trojkata:"
//let (a:float) = float(Console.ReadLine()) // pobranie zmiennej a
//printfn "Podaj dlugosc drugiego boku trojkata:"
//let (b:float) = float(Console.ReadLine()) // pobranie zmiennej b
//printfn "Podaj dlugosc trzeciego boku trojkata:"
//let (c:float) = float(Console.ReadLine()) // pobranie zmiennej c

//czyMoznaZbudowacTrojkat a b c 




// zadanie 4


//let obliczPole (a:float) (b:float) (c:float) = 
//    let obwod = a+b+c
//    sqrt(obwod*(obwod-a)*(obwod-b)*(obwod-c))  //zastosowanie wzoru harona

//let czyMoznaZbudowacTrojkat (a:float) (b:float) (c:float) = // poprzednia funkcja z zadania 3 pozwala na sprawdzenie czy mozna zbudować trojkat
//    if a>0.00 && b>0.00 && c>0.00 then
//        if a+b>c && a+c>b && b+c>a then
//            let wynik = obliczPole a b c 
//            printfn "Pole trojkata o podanych bokach: a=%f, b=%f, c=%f wynosi %f" a b c wynik
//        else
//            printfn "Nie mozna zbudowac trojkata z podanych wartosci."
//    else
//        printfn "Dlugosci bokow muszą być większe niż 0!"
        
        

//printfn "Podaj dlugosc pierwszego boku trojkata:"
//let (a:float) = float(Console.ReadLine()) // pobranie zmiennej a
//printfn "Podaj dlugosc drugiego boku trojkata:"
//let (b:float) = float(Console.ReadLine()) // pobranie zmiennej b
//printfn "Podaj dlugosc trzeciego boku trojkata:"
//let (c:float) = float(Console.ReadLine()) // pobranie zmiennej c

//czyMoznaZbudowacTrojkat a b c 



// zadanie 5

//let rec sumaNaturalnych (n:int) : int = 
//    if n = 1 then
//        1
//    else
//        n + sumaNaturalnych(n-1) // do wartosci n dodajemy wynik 


//printfn "Podaj wartosc dodania, do zsumowania wartosci liczbowych <1-n>"
//let (n:int) = int(Console.ReadLine())
//if n > 0 then
//    let (z:int) = sumaNaturalnych n
//    printfn "Suma liczb naturanych z przedzialu <1,%d> wynosi %d" n z
//else
//    printfn "Podano nieprawidlową liczbe naturalna dodatnią (n<=0)"


// zadanie 6

//let rec wartoscXdoN (x:int) (n:int) : int =
//    if x = 0 then
//        0
//    elif n = 0 || x = 1 then   
//        1
//    else
//        x * wartoscXdoN x (n-1) 


//printfn "Podaj wartosc x <0-n>"
//let (x:int) = int(Console.ReadLine())
//printfn "Podaj wartosc n <0-n>"
//let (n:int) = int(Console.ReadLine())

//if x>(-1) && n>(-1) then
//    let (score:int) = wartoscXdoN x n 
//    printfn "Wartosc wyrazenia %d^%d = %d" x n score
//else
//    printfn "Bledne dane wejsciowe."



// zadanie 7

//let rec fibo (n:int) : int = 
//    if n < 3 then
//        1
//    else
//        fibo(n-2) + fibo(n-1)

//printfn "Podaj wartosc n <0-n>"
//let (n:int) = int(Console.ReadLine())

//if n>(-1) then
//    let (score:int) = fibo n 
//    printfn "Wartosc %i wyrazu ciagu fibonaciego wynosi %d " n score
//else
//    printfn "Bledne dane wejsciowe."



// zadanie 8

//let rec dwumian (n:int) (k:int) : int = 
//    if k = 0 then
//        1
//    elif n=k then
//        1
//    else
//        dwumian(n-1) k + dwumian(n-1)(k-1)

//printfn "Podaj wartosc n "
//let (n:int) = int(Console.ReadLine())
//printfn "Podaj wartosc k "
//let (k:int) = int(Console.ReadLine())

//if n>(-1) && k>(-1) then
//    if k<>0 && n<>k then
//        let (score:int) = dwumian n k 
//        printfn "Wartosc wyrazenia dwumianu Newtona dla n=%i i k=%i wynosi %d" k n score
//    else
//        printfn "Nieprawidlowe wartosci. Nie mozna obliczyc."
//else
//    printfn "Bledne dane wejsciowe."



// zadanie 9

let rec czyPierwsza (n:int)(x:int) = 
    
    if n=1 then //liczba 1 nie jest liczba pierwsza ani zlozona
        false 
    elif x > int(sqrt(float(n))) then // jeżeli dzielnik bedzie wiekszy niz pierwiastek z liczby to liczba jest liczba pierwsza
        true
    elif n%x=0 then // jezeli nasze n podzieli sie przez dzielnik to jest to liczba zlozona
        false
    else 
        czyPierwsza n (x+1) // wywolanie funkcji z powiekszonym o 1 dzielnikiem
        
        

printfn "Podaj wartosc n (n>0)"
let (n:int) = int(Console.ReadLine())
let (x:int)=2
if n>0 then
    let (score:bool) = czyPierwsza n x  
    if score then
        printfn "Liczba %d jest liczba pierwsza"  n 
    else
        printfn "Liczba %d nie jest liczba pierwsza"  n  
else
    printfn "Bledne dane wejsciowe."


// zadanie 10

//let rzut_koscia (ilosc_rzutow:int) : list<_>=
//    let (rand:Random) = new Random()
//    [for i in 1..ilosc_rzutow -> rand.Next(1,7)]


//let mutable (ilosc_rzutow:int) = 1000
//let mutable (ilosc_szostek:int) = 0
//let mutable (index:int) = 0
//let (rzuty:list<_>) = rzut_koscia ilosc_rzutow 

//printfn "Lista: %A \n" rzuty
//while index<ilosc_rzutow do
//    if rzuty.[index] = 6 then
//        ilosc_szostek <- ilosc_szostek+1
//    index <- index+1

//let (pradopodobienstwo:float) = float(float(ilosc_szostek)/float(ilosc_rzutow))
//printfn "Podczas %d rzutów kostką do gry liczba 6 wypadła: %d razy \n Prawdopodobienstwo wyrzucenia 6 w tych losowaniach wynosi: %f" ilosc_rzutow ilosc_szostek pradopodobienstwo



// zadanie 11


//let rzut_koscia (ilosc_rzutow:int): list<_>=
//    let (rand:Random) = new Random()
//    [[for i in 1..ilosc_rzutow -> rand.Next(1,7)];[for j in 1..ilosc_rzutow -> rand.Next(1,7)]]


//let mutable (ilosc_rzutow:int) = 1000
//let mutable (ilosc_dublet_szostek:int) = 0
//let mutable (index:int) = 0
//let (rzuty:list<_>) = rzut_koscia ilosc_rzutow

//while index<ilosc_rzutow do
//    if rzuty.[0].[index] = 6 &&  rzuty.[1].[index] = 6 then
//        ilosc_dublet_szostek <- ilosc_dublet_szostek+1
//    index <- index+1


//let (pradopodobienstwo:float) = float(float(ilosc_dublet_szostek)/float(ilosc_rzutow))
//printfn "Podczas %d rzutów kostką do gry liczba 6 wypadła: %d razy \n Prawdopodobienstwo wyrzucenia 6 w tych losowaniach wynosi: %f" ilosc_rzutow ilosc_dublet_szostek pradopodobienstwo

// zadanie 12


//let NNW (a:int) (b:int) : int = 
//    let mutable (aa:int) = Math.Abs(a)
//    let mutable (bb:int) = Math.Abs(b)
//    while bb > 0 do
//        let mutable (t:int) = bb
//        bb <- aa%bb
//        aa <- t
//    aa

//printfn "Podaj wartosc pierwszej zmiennej:"
//let mutable (a:int) = int(Console.ReadLine())
//printfn "Podaj wartosc drugiej zmiennej:"
//let mutable (b:int) = int(Console.ReadLine())

//let (wynik:int) = NNW a b
//printfn "Najwiekszy wspolny dzielnik z liczb: %d %d wynosi %d" a b wynik


// zadanie 13 (szereg 1 i 2)

//let szereg_pierwszy : double=
//    let mutable (i:double) = 1.00
//    let mutable (wynik:double) = 0.00
//    let mutable (temp:double) = 1.00
//    while Math.Abs(temp) > Math.Pow(10,-7) do
//        temp <- Math.Abs(1.00/(i*i))
//        wynik <- wynik+temp
//        i <- i+1.00
//    wynik

//let rec silnia (i:double) : double =
//    if i=1 then
//        1
//    else
//        i* silnia(i-1.00)
  

//let szereg_drugi : double=
//    let mutable (i:double) = 1.00
//    let mutable (wynik:double) = 0.00
//    let mutable (temp:double) = 1.00
//    while Math.Abs(temp) >= Math.Pow(10,-7) do
//        if int(i)%2 = 0 then
//            temp <- 1.00/silnia(i) 
//        else 
//            temp <- -1.00/silnia(i)
//        wynik <- wynik+temp
//        i <- i+1.00
//    wynik


//let (wynik_pierwszego:double) = szereg_pierwszy
//let (wynik_drugiego:double) = szereg_drugi 

//printfn "Wynik pierwszego szeregu: %f\nWynik drugiego szeregu: %f\nDokladnosc jest ustalona na e=10^-7 \n" wynik_pierwszego wynik_drugiego    


// zadanie 15

//let zamiana_na_F (temperatura: byref<float>) : float =  // przekazuje referencje do wartosci - dla testu
//    32.0 + ((9.0/5.0)*temperatura)

//printfn "Podaj wartość temperatury w stopniach Celcjusza:"
//let mutable (temperatura:float) = float(Console.ReadLine())

//temperatura <- zamiana_na_F (&temperatura) // wskazanie referencyjnej zmiennej

//printfn "Wartosc temperatury wynosi: %f" temperatura


// zadanie 17

//let palindrom_check (slowo:string)  =
//    let mutable (licznik:int) = 0
//    for i=0 to (slowo.Length/2)-1 do
//        if slowo.[i] <> slowo.[slowo.Length-(i+1)] then
//            licznik <- licznik+1
//    if licznik = 0 then 
//        true
//    else 
//        false
        
//printfn "Podaj palindrom - słowo, które czytane od tyłu znaczy to samo"
//let (slowo:string) = string(Console.ReadLine())


//let czyPolindrom = palindrom_check slowo
//if czyPolindrom then 
//    printfn "Slowo: %s jest palindromem!" slowo
//else
//    printfn "Slowo: %s nie jest palindromem!" slowo

// zadanie 18

//let liczenie (slowo:string) (znak:char) : int = 
//    let mutable (x:int) = 0
//    for i in 0..(slowo.Length-1) do
//        if slowo.[i] = znak then
//            x <- x+1
//    x


//printfn "Podaj palindrom - słowo, które czytane od tyłu znaczy to samo"
//let (slowo:string) = string(Console.ReadLine())
//printfn "Podaj znak, ktory chcesz podliczyc w ciagu znakow:"
//let (wyraz:char) = char(Console.ReadLine())

//let (policz_znaki:int) = liczenie slowo wyraz 
//printfn "Liczba znakow ' %c ' w slowie \" %s \" wynosi %d " wyraz slowo policz_znaki

// zadanie 21

//printfn "Podaj swoje imie: "
//let (imie:string) = string(Console.ReadLine())
//printfn "Podaj swoje nazwisko:"
//let (nazwisko:string) = string(Console.ReadLine())

//printfn "Witaj <%s %s>" imie nazwisko


// zadanie 22

//printfn "Podaj rok do sprawdzenia:"
//let (rok:int) = int(Console.ReadLine())

//if rok%4=0 && (rok%100<>0 || rok%400=0) then 
//    printfn "Rok %d jest przestepny" rok
//else
//    printfn "Rok %d nie jest przestepny" rok



// zadanie 23

//printfn "Podaj 1 bok trojkata:"
//let (a:float) = float(Console.ReadLine())
//printfn "Podaj 2 bok trojkata:"
//let (b:float) = float(Console.ReadLine())
//printfn "Podaj 3 bok trojkata:"
//let (c:float) = float(Console.ReadLine())

//if a>0.00 && b>0.00 && c>0.00 then
//    if a+b>c && a+c>b && b+c>a then
//        if a=b && a=c then
//            printf "Z podanych wartosci mozna zbudowac trojkat rownoboczny"
//        elif (a=b && a<>c) || (a=c && a<>b) || (b=c && a<>b) then
//            printfn "Z podanych wartosci mozna zbudowac trojkat rownoramienny"
//        elif (a*a)+(b*b)=(c*c) || (a*a)+(c*c)=(b*b) || (c*c)+(b*b)=(a*a) then
//            printfn "Z podanych wartosci mozna zbudowac trojkat prostokatny"
//        else
//            printfn "Z podanych wartosci mozna zbudowac dowolny trojkat"
//    else
//        printfn "Nie da sie zbudowac zadnego trojkata."
//else 
//    printfn "Boki nie moga byc mniejsze od 0"


// zadanie 25

//let zaszyfruj (slowo:char ) (przesuniecie:int) : char =
//    let mutable (result:char) = slowo
//    if (char(int(slowo)+przesuniecie) >= 'A' && char(int(slowo)+przesuniecie) <='Z') || (char(int(slowo)+przesuniecie) >= 'a' && char(int(slowo)+przesuniecie) <='z') then 
//        result <- char(int(result)+przesuniecie)
//    elif przesuniecie > 26 then 
//        result <- char(int(result)+int(przesuniecie%26))
//    else
//        result <- char(int(int(result)+int(przesuniecie))-26)
//    result


//printfn "Podaj slowo do zaszyfrowania"
//let (slowo:string) = string(Console.ReadLine())
//printfn "Podaj o ile liter ma być przesuniete (1-26):"
//let (ilosc:int) = int(Console.ReadLine())

//let mutable i = 0 
//while i < slowo.Length do 
//    let mutable wyn_funkcji  = zaszyfruj slowo.[i] ilosc
//    printf "%c" wyn_funkcji
//    i <- i+1    


// zadanie 26

//let odszyfruj (slowo:char ) (przesuniecie:int) : char =
//    let mutable (result:char) = slowo
//    if (char(int(slowo)-przesuniecie) >= 'A' && char(int(slowo)-przesuniecie) <= 'Z') || (char(int(slowo)-przesuniecie) >= 'a' && char(int(slowo)-przesuniecie) <='z') then 
//        result <- char(int(result)-przesuniecie)
//    elif przesuniecie > 26 then 
//        result <- char(int(result)-int(przesuniecie%26))
//    else
//        result <- char(int(int(result)-int(przesuniecie))+26)
//    result


//printfn "Podaj slowo do odszyfrowania"
//let (slowo:string) = string(Console.ReadLine())
//printfn "Podaj o ile liter ma być przesuniete (1-26):"
//let (ilosc:int) = int(Console.ReadLine())

//let mutable i = 0 
//while i < slowo.Length do 
//    let mutable wyn_funkcji  = odszyfruj slowo.[i] ilosc
//    printf "%c" wyn_funkcji
//    i <- i+1    




