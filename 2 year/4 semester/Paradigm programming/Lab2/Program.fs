open System
//Zadanie 1
printf "---Zadanie 1 ---\n"
let zad1 (i:int) : string = 
    match i with
    |   1 -> "Wprowadziles 1"
    |   2 -> "Wprowadziles 2"
    |   3 -> "Wprowadziles 3"
    |   4 -> "Wprowadziles 4"
    |   _ -> "Wprowadzono inna wartosc niz 1 / 2 / 3 / 4 \n"
let (zad1_result:string) = zad1 2
printfn "%s" zad1_result

//Zadanie 2
printf "\n\n---Zadanie 2 ---\n"

let (zad2_a:int) = 2
let (zad2_b:int) = 3

let para_zad2 : (int * int) = (zad2_a,zad2_b)
//let para_zad21 = (zad2_dana_a, zad2_dana_b);; // prostszy przykład
printfn "Podane wartosc: %i %i\n\n" zad2_a zad2_b
match para_zad2 with
| (x, y) when x > y -> printfn "Wartosc pierwsza jest wieksza."
| (x, y) when y > x -> printfn "Wartosc druga jest wieksza"
| _ -> printfn "Wartosci sa takie same"
   
//Zadanie 3
printf "\n\n---Zadanie 3 ---\n"
let zadanie3_czy_trojkat (a:float) (b:float) (c:float) = 
    if (a>0.00) && (b>0.00) && (c>0.00) then
        if (a+b>c) && (a+c>b) && (c+b>a) then
            true
        else
            false
    else
        false

let zadanie3 (a:float) (b:float) (c:float) =
    let (obwod:float) = a+b+c
    let (polowa_obwodu:float) = obwod/2.0
    let (pole:float) = Math.Sqrt(polowa_obwodu*(polowa_obwodu-a)*(polowa_obwodu-b)*(polowa_obwodu-c))
    (obwod, pole)

let (zad3_a:float) = 3.0
let (zad3_b:float) = 4.0
let (zad3_c:float) = 5.0
let zad3_spr = zadanie3_czy_trojkat zad3_a zad3_b zad3_c 
Console.WriteLine($"Wartosci podane: {zad3_a} {zad3_b} {zad3_c} \n")

if zad3_spr then
    let zad3_score = zadanie3 3 4 5 
    printfn "Obwod trojkata: %f, Pole trojkata: %f\n" (fst zad3_score) (snd zad3_score)
else
    printf "Niestety. Nie mozna zbudowac trojkata.\n"

//Zadanie 4
printf "\n\n---Zadanie 4 ---\n"

let zadanie4 (email:string) =
    let mutable index_mouse = 0
    for i in 0..email.Length-1 do
        if email.[i] = '@' then
            index_mouse <- i
    (email.[0..index_mouse-1], email.[index_mouse+1..email.Length])

let (zad4_dana:string) = "username@pcz.pl"
Console.WriteLine($"Adres email podany: {zad4_dana}\n\n")
let zadanie4_result = zadanie4 zad4_dana
printfn "Nazwa uzytkownika %s, Domena: %s"  (fst zadanie4_result) (snd zadanie4_result)
let (zad4_dana1:string) = "firstlastname@username.net"
let zadanie4_result1 = zadanie4 zad4_dana1
printfn "Nazwa uzytkownika %s, Domena: %s"  (fst zadanie4_result1) (snd zadanie4_result1)

//Zadanie 5
printf "\n\n---Zadanie 5 ---\n"

match zadanie4_result with
| (_,b) when b="pcz.pl" -> Console.WriteLine($"Adres email: {zad4_dana} nalezy do domeny pcz.")
| _ -> Console.WriteLine($"Adres email: {zad4_dana} nie nalezy do domeny pcz.")

match zadanie4_result1 with
| (_,b) when b="pcz" -> Console.WriteLine($"Adres email: {zad4_dana1} nalezy do domeny pcz.")
| _ -> Console.WriteLine($"Adres email: {zad4_dana1} nie nalezy do domeny pcz.")

//Zadanie 6
printf "\n\n---Zadanie 6 ---\n"
let zadanie6 (x1:float,y1:float,z1:float) (x2:float,y2:float,z2:float) : float =
    Math.Sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1))

let zad6_krotka1 : (float*float*float) = (2.0, 3.0, 4.0)
let zad6_krotka2 : (float*float*float) = (5.0, 6.0, 7.0)
let zadanie6_result = zadanie6 zad6_krotka1 zad6_krotka2
Console.WriteLine($"Z punktów {zad6_krotka1} i {zad6_krotka2} w przestrzeni 3D odleglosc wynosi: {zadanie6_result}")

//Zadanie 7
printf "\n\n---Zadanie 7 ---\n"

let zadanie7 (promien:float) (px:float, py:float) (sx:float,sy:float) = 
    promien > Math.Sqrt(Math.Pow(px-sx,2)+Math.Pow(py-sy,2))

let (promien:float) = 7.0
let punkt7z : (float*float) = (3.0,3.0)
let srodekOkegu7z : (float*float) = (5.0,5.0)
let zadanie7_result = zadanie7 promien punkt7z srodekOkegu7z
Console.WriteLine($"Z uzytych wartosci:\n-promien{promien}\n-punkt{punkt7z}\n-srodek okregu{srodekOkegu7z}\n")
if zadanie7_result then Console.WriteLine($"Punkt lezy wewnątrz okregu")
else Console.WriteLine($"Punkt nie lezy wewnątrz okregu")
    
//Zadanie 8
printf "\n\n---Zadanie 8 ---\n"

type ulamek = {
    licznik:int
    mianownik:int};;

let zad8_NWD (a:int) (b:int) : int = 
    let mutable (aa:int) = Math.Abs(a)
    let mutable (bb:int) = Math.Abs(b)
    while bb > 0 do
        let mutable (t:int) = bb
        bb <- aa%bb
        aa <- t
    aa

let zad8_NWW (zad8_c:int) (zad8_d:int) : int = (zad8_c*zad8_d) / (zad8_NWD zad8_c zad8_d)

let zad8_dodawanie (zad8aa:int,zad8ab:int) (zad8ba:int, zad8bb:int) =
    let mutable (new_licznik:int) = 0 
    let mutable (new_mianownik:int) = 0 
    if zad8ab = zad8bb then
        new_licznik <- zad8aa+zad8ba
        new_mianownik <- zad8ab
    else
        new_mianownik <- zad8_NWW zad8ab zad8bb
        new_licznik <- zad8aa*(new_mianownik/zad8ab)+zad8ba*(new_mianownik/zad8bb)
    (new_licznik, new_mianownik)

let zad8_odejmowanie (zad8aa:int,zad8ab:int) (zad8ba:int, zad8bb:int) =
    let mutable (new_licznik:int) = 0 
    let mutable (new_mianownik:int) = 0 
    if zad8ab = zad8bb then
        new_licznik <- zad8aa-zad8ba
        new_mianownik <- zad8ab
    else
        new_mianownik <- zad8_NWW zad8ab zad8bb
        new_licznik <- zad8aa*(new_mianownik/zad8ab)-zad8ba*(new_mianownik/zad8bb)
    (new_licznik, new_mianownik)

let zad8_mnozenie (zad8aa:int,zad8ab:int) (zad8ba:int, zad8bb:int) = (zad8aa*zad8ba,zad8ab*zad8bb)

let zad8_dzielenie (zad8aa:int,zad8ab:int) (zad8ba:int, zad8bb:int)  = (zad8aa*zad8bb,zad8ab*zad8ba)
        
// zestaw a
let zad8_dana_a : (int*int)= (3,10)
let zad8_dana_b : (int*int)= (5,10)
// zestaw b
let zad8_dana_c : (int*int)= (8,15)
let zad8_dana_d : (int*int)= (9,20)
Console.WriteLine($"Zmienne do zadania - podpunkt a:\n1.{fst zad8_dana_a}/{snd zad8_dana_a}\n2.{fst zad8_dana_b}/{snd zad8_dana_b}\n")
let zad8_suma = zad8_dodawanie zad8_dana_a zad8_dana_b
let zad8_roznica = zad8_odejmowanie zad8_dana_a zad8_dana_b
let zad8_iloczyn = zad8_mnozenie zad8_dana_a zad8_dana_b
let zad8_iloraz = zad8_dzielenie zad8_dana_a zad8_dana_b
Console.WriteLine($"Wynik dodawania wynosi: {fst zad8_suma }/{snd zad8_suma}")
Console.WriteLine($"Wynik odejmowania wynosi: {fst zad8_roznica}/{snd zad8_roznica}")
Console.WriteLine($"Wynik mnozenia wynosi: {fst zad8_iloczyn}/{snd zad8_iloczyn}")
Console.WriteLine($"Wynik dzielenia wynosi: {fst zad8_iloraz}/{snd zad8_iloraz}")
//zestaw 2
Console.WriteLine($"\n\nZmienne do zadania - podpunkt b:\n1.{fst zad8_dana_c}/{snd zad8_dana_c}\n2.{fst zad8_dana_d}/{snd zad8_dana_d}\n")
let zad8_sumab = zad8_dodawanie zad8_dana_c zad8_dana_d
let zad8_roznicab = zad8_odejmowanie zad8_dana_c zad8_dana_d
let zad8_iloczynb = zad8_mnozenie zad8_dana_c zad8_dana_d
let zad8_ilorazb = zad8_dzielenie zad8_dana_c zad8_dana_d
Console.WriteLine($"Wynik dodawania wynosi: {fst zad8_sumab}/{snd zad8_sumab}")
Console.WriteLine($"Wynik odejmowania wynosi: {fst zad8_roznicab}/{snd zad8_roznicab}")
Console.WriteLine($"Wynik mnozenia wynosi: {fst zad8_iloczynb}/{snd zad8_iloczynb}")
Console.WriteLine($"Wynik dzielenia wynosi: {fst zad8_ilorazb}/{snd zad8_ilorazb}")

//Zadanie 9
printf "\n\n---Zadanie 9 ---\n"
  
let zad9_NWD (a:int) (b:int) : int = 
    let mutable (aa:int) = Math.Abs(a)
    let mutable (bb:int) = Math.Abs(b)
    while bb > 0 do
        let mutable (t:int) = bb
        bb <- aa%bb
        aa <- t
    aa

let zad9_NWW (zad9_c:int) (zad9_d:int) : int = (zad9_c*zad9_d) / (zad8_NWD zad9_c zad9_d)

let zad9_dodawanie (zad9a:ulamek) (zad9b:ulamek) : ulamek =
    let mutable (new_licznik:int) = 0 
    let mutable (new_mianownik:int) = 0 
    if zad9a.mianownik = zad9b.mianownik then
        new_licznik <- zad9a.licznik+zad9b.licznik
        new_mianownik <- zad9a.mianownik
        let (zad9_result:ulamek) = {licznik=new_licznik; mianownik=new_mianownik}
        zad9_result
    else
        new_mianownik <- zad9_NWW zad9a.mianownik zad9b.mianownik
        new_licznik <- zad9a.licznik*(new_mianownik/zad9a.mianownik)+zad9b.licznik*(new_mianownik/zad9b.mianownik)
        let (zad9_result:ulamek) = {licznik=new_licznik; mianownik=new_mianownik}
        zad9_result

let zad9_odejmowanie (zad9a:ulamek) (zad9b:ulamek) : ulamek =
    let mutable (new_licznik:int) = 0 
    let mutable (new_mianownik:int) = 0 
    if zad9a.mianownik = zad9b.mianownik then
        new_licznik <- zad9a.licznik-zad9b.licznik
        new_mianownik <- zad9a.mianownik
        let (zad9_result:ulamek) = {licznik=new_licznik; mianownik=new_mianownik}
        zad9_result
    else
        new_mianownik <- zad9_NWW zad9a.mianownik zad9b.mianownik
        new_licznik <- zad9a.licznik*(new_mianownik/zad9a.mianownik)-zad9b.licznik*(new_mianownik/zad9b.mianownik)
        let (zad9_result:ulamek) = {licznik=new_licznik; mianownik=new_mianownik}
        zad9_result

let zad9_mnozenie (zad9a:ulamek) (zad9b:ulamek) : ulamek = {licznik=zad9a.licznik*zad9b.licznik; mianownik=zad9a.mianownik*zad9b.mianownik}

let zad9_dzielenie (zad9a:ulamek) (zad9b:ulamek) : ulamek = {licznik=zad9a.licznik*zad9b.mianownik; mianownik=zad9a.mianownik*zad9b.licznik}
        
// zestaw a
let zad9_dana_a= {licznik=3; mianownik=10}
let zad9_dana_b= {licznik=5; mianownik=10}
// zestaw b
let zad9_dana_c= {licznik=8; mianownik=15}
let zad9_dana_d= {licznik=9; mianownik=20}
Console.WriteLine($"Zmienne do zadania - podpunkt a:\n1.{zad9_dana_a.licznik}/{zad9_dana_a.mianownik}\n2.{zad9_dana_b.licznik}/{zad9_dana_b.mianownik}\n")
let zad9_suma = zad9_dodawanie zad9_dana_a zad9_dana_b
let zad9_roznica = zad9_odejmowanie zad9_dana_a zad9_dana_b
let zad9_iloczyn = zad9_mnozenie zad9_dana_a zad9_dana_b
let zad9_iloraz = zad9_dzielenie zad9_dana_a zad9_dana_b
Console.WriteLine($"Wynik dodawania wynosi: {zad9_suma.licznik}/{zad9_suma.mianownik}")
Console.WriteLine($"Wynik odejmowania wynosi: {zad9_roznica.licznik}/{zad9_roznica.mianownik}")
Console.WriteLine($"Wynik mnozenia wynosi: {zad9_iloczyn.licznik}/{zad9_iloczyn.mianownik}")
Console.WriteLine($"Wynik dzielenia wynosi: {zad9_iloraz.licznik}/{zad9_iloraz.mianownik}")
//zestaw 2
Console.WriteLine($"\n\nZmienne do zadania - podpunkt b:\n1.{zad9_dana_c.licznik}/{zad9_dana_c.mianownik}\n2.{zad9_dana_d.licznik}/{zad9_dana_d.mianownik}\n")
let zad9_sumab = zad9_dodawanie zad9_dana_c zad9_dana_d
let zad9_roznicab = zad9_odejmowanie zad9_dana_c zad9_dana_d
let zad9_iloczynb = zad9_mnozenie zad9_dana_c zad9_dana_d
let zad9_ilorazb = zad9_dzielenie zad9_dana_c zad9_dana_d
Console.WriteLine($"Wynik dodawania wynosi: {zad9_sumab.licznik}/{zad9_sumab.mianownik}")
Console.WriteLine($"Wynik odejmowania wynosi: {zad9_roznicab.licznik}/{zad9_roznicab.mianownik}")
Console.WriteLine($"Wynik mnozenia wynosi: {zad9_iloczynb.licznik}/{zad9_iloczynb.mianownik}")
Console.WriteLine($"Wynik dzielenia wynosi: {zad9_ilorazb.licznik}/{zad9_ilorazb.mianownik}")

//Zadanie 11
printf "\n\n---Zadanie 11 ---\n"

type bezpieczene_dzielenie = {
    wynik:float
    komunikat:string};;

let zadanie11 (a:int) (b:int) : bezpieczene_dzielenie = 
    if b = 0 then {wynik=0; komunikat="Nie można dzielić przez 0."}
    else {wynik=float(float(a)/float(b)); komunikat=""}

let (zad11_licznik:int) = 1
let (zad11_mianownik:int) = 4
// przykład b
let (zad11_licznikb:int) = 2
let (zad11_mianownikb:int) = 0
let (zadanie11_result_a:bezpieczene_dzielenie) = zadanie11 zad11_licznik zad11_mianownik
let (zadanie11_result_b:bezpieczene_dzielenie) = zadanie11 zad11_licznikb zad11_mianownikb
Console.WriteLine($"Dla wartości: {zad11_licznik}/{zad11_mianownik} wynik")
match zadanie11_result_a with
| {komunikat="Nie można dzielić przez 0."} -> Console.WriteLine($"{zadanie11_result_a.komunikat}")
| _ -> Console.WriteLine($"Wynik dzielenia: {zadanie11_result_a.wynik}")
Console.WriteLine($"Dla wartości: {zad11_licznikb}/{zad11_mianownikb} wynik")
match zadanie11_result_b with
| {komunikat="Nie można dzielić przez 0."} -> Console.WriteLine($"{zadanie11_result_b.komunikat}")
| _ -> Console.WriteLine($"Wynik dzielenia: {zadanie11_result_b.wynik}")

//Zadanie 12
printf "\n\n---Zadanie 12 ---\n"

type VIN = {
    VIN : string
    kodKraju : string
    marka: string
    model: string
    producentKontynent: string
    rokProdukcji: string
    numerSeryjny : string
    inne : char};;    

let decodeVIN (vin:string) : VIN=
    {VIN=vin;
    kodKraju=vin.[0..2];
    marka=vin.[3..4];
    model=vin.[5..6];
    producentKontynent=vin.[7..8];
    rokProdukcji=vin.[9..10];
    numerSeryjny=vin.[11..15];
    inne=vin.[16]}

let wynik= decodeVIN "93KP0R1A1EE147257"
Console.WriteLine($"Numer VIN: {wynik.VIN}\nKod Kraju: {wynik.kodKraju}\nMarka: {wynik.marka}\nModel: {wynik.model
}\nProducent(Kontynent): {wynik.producentKontynent}\nRok produkcji: {wynik.rokProdukcji}\nNumer Seryjny: {wynik.numerSeryjny}\nInne: {wynik.inne}")

//Zadanie 14
printf "\n\n---Zadanie 14 ---\n"

type Rownanie = 
    | BrakPierwiastkow
    | JedenPierwiastek of float
    | DwaPierwiastki of float*float

let zadanie14_rownanie (a:float) (b:float) (c:float) : Rownanie =
    if a=0.00 then BrakPierwiastkow
    else
        let delta = (b*b) - (4.0*a*c)
        let pierwdelta = Math.Sqrt(delta)
        if delta > 0.00 then 
            let x1 = (-b+pierwdelta / (2.0*a))
            let x2 = (-b-pierwdelta / (2.0*a))
            DwaPierwiastki(x1,x2)
        elif delta=0.00 then JedenPierwiastek((-b/(2.0*a)))
        else BrakPierwiastkow

printf "Podaj wartosc a z rownania kwadratowego:"
let (a:float) = float(Console.ReadLine())
printf "Podaj wartosc b z rownania kwadratowego:"
let (b:float) = float(Console.ReadLine())
printf "Podaj wartosc c z rownania kwadratowego:"
let (c:float) = float(Console.ReadLine())
let (wynikRownania:Rownanie) = zadanie14_rownanie a b c
match wynikRownania with
|   BrakPierwiastkow -> printf"Brak pierwiastkow z liczb rzeczywistych. Są pierwiastki z liczb zespolonych lub brak rozwiązań."
|   JedenPierwiastek(x0) -> printf"Jeden pierwiastek wynosi: %f"x0
|   DwaPierwiastki(x1,x2) -> printf"Dwa pierwiastki. x1=%f, x2=%f" x1 x2 

//Zadanie 15
printf "\n\n---Zadanie 15 ---\n"

type Osoba ={
    mutable imie:string 
    mutable nazwisko:string
    mutable wiek:int};;
    
let pobieranieImienia (os:Osoba): string =
    printf "Podaj swoje imie:"
    let (imie:string) = string(Console.ReadLine())
    if imie = "" then os.imie
    else imie

let pobieranieNazwiska (os:Osoba): string =
    printf "Podaj swoje nazwisko:"
    let (nazwisko:string) = string(Console.ReadLine())    
    if nazwisko = "" then os.nazwisko
    else nazwisko

let pobieranieWieku (os:Osoba): int = 
    printf "Podaj swój wiek:"
    let (wiek:int) = int(Console.ReadLine())
    if wiek < 1  then os.wiek
    else wiek 

let menu (x:int)=
    let mutable (wyn:int) = 0
    printfn "WYBIERZ OPCJE\n1 - utworzenie rekordu\n2 - modyfikacja rekordu\n3 - pokaz rekord\n4 - zakończenie programu\nPodaj swoją liczbe"
    wyn <- int(Console.ReadLine())
    wyn

let pokaz_dane (os:Osoba) = Console.WriteLine($"Dane: {os.imie} {os.nazwisko} Wiek {os.wiek}")

let mutable (osoba_zadanie14:Osoba) = {imie="";nazwisko="";wiek=0} 
let mutable (numer_menu:int) = 0

while numer_menu <> 4 do
    numer_menu <- menu 1
    if ( numer_menu = 2 || numer_menu = 3 ) && (osoba_zadanie14.imie="" && osoba_zadanie14.nazwisko="" && osoba_zadanie14.wiek = 0) then
        printfn "Musisz najpierw stworzyc osobe. Wybierz opcje 1 przed wybraniem innych opcji."
    else
        match numer_menu with
            | 1 -> osoba_zadanie14 <- {imie=pobieranieImienia osoba_zadanie14 ;nazwisko=pobieranieNazwiska osoba_zadanie14;wiek=pobieranieWieku osoba_zadanie14}
            | 2 -> osoba_zadanie14 <- {imie=pobieranieImienia osoba_zadanie14;nazwisko=pobieranieNazwiska osoba_zadanie14;wiek=pobieranieWieku osoba_zadanie14}
            | 3 -> pokaz_dane osoba_zadanie14
            | _ -> printf"Wybrano niepoprawną wartość. Spróbuj ponownie"