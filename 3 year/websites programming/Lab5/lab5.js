const zad1_button = document.getElementById('zad1_button')
const zad2_mul = document.getElementById('zad2_mul')
const zad2_div = document.getElementById('zad2_div')
const zad3_ftoc = document.getElementById('zad3_ftoc')
const zad3_ctof = document.getElementById('zad3_ctof')
const zad4_score = document.getElementById('zad4_score')
const zad5_score = document.getElementById('zad5_score')
const zad6_score = document.getElementById('zad6_score')

zad1_button.addEventListener('click', zad1_func)
zad2_mul.addEventListener('click', zad2_mul_func)
zad2_div.addEventListener('click', zad2_div_func)
zad3_ctof.addEventListener('click', zad3_ctof_func)
zad3_ftoc.addEventListener('click', zad3_ftoc_func)
zad4_score.addEventListener('click', zad4_score_func)
zad5_score.addEventListener('click', zad5_score_func)
zad6_score.addEventListener('click', zad6_score_func)


function zad1_func() {
    let random = Math.floor(Math.random() * 10)+1;
    console.log(random)
    let x = document.getElementById('zad1_number').value
    let info = document.getElementById('zad1_info')
    if(x<1 || x>10) info.innerHTML = 'Bledna liczba. Podaj liczbe od 1 do 10'
    else if(x == random) info.innerHTML = 'Brawo! Udalo Ci sie zgadnac liczbe!'
    else info.innerHTML = 'Niestety. Nie udalo sie zgadnac liczby.'    
}
 
function zad2_mul_func() {
    let a = document.getElementById('zad2_number1').value
    let b = document.getElementById('zad2_number2').value
    let info_2 = document.getElementById('zad2_info')
    info_2.innerHTML = "Wynik mnozenia to: "+(a*b)
}

function zad2_div_func() {
    let a = document.getElementById('zad2_number1').value
    let b = document.getElementById('zad2_number2').value
    let info_2 = document.getElementById('zad2_info')
    if(b!==0) info_2.innerHTML = "Wynik dzielenia to: "+(a/b)
    else if(b===0) info_2.innerHTML = "Nie mozna dzielic przez 0"
    else info_2.innerHTML = "Niespodziewany wynik"
}

function zad3_ctof_func() {
    let value_rad = document.getElementById('zad3_radius_value').value
    let info_zad3 = document.getElementById('zad3_info')
    info_zad3.innerHTML = "Wartosc po przeliczeniu C na F to: "+((value_rad*9)/5+32)
}

function zad3_ftoc_func() {
    let value_rad = document.getElementById('zad3_radius_value').value
    let info_zad3 = document.getElementById('zad3_info')
    info_zad3.innerHTML = "Wartosc po przeliczeniu F na C to: "+(((value_rad-32)*5)/9)
}
function zad4_score_func() {
    let a = document.getElementById('zad4_number1').value
    let n = document.getElementById('zad4_number2').value
    let info_zad4 = document.getElementById('zad4_info')
    info_zad4.innerHTML = "Wynik twojego "+a+"^"+n+"="+(a**n);
}
function zad5_score_func() {
    let n = document.getElementById('zad5_number1').value
    let info_zad5 = document.getElementById('zad5_info')
    if(n>0) {
        let silnia = 1;
        for( let i=1; i<=n;i++) silnia*=i
        info_zad5.innerHTML = "Wynik "+n+"! = "+silnia
    } else {
        info_zad5.innerHTML = "Nieprawidłowa wartość do obliczenia silni."
    }   
}
function zad6_score_func() {
    let arr = []
    let info_zad6 = document.getElementById('zad6_info')
    for(let i=0;i<10;i++){
        arr[i] = Math.floor(Math.random() * 10)+1
    } 
    info_zad6.innerHTML = "Tablica przed sortowaniem:" + arr.join(", ")

    
    for(let i=0; i<arr.length; i++) {
        let min = i
        for(let j=i+1; j<arr.length; j++) {
            if(arr[min] > arr[j]) min=j
        }
        if(min!==i) {
            let temp = arr[min]
            arr[min] = arr[i]
            arr[i] = temp
        }
    }

    info_zad6.innerHTML += "<br><br>Tablica po sortowaniu:" + arr.join(", ")
}