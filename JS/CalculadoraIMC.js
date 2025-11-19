const executar = () => {
    const peso = eval(document.getElementById("v1").value);
    const altura = eval(document.getElementById("v2").value)
    const v_imc = imc(peso,altura);
    const v_sit = situacao(v_imc);
    document.getElementById("resp").innerHTML = `IMC: ${v_imc.toFixed(2)} | Situação: ${v_sit}`;
document.getElementById("resp").className = "alert alert-success";
}

const imc = (peso, altura) => peso / (altura * altura)
const situacao = (valor_imc) =>{
    if(valor_imc < 18.5)
        return "Abaixo do peso";
    else if(valor_imc < 25)
        return "Peso ideal";
    else if(valor_imc < 30)
        return "Levemente acima do peso";
    else if(valor_imc < 35)
        return "Obesidade de grau I";
    else if(valor_imc < 40)
        return "Obesidade de grau II";
    else
        return "Obesidade de grau III";
}