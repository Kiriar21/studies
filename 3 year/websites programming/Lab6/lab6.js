let p1 = document.getElementById('zad1')
let b1 = document.getElementById('zad1Button')

b1.addEventListener('click', zad1Func)

function zad1Func() {
    if(p1.style.color === 'red') {
        p1.style.color='black';
        p1.style.fontFamily='Arial'
        p1.style.fontSize='10px'
    } else {
        p1.style.color='red';
        p1.style.fontFamily='Verdana'
        p1.style.fontSize='20px'
    }
}

let p2 = document.getElementById('zad2')
let b2 = document.getElementById('zad2Button')

b2.addEventListener('click', zad2Func)

function zad2Func() {
    let f2 = document.getElementById('zad2file').files[0]
    let reader = new FileReader()
    reader.onload = function(e) {
        p2.src = e.target.result
    }
    
    if(f2) {    
        reader.readAsDataURL(f2)
    } else {
        alert('Musisz wybrać jakiś plik.')
    }
}

function dodajOdnosnik() {
    var lista = document.getElementById("lista");
    var link = document.getElementById("link").value;
    var text = document.getElementById("text").value;
    var li = document.createElement("li");
    var a = document.createElement("a");
    a.href = link;
    a.textContent = text;
    li.appendChild(a);
    lista.insertBefore(li, lista.firstChild);
  }

  let p2_zad4 = document.getElementById('zad4')

  p2_zad4.addEventListener('mouseover', zad4Func_on)
  p2_zad4.addEventListener('mouseout', zad4Func_off)
  p2_zad4.addEventListener('click', zad4Func_copy)



  function zad4Func_copy() {
      let p2_v2 = document.getElementById('zad4').innerHTML
      let x = document.getElementById('zad4_2')

      x.innerHTML = p2_v2
  }

  function zad4Func_on() {
    let date = new Date()
    p2_zad4.innerHTML = date
  }
  function zad4Func_off() {
    p2_zad4.innerHTML = 'Dowolny tekst'
  }


  function zad5(e) {
    var buttons = document.getElementsByTagName("button")
    for (var i = 0; i < buttons.length; i++) {
        buttons[i].style.backgroundColor = 'initial'
        buttons[i].style.color='black'
    }
    e.style.backgroundColor='red'
    e.style.color='gold'
  }