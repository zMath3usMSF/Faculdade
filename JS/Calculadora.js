const executar = () => {
    const a = eval(document.getElementById("v1").value)
    const b = eval(document.getElementById("v2").value)
    let oper = eval(document.getElementById("oper").selectedIndex);
    let resultado = (oper==0) ? somar(a,b) :
                    (oper==1) ? subtrair(a, b) :
                    (oper==2) ? multiplicar(a, b) :
                    dividir(a, b);
    
    function somar(a, b) {return a + b};
    function subtrair(a, b) {return a - b};
    function multiplicar(a, b) {return a * b};
    function dividir(a, b){
        if(b == 0)
        {
            alert("Divisão por Zero!")
        }
        return a/b;
    }

    document.getElementById("resp").className = "alert alert-success"
    document.getElementById("resp").innerHTML = `O Resultado da Operação é ${resultado}`
}