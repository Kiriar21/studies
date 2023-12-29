open System
open Microsoft.FSharp.Core

//zad3
let wczytaj (napis:string) = 
    Console.Write($"{napis}") 
    Console.ReadLine() 
 
let liczbaUzytkownika () = 
    let czyLiczba, dana = Int32.TryParse (wczytaj "Podaj liczbe calkowita: ") 
    if czyLiczba then Some (dana*dana) 
    else None 
Console.WriteLine("Zadanie3:\n")    
let liczba3 = liczbaUzytkownika() 
match liczba3 with 
| Some a -> Console.WriteLine($"{a}") 
| _ -> Console.WriteLine("Nie podales wartosci, to ja nie podam wyniku.") 

//zad4
Console.WriteLine("Zadanie4:\n")    
let liczba4 = liczbaUzytkownika() 
if( (Option.Some (liczba4.IsSome)) = Some true) then 
    Console.WriteLine($"{liczba4.Value*liczba4.Value}") 
else 
    Console.WriteLine("Nie podales wartosci, to ja nie podam wyniku.") 

//zad6
let zad6 () = 
    let czyLiczba, dana = Int32.TryParse (wczytaj "Podaj liczbe calkowita: ") 
    if czyLiczba then Ok (dana*dana) 
    else Error ("Nie została podana liczba całkowita") 

Console.WriteLine("Zadanie6:\n")    
let liczba = zad6() 
match liczba with 
| Ok a -> Console.WriteLine($"{a}") 
| Error n -> Console.WriteLine($"{n}") 

//zad7
let rec zad7() = 
    let liczba = liczbaUzytkownika()  
    if ( (Option.Some (liczba.IsSome)) = Some true) then Console.WriteLine($"{liczba.Value*liczba.Value}") 
    else Console.WriteLine("Nieprawidlowa wartosc.Wprowadz ponownie.\n") 

Console.WriteLine("Zadanie7:\n")    
zad7() 

//zad8
let Zadanie8() = 
    let rec petla i =  
        match Int32.TryParse (wczytaj "Podaj liczbe calkowita: ") with 
        | true, int -> Some int 
        | _ -> 
            if (i < 4) then 
                Console.WriteLine("Nie podano wartosci lub jest nieprawidlowa.") 
                petla (i + 1) 
            else 
                Console.WriteLine("No ile razy mozna sie mylić?") 
                None 
    petla 1 
Console.WriteLine("Zadanie8:\n")    
let x = Zadanie8()

//zad10
let liczbUzytkownika10 () = 
    let jestLiczba, liczba = Int32.TryParse (wczytaj "Podaj liczbe calkowita: ") 
    if jestLiczba then 
        Some (liczba) 
    else 
        None 

Console.WriteLine("Zadanie10:\n")     
let liczba1 = liczbUzytkownika10() 
let liczba2 = liczbUzytkownika10() 
if( ((Option.Some (liczba1.IsSome)) = Some true ) && ( (Option.Some (liczba2.IsSome)) = Some true) ) then Console.WriteLine($"{liczba1.Value + liczba2.Value}") 
else Console.WriteLine("Wprowadzone dane sa niepoprawne") 

//zad11
let spr11 (licz:string) = 
    let czyl11, dana = Int32.TryParse(licz) 
    if czyl11 then 
        Ok dana
    else 
        Error ("Nie została podana liczba całkowita numer: ") 
 
let wczyt11() = 
    let napis = wczytaj "Podaj liczbe calkowita: " 
    Result.bind spr11 (Ok napis)

let dodawanieRes (liczba1:Result<int,string>) (liczba2:Result<int,string>) = 
    match liczba1 with 
     | Ok a -> 
            match liczba2 with 
            | Ok b -> Console.WriteLine($"{a+b}") 
            | Error msg -> Console.WriteLine("blad") 
     | Error msg -> Console.WriteLine("blad")

let Zadanie11() = 
    let rec loop () = 
        Console.WriteLine("1. ") 
        let liczba1 = wczyt11() 
        match liczba1 with 
        | Ok a -> 
                Console.WriteLine("2. ") 
                let liczba2 = wczyt11() 
                match liczba2 with 
                | Ok a -> dodawanieRes liczba1 liczba2 
                | Error msg ->  
                        Console.WriteLine($"{msg} 2") 
        | Error msg ->  
                Console.WriteLine($"{msg} 1") 
    loop ()

Console.WriteLine("Zadanie11:\n")    
Zadanie11()

//zad12
let wczytywanieLiczbyZad12() = 
    let jestLiczba, liczba = Int32.TryParse (wczytaj "Podaj liczbe calkowita: ") 
    if jestLiczba then Some liczba 
    else None 
 
let dodawanie (liczba1:int Option) (liczba2:int Option) =  Console.WriteLine($"{liczba1.Value+liczba2.Value}") 
let Zadanie12() = 
    let rec loop () = 
        Console.WriteLine("1. ") 
        let liczba1 = wczytywanieLiczbyZad12() 
        match liczba1 with 
        | Some a -> 
                    Console.WriteLine("2. ") 
                    let liczba2 = wczytywanieLiczbyZad12() 
                    match liczba2 with 
                    | Some b -> dodawanie liczba1 liczba2 
                    | None ->  
                            Console.WriteLine("Liczba 2 jest niepoprawna") 
                            loop () 
        | None ->  
                Console.WriteLine("Liczba 1 jest niepoprawna") 
                loop ()  
    loop () 

Console.WriteLine("Zadanie12:\n")    
Zadanie12()